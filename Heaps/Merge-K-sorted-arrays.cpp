#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<int , vector<int> , greater<int>> pq;

    for(auto v :kArrays){
        for(int i : v){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}
