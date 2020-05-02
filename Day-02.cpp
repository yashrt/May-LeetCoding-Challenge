class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewelsCount = 0;
        map<char, int> jewels;		// map to store jewels 
        
        for(char j: J)				// inserting jewels character in map
            jewels[j] = 0;
        
        for(char s: S)
            if(jewels.count(s)>0)	//check if char(s) present in jewel map
                jewelsCount++;
        
        return jewelsCount;
    }
};
