#include <iostream>
#include <stdio.h>


using namespace std;

int szukajWzoru(int a);
int ostatniaCyfra(int liczba);
int potega(int a, int b);

int main(){
	int a = 1, b = 1;
	short wejsc;

	cin >> wejsc;//Pobranie liczby przypadków
	
	int wzor;
	int wykladnik;
	for (int i = 0; i < wejsc; ++i){
		cin >> a >> b;
		a = ostatniaCyfra(a);
		wzor = szukajWzoru(a);
		if (wzor == 0){
			wykladnik = b;
		}
		else{
			wykladnik = b%wzor;
			if (wykladnik == 0){
				wykladnik = wzor;
			}
		}
		printf("%u\n",ostatniaCyfra(potega(a, wykladnik)));
	}
	
	
	return 0;
}

int ostatniaCyfra(int liczba){
	return liczba % 10;
}

/*
Sprawdza, po ilu iteracjach wykładnika wraca ta sama ostatnia cyfra.
*/
int szukajWzoru(int a){
	int okres = 0;
	int wynik = 0;
	int wykladnik = 1;
	int cyfry[100];
	for (char i = 0; i < 100; ++i){//Inicjalizacja tablicy
		cyfry[i] = 0;
	}

	int indeksOstatniaCyfra = -1;

	int podstawa = 1;
	while (okres == 0){
		int wynik = podstawa * a;//Potęga ostatniej cyfry poprzedniego wyniku

		podstawa = ostatniaCyfra(wynik);
		cyfry[++indeksOstatniaCyfra] = podstawa;
		
		for (int i = 0; i < indeksOstatniaCyfra; ++i){//Szukanie powtórzeń
			if (cyfry[i] == podstawa){
				okres = wykladnik - i;
				break;
			}
		}
		++wykladnik;

	}
	return okres - 1;
}

int potega(int a, int b){
	int i = 1;
	int wynik = a;
	while (i < b){
		wynik = wynik * a;
		++i;
	}
	return wynik;
}

