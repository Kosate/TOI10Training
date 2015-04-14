#include <cstdio>

int N,M;

void prev(int n,long long num,int deep ) {
    if( deep == M ) { 
        if( n == 0 ) { 
            printf("%lld\n",num);
        }
        return ;
    }
    
    if( deep > M ) return ;
    for( int i=(num == 0)?1:0; i<=n && i<10; i++ ) {
        prev( n-i,num*10+i,deep+1 );
    }
}

int main() {
    
    scanf("%d%d",&N,&M);
    
    prev( N,0,0 );
    
    scanf(" ");
    return 0;
}
