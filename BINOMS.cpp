#include <iostream>

using namespace std;
int main(){
	double t, n, k, licznik, mianownik, odjemnik, wynik;
	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> n >> k;
		int j = 1;
		bool stop1 = false;
		bool stop2 = false;
		if (k == 0 && n == 0){
			wynik = 1;
		}else if (n == 0){
			wynik = 0;
		}
		else if (k == 0){
			wynik = n;
		}
		else{
			wynik = n / k;
			while (j <= k - 1){
				wynik *= n - j;
				wynik /= k - j;
				++j;
			}
		}

		cout << wynik << endl;
	}
	return 0;

}