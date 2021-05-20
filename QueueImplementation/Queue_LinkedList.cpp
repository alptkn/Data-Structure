#include <iostream>
#include <fstream>
using namespace std;


struct Node{
	int val;
	Node *next;
};


class Queue{
	Node *front;
	Node *rear;
	Node *prev;
	Node *temp;
	int size;
	int curr_size = 0;
	public:
		Queue(int x){
			front = NULL;
			rear = NULL;
			size = x;
		}
		bool isEmpty(){
			if(front == NULL)
				return true;
			else
				return false;
		}
		bool isFull(){
			if(curr_size >= size)
				return true;
			else
				return false;
		}
		int itemAtFront();
		void enqueue(int x);
		int dequeue();
		void printQueue();
};

void Queue::enqueue(int x){
	if(isFull()){
		cout << "Cannot operate enqueue operation since queue is full!" << endl;
		return;
	}
	else{
		temp = new Node;
		temp->val = x;
		temp->next = NULL;
		if(isEmpty()){
			front = temp;
			rear = temp;
		}
		else{
			prev = rear;
			rear->next = temp;
			rear = temp;
		}
		curr_size++;
	}
}

int Queue::dequeue(){
	if(isEmpty()){
		cout << "Cannot operate dequeue operation since queue is empty!" << endl;
		return -1;
	}
	else{
		int val = front->val;
		temp = front;
		front = front->next;
		delete temp;
		curr_size--;
		return val;	
	}
}

int Queue::itemAtFront(){
	return front->val;
}

void Queue::printQueue(){
	if(isEmpty()){
		cout << "Queue is empty! There is no element to print." << endl;
		return;
	}
	else{
		for(temp = front; temp != NULL; temp = temp->next)
			cout << temp->val << "|";
		cout << endl; 
	}
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
