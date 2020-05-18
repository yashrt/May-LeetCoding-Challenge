class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int alpha[26] = {0};
        for(char ch : p) 
            alpha[ch-'a']++;
        
        int sSize = s.size();
        int pSize = p.size();
        vector<int> res;
        
        if(pSize>sSize)
            return res;
        
        int counter = pSize, j=0;
    
        for(int i = 0; i< sSize; i++)
        {
            while(j < sSize && j - i < pSize)
            {
                if(alpha[s.at(j++) - 'a']-- > 0)
                    counter--;
            }
            if(counter == 0 && j - i == pSize) 
                res.push_back(i);
            if(alpha[s.at(i) - 'a']++ >= 0) 
                counter++;            
        }
        return res;
    }
};
