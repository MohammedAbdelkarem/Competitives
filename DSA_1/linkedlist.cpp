#include <bits/stdc++.h>
using namespace std;
template<class t>                     //template for defining with any datatype we want inside our code
class linkedlist
{
    struct Node                       //every node has two things:value and pointer to the next node
    {
        t value;                      //the value of the node
        Node *next;                     //pointer to refer to the next node
    };
    Node *first;                        //declearing pointer refer to the first position in linkedlist
    Node *last;                         //declearing pointer refer to the last position in linkedlist
    int length;                         //the length of the linkedlist, we will change it after any operation in linkedlist
public:
    linkedlist()                      //constructor to give initial value to length/initial positions to first and last pointers
    {
        first=last=NULL;
        length=0;
    }
    bool isEmpty()                    //function to determine if the linkedlist empty or not
    {
        return first==NULL;             //if the linkedlist is empty, the first node will for sure refer to null,so we will return it
    }
    void addFirst(t x)              //function to add node in the front,take one parameter:the value of the adding node
    {
        Node *node=new Node;           //declearing the adding node
        node->value=x;                 //giving the adding node a value
        if(isEmpty())                  //if the linkedlist is empty
        {
            first=last=node;              //making the node in the first position,as well as in the last position
            node->next=NULL;              //let the node refer to NULL(because the node located in the first and also in the last position also)
        }
        else                          //if it's not empty
        {
            node->next=first;             //let the node refer to the first node(so now it's lacated before the first position)
            first=node;                   //making the node in the first position(so now it's located in the first position)
        }
        length++;
    }
    void addLast(t x)               //function to add node in the back,take one parameter:the value of the adding node
    {
        Node *node=new Node;           //declearing the adding node
        node->value=x;                 //giving the adding node a value
        if(isEmpty())                  //if the linkedlist is empty
        {
            first=last=node;               //making the node in the first position,as well as in the last position
            node->next=NULL;               //let the node refer to NULL(because the node located in the first and also in the last position)
        }
        else                           //if it's not empty
        {
            last->next=node;               //let the last node refer to the node(so now it's located after the last position)
            node->next=NULL;               //let the node refer to NULL(because we want to make it in the last position, so it should refer to NULL)
            last=node;                     //making the node in the last position(so now it's located in the last position)
        }
        length++;
    }
    void addInPosition(int pos,t x)                           //function to add node in any position,take two parameters:the position of the node and the value of the node
    {
        if(pos<0 or pos>length){cout<<"Out of Range!"<<endl;}    //if the position we want to add in is out of linkedlist range,print out of range
        else if(pos==0){addFirst(x);}                            //if the position we want to add in is in the first of linkedlist,call addFirst function
        else if(pos==length){addLast(x);}                        //if the position we want to add in is int the last of linkedlist,call addLast function
        else                                                     //if the position we want to add in is between the first and the last of linkedlist:
        {
            Node *node=new Node;                                    //declearing the adding node
            node->value=x;                                          //giving the adding node a value
            Node *cur=first;                                        //declearing cur node refer to the first position
            for(int i=1;i<pos;i++)                                  //we will move by this loop and stop in the position before the position we want to add in
            {
                cur=cur->next;
            }
            node->next=cur->next;                                   //let the node refer to the position after cur position(the position we want to add in)
            cur->next=node;                                         //let the cur refer to the node
            length++;
        }
    }
    void popFront()                                                      //function to delete the first node in linkedlist
    {
        if(isEmpty()){cout<<"can't delete from empty linkedlist\n";}      //if there is no elements we will tell the user
        else                                                              //if it is not empty
        {
            if(length==1)                                                   //if there is one element in the linkedlist
            {
                delete first;                                                   //delete this element(format this node, this statement only exist in c++,in other languages we dont use it because there are garbage collectors,like Java,C#,etc...)
                last=first=NULL;                                                //the linked list now is empty,so every remain pointer(last and first)shouuld refer to NULL
            }
            else                                                            //if there is more than one element in the linkedlist
            {
                Node *cur=first;                                                //declear cur pointer,stand in the first element
                first=first->next;                                              //the first place will be the second place
                delete cur;                                                     //formatting the first place
            }
            length--;
        }
    }
    void popBack()                                                        //function to delete the last node in linkedlist
    {
        if(isEmpty()){cout<<"can't delete from empty linkedlist\n";}       //if there is no elements we will tell the user
        else
        {
            if(length==1)                                                  //if there is one element in the linkedlist
            {
                delete first;                                                  //delete this element
                last=first=NULL;                                               //the linked list now is empty,so every remain pointer(last and first)shouuld refer to NULL
            }
            else                                                           //if there is more than one element in the linkedlist
            {
                Node *prev=first;                                              //declear prev pointer,stand in the first element
                Node *cur=first->next;                                         //declear cur pointer,stand in the second element
                while(cur!=last)                                               //loop to get us to the last element,cur will stand in the last element and prev will stand in the element before the last
                {
                    prev=cur;                                            
                    cur=cur->next;
                }
                delete cur;                                                    //formating the last place
                prev->next=NULL;                                               //making the new last place (which is prev) refer to NULL
                last=prev;                                                     //making the last place is prev
            }
            length--;
        }
    }
    void popElement(t x)                                            //function to delete any element in the linkedlist,take one parameter:the element we want to delete
    {
        if(isEmpty()){cout<<"can't delete from empty linkedlist\n";}   //if there is no elements we will tell the user
        else                                                           //if there is one element in the linkedlist
        {
            if(length==1)
            {
                if(first->value==x)                                      //if this lonely element is the wanted element
                {
                    popFront();                                            //delete it by popfront
                }
                else                                                     //if it's not the wanted element , we will tell the user
                {
                    cout<<"element not exist\n";
                }
            }
            else                                                       //if there is more then one element in the linkedlist
            {
                if(first->value==x)                                     //if the first element is the wanted element , we will delete it by popfront
                {
                    popFront();
                }
                else                                                    //if the first element is not the wanrted element 
                {
                    Node *prev=first;                                       //declearing prev pointer, stand in the first element
                    Node *cur=first->next;                                  //declearing cur pointer,stand in the second element
                    while(cur!=NULL and cur->value!=x)                      //loop will traverse all the linkedlist(that's why it will not stop until cur==NULL)and will check if cur is the wanted element
                    {
                        prev=cur;
                        cur=cur->next;
                    }
                    if(cur==NULL){cout<<"element not exist\n";}           //if cur is not the wanted element,we will tell the user
                    else                                                  //if cur is the wanted element
                    {
                        prev->next=cur->next;                               //we will link the prev(which is before cur)in the element after cur
                        if(last==cur){last=prev;}                               //special case:if the wanted element located in the last place,we will make the last place before it
                        delete cur;                                         //formatting cur(the position of the wanted element)
                    }
                }
            }
        }
    }
    void popPosition(t pos)                                   //function to delete node by position
    {
        if(isEmpty()){cout<<"element is not exist\n";}           //if linkedlist is empty,we will tell the user
        else                                                     //if it is not empty
        {
            if(pos<0 or pos>length-1)                              //if the wanted position out of range,we will tell the user
            {
                cout<<"out of range\n";
            }
            else                                                   //if it is inside the range
            {
                if(pos==0)                                           //if the wanted position is the first position,call popfront
                {
                    popFront();
                }
                else if(pos==length-1)                               //if the wanted position is the last position,call popback
                {
                    popBack();
                }
                else                                                 //if the wanted position between the first and the last position
                {
                    Node *prev=first;                                       //declear prev pointer,stand in the first position
                    Node *cur=first->next;                                  //declear cur pointer,stand in the second position
                    for(int i=1;i<pos;i++)                                  //loop will stop when cur is the wanted position,prev is the position before the wanted position
                    {
                        prev=cur;
                        cur=cur->next;
                    }
                    prev->next=cur->next;                                   //link the position before the wanted position in the position after the wanted position
                    delete cur;                                             //formatting the wanted position
                }
                length--;
            }
        }
    }
    void searchAtPosition(t x)                                //function to search at element and return it's position
    {
        if(isEmpty()){cout<<"element is not exist\n";}           //if there is no elements,we will rell the user
        else
        {
            if(length==1)                                         //if there is lonely element in the linkedlist
            {
                if(first->value==x){cout<<0<<"\n";}                  //if this lonely element is the wanted element, we will print it's position(which is zero)
                else{cout<<"element not exist\n";}                   //if this lonely element is not the wanted element, we will tell the user
            }
            else                                                 //if there is more than one element in the linkedlist
            {
                if(first->value==x){cout<<0<<"\n";}                  //if the first element is the wanted element, we will print it's position(whix=ch is zero)
                else                                                 //if the wanted element is not the first element
                {
                    Node *prev=first;                                         //declearing prev pointer, stand at the first position
                    Node *cur=first->next;                                    //declearing cur pointer, stand at the second position
                    int c=1;                                                  //counter to give us in the end the position of the wanted element(start from 1 because we already check the first element)
                    while(cur!=NULL and cur->value!=x)                        //loop to traverse the linkedlist, and at the same time looking for the wnted element
                    {
                        prev=cur;
                        cur=cur->next;
                        c++;
                    }
                    if(cur==NULL){cout<<"element not exist\n";}                //if the loop finish and the wanted element not exist,we will tell the user
                    else{cout<<c<<"\n";}                                       //if the wanted element exist, we will print it's position(which is the counter)
                }
            }
        }
    }
    void print()                         //function to print linkedlist elements and it's length
    {
        Node *cur=first;                 //declearing cur node refer to the first position
        while(cur!=NULL)                 //loop will move to all elements and print them,it will stop when it equal to NULL(when it will be after the last position/out of the range)
        {
            cout<<cur->value<<" ";
            cur=cur->next;
        }
        cout<<"\nlength:"<<length;
    }
};
int main()
{
    linkedlist<string>l;
    l.addLast("aaa");l.addLast("bbb");l.addLast("cxcc");l.addLast("ssss");l.searchAtPosition("aaa");
    l.print();
}
