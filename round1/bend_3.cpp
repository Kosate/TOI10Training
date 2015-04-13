#include <cstdio>
#define Size 1005

const int HOR = 0; //horizontal
const int VER = 1; //vertical
const int inf = 1000000000;

int dp[Size][Size][2] = {0};
char am[Size][Size];

int min( int a,int b ) { return a < b ? a : b; }

int main() {
    
    int N,M;
    
    scanf("%d%d",&N,&M);
    for( int i=1; i<=N; i++ ) scanf("%s",am[i]+1);
    
    for( int i=0; i<=N+1; i++ )
        for( int j=0; j<=M+1; j++ ) 
            dp[i][j][0] = dp[i][j][1] = inf;
        
    for( int j=1; j<=M; j++ ) {
        dp[0][j][VER] = 0;
    }
        
    for( int i=1; i<=N; i++ ) {
        for( int j=1; j<=M; j++ ) {
            if( am[i][j] == '#' ) continue;
            dp[i][j][VER] = min( min( dp[i][j][VER],dp[i][j-1][HOR]+1 ),min( dp[i-1][j][VER],dp[i-1][j][HOR]+1 ) );
            dp[i][j][HOR] = min( min( dp[i][j][HOR],dp[i-1][j][VER]+1 ),min( dp[i][j-1][HOR],dp[i][j-1][VER]+1 ) );
        }
        for( int j=M; j>=1; j-- ) {
            if( am[i][j] == '#' ) continue;
            dp[i][j][HOR] = min( min( dp[i][j][HOR],dp[i-1][j][VER]+1 ),min( dp[i][j+1][HOR],dp[i][j+1][VER]+1 ) );
        }
    }
    
    int res = inf;
    for( int j=1; j<=M; j++ ) res = min( res,dp[N][j][VER] );
    
    printf("%d",res);
    
    scanf(" ");
    return 0;
}
