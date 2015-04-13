#include <cstdio>
#include <cstring>
#include <cstdlib>
#define Size 1003

using namespace std;

char nine[Size][Size];
char peak[Size][Size];

int sortstr( const void *a,const void *b ) { return strcmp( (char *)a,(char *)b ); }

int main() {
    
    int N;
    
    scanf("%d",&N);
    for( int i=0; i<N; i++ ) {
        scanf("%s",nine[i]);
        for( int j=0; j<N; j++ ) peak[j][i] = nine[i][j];
    }
    
    qsort( nine,N,sizeof(nine[0]),sortstr );
    qsort( peak,N,sizeof(peak[0]),sortstr );
    
    char comp[Size] = "-";
    int count = 0;
    int res1 = 1,res2 = 1;
    
    for( int i=0; i<N; i++ ) {
        if( strcmp(comp,nine[i]) == 0 ) {
            if( ++count > res1 ) res1 = count;
        } else {
            strcpy(comp,nine[i]);
            count = 1;
        }
    }
    
    count = 0;
    strcpy(comp,"-");
    for( int i=0; i<N; i++ ) {
        if( strcmp(comp,peak[i]) == 0 ) {
            if( ++count > res2 ) res2 = count;
        } else {
            strcpy(comp,peak[i]);
            count = 1;
        }
    }
    
    if( res1 > res2 )       printf("%d\nnine",N-res1);
    else if( res1 < res2 )  printf("%d\npeak",N-res2);
    else                    printf("%d\nboth",N-res1);
    
    scanf(" ");
    return 0;
}
