#include <iostream>
#include <cmath>


using namespace std;


int main(){
	const short WEJSC = 1;
	const double PI = 3.141592654;
	double r, d;

	for (int i = 0; i < WEJSC; ++i){
		cin >> r >> d;
		printf("%.2f\n", PI*pow(sqrt(pow(r, 2) - pow(d / 2, 2)), 2));
	}
	
	return 0;
}