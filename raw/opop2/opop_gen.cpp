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
    int n[10] = {10,100,252,512,1000,5000,10000,51515,99999,100000};
    
    for( int cas=0; cas<10; ++cas ) {
        char buffer[50];
        sprintf(buffer,"%d.in",cas+1);
        FILE *f = fopen(buffer,"w");
        
        int N = n[cas],Q = n[cas]*2;
        
        fprintf(f,"%d %d\n",N,Q);
        for( int i=0; i<N; ++i ) fprintf(f,"%d\n",rd(1,1000000000));
        for( int i=0; i<N; ++i ) {
            if( rand()%2 ) {
                fprintf(f,"1 %d\n",rd(1,N));
            } else {
                int s = rd(1,N);
                int e = min( N,s+rd(0,N) );
                fprintf(f,"2 %d %d\n",s,e);
            }
        }
                
    }
    
    return 0;
}
