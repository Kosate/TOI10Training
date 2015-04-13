#include <cstdio>
#define Size 15

int N,K;
bool check[Size+1] = {0};
int ans[Size] = {0};

void solve( int d ) {
    if( d == N ) {
        bool check = 1;
        for( int i=1; i<d; ++i ) check &= ( i%2 ? ans[i-1] < ans[i] : ans[i-1] > ans[i] );
        bool check2 = 1;
        for( int i=1; i<d; ++i ) check2 &= ( i%2 ? ans[i-1] > ans[i] : ans[i-1] < ans[i] );
        if( check || check2 ) {
            if( --K == 0 ) {
                for( int i=0; i<d; ++i ) printf("%d ",ans[i]);
                printf("\n");
            }
        }
    } else {
        for( int i=1; i<=N; ++i ) {
            if( !check[i] ) {
                check[i] = 1;
                ans[d] = i;
                solve( d+1 );
                check[i] = 0;
            }
        }
    }
}

int main() {
    
    scanf("%d%d",&N,&K);
    
    solve( 0 );
    
    scanf(" ");
    return 0;
}
