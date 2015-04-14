#include <cstdio>

int S[1002][1002];
int N;

int check( int k ) {
    for( int i=k; i<=N; i++ ) {
        for( int j=k; j<=N; j++ ) {
            int c = S[i][j] + S[i-k][j-k] - S[i-k][j] - S[i][j-k];
            if( c == 0 || c == k*k ) return 1;
        }
    }
    return 0;
}

int main() {
    
    scanf("%d",&N);
    for( int i=1; i<=N; i++ ) {
        char k[1002];
        scanf("%s",k+1);
        for( int j=1; j<=N; j++ ) {
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + (k[j] == '1');
        }
    }
    
    int lo = 1,hi = N;
    while( lo <= hi ) {
        int cen = (lo+hi)/2;
        if( check(cen) ) lo = cen+1;
        else hi = cen-1;
    }
    printf("%d",hi);
    
    scanf(" ");
    return 0;
}
