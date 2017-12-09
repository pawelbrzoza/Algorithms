#include<iostream>
using namespace std;

struct node
{
	int val;
	node *next;
}; 

void push(node *&head, int x)
{
	node *p=head;
	int i=1;
	int bufor;

	if(p)
	{
		node *n=new node;
		n->val=x;
		n->next=head;
		head=n;

		p=head;
		while(p->next)
		{
			i++;
			p=p->next;
		}

		for(int a=0;a<i;a++)
		{
			node *p1=head;
			node *p2=p1->next;
			for(int b=0;b<i-1;b++)
			{
				if(p1->val>p2->val)
				{
					bufor=p1->val;
					p1->val=p2->val;
					p2->val=bufor;
				}
				p1=p1->next;
				p2=p2->next;
			}
		}
	}
	else
	{
		node *p=new node;
		p->val=x;
		p->next=head;
		head=p;
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

int main()
{
	node *head=NULL;

	push(head, 4);
	push(head, 1);
	push(head, 5);
	push(head, 9);
	push(head, 2);
	push(head, 3);
	push(head, 4);
	push(head, 7);
	push(head, 5);
	push(head, 9);
	push(head, 1);
	push(head, 3);
	push(head, 4);
	push(head, 7);
	push(head, 5);
	push(head, 9);
	push(head, 6);
	push(head, 3);

	show(head);
	
	system("pause");
}
