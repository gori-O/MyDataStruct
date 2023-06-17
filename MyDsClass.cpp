#include "MyDsClass.h"
#include <iostream>
using namespace std;

Stack::Stack(int _stack_size)				
{
	stack_capacity = _stack_size;			// 원하는 사이즈를 인수로 받아 스택용량를 정함
	stack_count = 0;						// 처음엔 원소가 하나도 없으므로 0으로 초기화
	p_stack = new int[stack_capacity];		// 스택용량로 스택을 생성
}


Stack::~Stack()
{
	if (p_stack != NULL) delete p_stack;	// 만약 스택이 NULL 이 아니라면, 스택 메모리를 해제
}


void Stack::Push(int data)
{
	if (stack_count < stack_capacity) {				// 스택용량보다 원소개수가 작다면 (== 꽉차지 않았다면)
		*(p_stack + stack_count++) = data;			// 한칸씩 쌓아가면서 원소를 삽입
	}
	else
		cout << "스택이 가득 찼습니다." << endl;		// 스택이 꽉찬 상황. 삽입하지 않는다
}

void Stack::Pop()
{
	if (stack_count >= 0)									// 저장된 원소가 하나도 없다면 삭제하지 않는다
		cout << "스택에 저장된 값이 없습니다." << endl;		
	else
		*(p_stack + stack_count--) = 0;						// 있다면. 한칸씩 내리며, 해당원소를 삭제
}

void Stack::ShowAll()
{
	if (stack_count <= 0)									// 저장된 원소가 없다면 건너뜀
		cout << "스택에 저장된 값이 없습니다." << endl;
	else {
		cout << "Stack::원소를 출력합니다." << endl;			// 있다면. 순서대로 출력
		for (int i = 0; i < stack_count; i++) {
			cout << i << " : " << *(p_stack+i) << endl;
		}
	}

}


Queue::Queue(int _cap)
{
	p_queue = new int[_cap];
	capacity = _cap;
	front = 0;
	rear = -1;
	count = 0;	
}

Queue::~Queue()
{
	if (p_queue != NULL) delete p_queue;
}

int Queue::Size()
{
	return count;
}

bool Queue::isEmpty()
{
	return (Size() == 0);
}

bool Queue::isFull()
{
	return (Size() >= capacity);
}

void Queue::Enqueue(int data)
{
	if (this->isFull()) {
		cout << "overflow 발생!";
	}
	rear = (rear + 1) % capacity;			// 중요한 부분.
	*(p_queue + rear) = data;
	count++;
}

void Queue::Dequeue()
{
	if (this->isEmpty()) {
		cout << "underflow 발생!" << endl;
	}
	cout << "dequeued!" << endl;
	front = (front + 1) % capacity;
	count--;
}


void Queue::ShowAll()
{
	cout << "Queue::모든 원소를 출력합니다." << endl;
	for (int i = 0; i < Size(); i++) {
		cout << *(p_queue + i) << endl;
	}
}