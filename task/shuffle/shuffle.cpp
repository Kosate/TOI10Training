#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

list <int> D;

int main() {
    
    int N;
    
    scanf("%d",&N);
    for( int i=0; i<N; ++i ) {
        int d; scanf("%d",&d);
        D.push_back(d);
    }
    
    for( int i=0; i<N-1; ++i ) {
        int a,b;
        if( i%2 == 0 ) {
            a = D.front(); b = D.back();
            D.pop_front(); D.pop_back();
            if( a > b ) swap( a,b );
            D.push_back( a );
            printf("%d ",b);
        } else {
            a = D.front(); b = D.back();
            D.pop_front(); D.pop_back();
            if( a > b ) swap( a,b );
            D.push_front( b );
            printf("%d ",a);
        }
    }
    printf("\n%d\n",D.front());
    
    
    //scanf(" ");
    return 0;
}
