#include <cstdio>

typedef long long llint;

llint b[1024] = {0};

int main() {
    
    int N;
    
    scanf("%d",&N);
    for( int i=0; i<N; ++i ) {
        llint d; scanf("%lld",&d);
        int bit = 0;
        while( d ) {
            bit |= (1<<(d%10));
            d /= 10;
        }
        b[bit]++;
    }
    
    llint sol = 0;
    for( int i=1; i<1024; ++i ) {
        for( int j=i+1; j<1024; ++j ) {
            if( i & j ) {
                sol += b[i]*b[j];
            }
        }
        if( b[i] ) sol += ( b[i]*(b[i]-1) )/2;
    }
    printf("%lld",sol);
    
    scanf(" ");
    return 0;
}
