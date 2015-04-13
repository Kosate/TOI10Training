#include <cstdio>
#define Size 1005

const int HOR = 0; //horizontal
const int VER = 1; //vertical
const int inf = 1000000000;

char am[Size][Size];
int traveled[Size][Size] = {0};
int res = inf;
int N,M;

int min( int a,int b ) { return a < b ? a : b; }

void solved( int j,int i,int dir,int count ) {
    if( i == N ) {
        res = min( res,count );
        return ;
    }
    if( j < 0 || j >= M ) return ;
    if( am[i][j] == '#' ) return ;
    if( traveled[i][j] ) return ;
    traveled[i][j] = 1;
    solved( j+1,i,VER,count + (dir == HOR) );
    solved( j-1,i,VER,count + (dir == HOR) );
    solved( j,i+1,HOR,count + (dir == VER) );
    traveled[i][j] = 0;
}

int main() {
    
    scanf("%d%d",&N,&M);
    for( int i=0; i<N; i++ ) scanf("%s",am[i]);
    
    for( int j=0; j<M; j++ ) {
        solved( j,0,HOR,0 );
    }
    
    printf("%d",res);
    
    scanf(" ");
    return 0;
}
