#include "MyDsClass.h"
#include <iostream>
using namespace std;

Stack::Stack(int _stack_size)				
{
	stack_capacity = _stack_size;			// ���ϴ� ����� �μ��� �޾� ���ÿ뷮�� ����
	stack_count = 0;						// ó���� ���Ұ� �ϳ��� �����Ƿ� 0���� �ʱ�ȭ
	p_stack = new int[stack_capacity];		// ���ÿ뷮�� ������ ����
}


Stack::~Stack()
{
	if (p_stack != NULL) delete p_stack;	// ���� ������ NULL �� �ƴ϶��, ���� �޸𸮸� ����
}


void Stack::Push(int data)
{
	if (stack_count < stack_capacity) {				// ���ÿ뷮���� ���Ұ����� �۴ٸ� (== ������ �ʾҴٸ�)
		*(p_stack + stack_count++) = data;			// ��ĭ�� �׾ư��鼭 ���Ҹ� ����
	}
	else
		cout << "������ ���� á���ϴ�." << endl;		// ������ ���� ��Ȳ. �������� �ʴ´�
}

void Stack::Pop()
{
	if (stack_count >= 0)									// ����� ���Ұ� �ϳ��� ���ٸ� �������� �ʴ´�
		cout << "���ÿ� ����� ���� �����ϴ�." << endl;		
	else
		*(p_stack + stack_count--) = 0;						// �ִٸ�. ��ĭ�� ������, �ش���Ҹ� ����
}

void Stack::ShowAll()
{
	if (stack_count <= 0)									// ����� ���Ұ� ���ٸ� �ǳʶ�
		cout << "���ÿ� ����� ���� �����ϴ�." << endl;
	else {
		cout << "Stack::���Ҹ� ����մϴ�." << endl;			// �ִٸ�. ������� ���
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
		cout << "overflow �߻�!";
	}
	rear = (rear + 1) % capacity;			// �߿��� �κ�.
	*(p_queue + rear) = data;
	count++;
}

void Queue::Dequeue()
{
	if (this->isEmpty()) {
		cout << "underflow �߻�!" << endl;
	}
	cout << "dequeued!" << endl;
	front = (front + 1) % capacity;
	count--;
}


void Queue::ShowAll()
{
	cout << "Queue::��� ���Ҹ� ����մϴ�." << endl;
	for (int i = 0; i < Size(); i++) {
		cout << *(p_queue + i) << endl;
	}
}