//1. Perform enqueue and dequeue operations in Linear Queue

#include <iostream>
using namespace std;

class queue {
private:
	int front;
	int rear;
	int arr[5];

public:
	queue() {
		for (int i = 0; i < 5; i++)arr[i] = 0;
		front = -1;
		rear = -1;

	}
	void enque(int);
	int deque();
	int count();
	bool isEmpty();
	bool isFull();
};


bool queue::isEmpty() {
	return(front == -1 && rear == -1) ? true : false;
}

bool queue::isFull() {
	return(rear == size(arr)-1) ? true : false;
}

void queue::enque(int x) {
	if (isFull()) {
		throw "Queue is Full";
		return;
	}
	else if (isEmpty()) {
		front = 0;
		rear = 0;
	}
	else {
		rear++;
	}
	arr[rear] = x;
}

int queue::deque() {
	int x;
	if (isEmpty()) {
		throw"Queue is empty";
		
	}
	else if (front == 0 && rear == 0) {
		x = arr[front];
		front = -1;
		rear = -1;
		return x;
	}
	else {
		x = arr[front];
		front++;
		return x;
	}
}

int queue::count() {
	return isEmpty() ? 0 : (rear - front + 1);
}
int main() {
	queue q1;
	try {
		q1.enque(1);
		q1.enque(2);
		q1.enque(3);
		q1.enque(4);
		q1.enque(5);
		cout << "Dequeed: " << q1.deque() << endl;
		cout << "Dequeed: " << q1.deque() << endl;
	}
	catch (const char* exp)
	{
		cout << exp;
	}
	return 0;
}
