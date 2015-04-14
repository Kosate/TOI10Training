#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

char table[1002][1002];
struct data {
    char s;
    int y,x;
    data(char a,int b,int c) { s=a; y=b; x=c; }
};
queue < pair< int,data > > Q;

int main() {
    
    int N,M,K;
    
    scanf("%d %d %d",&N,&M,&K);
    memset(table,'.',sizeof(table));
    for( int i=0; i<=N+1; i++ ) table[i][0] = table[i][M+1] = 'A';
    for( int i=0; i<=M+1; i++ ) table[0][i] = table[N+1][i] = 'A';
    for( int i=0; i<K; i++ ) {
        getchar();
        char a;
        int b,c,d; scanf("%c %d %d %d",&a,&b,&c,&d);
        Q.push( make_pair( d,data(a,b,c) ) );
        table[b][c] = a;
    }
    
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    while( !Q.empty() ) {
        int k = Q.front().first;
        int y = Q.front().second.y;
        int x = Q.front().second.x;
        char s = Q.front().second.s;
        Q.pop();
        if( k == 1 ) continue;
        for( int i=0; i<4; i++ ) {
            y -= dir[i][0];
            x -= dir[i][1];
            if( table[y][x] == '.' || table[y][x] > s ) {
                table[y][x] = s;
                Q.push( make_pair(k-1,data(s,y,x)) );
            }
            y += dir[i][0];
            x += dir[i][1];
        }
    }
    
    for( int i=1; i<=N; i++ ) {
        for( int j=1; j<=M; j++ ) printf("%c",table[i][j]);
        printf("\n");
    }
    
    scanf(" ");
    return 0;
}
