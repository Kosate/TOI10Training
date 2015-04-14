#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int d[200000];

int rnd() {
    return (rand()+((unsigned)rand()<<16))%2100000000;
}
int rd( int s,int e ) {
    return s+(rnd()%(e-s+1));
}
int min( int a,int b ) { return a <? b; }

int data[1000][1000];

int main() {
    
    srand((unsigned)time(0));
    int n[10] = {10,45,100,252,100,500,777,818,999,1000};
    int m[10] = {10,50,100,212,500,200,617,818,999,1000};
    int k[10] = {3,10,20,100,25,33,600,818,333,500};
    
    for( int i=0; i<10; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        int dis = n[i]/k[i] + m[i]/k[i] - 2;
        if( i == 7 ) dis = 5;
        
        for( int j=0; j<n[i]; ++j )
            for( int k=0; k<m[i]; ++k ) data[j][k] = rd(0,1000);
        
        for( int j=0; j<dis; ++j )
            data[ rd(0,n[i]-1) ][ rd(0,m[i]-1) ] = -1;
        
        fprintf(f,"%d %d %d\n",n[i],m[i],k[i]);
        for( int j=0; j<n[i]; ++j,fprintf(f,"\n") )
            for( int k=0; k<m[i]; ++k ) fprintf(f,"%d ",data[j][k]);
        
    }
    
    return 0;
}
