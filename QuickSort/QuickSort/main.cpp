#include "naglowek.h"

using namespace std;


int main()
{

	string napis = "";
	vec_2 wynik;
	vector<int> liczby;
	vector<int> tmp;

	getline(cin, napis);

	wynik = parse(napis);
	if (wynik.liczby.size() > 0)
	{
		liczby = stringToInt(wynik.liczby);
	}
	cout << "\n";
	cout << "Wczytany napis: " << napis << "\n";

	tmp.reserve(wynik.slowa.size() + 1);

	for (int i = 0; i < wynik.slowa.size(); i++)
	{
		tmp.push_back(i);
	}

	cout << "\n";
	cout << "Sortowanie danych...\n";
	cout << "\n";
	if (wynik.liczby.size() > 0)
	{
		sortLiczby(liczby);
	}

	if (wynik.slowa.size() > 0)
	{
		sortowanieAlfabetyczne(wynik.slowa, tmp);
	}
	for (int i = 0; i < liczby.size(); i++)
	{
		cout << liczby[i] << ", ";
	}

	for (int i = 0; i < tmp.size(); i++)
	{
		cout << wynik.slowa[tmp[i]] << ", ";
	}

	cout << "\n";




	cout << endl;
	system("pause");
	return 0;
}