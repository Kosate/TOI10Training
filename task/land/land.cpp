#include <cstdio>
#define Size 1001

int land[Size][Size] = {0};
int chec[Size][Size] = {0};

int main() {
    
    int N,M,K;
    int sol = 1000000001;
    
    scanf("%d%d%d",&N,&M,&K);
    for( int i=1; i<=N; ++i )
        for( int j=1; j<=M; ++j ) {
            int b; scanf("%d",&b);
            land[i][j] = b + land[i-1][j] + land[i][j-1] - land[i-1][j-1];
            b = b < 0 ? 0 : b;
            chec[i][j] = b + chec[i-1][j] + chec[i][j-1] - chec[i-1][j-1];
        }
    
    for( int i=K; i<=N; ++i )
        for( int j=K; j<=M; ++j ) {
            int b = land[i][j] - land[i-K][j] - land[i][j-K] + land[i-K][j-K];
            if( b == chec[i][j] - chec[i-K][j] - chec[i][j-K] + chec[i-K][j-K] ) {
                sol = b < sol ? b : sol;  
            }
        }
    
    printf("%d\n",sol == 1000000001 ? -1 : sol);
    
    return 0;
}
