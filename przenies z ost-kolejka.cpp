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
void dequeue(node *&head3, node *&tail3)
{
  if(head3)
  {
    node *p = head3;
    head3 = head3->next;
    if(!head3) tail3 = NULL;
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

void przenies(node *&head, node *&tail)
{
	node *p=head;
	node *o=tail;
	
	if(p!=NULL && p->next!=NULL)
	{
		while(p->next->next!=NULL)
			p=p->next;

		p->next=NULL;
		tail->next=head;
		head=tail;
		tail=p;

	}

}


int main()
{
	node *head=NULL;
	node *tail=NULL;
	
	
	enqueue(head, tail, 4);
	enqueue(head, tail, 1);
	enqueue(head, tail, 2);
	enqueue(head, tail, 1);
	enqueue(head, tail, 10);

	
	show(head);

	przenies(head,tail);
	show(head);
	

	system("pause");
}