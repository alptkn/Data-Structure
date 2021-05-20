#include <iostream>
#include <cmath>
using namespace std;


struct Node{
	int data;
	Node* next;
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
	int result;
	int size;
	public:
		bool createList();
		void dec2bin();
		void print();
};

bool LinkedList::createList(){
	Node *ptr, *temp;
	cout << "Please enter the number of digits" << endl;
	cin >> size;
	//Check if the number of digit more than 10
	if (size > 10)
		return false;
	int *nums = new int[size];
	cout << "Please enter the binary number" << endl;
	for(int i = 0; i < int(size); i++)
		cin >> nums[i];	
	
	
	
	//This loop creates the linked list dynamically 
	for(int i = 0; i < size; i++){
		
		ptr = newNode(nums[i]);
		if(head == NULL)
			head = ptr;
		else{
			temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = ptr;
		} 
	}
	return true;	
}

//Convert binary number to decimal representation 
void LinkedList::dec2bin(){
	result = 0;
	while(head != NULL ){	
		//Multiply with required power of 2
		result += pow(2,size-1) * head->data;
		head = head->next;
		size--;
	}
	cout << "Binary equivalance : " << result << endl;
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
	bool flag = List.createList();
	if (!flag)
		cout << "Number of digit is more than 10" << endl;
	else
		List.dec2bin();

	
}
