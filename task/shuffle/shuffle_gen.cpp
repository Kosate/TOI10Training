#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

long long mmm[10] = {10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000LL};

int rnd() {
    return ((rand()+((unsigned)rand()<<16))%2100000000)%mmm[rand()%10];
}
int rd( int s,int e ) {
    return s+(rnd()%(e-s+1));
}
int min( int a,int b ) { return a <? b; }

int d[100000];

int main() {
    
    srand((unsigned)time(0));
    
    int n[7] = {101,512,1000,10000,50000,100000,100000};
    
    for( int i=0; i<7; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        
        fprintf(f,"%d\n",n[i]);
        for( int j=0; j<n[i]; ++j ) d[j] = j+1;
        for( int j=0; j<10000; ++j ) {
            swap( d[rd(0,n[i]-1)],d[rd(0,n[i]-1)] );
        }
        for( int j=0; j<n[i]; ++j ) fprintf(f,"%d ",d[j]);
        fprintf(f,"\n");
                
    }
    
    return 0;
}
