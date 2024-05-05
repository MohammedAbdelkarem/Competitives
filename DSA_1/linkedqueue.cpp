#include<bits/stdc++.h>
using namespace std;
template<class t>
class linkedqueue
{
    struct Node
    {
        t value;
        Node *next;
    };
    Node *front;
    Node *rear;
    int length;
public:
    linkedqueue()
    {
        front=rear=NULL;
        length=0;
    }
    bool isEmpty()
    {
        return length==0;
    }
    void enqueue(t x)
    {
        Node *node=new Node;
        node->value=x;
        if(isEmpty())
        {
            front=rear=node;
            node->next=NULL;
        }
        else
        {
            rear->next=node;
            node->next=NULL;
            rear=node;
        }
        length++;
    }
    void dequeue()
    {
        if(isEmpty()){cout<<"can't delete from empty queue\n";}
        else
        {
            if(length==1)
            {
                delete front;
                front=rear=NULL;
            }
            else
            {
                Node *cur=front;
                front=front->next;
                delete cur;
            }
            length--;
        }
    }
    void getFront()
    {
        cout<<front->value<<"\n";
    }
    void print()
    {
        cout<<length<<"\n";
        Node *cur=front;
        while(cur!=NULL)
        {
            cout<<cur->value<<" ";
            cur=cur->next;
        }
    }
};
int main()
{
    linkedqueue<int>l;
    l.enqueue(1);l.enqueue(2);l.enqueue(3);l.dequeue();l.getFront();
    l.print();
}