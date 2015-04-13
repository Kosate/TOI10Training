#include <stdio.h>
#include <string.h>
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
    
    if( false ) {
        char buffer[50];
        sprintf(buffer,"2.in");
        FILE *f = fopen(buffer,"w");
        
        int N = 40, M = 40;
        int sx = rd(0,39), sy = rd(0,39);
        
        fprintf(f,"40 40\n");
        for( int i=0; i<N; ++i ) {
            char ttt[10] = ".....E###";
            for( int j=0; j<N; ++j ) {
                if( i == sy && j == sx ) fprintf(f,"S");
                else fprintf(f,"%c",ttt[rd(0,8)]);
            }
            fprintf(f,"\n");
        }
                
    }
    if( false ) {
        char buffer[50];
        sprintf(buffer,"3.in");
        FILE *f = fopen(buffer,"w");
        
        int N = 40, M = 40;
        int sx = rd(0,39), sy = rd(0,39);
        int ex = rd(0,39), ey = rd(0,39);
        
        fprintf(f,"40 40\n");
        for( int i=0; i<N; ++i ) {
            char ttt[10] = "......###";
            for( int j=0; j<N; ++j ) {
                if( i == sy && j == sx ) fprintf(f,"S");
                else if( i == ey && j == sy ) fprintf(f,"E");
                else fprintf(f,"%c",ttt[rd(0,8)]);
            }
            fprintf(f,"\n");
        }
                
    }
    
    if( false ) {
        char buffer[50];
        sprintf(buffer,"4.in");
        FILE *f = fopen(buffer,"w");
        
        int N = 40, M = 40;
        int sx = rd(0,39), sy = rd(0,39);
        int ex = rd(0,39), ey = rd(0,39);
        
        fprintf(f,"40 40\n");
        for( int i=0; i<N; ++i ) {
            for( int j=0; j<N; ++j ) {
                fprintf(f,i%2 && j%2 ? "." : "#");
            }
            fprintf(f,"\n");
        }
                
    }
    
    if( false ) {
    
    for( int cas=5; cas<=10; cas++ ) {
        char buffer[50];
        sprintf(buffer,"%d.in",cas);
        FILE *f = fopen(buffer,"w");
        
        int n[6] = {20,100,50,100,50,300};
        int m[6] = {100,20,50,100,175,100};
        
        char prop[6][100] = {"..............................*#E\0",".*#E\0",".............****####E\0",".*#...*##*................................................................E\0","............................................................***E\0","..................................................................****####E\0"};
        
        int N = n[cas-5], M = m[cas-5];
        int sy = rd(0,N-1), sx = rd(0,M-1);
        
        fprintf(f,"%d %d\n",N,M);
        for( int i=0; i<N; ++i ) {
            for( int j=0; j<M; ++j ) {
                fprintf(f,"%c",prop[cas-5][rand()%strlen(prop[cas-5])]);
            }
            fprintf(f,"\n");
        }
    }    
    
    }
    
    if( false ) {    
        
        char buffer[50];
        sprintf(buffer,"11.in");
        FILE *f = fopen(buffer,"w");
        
        char prop[6][100] = {"..............................*#E\0",".*#E\0",".............****####E\0",".*#...*##*................................................................E\0","............................................................***E\0","..................................................................****####E\0"};
        
        int N = 300, M = 300;
        int sy = rd(0,N-1), sx = rd(0,M-1);
        
        fprintf(f,"%d %d\n",N,M);
        for( int i=0; i<N; ++i ) {
            for( int j=0; j<M; ++j ) {
                if( 100 < j && j < 200 ) fprintf(f,".");
                else fprintf(f,"%c",prop[3][rand()%strlen(prop[3])]);
            }
            fprintf(f,"\n");
        } 
    
    }
    if( false ) {    
        
        char buffer[50];
        sprintf(buffer,"12.in");
        FILE *f = fopen(buffer,"w");
        
        //char prop[6][100] = {"..............................*#E\0",".*#E\0",".............****####E\0",".*#...*##*................................................................E\0","............................................................***E\0","..................................................................****####E\0"};
        
        int N = 300, M = 300;
        int sy = rd(0,N-1), sx = rd(0,M-1);
        
        fprintf(f,"%d %d\n",N,M);
        for( int i=0; i<N; ++i ) {
            for( int j=0; j<M; ++j ) {
                if( i == 2 || i == 298 || j == 2 || j == 298 ) fprintf(f,"#");
                else fprintf(f,".");
            }
            fprintf(f,"\n");
        } 
    
    }
    if( false ) {    
        
        char buffer[50];
        sprintf(buffer,"13.in");
        FILE *f = fopen(buffer,"w");
        
        char prop[100] = "...##\0";
        //char prop[6][100] = {"..............................*#E\0",".*#E\0",".............****####E\0",".*#...*##*................................................................E\0","............................................................***E\0","..................................................................****####E\0"};
        
        int N = 300, M = 300;
        int sy = rd(0,N-1), sx = rd(0,M-1);
        
        fprintf(f,"%d %d\n",N,M);
        for( int i=0; i<N; ++i ) {
            for( int j=0; j<M; ++j ) {
                if( i-1 <= j && j <= i ) fprintf(f,".");
                else fprintf(f,"%c",prop[rand()%strlen(prop)]);
            }
            fprintf(f,"\n");
        } 
    
    }
    
    if( false ) {    
        
        char buffer[50];
        sprintf(buffer,"14.in");
        FILE *f = fopen(buffer,"w");
        
        //char prop[6][100] = {"..............................*#E\0",".*#E\0",".............****####E\0",".*#...*##*................................................................E\0","............................................................***E\0","..................................................................****####E\0"};
        
        int N = 300, M = 300;
        int sy = rd(0,N-1), sx = rd(0,M-1);
        
        fprintf(f,"%d %d\n",N,M);
        for( int i=0; i<N; ++i ) {
            for( int j=0; j<M; ++j ) {
                if( i == N/2 || j == N/2 ) fprintf(f,"#");
                else fprintf(f,".");
                //else fprintf(f,"%c",prop[rand()%strlen(prop)]);
            }
            fprintf(f,"\n");
        } 
    
    }
    
    return 0;
}
