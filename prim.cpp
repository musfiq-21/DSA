#include<bits/stdc++.h>
using namespace std;

#define inf 10000
#define n 8
int v[n][n], copyM[n][n];

int prim(){
    int min=inf;
    int src, dest;
    vector<int> nodes;
    int pos;
    int cost=0;
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(copyM[i][j]<min){
                min=copyM[i][j];
                src=i;  dest=j;
            }
        }
    }
    nodes.push_back(src);
    nodes.push_back(dest);
    cost+=v[src][dest];

    copyM[src][dest]=inf;
    copyM[dest][src]=inf;
    
    while(1){
        if(nodes.size()==n-1)   break;
        int mnm = inf;
        int s, d;
        for(auto node: nodes){
            for(int j=1; j<n; j++){
                if(copyM[node][j]<mnm){
                    mnm=copyM[node][j];
                    s=node; d=j;
                }
            }
        }
        nodes.push_back(d);
        cost+=v[s][d];

        copyM[s][d] = inf;
        copyM[d][s] = inf;

    }

    return cost;
}

void insert(int src, int dest, int cost){
    v[src][dest] = cost;
    v[dest][src] = cost;
    copyM[src][dest] = cost;
    copyM[dest][src] = cost;
}

void setM(){
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            v[i][j]=inf;
            copyM[i][j]=inf;
        }
    }
}
int main(){

    setM();

    insert(1,2,28);
    insert(1,6,10);
    insert(6, 5, 25);
    insert(5, 7, 24);
    insert(5, 4, 22);
    insert(4, 3, 12);
    insert(3, 2, 16);
    insert(2, 7, 14);
    insert(4, 7, 18);
    
    cout<<prim()<<"\n";
}