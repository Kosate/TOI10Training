#include <cstdio>
#include <cstring>

int main() {
    
    int a,b;
    long long c = 1;
    
    scanf("%d %d",&a,&b);
    for( int i=0; i<b; i++ ) { 
        c *= a;
        c %= 1000000007;
    }
    printf("%lld",c);
    
    scanf(" ");
    return 0;
}
