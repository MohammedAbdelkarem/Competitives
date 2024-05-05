#include<bits/stdc++.h>
using namespace std;
template<class t>                                                         //template for defining with any datatype we want inside our code
class linkedstack
{
    struct Node                                                           //struct to define from it a node and dive it value and pointer
    {
        t value;
        Node *next;
    };
    Node *top;                                                            //defining pointer refer to the last adding element in the linkedstack/if there is no elements top will refer to NULL
    int length;                                                           //to know the length of the linkedstack
public:
    linkedstack()                                                         //constructor to giv initial values to the top and length
    {
        top=NULL;
        length=0;
    }
    bool isEmpty()                                                       //function to check if the linkedstack is empty
    {
        return top==NULL;
    }
    void push(t x)                                                       //function to push element(node) to the linkedstack
    {
        Node *node=new Node;                                                //declearing node 
        node->value=x;                                                      //giving the node a value
        node->next=top;                                                     //link this node to the top
        top=node;                                                           //making the node in the top
        length++;
    }
    void pop()                                                           //function to pop element from the linkedstack
    { 
        if(isEmpty()){cout<<"can't pop empty linkedstack\n";}            //if the linkedstack is emoty,we will tell the user
        else                                                             //if it's not empty
        {
            Node *cur=top;                                                  //declearing node refer to the top(top is the deleting element in the linkedstack, and so on in the stack)because we will delete the last adding element
            top=top->next;                                                  //moving the top to the element(node)before the last element(node/cur),so now the top is not cur
            cur->next=NULL;                                                 //make cur(deleting element) refer to NULL
            delete cur;                                                     //formatting cur(the deleting element/node)
        }
    }
    void getTop()                                                        //function to get the last adding element
    {
        if(isEmpty()){cout<<"this linkedstack is empty\n";}              //if the linkedstack is empty,we will tell the user
        else                                                             //if it's not empty
        {
            cout<<top->value<<"\n";                                         //we will print the last element(the value of top)
        }
    }
    void print()                                                         //function to print linkedstack elements
    {
        cout<<"length:"<<length<<"\n";
        Node *cur=top;
        while(cur!=NULL)
        {
            cout<<cur->value<<" ";
            cur=cur->next;
        }
    }
};
int main()
{
    linkedstack<int>l;
    l.push(1);l.push(2);l.getTop();
    l.print();
}