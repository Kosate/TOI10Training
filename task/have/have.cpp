#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];

int main() {
    
    int N,Q;
    
    scanf("%d%d",&N,&Q);
    for( int i=0; i<N; ++i ) scanf("%d",a+i);
    
    sort( a,a+N );
    
    for( int i=0; i<Q; ++i ) {
        int qi; scanf("%d",&qi);
        printf("%s\n", a[ (int)(lower_bound(a,a+N,qi) - a) ] == qi ? "yes" : "no" );
    }
    
    scanf(" ");
    return 0;
}
