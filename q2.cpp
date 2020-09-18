//2. Perform enqueue and dequeue operations in Circular Queue


#include <iostream>
using namespace std;

class cqueue {
private:
	int front;
	int rear;
	int arr[5];
	int count;

public:
	cqueue() {
		for (int i = 0; i < 5; i++)arr[i] = 0;
		front = -1;
		rear = -1;
		count = 0;

	}
	void enque(int);
	int deque();
	int getCount();
	bool isEmpty();
	bool isFull();
};


bool cqueue::isEmpty() {
	return(front == -1 && rear == -1);
}

bool cqueue::isFull() {
	return(front == (rear+1)%size(arr));
}

void cqueue::enque(int x) {
	if (isFull()) {
		throw "Queue is Full";
		return;
	}
	else if (isEmpty()) {
		front = 0;
		rear = 0;
	}
	else {
		rear=(rear + 1) % size(arr);
	}
	arr[rear] = x;
	count++;
}

int cqueue::deque() {
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
		front = (front + 1) % size(arr);
		return x;
	}
	count--;
}

int cqueue::getCount() {
	return count;
}
int main() {
	cqueue q1;
	try {
		q1.enque(1);
		q1.enque(2);
		q1.enque(3);
		q1.enque(4);
		q1.enque(5);
		cout << "Dequeed: " << q1.deque() << endl;
		cout << "Dequeed: " << q1.deque() << endl;
		q1.enque(6);
		q1.enque(7);
		cout << "Dequeed: " << q1.deque() << endl;
		cout << "Dequeed: " << q1.deque() << endl;
	}
	catch (const char* err)
	{
		cout << err;
	}
	return 0;
}