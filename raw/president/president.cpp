//LANG : C++
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#define Size 100000

using namespace std;
typedef pair<int,int> par;

int p[Size];
vector < par > ans;

bool comp( par a,par b ) {
    if( a.second == b.second ) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    
    int N;
    
    scanf("%d",&N);
    for( int i=0; i<N; ++i ) scanf("%d",p+i);
    
    sort( p,p+N );
    
    int n = 1,S = p[0];
    for( int i=1; i<=N; ++i ) {
        if( S != p[i] || i == N ) {
            ans.push_back( make_pair(S,n) );
            S = p[i];
            n = 1;
        } else n++;
    }
    
    sort( ans.begin(),ans.end(),comp );
    for( vector< par >::iterator it = ans.begin(); it != ans.end(); ++it )
        printf("%d %d\n",it->first,it->second);
    
    //scanf(" ");
    return 0;
}
