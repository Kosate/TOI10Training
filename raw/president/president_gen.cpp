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

int data[100000];

int main() {
    
    srand((unsigned)time(0));
    int n[10] = {100,512,1024,5555,10121,31717,55555,76977,99999,100000};
    
    for( int i=0; i<10; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        
        for( int j=0; j<n[i]; ++j ) data[j] = rd(1,1000000000);
        
        fprintf(f,"%d\n",n[i]);
        for( int j=0; j<n[i]; ++j )
            fprintf(f,"%d\n",data[ rd(0,n[i]-1) ]);
                
    }
    
    return 0;
}
