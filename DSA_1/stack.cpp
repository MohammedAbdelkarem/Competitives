#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE=100;                                //constant value to the size of stack array
template<class t>                                      //template for defining with any datatype we want inside our code
class Stack
{
    int top=-1;                                        //the moval index of the stack, start from -1 because when we will add element to the stack it will be 0
    t element[MAX_SIZE];                               //array to store stack elements
public:
    Stack()                                            //stack constructor
    {
        top=-1;
    }
    bool isFull()                                     //function to check if the stack is empty
    {
        return top>=MAX_SIZE-1;
    }
    bool isEmpty()                                   //function to check if the stack is full
    {
        return top==-1;
    }
    void push(t x)                                   //function to add element to the stack,but if the stack is full we will tell the user
    {
        if(isFull()){cout<<"can't push because stack is full\n";}
        else
        {
            top++;
            element[top]=x;
        }
    }
    void pop()                                      //function to delete element from the stack,but if the stack is empty we will tell the user
    {
        if(isEmpty()){cout<<"can't pop because stack is empty\n";}
        else
        {
            top--;
        }
    }
    void getTop()                                   //function to return the last adding element to the stack(top element)
    {
        if(isEmpty()){cout<<"stack is empty\n";}
        else{cout<<element[top]<<"\n";}
    }
    void print()                                   //function to print stack elements and it's length
    {
        cout<<"length:"<<top+1<<"\n";
        for(int i=top;i>=0;i--)                    // we will print the last adding element firstly, and so on(because last in first out "LIFO")
        {
            cout<<element[i]<<" ";
        }
    }
};
int main()
{
    Stack<string>s;
    s.push("ali");s.push("ahmed");s.push("rony");s.getTop();
    s.print();
}