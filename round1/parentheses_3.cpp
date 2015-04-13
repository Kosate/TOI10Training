#include <cstdio>

int A,B,C,N,K;
char ans[50];

void solve( int n,int a,int b,int c,int pa,int pb,int pc ) {

    if( n == N ) {
        ans[n] = '\0'; printf("%s\n",ans);
        return ;
    }
    
    int priority = 3;
    if( pb != 0 ) priority = 2;
    if( pa != 0 ) priority = 1;
    
    if( pa != 0 ) { ans[n] = ')'; solve(n+1,a,b,c,pa-1,pb,pc);  }
    else if( pb != 0 ) { ans[n] = ']'; solve(n+1,a,b,c,pa,pb-1,pc); }
    else if( pc != 0 ) { ans[n] = '}'; solve(n+1,a,b,c,pa,pb,pc-1); }
    
    if( priority >= 3 && c != 0 ) { ans[n] = '{'; solve(n+1,a,b,c-1,pa,pb,pc+1); }
    if( priority >= 2 && b != 0 ) { ans[n] = '['; solve(n+1,a,b-1,c,pa,pb+1,pc); }
    if( priority >= 1 && a != 0 ) { ans[n] = '('; solve(n+1,a-1,b,c,pa+1,pb,pc); }
    
}

int main() {
    
    scanf("%d%d%d",&A,&B,&C);
    
    N = (A+B+C)*2;
    
    solve( 0,A,B,C,0,0,0 );
    
    scanf(" ");
    return 0;
}
