#ifndef FIFO_H
#define FIFO_H

class Fifo
{
	public:
		Fifo();
		~Fifo();
		void Init(int len);
		bool Enqueue(char data);
		char Dequeue();
		char* buffer;
		
	int Length;
	int Count;
	int First;
	int Rear;
};

#endif