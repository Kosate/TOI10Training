//LANG : C++
#include <cstdio>

int p[1001][1001];

int main() {
    
    int S,E,K;
    
    scanf("%d%d%d",&S,&E,&K);
    printf("%d\n",E/K - (S-1)/K);
    
    //scanf(" ");
    return 0;
}
