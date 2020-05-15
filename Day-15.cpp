class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        return circularKadane(A, A.size());
    }
    
    int Kadane(vector<int>& A, int len) {
        int sum = 0;
        int maxSum = INT_MIN;
        
        for(int i=0; i<len; i++)
        {
            sum = sum + A[i];
            if(maxSum < sum)
                maxSum = sum;
            
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
    
    int circularKadane(vector<int>& A, int len)
    {
        int sum = Kadane(A,len);
        int inverseSum = 0;
        
        for(int i=0; i<len; i++)
        {
            inverseSum += A[i];
            A[i] = -A[i];
        }
        inverseSum = inverseSum + Kadane(A,len);
        
        if(inverseSum == 0)
            return sum;
        return (inverseSum>sum) ? inverseSum : sum;
    }
};
