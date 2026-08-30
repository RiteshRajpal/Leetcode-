class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Map each number to its frequency
        unordered_map<int, int> umap;

        // Count frequency of every number
        for(auto x : nums) {
            umap[x]++;
        }

        // Min Heap
        // pair = {frequency, number}
        //
        // greater<pair<int,int>> makes it a Min Heap
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // Go through every number and its frequency
        for(auto x : umap) {

            // x.first  = number
            // x.second = frequency
            //
            // Store {frequency, number}
            pq.push(make_pair(x.second, x.first));

            // Keep only k elements in the heap
            if(pq.size() > k) {
                pq.pop();
            }
        }

        // Store the final k elements
        vector<int> ans;

        // Take elements from the heap
        while(!pq.empty()) {

            // Get the smallest frequency pair
            pair<int,int> temp = pq.top();

            // Remove it from the heap
            pq.pop();

            // temp.second is the actual number
            ans.push_back(temp.second);
        }

        // Return top k frequent elements
        return ans;
    }
};