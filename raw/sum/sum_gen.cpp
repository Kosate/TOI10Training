#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand((unsigned)time(0));
    int size[10] = {1,50,100,1000,1150,5555,19191,51212,99999,100000};
    
    for( int i=0; i<10; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        fprintf(f,"%d %d\n",size[i],size[i]);
        for( int j=0; j<size[i]; ++j ) {
            int k = ((rand()+((unsigned)rand()<<16))%2000000001)+(-1000000000);
            if( i < 4 ) {
                k = ((rand()+((unsigned)rand()<<16))%2001)+(-1000);
                k >?= -1000;
                k <?= 1000;
            }
            k >?= -1000000000;
            k <?= 1000000000;
            fprintf(f,"%d\n",k);
        }
        for( int j=0; j<size[i]; ++j ) {
            int s,e;
            s = (rand()%size[i])+1;
            e = (rand()%size[i])+s;
            e <?= size[i];
            fprintf(f,"%d %d\n",s,e); 
        }
    }
    
    return 0;
}
