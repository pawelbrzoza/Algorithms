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

void findElementOfValueAndMoveOnBack(node *&head, int x)
{
	node *p=head;

	if(p)
	{
		while(p->val!=x)
		{
			p=p->next;
		}
		
		if(p->next!=NULL)
		{
			if(head==p)
			{
				node *p1=head;

				while(p1->next!=NULL)
					p1=p1->next;	
				
				head=p->next;
				p1->next=p;
				p->next=NULL;
			}
			else
			{
				node *p2=head;
				while(p2->next!=p)
					p2=p2->next;

				node *p1=head;
				while(p1->next!=NULL)
					p1=p1->next;

				p2->next=p->next;
				p->next=NULL;
				p1->next=p;
			}
		}
	}
}

int main()
{
	node *head=NULL;

	push(head, 5);
	push(head, 2);
	push(head, 4);
	push(head, 3);
	push(head, 1);

	show(head);
	findElementOfValueAndMoveOnBack(head, 4);
	show(head);

	system("pause");
}
