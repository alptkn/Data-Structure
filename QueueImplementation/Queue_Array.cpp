#include <iostream>
using namespace std;
#include <fstream>



class Queue{
	int *queue;
	int rear = 0;
	int front = 0;
	int size;
	public:
		Queue(int x){
			size = x;
			queue = new int[size];
		}
		bool isFull(){
			if(rear == size)
				return true;
			else
				return false;
		}
		bool isEmpty(){
			if(rear == 0)
				return true;
			else
				return false;
		}
		void enqueue(int x);
		int dequeue();
		int itemAtFront();
		void printQueue(){
			if(isEmpty()){
				cout << "Queue is empty! There is no element to print." << endl;
				return;
			}
			else{
				for(int i = front; i < rear; i++)
				cout << queue[i] << "|";
				cout << endl;
			}
		}
};

void Queue::enqueue(int x){
	if(isFull()){
		cout << "Cannot operate enqueue operation since queue is full!" << endl;
		return;
	}
	else{
		queue[rear] = x;
		rear++;
	}
}

int Queue::dequeue(){
	if(isEmpty()){
		cout << "Cannot operate dequeue operation since queue is empty!" << endl;
		return -1;
	}
	else{
		int val = queue[front];
		front++;
		if(front == rear){
			rear = 0;
			front = 0;
		}
		return val;
	}
	
}

int Queue::itemAtFront(){
	return queue[front];
}

Queue buildFromTextFile(string filename){
	Queue q(10);
	int temp;
	ifstream fin;
	fin.open(filename.c_str());
	while(!fin.eof()){
		fin >> temp;
		q.enqueue(temp);
	}
	return q;
}


int main(){
	Queue q(3);
	int x;
	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(78);
	q.printQueue();
	x = q.dequeue();
	q.printQueue();
	cout << x << endl;
	q.dequeue();
	q.printQueue();
	q.dequeue();

	q.dequeue();
	q.printQueue();
	q.enqueue(23);
	q.enqueue(45);
	q.enqueue(21);
	q.enqueue(32);
	q.printQueue();
	x = q.itemAtFront();
	q.printQueue();
	cout << x << endl;	
	Queue q2 = buildFromTextFile("test.txt");
	q2.printQueue();
	q2.enqueue(12);
	q2.dequeue();
	q2.printQueue();
	cout << q2.itemAtFront() << endl;
	q2.dequeue();
	q2.dequeue();
	q2.dequeue();
	q2.dequeue();
	q2.dequeue();
	q2.dequeue();
	q2.dequeue();
	q2.dequeue();
	q2.dequeue();
	q2.dequeue();
	q2.printQueue();
	
}
