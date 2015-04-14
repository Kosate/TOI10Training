#include <cstdio>

int dp[501][501];

int max( int a,int b ) { return a > b ? a : b; }
int main() {
    
    int N,M;
    
    scanf("%d%d",&N,&M);
    for( int i=0; i<N; i++ )
        for( int j=1; j<=M; j++ ) scanf("%d",&dp[i][j]);
        
    for( int i=1; i<N; i++ )
        for( int j=1; j<=M; j++ ) dp[i][j] += max( dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]) );
    
    int sol = 0;
    for( int j=1; j<=M; j++ ) sol = max( sol,dp[N-1][j] );
    printf("%d",sol);
    
    scanf(" ");
    return 0;
}
