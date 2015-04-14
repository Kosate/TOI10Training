#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector <int> D;
vector < pair<int,int> > S;

int rnd() {
    return (rand()+((unsigned)rand()<<16))%2100000000;
}
int rd( int s,int e ) {
    return s+(rnd()%(e-s+1));
}
int min( int a,int b ) { return a <? b; }

int main() {
    
    srand((unsigned)time(0));
    int n[10] = {10,500,1000,5000,12000,25000,54321,75000,100000,100000};
    
    for( int cas=0; cas<10; ++cas ) {
        char buffer[50];
        sprintf(buffer,"%d.in",cas+1);
        FILE *f = fopen(buffer,"w");
        
        fprintf(f,"%d\n",n[cas]);
        for( int i=0; i<n[cas]; ++i ) fprintf(f,"%lld\n",1+(rnd()%1000000)+((rnd()%1000000)*1000000LL));
    }
    
    return 0;
}
