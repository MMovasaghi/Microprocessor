#ifndef UART_H
#define UART_H

enum DataLength
{
	Data_5Bits,
	Data_6Bits,
	Data_7Bits,
	Data_8Bits
};

enum StopBit
{
	Stop_1Bit,
	Stop_2Bit
};

enum Parity
{
	Parity_Odd,
	Parity_Even,
	Parity_Non = 10
};

class UART
{
	public:
		void Init(int uartNo, DataLength dlen, StopBit sb, Parity p, int Buadrate);
		void InitInterrupt(int uartNo, DataLength dlen, StopBit sb, Parity p, int Buadrate);
		void Connect(int uartNo);
		void SetBaudRate(char UartNum, int Baudrate);
		bool DataAvailable(char UartNum);
		void Send(char UartNo, unsigned char d);
		void Send(char UartNo, char* str);
		unsigned char Get(char UartNo);
		void InterruptHandler(char UartNo);
};

#endif