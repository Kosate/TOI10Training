#include <cstdio>

int main() {
    
    int A,B;
    char C[11];
    int chosen[10] = {0};
    int check[10] = {0};
    
    scanf("%d%d%s",&A,&B,C);
    for( int i=0; C[i]; i++ ) chosen[ C[i]-'0' ]++;
    
    int res = 0;
    for( int i=A; i<=B; i++ ) {
        int j = i;
        for( int k=0; k<10; k++ ) check[k] = 0;
        //memset( check,0,sizeof(check) );
        while( j != 0 ) {
            check[ j%10 ]++;
            j /= 10;
        }
        for( int k=0; k<10; k++ ) {
            if( chosen[k] != 0 && check[k] != 0 ) { res++; break; }
        }
    }
    printf("%d",res);
    
    scanf(" ");
    return 0;
}
