#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
}; 

void push(node *&head, int x)
{
	node *p=new node;
	p->val=x;
	p->next=head;
	head=p;
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

void revertStack(node *&head)
{
	node *p=head;
	node *p1;

	while(p->next)
	{
		p1=p->next;
		p->next=p1->next;
		p1->next=head;
		head=p1;
	}
}

int main()
{
	node *head=NULL;

	push(head, 4);
	push(head, 3);
	push(head, 2);
	push(head, 1);
	push(head, 0);

	show(head);
	revertStack(head);
	show(head);

	system("pause");
}
