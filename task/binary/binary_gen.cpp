#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector <int> D;
vector < pair<int,int> > S;

int rnd() {
    return (rand()+((unsigned)rand()<<16))%2100000000;
}
int rd( int s,int e ) {
    return s+(rnd()%(e-s+1));
}
int min( int a,int b ) { return a <? b; }

int main() {
    
    srand((unsigned)time(0));
    
    for( int cas=0; cas<10; ++cas ) {
        char buffer[50];
        sprintf(buffer,"%d.in",cas+1);
        FILE *f = fopen(buffer,"w");
        
        int c = cas+6;
        
        int e = 1<<c;
        int s = rd( 1,e );
        
        fprintf( f,"%d %d %d\n",s,e,rd(1,c+1));
    }
    
    return 0;
}
