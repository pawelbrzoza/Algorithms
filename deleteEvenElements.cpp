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

void deleteEvenElements(node *&head)
{
	if(head->val%2!=0)
	{
		node *p=head;
		node *p1=head->next;

		while(p1)
		{
			if(p1->val%2==0)
			{
				p->next=p1->next;
				delete p1;
				p1=p;
				p1=p1->next;
			}
			else
			{
				p1=p1->next;
				p=p->next;
			}
		}
	}
	else
	{
		node *p=head;
	
		while(head!=0 && head->val%2==0)
		{
			head=head->next;
			delete p;
			p=head;
		}

		node *p1=head->next;

		while(p1)
		{
			if(p1->val%2==0)
			{
				p->next=p1->next;
				delete p1;
				p1=p;
				p1=p1->next;
			}
			else
			{
				p1=p1->next;
				p=p->next;
			}
		}
	}
}

int main()
{
	node *head=NULL;
	
	push(head, 12);
	push(head, 5);
	push(head, 9);
	push(head, 2);
	push(head, 1);
	push(head, 8);
	push(head, 8);
	push(head, 1);

	show(head);
	deleteEvenElements(head);
	show(head);

	system("pause");
}
