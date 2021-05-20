#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

class Stack{
	Node *head;
	int stack_size;
	int curr_size;
	public:
		Stack(int x){
			head = NULL;
			stack_size = x;
		}
		void push(int data);
		int pop();
		int top();
		bool isEmpty();
		bool isFull();
		void print();
}; 
bool Stack::isEmpty(){
	if(head == NULL)
		return true;
	else
		return false;
}

bool Stack::isFull(){
	if(curr_size >= stack_size)
		return true;
	else
		return false;
}

void Stack::push(int data){
	Node *ptr = new Node;
	Node *temp;
	ptr->data = data;
	ptr->next = head;
	if(!isFull()){
		head = ptr;
		curr_size++;
	}
	else
		cout << "Stack is full!" << endl;
}

int Stack::pop(){
	Node *temp = head;
	int data;
	if(!isEmpty()){
		data = head->data;
		head = temp->next;
		delete temp;
		curr_size--;
		return data;
	}
	else{
		cout << "Stack is empty!" << endl;
		return 0;
	}
}

int Stack::top(){
	int data;
	if(!isEmpty()){
		data = head->data;
		return data;
	}
	else{
		cout << "Stack is empty!" << endl;
		return 0;
	}
}

void Stack::print(){
	if(isEmpty()){
		cout << "Stack is empty!" << endl;
		return;
	}
	Node *temp = head;
	while(temp){
		cout << temp->data << "|";
		temp = temp->next;
	}
	cout << endl;
}


int main(){
	Stack stack(4);
	stack.push(34);
	stack.push(21);
	stack.push(8);
	stack.push(2);
	stack.print();
	stack.push(28);
	stack.pop();
	stack.pop();
	stack.print();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.print();
	stack.push(12);
	stack.print();		
	stack.top();
	stack.print();
	
}
