#include <iostream>

using namespace std;

int main(){
	int t, n, a;
	int liczby[100];

	cin >> t;
	for (int i = 0; i < t; ++i){
		for (int i = 0; i < 100; ++i){
			liczby[i] = -1;
		}
		int n;
		cin >> n;
		for (int j = 1; j <= n; ++j){
			cin >> a;
			if ((j % 2) == 0){//Parzyste
				cout << a << ' ';
			}
			else{
				liczby[(j - 1) / 2] = a;
			}
		}
		for (int j = 0; j < 100; ++j){
			if (liczby[j] == -1){
				break;
			}
			cout << liczby[j] << ' ';
		}
		cout << endl;

	}
	return 0;

}