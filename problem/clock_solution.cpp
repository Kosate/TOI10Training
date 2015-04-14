#include <cstdio>

int abs( int x ) { return x < 0 ? -x : x; }
int main() {
    
    int h,m;
    
    scanf("%d%d",&h,&m);
    if( h >= 12 ) h -= 12;
    
    int dist = abs( ((h*60)+m) - m*12 );
    if( dist > 360 ) dist = 720 - dist;
    if( dist == 360 ) dist = 0;
    
    printf("%d",dist);
    
    return 0;
}
