#pragma once

#include<vector>
#include<iostream>
#include <string>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct vec_2 {
	vector<string> slowa;
	vector<string> liczby;
};

vec_2 parse(string &napis); //Zwraca vec_2 z poprawnie podzielonymi danymi z otrzymanego napisu

//Funkcje utility
void swap(int* a, int* b);
void printArr_S(vector<string> napis);
void printArr(vector<int> tab); //Wypiosuje wektor danych typu int na ekranie
void printStrings(vector<string> napisy); // Wypisuje wektor typu string na ekranie
bool stringEquals(string a, string b);  //porownainie dwuch napisow zwraca 1 jesli napis a wystepuje blizej poczatku alfabetu
bool ifCyfra(string napis);	//Funkcja zwraca 1 jezeli podany napis jest poprawna liczba
vector<int> stringToInt(vector<string> napisy); //Zamienia wektor typu string na wektor typu int 


//Funkcje operujace na napisach
void usunSpacje(string &dane);	// Usuwa zb�dn�(powielone spacje pomi�dzy wyrazami)
vector<string> podzielNaWyrazy(string &dane); //Zwraca vector typu string skladaj�cy si� z wyraz�w wej�ciowego napisu
void oczyscWyrazy(vector<string> &wyrazy); //Usuwa zb�dn� interpunkcj� w wektorze typu string 
vec_2 podzielDane(vector<string> &wyrazy); //Z 1 wektora typu string dostajemy vec_2 ktory zawiera 2 wektroy string zawierajace liczby oraz slowa odzielnie


//Funkcje sortuj�ce liczby
void sortLiczby(vector<int> &dane); //Wywo�uj� sortowanie metod� quick sort wektora liczby typu int
void quickSortLiczby(vector<int> &tab, int l, int h); //Sortowanie szybkie zadanego wektora typu int
int partycjaLiczby(vector<int> &tab, int l, int h); //Dzieli tablice na partycje zwracajac pozycje piwotu


//Funkcje sortuj�ce slowa
void sortowanieAlfabetyczne(vector<string> &slowa, vector<int> &liczby); //Wywo�uj� sortowanie metod� quick sort wektora napis�w typu string
void quickSortWyrazy(vector<string> &wyrazy, vector<int> &tab, int l, int h);//Sortowanie szybkie zadanego wektora typu string gdzie odpowwiednikiem
																				//posrtowania jest wektor typu int ktory ma indeksy w kolejnos�i jakiej		
																				//powinny by� wy�wietlone poprawnie posortowane napisy
int partycjaWyrazy(vector<string> &wyrazy, vector<int> &tab, int l, int h);