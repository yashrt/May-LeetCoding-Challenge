class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        // To store character along with count 
        unordered_map<char, int> myMap;
        
        // Inserting and updating character count of string magazine
        for(char m: magazine)
            myMap[m]++;
        
        // validating character count of string ransomNote
        for(char r: ransomNote)
            if(myMap[r]>0)
                myMap[r]--;
            else
                return false;
        
        return true;
    }
};
