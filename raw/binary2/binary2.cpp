//LANG: C++
#include <cstdio>

char n[1000001];
char m[31];

int main() {
    
    int N,M;
    int hash = 0;
    int comp = 0;
    
    scanf("%d%d%s%s",&N,&M,n,m);
    
    for( int i=0; i<M; ++i ) {
        hash = (hash<<1) + (n[i] == '1');
        comp = (comp<<1) + (m[i] == '1');
    }
    
    int sol = hash == comp;
    for( int i=M; i<N; ++i ) {
        hash = ((hash&((1<<(M-1))-1))<<1) + (n[i] == '1');
        sol += (hash == comp);
    }
    printf("%d\n",sol);
    
    //scanf(" ");
    return 0;
}
