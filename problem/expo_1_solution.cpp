#include <cstdio>
#include <cstring>

int main() {
    
    int a,b;
    long long c = 1;
    
    scanf("%d %d",&a,&b);
    for( int i=0; i<b; i++ ) c *= a;
    printf("%lld",c);
    
    scanf(" ");
    return 0;
}
