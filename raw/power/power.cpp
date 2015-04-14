//LANG: C++
#include <cstdio>

typedef long long llint;

const llint mod = 1000000007;
llint v[31];

int main() {
    
    int X,Y,i,j;
    llint sol = 1;
    
    scanf("%d%d",&X,&Y);
    v[0] = X;
    for( i=1,j=2; j<=Y; ++i,j<<=1 ) v[i] = (v[i-1]*v[i-1])%mod;
    for( j>>=1,--i; j; --i,j>>=1 ) {
        if( Y&j ) sol = (sol*v[i])%mod;
    }
    
    printf("%lld\n",sol);
    
    //scanf(" ");
    return 0;
}
