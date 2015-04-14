#include <cstdio>

int main() {
    
    int N;
    
    scanf("%d",&N);
    N %= 360;
    printf("%d", N < 180 ? N : 360-N );
    
    scanf(" ");
    return 0;
}
