#include <stdlib.h>
#include <iostream>
using namespace std;
class Node 
{
    public:
        int data;
        Node *next;
};
class List:public Node 
{
    Node *listptr,*listptr2, *temp, *q;
    public:
    List() 
	{
        listptr=NULL;
        temp=NULL;
    }
    void create(int );
    void display();
    void insert();
    void del();
    void rev();
    void concat();
};
void List::create(int x)
 {
    Node *newNode=new Node();
    newNode->data=x;
    newNode->next=NULL;    
    if(listptr==NULL)
	{
        listptr=newNode;
        temp=newNode;
    }
    else 
	{
        temp->next=newNode;
        temp=newNode;
    }
}

void List::display() 
{    
    if (listptr==NULL)
        cout<<"List is empty. "<<endl;
    else 
	{
		cout<<"The created Linkedlist is : \t";
        temp=listptr;
        while (temp!=NULL)
		{
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
}
void List::insert()
{
	Node *newNode=new Node();
	cout<<"\nEnter the element ";
    cin>>newNode->data;
    newNode->next=NULL;
	int op,p,i=1,check;
	temp=listptr;
	cout<<"Choose the position of insertion.Enter\n 1.Start\n 2.End\n 3.In between. ";
	cin>>op;
	switch(op)
	{
		case 1:
			newNode->next=listptr;
			listptr=newNode;
			break;
		case 2:
			if(listptr==NULL)
			{
				listptr=newNode;
                temp=newNode;
			}
			else
			{
				while(temp->next!=NULL)
			    {
				temp=temp->next;
			    }
			    temp->next=newNode;
			}			
			break;
		case 3:
			if(listptr==NULL)
			{
				listptr=newNode;
                temp=newNode;
                cout<<"The list was empty and hence the element is inserted at first position."<<endl;
			}
			else 
			{
				cout<<"Enter the position in which you want to insert the element.(Positions starting from 1) ";
				do
				{
					temp=listptr;
					check=0;
					cin>>p;			
			        for(i=1;i<p-1;i++)
			        {
				    temp=temp->next;
				    if(temp==NULL)
				    {
					cout<<"The list is not long enough to have position "<<p<<endl;
					cout<<"Enter the correct position ";
					check=1;
					break;					
				    }				    
			        }
				}while(check!=0);
			    
			newNode->next=temp->next;
			temp->next=newNode;
			break;
			}			
	}
	display();
}

void List::del()
{
	if(listptr==NULL)
	cout<<"\nThe list is empty and cannot delete any element.";
	else
	{
	int op,p,i=1,check;
	temp=listptr;
	cout<<"\nChoose the position of deletion.Enter\n 1.Start\n 2.End\n 3.In between. ";
	cin>>op;
	switch(op)
	{
		case 1:
			listptr = temp->next;
			delete (temp);
			break;
		case 2:
			if(temp->next==NULL)
			{
				delete(temp);
				listptr=NULL;
                temp=NULL;				
			}
			else
			{
				while(temp->next->next!=NULL)
			    {
				    temp=temp->next;
			    }
			    q=temp->next;
			    temp->next=NULL;
			    delete(q);
			}			
			break;
		case 3:
			cout<<"Enter the position in which you want to delete the element.(Positions starting from 1) ";
				do
				{
					temp=listptr;
					check=0;
					cin>>p;			
			        for(i=1;i<p-1;i++)
			        {
				    temp=temp->next;
				    if(temp->next ==NULL)
				    {
					cout<<"The list is not long enough to have position "<<p<<endl;
					cout<<"Enter the correct position ";
					check=1;
					break;					
				    }				    
			        }
				}while(check!=0);
			q=temp->next;
			temp->next=q->next;
			delete (q);
			break;
		default :
			cout<<"Wrong choice";
	}
	}  
	display();
}
void List::rev()
{
	if(listptr!=NULL)
	{
		Node *f,*c,*b;
	    f=listptr;
	    c=NULL;
	    while(f!=NULL)
	    {
		    b=c;
		    c=f;
		    f=f->next;
		    c->next=b;
	    }
	    listptr = c;
	    cout<<"\nThe list is reversed.\n";
	    display();
	}
	else
	cout<<"The list is empty and cannot be reversed.";	
}
void List::concat()
{
	int n;
	listptr2=NULL;
    cout<<"\nEnter no. of nodes of second list : ";
    cin>>n;
    cout<<"Enter the numbers: ";
    for(int i=0;i<n;i++)
    {
    	Node *newNode=new Node();
        cin>>newNode->data;
        newNode->next=NULL;    
        if(listptr2==NULL)
	    {
        listptr2=newNode;
        temp=newNode;
        }
        else 
	    {
        temp->next=newNode;
        temp=newNode;
        }
	}
	temp=listptr;
	while(temp->next!=NULL)
	temp = temp->next;
	temp->next = listptr2;
	display();
}

int main () 
{
    int ch,cnt,c,x;
    bool quit = false;
    List L;
    while (quit==false)
    {
        cout<<"Operations on Linked List. Enter\n 1.Create\n 2.Display\n 3.Insert element\n 4.Delete element\n 5.Reverse\n 6.Concatenate 2 lists ";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch (ch) 
		{
            case 1:
                cout<<"Enter no. of nodes: ";
                cin>>cnt;
                cout<<"Enter the numbers: ";
                while(cnt!=0)
				{
					cin>>x;
                    L.create(x);
                    cnt--;
                }
				break;				
            case 2:
                L.display();
                break;
            case 3:
            	L.insert();
            	break;
            case 4:
            	L.del();
            	break;
            case 5:
            	L.rev();
            	break;
            case 6:
            	L.concat();
            	break;
                
            default:
			    cout<<"\nWrong Choice. ";			
        }
        cout<<"\nPress 1 to continue, else any other key."<<endl;
        cin>>c;
        if(c!=1)
        quit=true;
    }
}
