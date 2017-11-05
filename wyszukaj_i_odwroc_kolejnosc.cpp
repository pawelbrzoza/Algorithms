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

void search_and_change(node *&head)
{
	node *p=head;
	node *p2;
	int max=0;
	
	while(p)
	{
		if(p->val>max)
		{
			max=p->val;
			p2=p;
		}
		p=p->next;
	}
	
	p=p2->next;
	p2->next=NULL;

	while(p)
	{
		p2=p->next;
		p->next=head;
		head=p;
		p=p2;
	}


}

int main()
{
	node *head=NULL;
	push(head, 11);
	push(head, 4);
	push(head, 1);
	push(head, 5);
	push(head, 9);
	push(head, 0);
	push(head, 3);
	

	show(head);
	search_and_change(head);
	show(head);

	system("pause");
}