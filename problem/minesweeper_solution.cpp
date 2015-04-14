#include <cstdio>

int main() {
    
    int N,M;
    char map[102][102];
    
    scanf("%d%d",&N,&M);
    for( int i=1; i<=N; i++ )
        scanf("%s",map[i]+1);
    for( int i=0; i<N; i++ ) {
        for( int j=0; j<M; j++ ) {
            int s = 0;    
            for( int l=0; l<3; l++ )
                for( int m=0; m<3; m++ ) s += (map[i+l][j+m] == 'X');
            printf("%c", map[i+1][j+1] == 'X' ? 'X' : s+'0');
        }
        printf("\n");
    }
    
    scanf(" ");
    return 0;
}
