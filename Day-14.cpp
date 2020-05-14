class Trie {
public:
    /** Initialize your data structure here. */
    
    // To represent string from root to perticular node exists or not.
    bool val;
    
    // Array to store pointers of all 26 alphabets 
    // index 0 for 'a'...... index 25 for 'z'
    Trie* next[26];
    
    /** Constructor fot the trie. */
    Trie() {
        this->val = 0;
        for(int i=0; i<26; i++)
            this->next[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* curr = this;
        for(char ch: word)
        {
            if(curr->next[ch-'a']==NULL)
                curr->next[ch-'a'] = new Trie();
            
            curr = curr->next[ch-'a'];
        }
        curr->val = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* curr = this;
        for(char ch: word)
        {
            if(curr->next[ch-'a']==NULL)
                return false;
            else
                curr = curr->next[ch-'a'];
        }
        return curr->val==1;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* curr = this;
        
        for(char ch: prefix)
        {
            if(curr->next[ch-'a']==NULL)
                return false;
            else
                curr = curr->next[ch-'a'];
        }
            
        return true;
    }
};
