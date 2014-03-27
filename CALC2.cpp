#include <iostream>

using namespace std;
/* CALC2 */
int main()
{
	char znak = 0;
	int a, b;
	int rejestr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	while (cin >> znak){
		cin >> a >> b;
		switch (znak){
		case '+':
			cout << rejestr[a] + rejestr[b] << endl;
			break;
		case '-':
			cout << rejestr[a] - rejestr[b] << endl;
			break;
		case '*':
			cout << rejestr[a] * rejestr[b]<<endl;
			break;
		case '/':
			cout << rejestr[a] / rejestr[b] << endl;
			break;
		case '%':
			cout << rejestr[a] % rejestr[b] << endl;
			break;
		case 'z':
			rejestr[a] = b;
			break;
		}
	}
	return 0;
}