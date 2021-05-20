#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;


struct node{
	string name;
	int count;
	node *left, *right;
};

class BST{
	node *root = NULL;
	node *insert(string name, node *t){
		if(t == NULL){
			node *temp = new node;
			temp->name = name;
			temp->count = 1;
			temp->left = temp->right = NULL;
			t = temp;
		}
		else if(name.compare(t->name) < 0)
			t->left = insert(name, t->left);
		else if(name.compare(t->name) > 0)
			t->right = insert(name, t->right);
		else
			t->count++;	
		return t;
	}
	node *makeEmpty(node *t){
		if(t == NULL)
			return NULL;
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		return NULL;		
	}
	void inorder(node *t){
		if(t == NULL)
			return;
		inorder(t->left);
		cout << t->name << " " << t->count << endl;
		inorder(t->right);
	}
	public:
		~BST(){
			root = makeEmpty(root);
		}
		void insert(string name){
			root = insert(name, root);
		}
		void display(){
			inorder(root);
		}
		void construct_tree(string filename){
			ifstream fin;
			fin.open(filename.c_str());
			string temp;
			while(!fin.eof()){
				fin >> temp;
				insert(temp);
			}
			display();
		}
};

int main(){
	BST tree;
	tree.construct_tree("test.txt");
	
}
