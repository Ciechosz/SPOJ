#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Liczba{
    string val;

    Liczba(string val) : val(val){}
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



int main(){

    Liczba a1("353");
    Liczba a2("315");
    cout << (a1 < a2) << endl;

}
