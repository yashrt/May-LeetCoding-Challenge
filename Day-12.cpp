// Using Binary Search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        int low = 0;
        
        int high = size-1;
        long mid = 0;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            // For Boundry elements at index 0 and (size of vector -1)
            if(low==high)
                    return nums[mid];
            // For Middle element
            else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1])
                    return nums[mid];
                
            if(mid%2 == 0)
            {
                if(nums[mid-1]==nums[mid])
                    high = mid;
                else
                    low = mid;
            }
            else{
                if(nums[mid-1]==nums[mid])
                    low = mid+1;
                else
                    high = mid-1;
            } 
        }
        return mid;
    }
};
