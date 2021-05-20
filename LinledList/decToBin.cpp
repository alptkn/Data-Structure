#include <iostream>
#include <cmath>
using namespace std;


struct Node{
	int data;
	Node *next;
	public:
		Node *newNode(int data);
};
//Utility function to create new node 
Node *newNode(int data){
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}


class LinkedList{
	Node *head = NULL;
	int binarray[32];
	void createList(int len);
	public:
		void dec2bin(int num);
		void print();
		
};

void LinkedList::createList(int len){
	Node *ptr, *temp;
	for(int i = len-1; i >= 0; i--){
		ptr = newNode(binarray[i]);
		if(head == NULL)
			head = ptr;
		else{
			temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = ptr;
		}
	}
}

void LinkedList::dec2bin(int num){
	int i = 0;
	while(num > 0){
	binarray[i] = num % 2;
	num = num / 2;
	i++;
	}
	createList(i);
}

void LinkedList::print(){
	Node *temp = head;
	while(temp){
		cout << temp->data;
		temp = temp->next;
	}
}



int main(){
	LinkedList List;
	int number;
	cout << "Please enter the decimal number" << endl;
	cin >> number;
	List.dec2bin(number);
	List.print();
}

