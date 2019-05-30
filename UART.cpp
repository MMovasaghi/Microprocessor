#include "uart.h"
#include "lpc17xx.h"


void UART::send(char d)
{
	Send(2, d);
}

void UART::Connect(int uartNo)
{
	if (uartNo == 2)
	{
		//LPC_PINCON->PINSEL0 &= ~(15 << 20);
		LPC_PINCON->PINSEL0 |= 1 << 20; //txd2
		LPC_PINCON->PINSEL0 |= 1 << 22;	//rxd2
	}
}

void UART::InitInterrupt(int uartNo, DataLength dlen, StopBit sb, Parity p, int Buadrate)
{
	Init(uartNo, dlen, sb, p, Buadrate);
	if (uartNo == 2)
	{
		NVIC_EnableIRQ(UART2_IRQn);
		LPC_UART2->IER = 3;
	}
}

void UART::Init(int uartNo, DataLength dlen, StopBit sb, Parity p, int Buadrate)
{
	Connect(uartNo);
	if (uartNo == 2)
	{
		ReceiveBuffer2.Init(500);
		SendBuffer2.Init(500);
		LPC_SC->PCONP |= 1 << 24;
		LPC_UART2->LCR = dlen;
		LPC_UART2->LCR |= sb << 2;
		if (p != Parity_Non)
		{
			LPC_UART2->LCR |= 1 << 3;
			LPC_UART2->LCR |= p << 4;
		}	
	}
	
	SetBaudRate(uartNo, Buadrate);
}

extern uint32_t SystemFrequency;
void UART::SetBaudRate(char UartNum, int Baudrate)
{
	unsigned int uClk = SystemFrequency >> 2;
	unsigned int d, m, bestd, bestm, tmp;
	uint64_t best_divisor, divisor;
	unsigned int current_error, best_error;
	unsigned int recalcbaud;
	best_error = 0xFFFFFFFF; /* Worst case */
	bestd = 0;
	bestm = 0;
	best_divisor = 0;
	for (m = 1 ; m <= 15 ;m++)
	{
		for (d = 0 ; d < m ; d++)
		{
			divisor = ((uint64_t)uClk * 268435456)*m / (Baudrate*(m+d));
			current_error = divisor & 0xFFFFFFFF;

			tmp = divisor / 4294967296;

			/* Adjust error */
			if(current_error > ((unsigned int)0x80000000))
			{
				current_error = -current_error;
				tmp++;
			}

			/* Out of range */
			if(tmp < 1 || tmp > 65536)
				continue;

			if( current_error < best_error)
			{
				best_error = current_error;
				best_divisor = tmp;
				bestd = d;
				bestm = m;
				
				if(best_error == 0) 
					break;
			}
		} /* end of inner for loop */

		if (best_error == 0)
			break;
	} /* end of outer for loop  */
	recalcbaud = (uClk >> 4) * bestm / (best_divisor * (bestm + bestd));
	/* reuse best_error to evaluate baud error*/
	if(Baudrate > recalcbaud) 
		best_error = Baudrate - recalcbaud;
	else 
		best_error = recalcbaud -Baudrate;
	best_error = best_error * 100 / Baudrate;
 	if (best_error < 3)
	{
		if (UartNum == 2)
		{
			LPC_UART2->LCR |= 0x80;
			LPC_UART2->DLM = (best_divisor >> 8) & 0xFF;
			LPC_UART2->DLL = best_divisor & 0xFF;
			/* Then reset DLAB bit */
			LPC_UART2->LCR &= ~0x80;
			LPC_UART2->FDR = ((bestm << 4) & 0xF0)
								| (bestd & 0x0F);
		}
	}
}

void UART::Send(char UartNo, unsigned char d)
{
	if (UartNo == 2)
	{
		while (!(LPC_UART2->LSR & (1 << 5)));
		LPC_UART2->THR = d;
	}
}

void UART::Send2(char UartNo, unsigned char d)
{
	if (UartNo == 2)
	{
		if(LPC_UART2->LSR & (1 << 5))
			LPC_UART2->THR = d;
		else
			SendBuffer2.Enqueue(d);
	}
}

void UART::Send(char UartNo, char* str)
{
	int index= 0;
	while(str[index] != 0)
	{
		Send(UartNo, str[index]);
		index++;
	}
}

void UART::Send2(char UartNo, char* str)
{
	int index= 0;
	while(str[index] != 0)
	{
		Send2(UartNo, str[index]);
		index++;
	}
}

bool UART::DataAvailable(char UartNo)
{
	if (UartNo == 2)
		return (LPC_UART2->LSR & 1);
	
	return false;
}

bool UART::DataAvailable2(char UartNo)
{
	if (ReceiveBuffer2.Count > 0)
		return true;
	else	
		return false;
}

unsigned char UART::Get(char UartNo)
{
	
}

unsigned char UART::Get2(char UartNo)
{
	return ReceiveBuffer2.Dequeue();
}

void UART::InterruptHandler(char UartNo)
{
	unsigned int iir = (LPC_UART2->IIR >> 1) & 7;
	if (iir == 1)	//Transmit complete
	{
		if (SendBuffer2.Count > 0)
			LPC_UART2->THR = SendBuffer2.Dequeue();
	}
	else if (iir == 2)	//Data Recieved
	{
		if (ReceiveBuffer2.Enqueue(LPC_UART2->RBR) == false)
		{
			//Send2(2, "Recieve Buffer is Full");
		}
	}
}

extern "C"
{
	extern UART uart;
	void UART2_IRQHandler()
	{
		uart.InterruptHandler(2);
	}
}