/*
 * KC009
 * Odwracanie wyrazów
 * 2014-09-17
 *
 * char[1001] and printf solution. Time: 0.45
 */
#include <iostream>

using namespace std;


int main(){
	char word[1001];
	char ch;
	int i = 0;
	while ((scanf("%c",&ch)) != EOF){
		if (ch == '\n'){
			for (--i; i >= 0; --i){
				printf("%c", word[i]);
			}
			printf("%c", '\n');
			i = 0;
		}
		else{
			word[i] = ch;
			++i;
		}
	}

	return 0;
}