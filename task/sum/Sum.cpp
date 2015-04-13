#include <cstdio>
#define Size 1000001

long long V[Size];

int main() {
    
    int N,Q;
    
    scanf("%d%d",&N,&Q);
    for( int i=1; i<=N; ++i ) {
        scanf("%lld",V+i);
        V[i] += V[i-1];
    }
    for( int i=0; i<Q; ++i ) {
        int s,e; scanf("%d%d",&s,&e);
        printf("%lld\n",V[e]-V[s-1]);
    }
    
    //scanf(" ");
    return 0;
}
