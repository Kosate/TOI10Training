#include <cstdio>
#include <cstring>

char a[1500001],b[1500001];

int max(int a,int b) { return a>b?a:b; }
int main() {
    
    int n;
    int c[10] = {0};
    int s = 0;
    
    scanf("%d%s%s",&n,a,b);
    
    for( int i=0; i<n; i++ ) c[a[i]-'0']++;
    for( int i=0; i<n; i++ ) {
        if( c[b[i]-'0'] == 0 ) s++;
        else c[b[i]-'0']--;
    }
    printf("%d",s);
    
    scanf(" ");
    return 0;
}
