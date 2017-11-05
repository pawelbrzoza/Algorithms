//kolejka (implementacja przy uzyciu listy dwukierunkowej)
//www.algorytm.org
 
#include<iostream>
using namespace std;
 
struct element
{
int liczba;
element *nastepny; // wskaznik na nastepny element
element *poprzedni; // wskaznik na poprzedni element
};
 
int main()
{
element *wierzcholek_kolejki = NULL; // lista jest pusta
element *koniec_kolejki = NULL; // lista jest pusta
element *pomoc = NULL; // wskaznik pomocniczy
cout << "Podaj jedna z instrukcji:\n"
<< "d liczba - aby dodac liczbe do stosu\n"
<< "u - aby usunac liczbe ze stosu\n"
<< "w - aby wyswietlic zawartosc stosu\n"
<< "CTRL+Z - aby zakonczyc\n";
char instrukcja;
while (cin >> instrukcja)
{
switch (instrukcja)
{
case 'd':
pomoc = new element; // tworzymy nowy obiekt
cin >> pomoc->liczba;
if (wierzcholek_kolejki == NULL) // jezeli kolejka jest pusta
{
pomoc->nastepny = pomoc->poprzedni = NULL;
koniec_kolejki = wierzcholek_kolejki = pomoc; // poczatek i koniec kolejki jest tym samym elementem
}
else
{
pomoc->nastepny = NULL;
koniec_kolejki->nastepny = pomoc; // dodajemy element na koniec wiec, ustawiamy wskaznik na niego w elemencie, ktory byl ostatni
pomoc->poprzedni = koniec_kolejki; // poprzednikiem nowego elementu jest dotychczasowy ostatni element
koniec_kolejki = pomoc; // ustawiamy koniec kolejki na nowym elemencie
}
break;
case 'u':
if (wierzcholek_kolejki != NULL)
{
pomoc = wierzcholek_kolejki; // ustawiamy pomoc na wierzcholek kolejki
if (wierzcholek_kolejki == koniec_kolejki) // jezeli jest tylko jeden element w kolejce
wierzcholek_kolejki = koniec_kolejki = NULL; // to teraz kolejka bedzie usta
else // jezeli jest wiecej elementow
wierzcholek_kolejki = wierzcholek_kolejki->nastepny; // przestawiamy wierzcholek na drugi element (pierwszy musimy usunac)
delete pomoc; // usuwamy element ze szczytu stosu
}
else
cout << "Kolejka jest pusta\n";
break;
case 'w':
if (wierzcholek_kolejki != NULL)
{
cout << "Zawartosc kolejki:\n";
pomoc = wierzcholek_kolejki;
while (pomoc != NULL) // dopoki pokazujemy na jakis element stosu (listy)
{
cout << pomoc->liczba << " ";
pomoc = pomoc->nastepny; // przechodzimy na nastepny element na liscie
}
}
else
cout << "Kolejka jest pusta";
cout << endl;
break;
default:
cout << "Musisz wybrac jedna z instrukcji:\nd - aby dodac element do stosu, "
<< "u - aby usunac element ze stosu lub w - aby wyswietlic zawartosc stosu\n";
break;
}
}
 
return 0;
}