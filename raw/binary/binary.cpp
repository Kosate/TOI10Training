//LANG: C++
#include <cstdio>

int main() {
    
    int S,E,N;
    
    scanf("%d%d%d",&S,&E,&N);
    for( ; S<=E; ++S ) {
        if( S & (1<<(N-1)) ) {
            int j = 1;
            while( j <= S ) j <<= 1; j >>= 1;
            while( j ) {
                printf("%d",!(!(S&j)));
                j >>= 1;
            }
            printf("\n");
        }
    }
    
    //scanf(" ");
    return 0;
}
