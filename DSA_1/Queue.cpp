#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE=100;
template<class t>  
class Queue                                                                  //circular queue
{
    int front,rear,length;
    t element[MAX_SIZE];                                                     //array to store queue elements
public:
    Queue()                                                                  //constructor
    {
        front=0;
        rear=MAX_SIZE-1;
        length=0;
    }
    bool isEmpty()
    {
        return length==0;
    }
    bool isFull()
    {
        return length==MAX_SIZE;
    }
    void enqueue(t x)                                                         //function to add elements to this queue,we just add from back(rear)
    {
        if(isFull()){cout<<"can't add because queue is full\n";}
        else
        {
            rear=(rear+1)%MAX_SIZE;                                           //to make it a circular queue
            element[rear]=x;
            length++;
        }
    }
    void dequeue()                                                          //function to delete an element fron this queue,we just delete from front(first in first out/FIFO)
    {
        if(isEmpty()){cout<<"can't delete from empty queue\n";}
        else
        {
            front=(front+1)%MAX_SIZE;                                       //to make it a circular queue
            length--;
        }
    }
    void getFront()                                                        //fuction to get the first element in the queue
    {
        cout<<element[front]<<"\n";
    }
    void print()                                                           //function to print queue elements
    {
        cout<<length<<"\n";
        for(int i=front;i!=rear;i=(i+1)%MAX_SIZE)
        {
            cout<<element[i]<<" ";
        }
        cout<<element[rear]<<"\n";
    }
};                                                       
int main()
{
    Queue<int>q;
    q.print();
}