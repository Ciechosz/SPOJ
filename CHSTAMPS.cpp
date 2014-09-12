/*
 * CHSTAMPS
 * Piecz¹tki dzieci
 * 2014-09-10
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void increment(string::reverse_iterator current, string &number, short& fivesNumber, short fivesGoal, vector<bool>::reverse_iterator touchedRit, vector<bool>& touched);
void increase(string::reverse_iterator current, string& number, short& fivesNumber, short fivesGoal, vector<bool>::reverse_iterator touchedRit, vector<bool>& touched);

int main(){
	string number;
	short fivesNumber = 0;
	short fivesGoal;
	vector<bool> touched(20); //Says which numbers where changed

	//zero vector
	fill(touched.begin(), touched.end(), false);

	vector<bool>::reverse_iterator touchedRit = touched.rbegin();//Is moved whenever number iterator is.
	
	cin >> number >> fivesGoal;

	//count fives
	for (string::iterator it = number.begin(); it != number.end(); ++it){
		if (*it == '5'){
			++fivesNumber;
		}
	}

	//increment the number, because new one must by greater, not equal.
	increment(number.rbegin(), number, fivesNumber, fivesGoal, touchedRit, touched);

	while (fivesNumber != fivesGoal){
		string::reverse_iterator rit = number.rbegin();
		touchedRit = touched.rbegin();
		increase(rit, number, fivesNumber, fivesGoal, touchedRit, touched);
	}

	cout << number;

	return 0;
}

//Used when incrementing lower number would result in 10
void increment(string::reverse_iterator current, string& number, short& fivesNumber, short fivesGoal, vector<bool>::reverse_iterator touchedRit, vector<bool>& touched){

	if (*current == '9' || (*current >= '5' && *touchedRit == true)){
		//I need to add new digit on the left
		if (current == --number.rend()){//There is no higher position
			number = "0" + number;

			//Set newly added 0 as touched
			touched[touched.size() - number.length() + 1] = true;
			current = ----number.rend();//Recreate current on the same position;
		}
		increment(++current, number, fivesNumber, fivesGoal,++touchedRit, touched);
	}
	else{
		if (!(*touchedRit)){
			//Incerement by one, because it has not been yet modified
			*touchedRit = true;
			++*current;
			if (*current == '6'){
				//There was a five, now removed
				--fivesNumber;
			}
			else if (*current == '5'){
				++fivesNumber;
			}
			//Zero or five all lower
			//First five all, then remove fives that exceed the limit

			for (string::reverse_iterator rit = number.rbegin(); rit != current; ++rit){
				if (*rit != '5'){
					++fivesNumber;
				}
				*rit = '5';
			}
			for (string::iterator it = (current.base()); it != number.end() && fivesNumber > fivesGoal; ++it){
				--fivesNumber;
				*it = '0';
			}
		} else{ //I already changed this digit, so digits other done five are of no use

			//Increase to 5 if possible
			if (*current < '5'){
				*current = '5';
				++fivesNumber;
			}

		}
	}
}

//Digits other than 5 are pretty much useles, unless caused by digit >= 10
void increase(string::reverse_iterator current, string& number, short& fivesNumber, short fivesGoal, vector<bool>::reverse_iterator touchedRit, vector<bool>& touched){
	if (*current < '5'){
		*current = '5';
		*touchedRit = true;
		++fivesNumber;
	}
	else{
		if (current == --number.rend()){//There is no digit to the left
			number = "0" + number;
			//Set newly added 0 as touched
			touched[touched.size() - number.length() + 1] = true;
			current = ----number.rend();//Recreate current on the same position;
		}
		
		increment(++current, number, fivesNumber, fivesGoal, ++touchedRit, touched);
	}
}

