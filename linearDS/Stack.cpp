#include<iostream>
using namespace std;

class Stack{
public:
    struct stack
    {
        int data;
        stack * next;
        stack * prev;        
    };
    stack * top;
    stack * bottom;

    Stack(){
        
        top = NULL;
        bottom = NULL;

    }


    void pushBack(int new_data){
        stack * new_node = new stack;
        if(top==NULL){
            new_node->prev = NULL;
            new_node->data = new_data;
            top = new_node;
            bottom = new_node;
            new_node->next = NULL;
        }
        else{
            new_node->prev = top;
            new_node->data = new_data;
            top->next = new_node;
            new_node->next=NULL;
            top = new_node;
        }
    }

    int popBack(){
        int pop_element;
        stack *curr_prev=top->prev;
        pop_element= top->data;
        free(top);
        top=curr_prev;
        top->next=NULL;

        return pop_element;
    }

    void printStack(){
        stack * top_init=top; 
        while(top!=NULL){
            cout<<"|"<<top->data<<"|"<<endl;
            cout<<"----"<<endl;
            top=top->prev;
        }
        top = top_init;
    }

    int peek(){
        return top->data;
    }
    
};

int main(){
    Stack st = Stack();
    st.pushBack(10);
    st.pushBack(12);
    st.pushBack(13);
    st.popBack();
    st.popBack();
    st.pushBack(21);
    st.pushBack(15);
    st.printStack();
}