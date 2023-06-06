class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;

        // creating a mapping for frequency of elements of nums
        for(int i : nums){
            mp[i]++;
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        // adding the top k pair of frequency and value in the min heap
        for(auto i : mp){
            if(pq.size() < k){
                pq.push({i.second , i.first});
            }

            else if(i.second > pq.top().first){
                pq.pop();
                pq.push({i.second , i.first});
            }
        }

        // poping out the k elements from min heap
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
