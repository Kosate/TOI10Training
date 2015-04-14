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
    int n[10] = {101,512,1000,10000,50000,100000,256256,512512,999999,1000000};
    int m[10] = {1,5,10,15,20,25,30,30,30,30};
    
    for( int i=0; i<10; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        
        fprintf(f,"%d %d\n",n[i],m[i]);
        
        char nn[1000001]; 
        char mm[31]; 
        for( int j=0; j<n[i]; ++j ) nn[j] = rd(0,1) + '0';
        for( int j=0; j<m[i]; ++j ) mm[j] = rd(0,1) + '0';
        
        int t = 0;
        for( int k=0; k<5000; ++k ) {
            if( t >= n[i]-m[i] ) break;
            for( int j=0; j<m[i]; ++j ) nn[j+t] = mm[j];
            t += rd(m[i],rd(100,1000));
        }
        nn[n[i]] = '\0';
        mm[m[i]] = '\0';
        fprintf(f,"%s\n%s\n",nn,mm);
                
    }
    
    return 0;
}
