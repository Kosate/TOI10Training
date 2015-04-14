#include <cstdio>
#include <cstring>

int main() {
    
    int N;
    char a[101],b[101],c[101];
    int lena,lenb;
    int s;
    
    scanf("%d %s %s",&N,a,b);
    lena = strlen(a); lenb = strlen(b);
    for( int i=0; i<N; i++ ) {
        s = 0;
        scanf("%s",c);
        for( int j=0; c[j]; j++ ) {
            int cc = 1,k;
            for( k=0; c[j+k] && a[k]; k++ ) {
                if( c[j+k] != a[k] ) { cc = 0; break; }
            }
            if( cc && k == lena ) s += 2;
            cc = 1;
            for( k=0; c[j+k] && b[k]; k++ ) {
                if( c[j+k] != b[k] ) { cc = 0; break; }
            }
            if( cc && k == lenb ) s -= 1;
        }
        printf("%d\n",s);
    }
    
    
    scanf(" ");
    return 0;
}
