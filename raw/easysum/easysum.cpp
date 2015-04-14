//LANG: C++
#include <cstdio>

int main() {
    
    int N;
    int sol = 0;
    
    scanf("%d",&N);
    for( int i=0; i<N; ++i ) {
        int a; scanf("%d",&a);
        sol += a;
    }
    printf("%d\n",sol);
    
    //scanf(" ");
    return 0;
}
