class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> umap;
        unsigned int ans = 0;
       
        for(int i=0;i<nums.size();i++){
        
            if(nums[i]==0)
                sum += -1;
            else
                sum += 1;    
            auto it = umap.find(sum);
           
            if(sum == 0){
                if(ans < i+1)
                    ans = i+1;
            }
            else if(it != umap.end()){
                if(ans < i-it->second)
                    ans = i-it->second;
            }
            else if(it == umap.end())
                umap.insert({sum,i});
       }
        return ans;
    }
};
