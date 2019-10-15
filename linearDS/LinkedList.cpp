#include<iostream>
using namespace std;


// Node of linked list;

struct node
{
	int data;
	struct node *next;
};


//Head and Tail pointers of the liknked list

struct node *head = NULL;
struct node *tail = NULL;


// Function to insert at Last
void insertLast(int new_data){

	node *new_node = new node;
	new_node->data = new_data;
	new_node->next = NULL;
	if(head==NULL)
	{
		head = new_node;
		tail = new_node;

	}
	else
	{
		tail->next = new_node;
		tail = tail->next;
	}

}

// function to insert at first
void insertBegin(int new_data){

	node *new_node = new node;
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
}

//function to return length of linked list
int length(){
	
	node *ptr = head;
	int count = 0;

	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}

	return count;
}

//function to print the element of the linked list
void print(){
	node *ptr = head;
	if(ptr==NULL)cout<<"No Elements in linked list"<<endl;

	while(ptr!=NULL){
		cout<<"| "<<ptr->data<<" |";
		ptr=ptr->next;
		if(ptr!=NULL)cout<<"--->";
	}
}

int main(){

	
	insertLast(2);
	insertBegin(90);
	insertLast(30);
	insertBegin(10);

	print();

	return 0;
}
