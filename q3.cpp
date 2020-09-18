/*
3. Perform operations in Deque( Double ended queue) for:
a. Add at beginning
b. Add at end
c. Delete from beginning
d. Delete from end
*/

#include <iostream>

class deque {
private:
	int front, rear;
	int arr[5];
public:
	deque() {
		
		for (int i = 0; i < 5; i++) {
			arr[i] = 0;
		}       //initiailising array with 0
		front = -1;
		rear = -1;
	}
	void insFront(int);
	void insRear(int);
	int delFront();
	int delRear();
	bool isFull();
	bool isEmpty();
	void display();

};

bool deque::isFull() {
	return((front == rear + 1) || (front == 0 && rear == 4)); //is full if front == 0 and rear points to last index
}

bool deque::isEmpty() {
	return(front == -1 && rear == -1); //of course

}

void deque::display() {
	std::cout << "Following elements are in the deque: ";
	for(int i=front;i!=rear;i=(i+1)%5){ // circular implementation
		std::cout<<' '<< arr[i];

	}
	std::cout <<' '<< arr[rear];

}

void deque::insFront(int x) {
	if (isFull())
	{
		throw "Deque is Full"; //obvious error
	}
	else if (front == -1 && rear == -1) { //both front and rear are to be initialised to 0
		front = 0;
		rear = 0;
		arr[front] = x;

	}
	else if (front == 0) { //if there only one element, we have to go to the other end to insert
		front = 4;
		arr[front] = x;

	}
	else {   //for all other elements, we have to decrease the front value
		front--;
		arr[front] = x;

	}

}

int deque::delFront() {
	int del;
	if (isEmpty())throw "Deque is Empty";
	else if (front == rear) { //only one element
		del = arr[front];
		front = rear = -1;
		return del;
	}
	else if (front == 5 - 1) {//5-1 can be replaced by size(arr)-1 boundary condition
		del = arr[front];
		front = 0;//boundary circulation
		return del;
	}
	else {
		del = (arr[front]);
		front++;
		return del;
	}

}
int deque::delRear() {
	int del;
	if (isEmpty())throw "Deque is Empty";
	else if (front == rear) {
		del = arr[rear];
		front = -1;
		rear = -1;
		return del;
	}
	else if (rear == 0) { 
		del = arr[rear];
		rear = 5 - 1;//boundary circulation
		return del;
	}
	else {
		del = (arr[rear]);
		rear--;
		return del;
	}

}

void deque::insRear(int x) {
	if (isFull())throw "Deque is Full";
	else if ((front == -1) && (rear == -1)) {
		front = 0;
		rear = 0;
		arr[rear] = x;
	}
	else if (rear == (5 - 1)) {
		rear = 0;
		arr[rear] = x;
	}
	else {
		rear=rear+1;
		arr[rear] = x;
	}


}


int main() {
	deque d1;
	try
	{
		d1.insRear(1);
		d1.insRear(2);
		d1.insRear(3);
		std::cout <<"Deleted: "<< d1.delFront()<<std::endl;
		d1.insFront(4);
		d1.insFront(5);
		std::cout << "Deleted: " << d1.delRear() << std::endl;
	}
	catch (const char* err)
	{
		std::cout << err;
	}
	d1.display();
	return 0;
}
