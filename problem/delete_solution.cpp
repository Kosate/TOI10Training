#include <cstdio>
#define Size 100005

int fw[Size] = {0};
int num[Size];

int sum( int t ) {
    int s = 0;
    for( int i=t; i>0; i -= (i & (-i)) ) {
        s += fw[i];
    }
    return s;
}
void update( int t ) {
    for( int i=t; i<Size; i += (i & (-i)) ) {
        fw[i]++;
    }
}

int main() {
    
    int N,K;
    scanf("%d",&N);
    for( int i=1; i<=N; i++ ) scanf("%d",num+i);
    
    scanf("%d",&K);
    for( int i=0; i<K; i++ ) {
        int t; scanf("%d",&t);
        int k = sum(t)+t;
        while( num[k] == -1 && k <= N ) { 
            k++;
        }
        num[k] = -1;
        update( t );
    }
    
    for( int i=1; i<=N; i++ ) if( num[i] != -1 ) printf("%d ",num[i]); printf("\n");
   

    
    scanf(" ");
    return 0;
}
