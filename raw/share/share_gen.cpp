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
    int n[10] = {5,10,121,999,1112,5012,21515,41616,99999,100000};
    int q[10] = {10,20,252,788,1999,4158,21515,50000,99999,100000};
    
    for( int cas=0; cas<10; ++cas ) {
        char buffer[50];
        sprintf(buffer,"%d.in",cas+1);
        FILE *f = fopen(buffer,"w");
        
        int N = n[cas];
        for( int j=1; j<=N; ++j ) D.push_back(j);
        for( int i=0; i<50000; ++i ) {
            int s = rd(0,N-1);
            int e = rd(0,N-1);
            int tmp = D[s];
            D[s] = D[e];
            D[e] = tmp;
        }
        
        vector <int> Q;
        while( D.size() > 1 ) {
            Q.clear();
            int d = rd(2,D.size());
            while( d-- ) {
                Q.push_back( D.back() );
                D.pop_back();
            }
            
            for( int j=Q.size()*2; j>=0; --j ) {
                int s = rd(0,Q.size()-1);
                int e = rd(0,Q.size()-1);
                while( e == s ) e = rd(0,Q.size()-1);
                S.push_back( make_pair( Q[s],Q[e]) );
            }
        }
        unique( S.begin(),S.end() );
        
        fprintf(f,"%d %d %d\n",n[cas],min(100000,S.size()),q[cas]);
        for( int i=0; i<S.size() && i < 100000; ++i ) fprintf(f,"%d %d\n",S[i].first,S[i].second);
        for( int i=0; i<q[cas]; ++i ) {
            int s = rd(1,N);
            int e = rd(1,N);
            while( e == s ) e = rd(1,N);
            fprintf(f,"%d %d\n",s,e);
        }
        printf("!");
    }
    
    return 0;
}
