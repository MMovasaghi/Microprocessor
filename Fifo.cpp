#include "Fifo.h"

Fifo::Fifo()
{
	buffer = 0;
	Length = 0;
	First = 0;
	Rear = 0;
}

Fifo::~Fifo()
{
	delete[] buffer;
}

void Fifo::Init(int len)
{
	buffer = new char[len];
	Length = len;
	First = 0;
	Rear = 0;
	Count = 0;
}

bool Fifo::Enqueue(char data)
{
	if (Count >= Length)
		return false;
	buffer[Rear] = data;
	Rear++;
	if (Rear >= Length)
		Rear = 0;
	Count++;
	return true;
}

char Fifo::Dequeue()
{
	if (Count == 0)
		return 0;
	
	char result = buffer[First];
	First++;
	if (First >= Length)
		First = 0;
	Count--;
	return result;
}