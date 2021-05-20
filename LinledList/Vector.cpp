#include <iostream>
#include <vector>
using namespace std;



template <class T>
struct Node{
	T data;
	Node<T> *next;
};

template <class T>
class LinkedList{
	Node<T> *head = NULL;
	int size = 0;
	public:
		vector<T> toVector();
		void addback(T data);
		void duplicateAll(void);
		void insertPos(T data, int pos);
		void removeDuplicate(void);
		void print(void);
};
template <class T>
void LinkedList<T>::addback(T data){
	Node<T> *ptr = new Node<T>;
	Node<T> *temp = head;
	ptr->data = data;
	ptr->next = NULL;
	if(head == NULL)
		head = ptr;
		
	else{
		temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = ptr;
	}
	size++;
}
template <class T>
void LinkedList<T>::print(){
	Node<T> *temp = head;
	if(head == NULL)
		cout << "List is empty" << endl;
	else{
		while(temp != NULL){
			cout << temp->data;
			temp = temp->next;
		}
	}
	cout << endl;	
}
template <class T>
void LinkedList<T>::insertPos(T data, int pos){
	Node<T> *temp = new Node<T>;
	int index = 0;
	if(pos < 0){
		cout << "Negative index!"<< endl;
		return;
	}
	if(pos >= size){
		cout << "Extension is not suppurted! Please enter the postion between 0 and " << size-1 << endl;
		return;
	}
	if(pos == 0){
		
		temp->next = head;
		temp->data = data;
		head = temp;
	}
	else{
		Node<T> *prev, *curr;
		curr = head;
		while(index != pos){
			if(index == pos-1)
				prev = curr;
			curr = curr->next;
			index++;
		}
		temp->data = data;
		temp->next = curr;
		prev->next = temp;
	}
	size++;
}

template <class T>
void LinkedList<T>::duplicateAll(){
	Node<T> *curr = head;
	int i;
	while(curr != NULL){
		Node<T> *temp = new Node<T>;
		temp->data = curr->data;
		temp->next = curr->next;
		curr->next = temp;
		i = 0;
		while(i < 2){
			curr = curr->next;
			i++;
		}
			
	}
	size*=2;
}

template <class T> 
void LinkedList<T>::removeDuplicate(){
	Node<T> *ptr1, *ptr2, *dup;
	ptr1 = head;
	while(ptr1 != NULL && ptr1->next != NULL){
		ptr2 = ptr1;
		while (ptr2->next != NULL){
			if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
                size--;
            }
            else{
            	ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}
template <class T>
vector<T> LinkedList<T>::toVector(){
	vector<T> vect;
	Node<T> *temp = head;
	while(temp){
		vect.push_back(temp->data);
		temp = temp->next;
	}	
	return vect;
}


int main(){
	LinkedList<char> list;
	vector<char> vect;
	list.addback('a');
	list.addback('l');
	list.addback('p');
	//list.addback('a');
	list.addback('y');
	list.print();
	list.insertPos('a',3);
	list.print();
	/*
	list.addback('t');
	list.addback('e');
	list.print();
	list.duplicateAll();
	vect = list.toVector();
	list.print();
	list.removeDuplicate();
	list.print();
	
	for(int i = 0; i < vect.size(); i++)
		cout << vect[i] << endl;
	*/
}


















