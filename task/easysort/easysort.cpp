//LANG : C++
#include <cstdio>
#include <algorithm>

using namespace std;

int d[100000];
int K;

bool comp( int a,int b ) {
    if( a%K == b%K ) return a < b;
    return a%K < b%K;
}

int main() {
    
    int N;
    
    scanf("%d%d",&N,&K);
    for( int i=0; i<N; ++i ) scanf("%d",d+i);
    
    sort( d,d+N,comp );
    
    for( int i=0; i<N; ++i ) printf("%d\n",d[i]);
    
    scanf(" ");
    return 0;
}
