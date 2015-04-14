#include <cstdio>
#include <vector>
#define Size 100001

using namespace std;

vector <int> G[Size];
int L[Size] = {0};

void label( int n,int l ) {
    if( L[n] ) return ;
    L[n] = l;
    for( int i=0; i<G[n].size(); i++ ) {
        label( G[n][i],l );
    }
}

int main() {
    
    int N,K,Q;
    
    scanf("%d%d%d",&N,&K,&Q);
    for( int i=0; i<K; i++ ) {
        int a,b; scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for( int i=1; i<=N; i++ ) {
        if( L[i] == 0 ) {
            label( i,i );
        }
    }
    
    for( int i=0; i<Q; i++ ) {
        int a,b; scanf("%d%d",&a,&b);
        printf("%s\n", L[a] == L[b] ? "yes" : "no");
    }
    
    scanf(" ");
    return 0;
}
