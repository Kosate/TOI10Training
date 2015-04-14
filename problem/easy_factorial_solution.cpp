#include <cstdio>

int main() {
    
    int n,r;
    int i,j;
    long long sol = 1;
    
    scanf("%d%d",&n,&r);
    if( n-r > r ) r = n-r;
    
    for( i=r+1,j=2; i<=n; i++ ) {
        sol *= i;
        if( sol%j == 0 && j <= n-r ) sol /= j++;
    }
    for( ; j<=n-r; j++ ) sol /= j;
    printf("%lld",sol);
    
    scanf(" ");
    return 0;
}
