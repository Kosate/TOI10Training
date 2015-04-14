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
    int n[10] = {5,7,12,15,17,20,23,25,25,25};
    
    for( int i=0; i<10; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        
        char s[51];
        int k = 0;
        
        int L = n[i],R = n[i];
        while( L || R ) {
            if( rand()%2 == 1 ) {
                if( L ) { s[k++] = '('; --L; }
            } else {
                if( R && L < R ) { s[k++] = ')'; --R; }
            }
        }
        int t = min(20,rd(n[i],n[i]*2));
        while( t-- ) {
            s[ rd(0,n[i]*2-1) ] = '_';
        }
        s[n[i]*2] = '\0';
        
        fprintf(f,"%d\n%s\n",n[i]*2,s);
                
    }
    
    return 0;
}
