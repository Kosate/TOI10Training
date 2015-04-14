#include <cstdio>

int main() {
    
    int N;
    char s[100001];
    int in,p,res = 0;
    
    scanf("%d%s",&N,s);
    for( int i=0; i<N; i++ ) {
        if( s[i] == '[' ) in = 1,p = 0;
        else if( s[i] == ']' ) {
            if( p&1 ) ;
            else if( p&2 ) res += 5;
            else if( p&4 ) res += 10;
            p = 0;
            in = 0;
        }
        else {
            if( in ) {
                switch(s[i]) {
                    case 'P' : p |= 4; break;
                    case 'S' : p |= 2; break;
                    case '-' : p |= 1; break;
                }
            } else {
                switch(s[i]) {
                    case 'P' : res += 10; break;
                    case 'S' : res += 5; break;
                }
            }
        }
    }
    printf("%d\n",res);
    
    scanf(" ");
    return 0;
}
