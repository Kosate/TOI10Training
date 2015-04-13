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

int main() {
    
    srand((unsigned)time(0));
    int n[10] = {5,7,10,50,100,212,333,512,888,1000};
    
    for( int i=5; i<6; ++i ) {
        char buffer[50];
        sprintf(buffer,"%d.in",i+1);
        FILE *f = fopen(buffer,"w");
        fprintf(f,"%d %d\n",n[i],rnd()%1001);
        for( int j=0; j<n[i]; ++j ) {
            int tt[9] = {23, 31, 37, 41, 53, 59, 67, 73, 89};
            switch( i ) {
                case 5 : fprintf(f,"%d\n",rd(1,2)); break;
                case 6 : fprintf(f,"%d\n",tt[rd(6,8)]); break;
                case 7 : fprintf(f,"%d\n",rd(69,69)); break;
                case 8 : fprintf(f,"%d\n",rd(83,87)); break;
                case 9 : fprintf(f,"%d\n",rd(90,100)); break;
                default : fprintf(f,"%d\n",rnd()%101); 
            }
            
        }
    }
    
    return 0;
}
