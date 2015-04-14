//LANG : C++

#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <utility>
#define Size 300

using namespace std;

int N,M;
char dat[Size][Size+1];
int cool[Size][Size];
bool travel[Size][Size];
int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};

list < pair<pair<int,int>,int> > Q;
priority_queue < pair<int,pair<int,int> > > P;

int main() {
    
    scanf("%d%d",&N,&M);
    for( int i=0; i<N; ++i ) {
        scanf("%s",dat[i]);
        for( int j=0; j<M; ++j )
            if( dat[i][j] == '*' ) Q.push_back( make_pair(make_pair(i,j),0) );
    }
    
    memset( cool,-1,sizeof(cool) );
    memset( travel,0,sizeof(travel) );
    
    while( !Q.empty() ) {
        int y = Q.front().first.first;
        int x = Q.front().first.second;
        int t = Q.front().second;
        Q.pop_front();
        
        if( !( 0 <= x && x < M && 0 <= y && y < N ) ) continue;
        if( cool[y][x] != -1 ) continue;
        
        cool[y][x] = t;
        
        for( int i=0; i<4; ++i ) {
            Q.push_back( make_pair(make_pair(y+dir[i][0],x+dir[i][1]),t+1) );
        }
        
    }
    
    /*
    for( int i=0; i<N; ++i,printf("\n") )
        for( int j=0; j<M; ++j ) printf("%d ",cool[i][j]);
    */
    int ret;
    bool isRet = false;
    
    for( int i=0; i<N && P.empty(); ++i )
        for( int j=0; j<M; ++j )
            if( dat[i][j] == 'S' ) {
                P.push( make_pair(cool[i][j],make_pair(i,j)) );
                ret = cool[i][j];
            }
    
    while( !P.empty() ) {
        pair <int,pair<int,int> > tmp = P.top();
        int y = tmp.second.first;
        int x = tmp.second.second;
        int t = tmp.first;
        P.pop();
        
        if( travel[y][x] || dat[y][x] == '#' ) continue;
        
        travel[y][x] = 1;
        ret = min( ret,cool[y][x] );
        if( dat[y][x] == 'E' ) { isRet = 1; break; }
        
        //printf("%d %d %d %d\n",y,x,t,ret);
        
        for( int i=0; i<4; ++i ) {
            y += dir[i][0];
            x += dir[i][1];
            
            if( ( 0 <= x && x < M && 0 <= y && y < N ) )    
                P.push( make_pair( cool[y][x],make_pair(y,x) ) );
            
            y -= dir[i][0];
            x -= dir[i][1];
        }
        
    }
    
    if( isRet )
        if( ret == -1 ) printf("warm\n");
        else printf("%d\n",ret);
    else printf("no answer\n");
    
    scanf(" ");
    return 0;
}
