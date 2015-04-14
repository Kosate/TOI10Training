#include <cstdio>
#include <algorithm>

using namespace std;

int T[100000];

int main() {
    
    int N,Q;
    
    scanf("%d%d",&N,&Q);
    for( int i=0; i<N; i++ ) scanf("%d",&T[i]);
    
    sort( T,T+N );
    
    for( int i=0; i<Q; i++ ) {
        int q; scanf("%d",&q);
        printf("%d\n",N-(int)(lower_bound(T,T+N,q+1)-T));
    }
    
    scanf(" ");
    return 0;
}
