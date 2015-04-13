//LANG : C++
#include <cstdio>

int p[1001][1001];

int main() {
    
    int N,M;
    
    scanf("%d%d",&N,&M);
    for( int i=1; i<=N; ++i )
        for( int j=1; j<=M; ++j ) {
            scanf("%d",&p[i][j]);
            p[i][j] += p[i-1][j] < p[i][j-1] ? p[i][j-1] : p[i-1][j];
        }
    
    printf("%d\n",p[N][M]);
    
    //scanf(" ");
    return 0;
}
