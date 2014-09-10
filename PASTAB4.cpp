/*
 * PASTAB4
 * Histogram z liczb
 * 2014-09-10
 */
#include <iostream>
#include <cmath>


using namespace std;
int main(){
	const int width = 30;

	int numbers[21];
	int number;
	int max; //Max count
	max = 0;
	for (int i = 0; i < 21; ++i){
		numbers[i] = 0;
	}

	while (cin >> number){
		++numbers[number + 10];
		if (numbers[number + 10] > max)
		{
			max = numbers[number + 10];
		}
	}

	//draw histogram
	if (max){
		for (int i = 0; i < 21; ++i){
			float starNumber = round((width*numbers[i] / (float)max));
			float spaceNumber = (float)width - starNumber;
			
			if (i - 10 >= 0 && i - 10 != 10){
				cout << "  ";
			}
			else if (i - 10 < 0 && i != 0 || i == 20){
				cout << " ";
			}
			cout << i - 10 << ":|";
			for (int j = 0; j < starNumber; ++j){
				cout << "*";
			}
			for (int j = 0; j < spaceNumber; ++j){
				cout << " ";
			}
			cout << "|" << endl;
		}
	}



	return 0;
}