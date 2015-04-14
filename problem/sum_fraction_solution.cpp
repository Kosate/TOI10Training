#include <cstdio>

typedef long long llint;

llint gcd( llint a,llint b ) {
    return a%b == 0 ? b : gcd(b,a%b);
}

int main() {
    
    int in[5];
    llint A = 0;
    llint B = 1;
    for( int i=0; i<5; i++ ) {
        scanf("%d",&in[i]);
        B = (B*in[i])/gcd(B,in[i]);
    }
    for( int i=0; i<5; i++ ) {
        A += B/in[i];
    }
    int d = gcd(A,B);
    A /= d; B /= d;
    printf("%lld %lld\n",A,B);
    
    scanf(" ");
    return 0;
}
