#include"naglowek.h"

//Funkcje utility

vec_2 parse(string &napis)
{
	vec_2 dane;
	vector<string> wyrazy;
	usunSpacje(napis);

	wyrazy = podzielNaWyrazy(napis);
	oczyscWyrazy(wyrazy);
	dane = podzielDane(wyrazy);

	return dane;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


void printArr_S(vector<string> napis)
{
	for (int i = 0; i < napis.size(); i++)
	{
		cout << napis[i] << "  ";
	}
	cout << endl;
}
void printArr(vector<int> tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		cout << tab[i] << "    ";
		if (i % 10 == 9)
		{
			cout << endl;
		}
	}
	cout << endl;
}
void printStrings(vector<string> napisy)
{
	cout << endl;
	for (int i = 0; i < napisy.size(); i++)
	{
		cout << i + 1 << "." << napisy[i];
		cout << endl;
	}
}
bool stringEquals(string a, string b)
{
	int x = min(a.length(), b.length());

	string lowera = a;
	transform(lowera.begin(), lowera.end(), lowera.begin(), ::tolower);

	string lowerb = b;
	transform(lowerb.begin(), lowerb.end(), lowerb.begin(), ::tolower);


	for (int i = 0; i < x; i++) {
		if (lowera[i] < lowerb[i]) {
			//czyli string a bedzie pierwszy
			return true;
		}
		else if (lowera[i] == lowerb[i]) {

		}
		else {
			return false;
		}
	}

}
bool ifCyfra(string napis)
{
	bool flaga = true;
	for (int i = 0; i < napis.length(); i++)
	{
		if (napis[i] >= '0'&& napis[i] <= '9') {

		}
		else {
			flaga = false;
		}
	}

	return  flaga;
}
vector<int> stringToInt(vector<string> napisy)
{
	string a = "";
	vector<int> liczby;
	int x;
	for (int i = 0; i < napisy.size(); i++)
	{
		x = atoi(napisy[i].c_str());
		liczby.push_back(x);
	}
	return liczby;
}



//Funkcje operujace na napisach
void usunSpacje(string &dane)
{
	vector<string> wyrazy;

	for (int i = dane.size() - 1; i > 0; i--)
	{
		if (dane[i - 1] == ' ' && dane[i] == ' ')
		{
			dane.erase(i, 1);
		}
	}

	if (dane[0] == ' ')
	{
		dane.erase(0, 1);
	}

}
vector<string> podzielNaWyrazy(string &dane)
{
	vector<string> wyrazy;

	int start = 0;
	for (int i = 0; i < dane.length(); i++)
	{
		if (dane[i] == ' ')
		{
			wyrazy.push_back(dane.substr(start, i - start));
			start = i + 1;
		}
	}
	wyrazy.push_back(dane.substr(start - 1));

	return wyrazy;
}
void oczyscWyrazy(vector<string> &wyrazy)
{
	for (int i = wyrazy.size() - 1; i >= 0; i--)
	{
		for (int j = wyrazy[i].length() - 1; j >= 0; j--)
		{
			if (wyrazy[i][j] == ' ')
			{
				wyrazy[i].erase(j, 1);
			}
		}
	}
	for (int i = wyrazy.size() - 1; i >= 0; i--)
	{
		for (int j = wyrazy[i].length() - 1; j >= 0; j--)
		{
			if (wyrazy[i][j] == ',')
			{
				wyrazy[i].erase(j, 1);
			}
		}
	}
	for (int i = wyrazy.size() - 1; i >= 0; i--)
	{
		for (int j = wyrazy[i].length() - 1; j >= 0; j--)
		{
			if (wyrazy[i][j] == '.')
			{
				wyrazy[i].erase(j, 1);
			}
		}
	}
}
vec_2 podzielDane(vector<string> &wyrazy)
{

	vec_2 dane;

	for (int i = 0; i < wyrazy.size(); i++)
	{
		if (ifCyfra(wyrazy[i]))
		{
			dane.liczby.push_back(wyrazy[i]);
		}
		else
		{
			dane.slowa.push_back(wyrazy[i]);
		}
	}



	return dane;

}


//Funkcje sortuj¹ce liczby
void sortLiczby(vector<int> &dane)
{
	quickSortLiczby(dane, 0, dane.size() - 1);
}
void quickSortLiczby(vector<int> &tab, int l, int h)
{

	int stack[1000];


	int top = -1;


	stack[++top] = l;
	stack[++top] = h;


	while (top >= 0)
	{

		h = stack[top--];
		l = stack[top--];

		int p = partycjaLiczby(tab, l, h);

		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		if (p + 1 < h)
		{
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}
int partycjaLiczby(vector<int> &tab, int l, int h)
{
	int x = tab[h];
	int i = (l - 1);
	/*cout << endl << "x=" << x << endl;
	cout << endl << "i=" << i << endl;*/
	for (int j = l; j <= h - 1; j++)
	{
		if (tab[j] <= x)
		{
			i++;
			/*cout << "swap i=" << i << endl;*/
			swap(&tab[i], &tab[j]);
		}
	}
	//cout << "i po petli=" << i << endl;
	swap(&tab[i + 1], &tab[h]);
	return (i + 1);
}


//Funkcje sortuj¹ce s³owa
void sortowanieAlfabetyczne(vector<string> &slowa, vector<int> &liczby)
{
	quickSortWyrazy(slowa, liczby, 0, slowa.size() - 1);
}
void quickSortWyrazy(vector<string> &wyrazy, vector<int> &tab, int l, int h)
{

	int stack[1000];


	int top = -1;


	stack[++top] = l;
	stack[++top] = h;


	while (top >= 0)
	{

		h = stack[top--];
		l = stack[top--];

		int p = partycjaWyrazy(wyrazy, tab, l, h);

		if (p - 1 > l)
		{
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		if (p + 1 < h)
		{
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}
int partycjaWyrazy(vector<string> &wyrazy, vector<int> &tab, int l, int h)
{

	string liczba = wyrazy[h];

	int i = (l - 1);

	for (int j = l; j <= h - 1; j++)
	{
		if (stringEquals(wyrazy[j], liczba))
		{
			i++;
			swap(&tab[j], &tab[i]);
		}
	}

	swap(&tab[i + 1], &tab[h]);
	return (i + 1);

}
