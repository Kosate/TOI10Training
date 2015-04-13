//LANG : C++

#include <cstdio>
#define Size 100001

int d[Size];
long long s[Size] = {0};

void update( int x,int val ) {
    for( ; x<Size; x += x&-x ) s[x] += val;
}

long long query( int x ) {
    long long ret = 0;
    for( ; x>0; x -= x&-x ) ret += s[x];
    return ret;
}

int main() {
    
    int N,Q;
    scanf("%d%d",&N,&Q);
    for( int i=1; i<=N; ++i ) scanf("%d",&d[i]);
    
    for( int i=0; i<Q; ++i ) {
        int q,s,e; scanf("%d",&q);
        if( q == 1 ) {
            scanf("%d",&s);
            printf("%lld\n",query(s)+d[s]);
        } else {
            scanf("%d%d",&s,&e);
            update(s,1);
            update(e+1,-1);
        }
    }
    
    //scanf(" ");
    return 0;
}
