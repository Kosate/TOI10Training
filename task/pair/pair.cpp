//LANG : C++
#include <cstdio>
#include <algorithm>

using namespace std;

int n[100000];
int m[100000];

int main() {
    
    int N;
    
    scanf("%d",&N);
    for( int i=0; i<N; ++i ) scanf("%d",n+i);
    for( int i=0; i<N; ++i ) scanf("%d",m+i);
    
    sort( n,n+N );
    sort( m,m+N );
    
    long long sol = 0;
    for( int i=0; i<N; ++i ) sol += abs( n[i]-m[i] );
    
    printf("%lld\n",sol);
    
    //scanf(" ");
    return 0;
}
