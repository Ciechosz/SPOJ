// 2015-11-19
// DZIAŁA

#include <bits/stdc++.h>

using namespace std;

//#define DEBUG

int main(){
    int tests, mian1, mian2, n, k;
    scanf("%d", &tests);
    for(int i = 0; i < tests; ++i){
            unsigned long long wynik = 1;
        scanf("%d %d", &n, &k);
        if(k == 0 || k == n){
            printf("1\n");
            continue;
        }
        mian1 = max(n - k, k);
        mian2 = min(n - k, k);
        #ifdef DEBUG
        printf("n: %d k: %d\n", n, k);
        printf("m1: %d m2: %d\n", mian1, mian2);
        #endif
        int wgore = mian1 + 1;
        int wdol = 2;
        while(wgore <= n || wdol <= mian2){
            if(wgore <= n){
                wynik *= wgore;
                #ifdef DEBUG
                printf("w1: %llu wg: %d\n", wynik, wgore);
                #endif // DEBUG
                ++wgore;
            }
            if (!(wynik % wdol) && wdol <= mian2){
                wynik /= wdol;
                #ifdef DEBUG
                printf("w1: %llu wd: %d\n", wynik, wdol);
                #endif // DEBUG
                ++wdol;
            }
        }
        printf("%llu\n", wynik);

    }
}
