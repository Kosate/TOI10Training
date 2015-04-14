#include <cstdio>

int main() {
    
    int N;
    
    scanf("%d",&N);
    for( int i=0; i<N; i++ ) {
        int k; scanf("%d",&k);
        int c = 1;
        for( int i=2; i*i<=k; i++ ) if( k%i == 0 ) { c = 0; break; }
        printf("%s\n", c && k != 1 ? "yes" : "no");
    }
    
    scanf(" ");
    return 0;
}
