#include<iostream>
using namespace std;


class Queue{
    public:

    struct node{
        int data;
        struct node * next;
    };

    node * front = NULL;
    node * back  = NULL;

    void pushBack(int new_data){
        node * new_node = new node;
        new_node->data = new_data;
        new_node->next = NULL;
        if(front==NULL){
            
            back = new_node;
            front = new_node;
        }
        else{
            back->next = new_node;
            back = back->next;
        }
    }
    int popFront(){
        if(front==NULL){
            cout<<"NO elements"<<endl;
            return 0;
        }
        else{
            int tmp = front->data;
            node * curr = front;
            front=front->next;
            free(curr);
            return tmp;
        }
    }
    void printQueue(){
        if(front==NULL){
            cout<<"No Elements found in the Queue"<<endl;
        }
        else{
            node * ptr = front;
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
        }
        cout<<endl;
    }


};

int main(){
    Queue qt  = Queue();
    qt.pushBack(11);
    qt.pushBack(12);
    qt.pushBack(13);
    qt.pushBack(14);
    qt.pushBack(15);
    qt.pushBack(16);
    qt.printQueue();
    qt.popFront();
    qt.printQueue();
    qt.popFront();
    qt.printQueue();
    qt.popFront();
    qt.printQueue();
}
