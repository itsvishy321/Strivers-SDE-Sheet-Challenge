#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans;
    priority_queue<int , vector<int> , greater<int>> pq;

    for(auto query : q){
        // push in the min Heap
        if(query[0] == 0){
            pq.push(query[1]);
        }

        // pop from the min Heap
        else{
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    return ans;
}
