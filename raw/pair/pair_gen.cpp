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
    
    for( int i=0; i<10; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        
        fprintf(f,"%d\n",n[i]);
        for( int j=0; j<n[i]*2; ++j )
            if( i < 5 ) fprintf(f,"%d\n",rd(0,1000000));
            else fprintf(f,"%d\n",rd(0,1000000000));
                
    }
    
    return 0;
}
