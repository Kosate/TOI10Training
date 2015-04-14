#include <cstdio>
#include <algorithm>

int t[100000];

bool comp( int a,int b ) {
	int ta = a,tb = b;
    int aa = 0,bb = 0;
    while( a ) { aa += a%10; a /= 10; }
    while( b ) { bb += b%10; b /= 10; }
    if( aa == bb ) return tb < ta;
    return aa < bb;
}

int main() {
    
    int N;
    
    scanf("%d",&N);
    for( int i=0; i<N; i++ ) scanf("%d",t+i);
    
    std::sort(t,t+N,comp);
    
    for( int i=0; i<N; i++ ) printf("%d\n",t[i]);
    
    scanf(" ");
    return 0;
}
