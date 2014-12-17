// my_queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <queue>
#include <stack>

using namespace std;

// construct my_queue using two stacks
template <typename T>
class my_queue{
private :
	stack<T> s1;
	stack<T> s2;

public :
	my_queue(){}
	void push(const T &x);
	T pop();
};

template <typename T>
void my_queue<T>::push(const T &x)
{
	s1.push(x);
}

template <typename T>
T my_queue<T>::pop()
{
	if (s2.size() == 0){
		T tmp;
		while (s1.size() > 0){
			tmp = s1.top();
			s1.pop();
			s2.push(tmp);
		}
	}

	if (s2.size() == 0)
		throw new exception("error");

	T tmp = s2.top();
	s2.pop();

	return tmp;
}

// construct stack using two queues
template <typename T>
class my_stack{
private :
	queue<T> q1;
	queue<T> q2;

public :
	my_stack(){}
	void push(const T &x);
	T pop();
};

template <typename T>
void my_stack<T>::push(const T &x)
{
	if (q1.size() != 0)
		q1.push(x);
	if (q2.size() != 0)
		q2.push(x);
	if (q1.size() == 0 && q2.size() == 0)
		q1.push(x);
}

template <typename T>
T my_stack<T>::pop()
{
	T tmp;
	if (q1.size() != 0){
		while (q1.size() > 1){
			tmp = q1.front();
			q1.pop();
			q2.push(tmp);
		}

		tmp = q1.front();
		q1.pop();
		return tmp;
	}
	else
		if (q2.size() != 0){
			while (q2.size() > 1){
				tmp = q2.front();
				q2.pop();
				q1.push(tmp);
			}

			tmp = q2.front();
			q2.pop();
			return tmp;
		}
}

// circular queue
template <typename T>
class cQueue{
private :
	T *array;
	int nElem;
	int realElem;
	int front;
	int rear;

public :
//	cQueue() : array(NULL), nElem(0), realElem(0), front(0), rear(0){}
	cQueue(int n) : array(new T[n]), nElem(n), realElem(0), front(0), rear(0) {}
	~cQueue(){ if (array != NULL){ delete[] array; } }

	void push(const T &x);
	T pop();

	int size() const;
};

template <typename T>
void cQueue<T>::push(const T &x)
{
	if (realElem == nElem){
		printf("queue is full\n");
		return;
	}

	array[rear] = x;
	++rear;
	if (rear == nElem)
		rear = 0;
	++realElem;
}

template <typename T>
T cQueue<T>::pop()
{
	if (realElem == 0){
		throw new exception("queue is empty");
	}

	T tmp = array[front];
	++front;
	if (front == nElem)
		front = 0;
	--realElem;

	return tmp;
}

template <typename T>
int cQueue<T>::size() const
{
	return realElem;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cQueue<int> cq(5);

	cq.push(1);
	cq.push(2);
	cq.push(3);
	cq.push(4);
	cq.push(5);
	cq.push(6);
	printf("%d\n", cq.pop());
	cq.push(6);
	printf("%d\n", cq.pop());
	printf("%d\n", cq.pop());
	printf("%d\n", cq.pop());
	printf("%d\n", cq.pop());
	printf("%d\n", cq.pop());
	return 0;
}

