#include <cstdio>

int main() {
    
    int A,B;
    char C[11];
    int chosen = 0;
    int res = 0;
    
    scanf("%d%d%s",&A,&B,C);
    for( int i=0; C[i]; i++ ) chosen |= (1<<(C[i]-'0'));
    for( int i=A; i<=B; i++ ) {
        int j = i;
        int comp = 0;
        while( j ) {
            comp |= (1<<(j%10));
            j /= 10;
        }
        if( chosen & comp ) res++;
    }
    
    printf("%d",res);
    
    scanf(" ");
    return 0;
}
