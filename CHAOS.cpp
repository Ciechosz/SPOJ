/*
 * CHAOS
 * Godzina chaosu
 * 2014-04-18
 */
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;
class Hour {
public:
	int hours;
	int minutes;
	bool isPalindromic();
	/*
	Move hour by one minute 
	*/
	void later();
	string toString(bool nice = false);
};
int main(){
	int t = 0;
	cin >> t;
	Hour* h = new Hour;
	for (t; t; --t){
		scanf("%d:%d", &h->hours, &h->minutes);
		do{
			h->later();
		} while (!h->isPalindromic());
		cout << h->toString(true) << endl;
	}
	delete h;
	return 0;
}
bool Hour::isPalindromic(){
	string str = toString(false);
	int length = str.length();
	for (int i = 0; i < length; ++i){
		if (str[i] != str[length - 1 - i]){
			return false;
		}
	}
	return true;
}
void Hour::later(){
	if (minutes < 59){
		++minutes;
	}
	else{
		minutes = 0;
		if (hours < 23){
			++hours;
		}
		else{
			hours = 0;
		}
	}
}
string Hour::toString(bool nice){
	ostringstream stream;
	char ch[6];
	if (nice){
		sprintf(ch, "%02d:%02d", hours, minutes);
		stream.write(ch, 5);	
	}
	else{//For checking palindromness
		if (hours == 0){
			stream << minutes;
		}else if (hours !=0 && minutes < 10){//Dirty, but simpler
			stream << hours << "0"<<minutes;
		}
		else{
			stream << hours << minutes;
		}
	}
	return stream.str();
}

