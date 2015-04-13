#include <cstdio>
#include <cstring>
#define Size 1003

using namespace std;

char nine[Size][Size];
char peak[Size][Size];

int main() {
    
    int N;
    
    scanf("%d",&N);
    for( int i=0; i<N; i++ ) {
        scanf("%s",nine[i]);
        for( int j=0; j<N; j++ ) peak[j][i] = nine[i][j];
    }
    
    int count;
    int res1 = 1,res2 = 1;
    
    for( int i=0; i<N; i++ ) {
        count = 0;
        for( int j=0; j<N; j++ ) {
            if( strcmp(nine[i],nine[j]) == 0 ) count++;
        }
        if( count > res1 ) res1 = count;
    }
    
    for( int i=0; i<N; i++ ) {
        count = 0;
        for( int j=0; j<N; j++ ) {
            if( strcmp(peak[i],peak[j]) == 0 ) count++;
        }
        if( count > res2 ) res2 = count;
    }
    
    if( res1 > res2 )       printf("%d\nnine",N-res1);
    else if( res1 < res2 )  printf("%d\npeak",N-res2);
    else                    printf("%d\nboth",N-res1);
    
    scanf(" ");
    return 0;
}
