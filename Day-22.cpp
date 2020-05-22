class Solution {
public:
    string frequencySort(string s) {
        
        if(s.size()<=2)
            return s;
        
        // unordered map to store the frequency
        unordered_map<char,int> umap;
    
        // To Store the resulting string
        string res = "";
        
        // vector of pair whose first represent to alphabet
        // second represent to alphabets frequency
        vector<pair<char,int>> alpha;
        
        // updating frequency of alphabet's frequency
        for(char ch: s)
            umap[ch]++;
        
        
        // Inserting each unique alphabet with it's frequecy in vector
        for(auto i: umap)
            alpha.push_back(make_pair(i.first, i.second));
        
        
        // Applying insertion sort to sort vector according to frequncy of alphabet
        for(int i=1; i<umap.size(); i++)
        {
            int j = i-1;
            pair<char,int> temp = alpha[i];
            while(j>=0 && alpha[j].second <= temp.second)
            {
                alpha[j + 1].first = alpha[j].first;
                alpha[j + 1].second = alpha[j].second;  
                j = j - 1;  
            }
            alpha[j + 1].first = temp.first;
            alpha[j + 1].second = temp.second;
        }
        
        // Generating output according to frequncy of alphabet of the sorted vector
        for(int i=0; i<alpha.size(); i++)
            for(int j=1; j<=alpha[i].second; j++)
                res += alpha[i].first;
        
        return res;    
    }
};
