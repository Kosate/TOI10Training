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

int main() {
    
    srand((unsigned)time(0));
    
    int n[10] = {10,100,500,1000,1000,10000,21212,51212,100000,100000};
    
    for( int cas=0; cas<10; ++cas ) {
        char buffer[50];
        sprintf(buffer,"%d.in",cas+1);
        FILE *f = fopen(buffer,"w");
        
        
        if( cas < 5 ) {
            fprintf(f,"%d %d\n",n[cas],rd(1,1000));
            for( int i=0; i<n[cas]; ++i ) {
                fprintf(f,"%d\n",rd(0,1000));
            }
        } else {
            fprintf(f,"%d %d\n",n[cas],rd(1,1000000000));
            for( int i=0; i<n[cas]; ++i ) {
                fprintf(f,"%d\n",rd(0,1000000000));
            }
        }
                
    }
    
    return 0;
}
