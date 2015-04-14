#include <cstdio>

int min( int a,int b ) { return a<b?a:b; }
int main() {
    
    int a[13] = {0};
    int N;
    char s[1000001];
    
    scanf("%d",&N);
    scanf("%s",s);
    for( int i=0; i<N; i++ ) {
        switch(s[i]) {
            case 'A' : a[1]++; break;
            case 'J' : a[10]++; break;
            case 'Q' : a[11]++; break;
            case 'K' : a[12]++; break;
            default : a[s[i]-'0']++; break;
        }
    }
    printf("%d",min(a[1],a[9])+min(a[2],a[8])+min(a[3],a[7])+min(a[4],a[6])+a[5]/2+a[10]/2+a[11]/2+a[12]/2);
    
    scanf(" ");
    return 0;
}
