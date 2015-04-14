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
    int n[10] = {10,45,100,252,100,500,777,818,999,1000};
    int m[10] = {10,50,100,212,500,200,617,818,999,1000};
    
    for( int i=0; i<10; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        
        
        fprintf(f,"%d %d\n",n[i],m[i]);
        for( int j=0; j<n[i]; ++j,fprintf(f,"\n") )
            for( int k=0; k<m[i]; ++k ) fprintf(f,"%d ",rd(0,1000));
                
    }
    
    return 0;
}
