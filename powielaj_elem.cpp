#include<iostream>
#include<time.h>
#include<windows.h>
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

void kopiuj(node *&head)
{
	node *p=head;
	while(p)
	{
		int x=p->val;
		while(x>1)
		{
			node *p1=new node;
			p1->val=p->val;
			p1->next=p->next;
			p->next=p1;
			p=p->next;
			x--;
		}
		p=p->next;		
	}
}

int main()
{
	srand((unsigned)time(NULL));
	node *head=NULL;
	node *tail=NULL;
	int x,y;
	cout<<"Podaj liczbe elementow: ";
	cin>>x;
	for(int i=0;i<x;i++)
	{
		y=rand()%(20-10)+10;
		enqueue(head, tail, y);	
		Sleep(3);
	}
	
	show(head);

	kopiuj(head);
	
	show(head);

	system("pause");
}