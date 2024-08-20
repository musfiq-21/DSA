#include<bits/stdc++.h>
using namespace std;

#define size 7
vector<pair<int, int>> vp(size);    //weight, profit

float frac_knapsack(int sack){

    set<pair<float, int> > heap;    //{pbyw, index}

    for(int i=0; i<size; i++){
        float p_by_w = 1.0*vp[i].second/vp[i].first;    //p_by_w(profit by weight)
        heap.insert({-p_by_w, i});
    }

    float total_profit=0;
    
    auto pr=heap.begin();

    while(sack>0 and pr != heap.end()){
        if(sack>= vp[pr->second].first){      //sack greater than weight
            
            total_profit+= vp[pr->second].second;     //add full profit
            sack-=vp[pr->second].first;
            
        }
        else{

            cout<<sack<<" "<< pr->first<<"\n";
            total_profit-= sack*(pr->first);      //add frac profit
            
            sack = 0;
        }

        pr++;
    }
    return total_profit;
}

int main(){

    vp[0] = {2, 10};
    vp[1] = {3, 5};
    vp[2] = {5, 15};
    vp[3] = {7, 7};
    vp[4] = {1, 6};
    vp[5] = {4, 18};
    vp[6] = {1, 3};

    cout<<frac_knapsack(15)<<"\n";
}