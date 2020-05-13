class Solution {
public:
    string removeKdigits(string num, int k) {
        
        // Return "0" if string "num" size is same as k
        int size = num.size();
        if(size == k)
            return "0";
        
        // Remove the digit whose next digit is smaller
        // If we reach at the end than remove last digit
        for(int j=0; j<k; j++)
        {
            int i=0;
            while(i!=num.size()-1 && num[i]<=num[i+1])
                i++;
            
            num.erase(num.begin() + i);
        }
        // Removing if there is any leading zero
        while(num[0]=='0' && num.size()>0)
            num.erase(num.begin());
        
        // check after removing leading zero if size is 0 return "0"
        // else string "num itself"
        if(num.size()==0)
            return "0";
        else
            return num;
    }
};
