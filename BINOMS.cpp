// 2015-11-19
// DZIAŁA

//#define DEBUG

#include <bits/stdc++.h>

using namespace std;

int main(){
    /*
    tests - liczba testów
    mian1 - wiekszy czynnik mianownika
    mian2 - mniejszy czynnik mianownika
    n - licznosc zbioru
    k - licznosc podzbioru
    */
    int tests, mian1, mian2, n, k;
    scanf("%d", &tests);
    for(int i = 0; i < tests; ++i){
        unsigned long long wynik = 1;
        
        // wczytanie wejscia
        scanf("%d %d", &n, &k); 
        
        // z definicji
        if(k == 0 || k == n){
            printf("1\n");
            continue;
        }
        
        // znajdź mian1 i mian2
        mian1 = max(n - k, k);
        mian2 = min(n - k, k);
        
        #ifdef DEBUG
        printf("n: %d k: %d\n", n, k);
        printf("m1: %d m2: %d\n", mian1, mian2);
        #endif
        
        /* 
        Ponizej wykorzystuje obserwacje, ze czynniki z mianownika
        z przedzialu [1, mian1] i z mianownika z przedzialu [1, mian1] 
        skracaja sie.
        */
        int wgore = mian1 + 1; // odpowiada za mnozenie czynnikow *licznika*, z przedzialu [mian1 + 1, k]
        int wdol = 2; // odpowiada za mnozenie czynnikow *mianownika* z przedzialu [2, mian2]
        while(wgore <= n || wdol <= mian2){
            if(wgore <= n){
                wynik *= wgore;
                
                #ifdef DEBUG
                printf("w1: %llu wg: %d\n", wynik, wgore);
                #endif // DEBUG
                
                ++wgore;
            }
            if (!(wynik % wdol) && wdol <= mian2){ 
                /*
                Dzielenia dokonuje tylko, gdy daje wynik calkowity
                w przeciwnym razie czekam az mnozenie wgore
                doprowadzi do takiej sytuacji
                */
                
                wynik /= wdol;
                
                #ifdef DEBUG
                printf("w1: %llu wd: %d\n", wynik, wdol);
                #endif // DEBUG
                
                ++wdol;
            }
        }
        // wypisz wynik
        printf("%llu\n", wynik);
    }
}
