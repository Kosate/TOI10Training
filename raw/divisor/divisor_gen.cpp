#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rnd() {
    return (rand()+((unsigned)rand()<<16))%2100000000;
}
int rd( int s,int e ) {
    return s+(rnd()%(e-s+1));
}
int min( int a,int b ) { return a <? b; }
int max( int a,int b ) { return a >? b; }

int main() {
    
    srand((unsigned)time(0));
    int n[10] = {100,1000,10000,100000,1000000,10000000,100000000,1000000000,1000000000,1000000000};
    
    for( int cas=1; cas<10; ++cas ) {
        char buffer[50];
        sprintf(buffer,"%d.in",cas+1);
        FILE *f = fopen(buffer,"w");
        
        if( cas >= 4 ) n[cas] -= rd(1,100000);
        int E = n[cas];
        
        int S = rd(0,E);
        while( S*(long long)S > E ) S = rd(0,E);
        
        int K = rd(1,E);
        while( K*(long long)K > E ) K = rd(1,E);
        
        fprintf(f,"%d %d %d\n",S,E,K);
                
    }
    
    return 0;
}
