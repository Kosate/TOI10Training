#include <cstdio>
#include <vector>
#define Size 100001

using namespace std;

vector <int> G[Size];
int travel[Size] = {0};

void flow( int i,int k ) {
    if( travel[i] ) return ;
    travel[i] = k;
    for( vector<int>::iterator it = G[i].begin(); it != G[i].end(); ++it )
        flow( *it,k );
}

int main() {
    
    int N,M,Q;
    
    scanf("%d%d%d",&N,&M,&Q);
    for( int i=0; i<M; ++i ) {
        int s,e;
        scanf("%d%d",&s,&e);
        G[s].push_back(e);
        G[e].push_back(s);
    }
    int k = 0;
    for( int i=1; i<=N; ++i ) {
        if( !travel[i] ) flow( i,++k );
    }
    
    for( int i=0; i<Q; ++i ) {
        int s,e;
        scanf("%d%d",&s,&e);
        printf("%s\n",travel[s] == travel[e] ? "yes" : "no");
    }
    
    //scanf(" ");
    return 0;
}
