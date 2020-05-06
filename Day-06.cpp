class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // storing size of vector
        int n = nums.size(); 
        
        // To store elements of input vector and it's frequency
        unordered_map<int, int> umap;
        
        // storing elements of input vector and it's frequency
        for(int num: nums)
            umap[num]++;
        
        // Checking for Majority Element in the umap
        for(auto i: umap)
            if(i.second > n/2)
                return i.first;
        
        return 1;
    }
};
