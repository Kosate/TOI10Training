#include <cstdio>

int main() {
    
    int N,Q;
    
    scanf("%d%d",&N,&Q);
    for( int i=0; i<Q; i++ ) {
        int k; scanf("%d",&k);
        for( int j=1,c=0; ; j<<=1,c++ ) {
            if( k&j ) { printf("%d\n",N-c); break; }
        }
    }
    
    scanf(" ");
    return 0;
}
