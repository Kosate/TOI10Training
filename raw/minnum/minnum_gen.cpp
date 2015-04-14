#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long mmm[10] = {10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000LL};

int rnd() {
    return ((rand()+((unsigned)rand()<<16))%2100000000)%mmm[rand()%10];
}
int rd( int s,int e ) {
    return s+(rnd()%(e-s+1));
}
int min( int a,int b ) { return a <? b; }

int main() {
    
    srand((unsigned)time(0));
    int n[10] = {10,45,100,252,1000,10000,51515,81818,99999,100000};
    
    for( int cas=0; cas<10; ++cas ) {
        
        if( cas == 1 ) continue;
        
        char buffer[50];
        sprintf(buffer,"%d.in",cas+1);
        FILE *f = fopen(buffer,"w");
        
        n[cas]--;
        
        fprintf(f,"%d\n",n[cas]+1);
        if( cas%2 ) {
            fprintf(f,"%d",rd(cas,9));
            for( int i=0; i<n[cas]; ++i ) fprintf(f,"%d",rd(0,9) == 0 ? 0 : rd(cas,9));
        } else {
            fprintf(f,"%d",rd(1,9));
            for( int i=0; i<n[cas]; ++i ) fprintf(f,"%d",rd(0,9));
        }
        printf("\n");
                
    }
    
    return 0;
}
