#include <cstdio>

int A,B,C,N,K;
char ans[50];
char stack[50];
int is = 0;

void solve( int n,int a,int b,int c ) {

    if( n == N ) {
        ans[n] = '\0'; printf("%s\n",ans);
        return ;
    }
    
    int priority = 3;
    if( is > 0 ) {
        if( stack[is-1] == '{' ) priority = 3;
        if( stack[is-1] == '[' ) priority = 2;
        if( stack[is-1] == '(' ) priority = 1;
    }
    
    if( priority >= 1 && a != 0 ) { stack[is++] = ans[n] = '('; solve( n+1,a-1,b,c ); --is; }
    if( priority >= 2 && b != 0 ) { stack[is++] = ans[n] = '['; solve( n+1,a,b-1,c ); --is; }
    if( priority >= 3 && c != 0 ) { stack[is++] = ans[n] = '{'; solve( n+1,a,b,c-1 ); --is; }
    
    if( is > 0 ) {
        if( priority == 1 ) { --is; ans[n] = ')'; solve( n+1,a,b,c ); stack[is++] = '('; }
        if( priority == 2 ) { --is; ans[n] = ']'; solve( n+1,a,b,c ); stack[is++] = '['; }
        if( priority == 3 ) { --is; ans[n] = '}'; solve( n+1,a,b,c ); stack[is++] = '{'; }
    }
    
}

int main() {
    
    scanf("%d%d%d",&A,&B,&C);
    
    N = (A+B+C)*2;
    
    solve( 0,A,B,C );
    
    scanf(" ");
    return 0;
}
