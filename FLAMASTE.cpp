#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

int main(){
	short wejsc;
	cin >> wejsc;//Pobranie liczby przypadków
	char poprzedni = 0;//Poprzedni znak
	unsigned char n = 0;//Liczba powtórzeñ

	char slowo[201];
	for (int i = 0; i < 201; ++i){//Czyszczenie slowa
		slowo[i] = '\0';
	}
	for (short i = 0; i<wejsc; ++i){
		cin >> slowo;
		for (int j = 0; j <= 201; ++j){//Iteracja po słowie
			if (slowo[j] == poprzedni){
				++n;
			}
			else{

				if (n > 2){
					cout << (int)n;
				}
				else if (n == 2){
					cout << poprzedni;
				}
				if (slowo[j] != '\0'){
					cout << slowo[j];
					poprzedni = slowo[j];
				}
				n = 1;
				
			}
			if (slowo[j] == '\0'){
				break;
			}
		}
		poprzedni = 0;
		n = 0;
		for (int i = 0; i < 201; ++i){//Czyszczenie slowa
			slowo[i] = '\0';
		}
		cout << "\n";
	}

	return 0;
}

