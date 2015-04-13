#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    
    int s[3];
    
    scanf("%d%d%d",&s[0],&s[1],&s[2]);
    
    sort( s,s+3 );
    
    int d = min( s[1]-s[0],s[2]-s[1] );
    
    int sol = s[0];
    while( sol == s[0] || sol == s[1] || sol == s[2] ) sol += d;
    printf("%d\n",sol);
    
    scanf(" ");
    return 0;
}
