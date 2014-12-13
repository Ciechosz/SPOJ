// Trzy liczby
// TTRI
// 2014-11-28

#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long ull;

ull NWD(ull a, ull b){
    ull c = a % b;
    while(c != 0){
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}

ull NWW(ull a, ull b){
    return a/NWD(a,b) * b;
}

struct Ulamek{
    public:
    ull licznik;
    ull mianownik;

    Ulamek() : Ulamek(1, 1){}

    Ulamek(ull licznik, ull mianownik){
        ull dzielnik = NWD(licznik, mianownik);
        this->licznik = licznik/dzielnik;
        this->mianownik = mianownik/dzielnik;
    }

    Ulamek operator+(Ulamek const& other){
        ull nowyMianownik = NWW(mianownik, other.mianownik);
        ull mnoznik1 = nowyMianownik / mianownik;
        ull mnoznik2 = nowyMianownik / other.mianownik;
        ull nowyLicznik = licznik * mnoznik1 + other.licznik * mnoznik2;
        return Ulamek(nowyLicznik, nowyMianownik);
    }

    Ulamek operator-(Ulamek const& other){
        ull nowyMianownik = NWW(mianownik, other.mianownik);
        ull mnoznik1 = nowyMianownik / mianownik;
        ull mnoznik2 = nowyMianownik / other.mianownik;
        ull nowyLicznik = licznik * mnoznik1 - other.licznik * mnoznik2;
        return Ulamek(nowyLicznik, nowyMianownik);
    }

    bool operator>=(Ulamek const& other){
        ull nowyMianownik = NWW(mianownik, other.mianownik);
        ull mnoznik1 = nowyMianownik / mianownik;
        ull mnoznik2 = nowyMianownik / other.mianownik;
        ull nowyLicznik1 = licznik * mnoznik1;
        ull nowyLicznik2 = other.licznik * mnoznik2;

        if(nowyLicznik1 >= nowyLicznik2){
            return true;
        }else{
            return false;
        }
    }

    bool operator<=(Ulamek const& other){
        ull nowyMianownik = NWW(mianownik, other.mianownik);
        ull mnoznik1 = nowyMianownik / mianownik;
        ull mnoznik2 = nowyMianownik / other.mianownik;
        ull nowyLicznik1 = licznik * mnoznik1;
        ull nowyLicznik2 = other.licznik * mnoznik2;

        if(nowyLicznik1 <= nowyLicznik2){
            return true;
        }else{
            return false;
        }
    }
    bool operator>(Ulamek const& other){
        ull nowyMianownik = NWW(mianownik, other.mianownik);
        ull mnoznik1 = nowyMianownik / mianownik;
        ull mnoznik2 = nowyMianownik / other.mianownik;
        ull nowyLicznik1 = licznik * mnoznik1;
        ull nowyLicznik2 = other.licznik * mnoznik2;

        if(nowyLicznik1 > nowyLicznik2){
            return true;
        }else{
            return false;
        }
    }

    bool operator<(Ulamek const& other){
        ull nowyMianownik = NWW(mianownik, other.mianownik);
        ull mnoznik1 = nowyMianownik / mianownik;
        ull mnoznik2 = nowyMianownik / other.mianownik;
        ull nowyLicznik1 = licznik * mnoznik1;
        ull nowyLicznik2 = other.licznik * mnoznik2;

        if(nowyLicznik1 < nowyLicznik2){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        Ulamek boki[3];
        for(int i = 0; i < 3; ++i){
            ull licznik, mianownik;
            scanf("%llu/%llu", &licznik, &mianownik);
            boki[i] = Ulamek(licznik, mianownik);
        }
        Ulamek roznica;
        if(boki[1] >= boki[2]){
            roznica = boki[1] - boki[2];
        }else{
            roznica = boki[2] - boki[1];
        }
        if(boki[0] < (boki[1] + boki[2]) && boki[0] > (roznica)){
            cout << "TAK" << endl;
        }else{
            cout << "NIE" << endl;
        }

    }

}
