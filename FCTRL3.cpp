#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int silnia(unsigned int liczba);
char getCyfraJednosci(unsigned int liczba);
char getCyfraDziesiatek(unsigned int liczba);

int main(){
	int wejsc;
	unsigned int wejscie;
	int varSilnia;
	cin >> wejsc;

	int i = 0;
	while (i < wejsc){
		cin >> wejscie;
		if (wejscie < 10){
			varSilnia = silnia(wejscie);
			printf("%u %u", getCyfraDziesiatek(varSilnia), getCyfraJednosci(varSilnia));
			cout << endl;
		}
		else{
			printf("0 0");
			cout << endl;
		}
		++i;
	}

	return 0;
}

int silnia(unsigned int liczba){
	if (liczba <= 1){
		return 1;
	}
	else{
		return liczba * silnia(liczba - 1);
	}
}

char getCyfraJednosci(unsigned int liczba){

	return (liczba - floor(liczba / 10) * 10);
}

char getCyfraDziesiatek(unsigned int liczba){
	return floor((liczba - floor(liczba / 100) * 100) / 10);
}
