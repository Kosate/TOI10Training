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
        if( am[1][j] != '#' ) {
            dp[1][j][VER] = 0;
            dp[1][j][HOR] = 1;
        }
    }
        
    for( int i=1; i<=N; i++ ) {
        for( int j=1; j<=M; j++ ) {
            if( am[i][j] == '#' ) continue;
            for( int k=i-1; dp[k][j][VER] < inf; k-- ) {
                dp[i][j][VER] = min( dp[i][j][VER],dp[k][j][VER] );
                dp[i][j][HOR] = min( dp[i][j][HOR],dp[k][j][VER]+1 );
            }
            for( int k=j-1; dp[i][k][HOR] < inf; k-- ) {
                dp[i][j][VER] = min( dp[i][j][VER],dp[i][k][HOR]+1 );
                dp[i][j][HOR] = min( dp[i][j][HOR],dp[i][k][HOR] );
            }
        }
        for( int j=M; j>=1; j-- ) {
            if( am[i][j] == '#' ) continue;
            for( int k=j+1; dp[i][k][HOR] < inf; k++ ) {
                dp[i][j][VER] = min( dp[i][j][VER],dp[i][k][HOR]+1 );
                dp[i][j][HOR] = min( dp[i][j][HOR],dp[i][k][HOR] );
            }
        }
    }
    
    int res = inf;
    for( int j=1; j<=M; j++ ) res = min( res,dp[N][j][VER] );
    
    printf("%d",res);
    
    scanf(" ");
    return 0;
}
