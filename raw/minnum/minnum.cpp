//LANG : C++
#include <cstdio>
#include <algorithm>

using namespace std;

char d[100001];

int main() {
    
    int N;
    scanf("%d%s",&N,d);

    sort( d,d+N );
    
    int prefix = -1;
    for( int i=0; i<N; ++i ) if( d[i] != '0' ) { prefix = i; break; }
    printf("%c",d[prefix]);
    for( int i=0; i<N; ++i ) if( i != prefix ) printf("%c",d[i]);
    printf("\n");
    
    //scanf(" ");
    return 0;
}
