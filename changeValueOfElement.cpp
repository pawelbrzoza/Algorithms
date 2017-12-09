#include<iostream>
using namespace std;

struct Node
{
	int val;
	Node *next;
};

void push(Node *&head, int x)
{
	Node *p = new Node;
	p->val=x;
	p->next=head;
	head=p;
}

void pop(Node *&head)
{
	if(head)
	{
		Node *p=head;
		head=p->next;
		delete p;
	}
}

void show(Node *&head)
{
	Node *p=head;
	cout<<"Head->";
	
	while(p)
	{
		cout<<p->val;
		cout<<"->";
		p=p->next;
	}

	cout<<"Null"<<endl;
}


void zamien(Node *&head, int x, int y)
{
	Node *p=head;
	if(head)
	{
		if(head && head->val!=x)
		{
			while(p)
			{
				if(p->val==x)
					p->val=y;
				p=p->next;
			}
		}
		else
			p->val=y;
	}
}
		
int main()
{
	Node *head=NULL;
	
	show(head);
	zamien(head, 2, 7);
	show(head);

	system("pause");
}
