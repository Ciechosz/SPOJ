// KMP
// 2015-02-13
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

struct combined{
    char delim;
    string* wzorzec;
    string* tekst;
    int wLen;
    int tLen;
    int len;

    combined(string* wzorzec, string* tekst, char delim = '#'){
        this->delim = delim;
        this->wzorzec = wzorzec;
        this->tekst = tekst;
        wLen = wzorzec->size();
        tLen = tekst->size();
        len = wLen + tLen + 1; // +1 - delim
    }

    void print(){
        cout << *wzorzec << delim << *tekst << endl;
    }

    char& get(int x){
        if(x < wLen){
            return (*wzorzec)[x];
        } else if(x == wLen){
            return delim;
        } else{
            return (*tekst)[x - wLen - 1];
        }
    }

    char& operator[](int x){
        return get(x);
    }

};

int main(){
    int T;
    cin >> T;
    while(T--){
        int w;
        cin >> w;
        string wzorzec;
        cin >> wzorzec;
        string tekst;
        cin >> tekst;
        combined comb(&wzorzec, &tekst);

        int* P = new int[comb.len];
        int t = P[0] = 0;
        for(int i = 1; i < comb.len; ++i){
            while(t > 0 && comb[t] != comb[i]){
                t = P[t-1];
            }
            if(comb[t] == comb[i]){
                ++t;
            } else{
                t = 0;
            }
            P[i] = t;
            if(t == comb.wLen){
                cout << i - comb.wLen * 2 << endl;
            }
        }

        delete[] P;
    }
}
