#include<iostream>

using namespace std;

// LISTA JEDNOKIERUNKOWA

struct node
{
	int val;
	node *next;
	int licznik;
};


void push(node *&head, int x)
{
	node *p=new node;
	p->val = x;
	p->next=head;
	head=p;
}

void show(node *head)
{
	cout<<"Head->";
	//utworzyc wskaznik pomocniczy
	node *p=head;

	while(p)
	{
		cout<<p->val<<"->";
		p=p->next;
	}
	cout<<"NULL"<<endl;

}


// sciaganie ze stosu liczby
void pop(node *&head)
{
	if(head)
	{
		node *p=head;
		head=p->next;
		delete p;
	}
}
void wstaw(node *&head, int x)
{
	if(head)
		head->val+=x;
}

void dodaj2(node *&head, int x)
{
	node *p=new node;
	if(head->val!=NULL)
	
	p->val = x;
	p->next=head;
	head=p;
}


int main ()
{
	node *head=NULL;
	int x;

	for(;;)
	{
		cout<<"1.Dodaj element \n2.Zdejmij element \n3.Wyswietl zawartosc \n4.Dodaj do head liczbe \n5.Dodaj posortowanie \n0.Wyjdz z programu"<<endl;
		cin>>x;
		switch(x)
		{
		case 1:
			{
				cout<<"Dodaj element do listy: ";
				cin>>x;
				push(head, x);
				break;
			}
		case 2:
			{
				cout<<"Zdejmuje element z listy\n";
				pop(head);
				break;
			}
		case 3:
			{
				show(head);
				break;
			}
		case 4:
			{
				int a;
				cout<<"Podaj liczbe: ";
				cin>>a;
				wstaw(head,a);
				break;
			}
		case 5:
			{
				dodaj2		
				break;
			}
		default:
			exit(0);

		cout<<endl;
		}
	}


	//push(head, 5);
	//push(head, 10);

	//cout<<head->val<<endl;	// wyswietlanie warosci 10
	//cout<<head->next->val<<endl;  // wyswietlanie warosci 5
	//	
	//wyswietlanie calej listy	(funkcja pomocnicza - nie mozna wyswietlic stosu ani kolejki)
	//show(head);
	//pop(head);
	//show(head);
	//

	system("pause");
}

// W domu: Zaimplementowac sobie to w domu jeszcze raz!
//Dla chetnych: Stworzyc sobie z 5-3 elementow,  funkcje wstaw, do heada bedzie dodawalo x