#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

inline string intToStr(int v){
	string result = "";
	if(!v)
		return "0";
	while(v){
		result = (char)((v - v / 10 * 10)+'0') + result; 
		v /= 10;
	}
	return result;
}

struct Liczba{
    string val;

	Liczba(){
		val = "0";
	}
	
    Liczba(string val) : val(val){}
	
	Liczba(int val){
		this->val = intToStr(val);
	}
	
	Liczba DivBy2(){
		string result = "";
		int overflow = 0;
		bool leadingZeros = true;
		for(string::iterator it = val.begin(); it != val.end(); ++it){
			int digit = (*it - '0' + overflow*10) / 2;
			if(digit != 0)
				leadingZeros = false;
			if(!leadingZeros)
				result += (char)(digit + '0');
			overflow = (*it - '0' + overflow*10) % 2;
		}
		if(leadingZeros)
			return Liczba("0");
		return Liczba(result);
	}
	
	bool isEven(){
		char last = val[val.size() - 1];
		return (last - '0') % 2 == 0;
	}
};

bool operator<(Liczba const& l, Liczba const& r){
    return l.val.size() < r.val.size() || (l.val.size() == r.val.size() && l.val < r.val);
}
bool operator<=(Liczba const& l, Liczba const& r){
    return l.val.size() < r.val.size() || (l.val.size() == r.val.size() && l.val < r.val);
}
bool operator>(Liczba const& l, Liczba const& r){
    return l.val.size() > r.val.size() || (l.val.size() == r.val.size() && l.val > r.val);
}
bool operator>=(Liczba const& l, Liczba const& r){
    return l.val.size() > r.val.size() || (l.val.size() == r.val.size() && l.val > r.val);
}
bool operator==(Liczba const& l, Liczba const& r){
    return l.val == r.val;
}
bool operator!=(Liczba const& l, Liczba const& r){
    return l.val != r.val;
}
	
Liczba operator+(Liczba const& l, Liczba const& r){
	string result = "";
	int overflow = 0;
	string::const_reverse_iterator lit = l.val.rbegin();
	string::const_reverse_iterator rit = r.val.rbegin();
	while(true){
		int lval = lit == l.val.rend() ? 0 : *lit - '0'; 
		int rval = rit == r.val.rend() ? 0 : *rit - '0';
		int suma = lval + rval + overflow;
		
		result = (char)(suma%10 + '0') + result;
		overflow = suma / 10;
		
				
		if(lit != l.val.rend())
			++lit;	
		if(rit != r.val.rend())
			++rit;
		
		if(lit == l.val.rend() && rit == r.val.rend() && !overflow)
			break;
	}		
	
	return Liczba(result);
}

// Rzuca wyjątek dla ujemnych wyników
Liczba operator-(Liczba const&l, Liczba const& r){
	string result = "";
	int overflow = 0;
	string::const_reverse_iterator lit = l.val.rbegin();
	string::const_reverse_iterator rit = r.val.rbegin();
	while(true){
		int lval = lit == l.val.rend() ? 0 : *lit - '0'; 
		int rval = rit == r.val.rend() ? 0 : *rit - '0';
		int roznica = lval + overflow - rval;
		overflow = 0;
		if(roznica < 0){
			overflow = -1;
			roznica += 10;
		}
		
		result = (char)(roznica + '0') + result;
		
		if(lit != l.val.rend())
			++lit;	
		if(rit != r.val.rend())
			++rit;
		
		if(lit == l.val.rend() && rit != r.val.rend())
			throw -1;
			
		if(lit == l.val.rend() && rit == r.val.rend()){
			if(overflow != 0)
				throw -1;
			break;
		}
	}
	return Liczba(result);
}

// Przechowuje liczebności danych elementów
struct RangeTree{
	Liczba Size;
	map<Liczba, int> Container;
	RangeTree(Liczba Size){
		this->Size = Size;
	}
	
	// Ten insert jest mało unierwsalny. 
	void insert(int index, int val = 1){
		Liczba node = Size + index;
		Container[node] += val;
		while(node != Liczba(1)){
			node = node.DivBy2();
			Container[node] += val;
		}
	}
	
	int count(Liczba l, Liczba r){
		Liczba lNode = Size + l;
		Liczba rNode = Size + r;
		int result = Container[lNode];
		if(rNode != lNode)
			result += Container[rNode];
		while(lNode.DivBy2() != rNode.DivBy2()){
			if(lNode.isEven()){
				result += Container[lNode + Liczba(1)];
			}
			if(!rNode.isEven())
				result += Container[rNode - Liczba(1)];
			
			lNode = lNode.DivBy2();
			rNode = rNode.DivBy2();
		}
		return result;
	}
	
	void print(){
		for(map<Liczba, int>::iterator it = Container.begin(); it != Container.end(); ++it){
			cout << (*it).first.val << ": " << (*it).second << endl;
		}
	}
};



int main(){
	Liczba Size("1267650600228229401496703205376");
    RangeTree Tree(Size); // 2**100
	
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int a;
		cin >> a;
		Tree.insert(a);
	}
	cin >> t;
	for(int i = 0; i < t; ++i){
		int a;
		cin >> a;
		--a;
		cout << Tree.count(0, a) << endl;
	}
}

