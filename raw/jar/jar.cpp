#include <cstdio>
#include <cstring>
#define Size 1001

int dp[Size] = {0};
int tmp[Size] = {0};

int main() {
    
    int N,V;
    dp[0] = 1;
    
    scanf("%d%d",&N,&V);
    for( int i=0; i<N; ++i ) {
        int vi; scanf("%d",&vi);
        memset( tmp,0,sizeof(tmp) );
        for( int j=vi; j<Size; ++j ) tmp[j] |= dp[j-vi];
        for( int j=0; j<Size; ++j ) dp[j] |= tmp[j];
    }
    
    while( !dp[V] ) --V;
    printf("%d\n",V);
    
    return 0;
}
