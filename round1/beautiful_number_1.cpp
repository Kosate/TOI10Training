#include <cstdio>

int main() {
    
    int A,B;
    char chosen[11];
    
    scanf("%d%d%s",&A,&B,chosen);
    
    int res = 0;
    for( int i=A; i<=B; i++ ) {
        int check = 0;
        int j = i;
        while( j != 0 ) {
            for( int k=0; chosen[k]; k++ ) {
                if( j%10 == chosen[k]-'0' ) { check = 1; break; }
            }
            if( check != 0 ) break;
            j /= 10;
        }
        if( check != 0 ) res++;
    }
    printf("%d",res);
    
    scanf(" ");
    return 0;
}
