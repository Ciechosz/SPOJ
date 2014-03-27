

#include <iostream>
#include <cstring>

using namespace std;

#define T_SIZE 1001

char* string_merge(char * S1, char * S2);

int main(){
	int t, n;
	char S1[T_SIZE], S2[T_SIZE], *S;

	cin >> t; /* wczytaj liczbę testów */
	cin.getline(S1, T_SIZE);
	while (t){
		cin.getline(S1, T_SIZE, ' ');
		cin.getline(S2, T_SIZE);
		S = string_merge(S1, S2);
		cout << S << endl;
		//delete[] S;
		--t;
	}
	return 0;
}

char* string_merge(char * S1, char * S2){
	//Znalezienie krotszej;
	int rozmiar,i;
	i = 0;
	while (S1[i] != '\0' && S2[i] != '\0') {
		++i;
	} 
	
	rozmiar = i * 2 + 1; //rozmiar nowej tablicy
	char * wynik = new char[rozmiar];

	for (int i = 0; i < rozmiar - 1; ++i){
		wynik[i*2] = S1[i];
		
		wynik[i*2+1] = S2[i];
	}
	wynik[rozmiar - 1] = '\0';
	return wynik;
}
