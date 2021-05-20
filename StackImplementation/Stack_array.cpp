#include <iostream>
#define MAX 100
using namespace std;

class Stack{
	int *array;
	int stack_size;
	int head;
	public:
		Stack(int size){
			array = new int[size];
			head = -1;
			stack_size = size;
		}
		void push(int);
		bool isEmpty();
		bool isFull();
		int pop();
		int top();
		void print(){
			if(head < 0){
				cout << "Stack is empty!" << endl;
				return;
			}
			for(int i = head; i >= 0; i-- )
				cout << array[i] << "|";
			cout << endl;
		}
		~Stack(){
			delete array;
		}
};
bool Stack::isEmpty(){
	if(head < 0)
		return true;
	else 
		return false;
}

bool Stack::isFull(){
	if(head >= stack_size-1)
		return true;
	else
		return false;
}

void Stack::push(int data){
	if(!isFull()){
		array[++head] = data;
	}
	else
		cout << "Stack is full!" << endl;
}

int Stack::pop(){
	if(!isEmpty()){
		int data = array[head--];
		return data;
	}
	else{
		cout << "Stack is empty!" << endl;
		return 0;
	}
}

int Stack::top(){
	if(!isEmpty()){
		int data = array[head];
		return data;
	}
	else{
		cout << "Stack is empty!" << endl;
		return 0;
	}
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
