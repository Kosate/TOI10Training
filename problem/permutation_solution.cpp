#include <cstdio>
#define MAXN 51

int main() {
    
    int N,K;
    long long fac[MAXN];
    
    scanf("%d %d",&N,&K);
    fac[1] = 1;
    for( int i=2; i<=N; i++ ) {
        if( fac[i-1] == -1 ) { fac[i] = -1; continue; }
        fac[i] = fac[i-1]*(i-1);
        if( fac[i] > 1000000000 ) fac[i] = -1;
    }
    
    K--;
    int used[MAXN] = {0};
    for( int i=N; i>1; i-- ) {
        int div;
        if( fac[i] == -1 ) div = 0;
        else {
            div = K/fac[i];
            K %= fac[i];
        }
        int dd = -1;
        for( int j=1; j<MAXN; j++ ) {
            if( !used[j] ) {
                if( ++dd == div ) {
                    used[j] = 1;
                    printf("%d ",j);
                    break;
                }
            }
        }
    }
    for( int j=1; j<MAXN; j++ ) if( !used[j] ) { printf("%d\n",j); break; }
    
    scanf(" ");
    return 0;
}
