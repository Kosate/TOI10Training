#include <cstdio>

int N;
char S[51];

int solve( int d,int stk ) {
    if( d == N ) {
        if( stk == 0 ) return 1;
        return 0;
    }
    if( S[d] == '(' ) return solve( d+1,stk+1 );
    else if( S[d] == ')' ) {
        if( stk > 0 ) return solve( d+1,stk-1 );
        return 0;
    } else {
        int ret = 0;
        ret += solve( d+1,stk+1 );
        if( stk > 0 ) ret += solve( d+1,stk-1 );
        return ret;
    }
}

int main() {
    
    scanf("%d%s",&N,S);
    
    printf("%d\n",solve(0,0));
    
    scanf(" ");
    return 0;
}
