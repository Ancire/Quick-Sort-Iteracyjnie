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
void usunSpacje(string &dane);	// Usuwa zbêdnê(powielone spacje pomiêdzy wyrazami)
vector<string> podzielNaWyrazy(string &dane); //Zwraca vector typu string skladaj¹cy siê z wyrazów wejœciowego napisu
void oczyscWyrazy(vector<string> &wyrazy); //Usuwa zbêdn¹ interpunkcjê w wektorze typu string 
vec_2 podzielDane(vector<string> &wyrazy); //Z 1 wektora typu string dostajemy vec_2 ktory zawiera 2 wektroy string zawierajace liczby oraz slowa odzielnie


//Funkcje sortuj¹ce liczby
void sortLiczby(vector<int> &dane); //Wywo³ujê sortowanie metod¹ quick sort wektora liczby typu int
void quickSortLiczby(vector<int> &tab, int l, int h); //Sortowanie szybkie zadanego wektora typu int
int partycjaLiczby(vector<int> &tab, int l, int h); //Dzieli tablice na partycje zwracajac pozycje piwotu


//Funkcje sortuj¹ce slowa
void sortowanieAlfabetyczne(vector<string> &slowa, vector<int> &liczby); //Wywo³ujê sortowanie metod¹ quick sort wektora napisów typu string
void quickSortWyrazy(vector<string> &wyrazy, vector<int> &tab, int l, int h);//Sortowanie szybkie zadanego wektora typu string gdzie odpowwiednikiem
																				//posrtowania jest wektor typu int ktory ma indeksy w kolejnosæi jakiej		
																				//powinny byæ wyœwietlone poprawnie posortowane napisy
int partycjaWyrazy(vector<string> &wyrazy, vector<int> &tab, int l, int h);