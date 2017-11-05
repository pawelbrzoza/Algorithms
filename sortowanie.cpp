#include<iostream>
using namespace std;


int main()
{
	int a, b, c, d;
	int bufor;

	cin>>a>>b>>c>>d;

	//SORTOWANIE MALEJ¥CO

	for(int i=0; i<3; i++)
	{
		if(a<b)
		{
			bufor=a;
			a=b;
			b=bufor;
		}
		if(b<c)
		{
			bufor=b;
			b=c;
			c=bufor;
		}
		if(c<d)
		{
			bufor=c;
			c=d;
			d=bufor;
		}
	}
	cout<<a<<b<<c<<d<<endl;

	//SORTOWANIE ROSN¥CO

	for(int i=0; i<3; i++)
	{
		if(a>b)
		{
			bufor=a;
			a=b;
			b=bufor;
		}
		if(b>c)
		{
			bufor=b;
			b=c;
			c=bufor;
		}
		if(c>d)
		{
			bufor=c;
			c=d;
			d=bufor;
		}
	}

	cout<<a<<b<<c<<d<<endl;


	system("pause");
}