#include <cstdio>

int A,B,C,N;
char ans[50];

void solve( int n ) {

    if( n == N ) {
        int check = 1;
        
        int cc[3] = {0};
        int crr[3] = {0};
        for( int i=0; i<n; i++ ) {
            
            if( ans[i] == '(' ) { 
                ++crr[0]; 
                if( ++cc[0] > A )       { check = 0; break; } 
            }
            if( ans[i] == '[' ) { 
                if( crr[0] )            { check = 0; break; }
                ++crr[1]; 
                if( ++cc[1] > B )       { check = 0; break; } 
            }
            if( ans[i] == '{' ) { 
                if( crr[0] || crr[1] )  { check = 0; break; }
                ++crr[2]; 
                if( ++cc[2] > C )       { check = 0; break; } 
            }
            
            if( ans[i] == ')' ) {
                if( --crr[0] < 0 )      { check = 0; break; }
            }
            if( ans[i] == ']' ) {
                if( crr[0] )            { check = 0; break; }
                if( --crr[1] < 0 )      { check = 0; break; }
            }
            if( ans[i] == '}' ) {
                if( crr[0] || crr[1] )  { check = 0; break; }
                if( --crr[2] < 0 )      { check = 0; break; }
            }
        }
        
        if( check ) {
            ans[n] = '\0';
            printf("%s\n",ans);
        }
        return ;
    }
    
    char S[7] = "{[()]}";
    
    for( int i=0; i<6; i++ ) {
        ans[n] = S[i];
        solve( n+1 );
    }
    
}

int main() {
    
    scanf("%d%d%d",&A,&B,&C);
    
    N = (A+B+C)*2;
    
    solve( 0 );
    
    scanf(" ");
    return 0;
}
