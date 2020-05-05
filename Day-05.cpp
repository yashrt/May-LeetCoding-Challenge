class Solution {
public:
    int firstUniqChar(string s) {
        // unordered map to store frequency of each character in string
        unordered_map<char, int> umap;
        
        // inserting and updating frequency of each character
        for(char c: s)
            umap[c]++;
        
        // returning very first character having frequency 1 else return -1
        for(int i=0; i<s.size(); i++)
            if(umap[s[i]]==1)
                return i;
        
        return -1;
    }
};
