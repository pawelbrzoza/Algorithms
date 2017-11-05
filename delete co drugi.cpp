#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
}; 


void enqueue(node *&head, node *&tail, int x)
{
	node *p=new node;
	p->val=x;
	p->next=NULL;

	if(tail)
		tail->next=p;
	else
		head=p;
	tail=p;

}
void dequeue(node *&head, node *&tail)
{
  if(head)
  {
    node *p = head;
    head = head->next;
	if(head==0)
		tail=NULL;
	delete p;
  }  
  
} 

void show(node *&head)
{
	node *p=head;

	cout<<"Head->";

	while(p)
	{
		cout<<p->val;
		p=p->next;
		cout<<"->";
	}

	cout<<"NULL"<<endl;
}

void usun(node *&head)
{
	node *p=head;

	while(p->next)
	{
			node *p1=p->next;
			if(p1->next)
			{
				p->next=p1->next;
				p=p->next;
			}
			else
				delete p1;	
		
	}
}


int main()
{
	node *head=NULL;
	node *tail=NULL;
	
	
	enqueue(head, tail, 4);
	enqueue(head, tail, 1);
	enqueue(head, tail, 2);
	enqueue(head, tail, 7);

	
	show(head);

	usun(head);
	show(head);
	

	system("pause");
}