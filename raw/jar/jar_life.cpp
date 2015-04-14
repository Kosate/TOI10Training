// LANG : C++

#include "cstdio"
#include "cstdlib"
#include "cstring"

#include "list"
#include "deque"
#include "queue"
#include "stack"
#include "vector"
#include "utility"
#include "algorithm"

using namespace std;

int _max( int a , int b ){ return a > b ? a : b; }

int main(int argc, char const *argv[]){
	
	int n , w , v ;
	int dp[ 1001 ] = {0};
	
	scanf("%d%d",&n,&v);
	
	for(int i=0;i<n;i++){
		scanf("%d",&w);
		for(int j=v;j>w;j--)
			if( dp[ j-w ] )
				dp[ j ] = 1 ;
		dp[ w ] = 1 ;
	}
	
	for(int i=v;i>0;i--)
		if( dp[i] ){
			printf("%d",i);
			break ; 
		}
	return 0 ;

}


