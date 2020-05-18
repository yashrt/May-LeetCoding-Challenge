class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int alpha[26] = {0};
        for(char ch : s1) 
            alpha[ch-'a']++;
        
        int s2Len = s2.size();
        int s1Len = s1.size();
        
        if(s1Len>s2Len)
            return false;
        
        int counter = s1Len, j=0;
    
        for(int i = 0; i< s2Len; i++)
        {
            while(j < s2Len && j - i < s1Len)
            {
                if(alpha[s2.at(j++) - 'a']-- > 0)
                    counter--;
            }
            if(counter == 0 && j - i == s1Len) 
                return true;
            if(alpha[s2.at(i) - 'a']++ >= 0) 
                counter++;            
        }
        return false;
    }
};
