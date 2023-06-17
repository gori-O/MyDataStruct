#pragma once


class Stack
{
private:
	int* p_stack;				// ������ �Ӹ��κ� ������
	int stack_capacity;			// ������ �ִ� �뷮
	int stack_count;			// ���� �ȿ� �����ϴ� ���� ����

public:
	Stack(int _stack_size);		// ������ 
	~Stack();					// �Ҹ���
	void Push(int data);		// ���ÿ� ���Ҹ� ����
	void Pop();					// ���� ž�� ���Ҹ� ����
	void ShowAll();				// ��� ���Ҹ� ���ʴ�� ���
};


class Queue
{
private:
	int* p_queue;
	int capacity;
	int front;
	int rear;
	int count;
public:
	Queue(int _q_cap);
	~Queue();
	int Size();
	bool isEmpty();
	bool isFull();
	void Enqueue(int data);
	void Dequeue();
	void ShowAll();
};
