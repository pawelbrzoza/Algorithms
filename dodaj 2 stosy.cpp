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
void pop(node *&head)
{
	node *p=head;
	if(p!=NULL)
	{
		head=p->next;
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

void dodaj(node *&head, node *&head2)
{
	node *p=head;

	if( head !=NULL && head2 !=NULL)
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=head2;
	}
	

}

int main()
{
	node *head=NULL;
	node *head2=NULL;

	push(head, 4);
	push(head, 1);
	push(head, 5);
	push(head, 9);
	
	push(head2, 2);
	push(head2, 1);
	push(head2, 0);
	push(head2, 8);	

	
	show(head);
	show(head2);

	dodaj(head,head2);
	show(head);

	pop(head);
	show(head);
	

	system("pause");
}