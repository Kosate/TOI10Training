#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long mmm[10] = {10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000LL};

int rnd() {
    return ((rand()+((unsigned)rand()<<16))%2100000000);
}
int rd( int s,int e ) {
    return s+(rnd()%(e-s+1));
}
int min( int a,int b ) { return a <? b; }

int main() {
    
    srand((unsigned)time(0));
    
    for( int i=0; i<10; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        
        int a[4];
        int s = rd(1,100);
        int d = rd(1,25);
        for( int i=0; i<4; ++i ) a[i] = s + d*i;
        for( int i=0; i<10; ++i ) {
            int aa = rd(0,3); int bb = rd(0,3);
            int tmp = a[aa];
            a[aa] = a[bb];
            a[bb] = tmp;
        }
        for( int i=0; i<3; ++i ) fprintf(f,"%d ",a[i]);
        fprintf(f,"\n");
                
    }
    
    return 0;
}
