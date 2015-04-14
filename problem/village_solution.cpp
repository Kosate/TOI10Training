#include <cstdio>

int map[22][22];
int block[22][22] = {0};
int sol = 1000000000;
int N,M,K;

void calc( int x,int y,int res,int deep ) {
    if( K == deep ) {    
        sol = res < sol ? res : sol;
        return ;
    }
    if( x > M ) { y++; x = 1; }
    if( y > N ) return ;
    if( block[y][x] == 0 ) {            
        int dir[9][2] = {{-1,0},{0,-1},{1,0},{0,1},{-1,1},{1,-1},{-1,-1},{1,1},{0,0}};
        for( int i=0; i<9; i++ ) block[y+dir[i][0]][x+dir[i][1]]++;
        calc( x+1,y,res*map[y][x],deep+1 );
        for( int i=0; i<9; i++ ) block[y+dir[i][0]][x+dir[i][1]]--;
    }
    calc( x+1,y,res,deep );
    
}

int main() {
    
    scanf("%d%d%d",&N,&M,&K);
    for( int i=1; i<=N; i++ ) {
        for( int j=1; j<=M; j++ ) scanf("%d",&map[i][j]);
    }
    
    calc( 1,1,1,0 );
    printf("%d",sol);
    
    scanf(" ");
    return 0;
}
