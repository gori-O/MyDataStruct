#pragma once


class Stack
{
private:
	int* p_stack;				// 스택의 머리부분 포인팅
	int stack_capacity;			// 스택의 최대 용량
	int stack_count;			// 스택 안에 존재하는 원소 개수

public:
	Stack(int _stack_size);		// 생성자 
	~Stack();					// 소멸자
	void Push(int data);		// 스택에 원소를 삽입
	void Pop();					// 스택 탑의 원소를 삭제
	void ShowAll();				// 모든 원소를 차례대로 출력
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
