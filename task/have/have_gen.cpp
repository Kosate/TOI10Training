#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int d[200000];

int rnd() {
    return (rand()+((unsigned)rand()<<16))%2100000000;
}

int main() {
    
    srand((unsigned)time(0));
    int n[10] = {1,50,100,1000,1150,5555,19191,51212,99999,100000};
    int q[10] = {5,10,121,999,1112,5012,21515,41616,99999,100000};
    
    for( int i=0; i<10; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        fprintf(f,"%d %d\n",n[i],q[i]);
        for( int j=0; j<n[i]*2; ++j ) {
            d[j] = rnd()%1000000001;
            if( j < n[i] ) fprintf(f,"%d\n",d[j]);
        }
        for( int j=0; j<q[i]; ++j ) fprintf(f,"%d\n",d[rnd()%(n[i]*2)]);
    }
    
    return 0;
}
