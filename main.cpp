#include "MyDsClass.h"
#include <iostream>
using namespace std;

int main()
{
	Stack ss(10);
	Queue qq(10);

	ss.Push(10);
	ss.Push(20);
	ss.Push(30);
	ss.Push(40);
	ss.Push(50);

	qq.Enqueue(11);
	qq.Enqueue(22);
	qq.Enqueue(33);
	qq.Enqueue(44);
	qq.Enqueue(55);

	ss.ShowAll();
	qq.ShowAll();

	return 0;
}