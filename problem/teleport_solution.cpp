#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

pair< int,int > T[1000001];

int main() {
    
    int N,M;
    scanf("%d %d",&N,&M);
    
    for( int i=0; i<N; i++ ) {
        for( int j=0; j<M; j++ ) {
            int t; scanf("%d",&t);
            T[t] = make_pair(i,j);
        }
    }
    
    int m = 0;
    for( int i=1; i<N*M; i++ ) {
        m += abs(T[i].first - T[i-1].first) + abs(T[i].second - T[i-1].second);
    }
    printf("%d",m);
    
    scanf(" ");
    return 0;
}

