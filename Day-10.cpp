// Using unordered map to store information of each person from 1 to N
// Each key in unordered map is associated with a pair of two values
// Each pair's first value represent total count of people trust the person having key as lebel
// Each pair's second value represent the person having key as lebel trust anyone


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // unordered map to store each person's (i.e 1 to N) information
        unordered_map<int, pair<int,bool>> umap;
        
        // Initially setting the count of total people trust him to 0 and Person trust anyone as false
        for(int i=1; i<=N; i++)
            umap[i] = make_pair(0,false);
        
        // Updating values in the unordered map according to trust vector
        for(vector<int> v: trust)
        {
            umap[v[1]].first++;
            umap[v[0]].second = true;
        }
        
        // Town judge must have total number of people trusting him equal to N-1
        // and he don't trust anyone 
        for(int i=1; i<=N; i++)
            if(umap[i].first==N-1 && !umap[i].second)
                return i;
        // else return
        return -1;
    }
};
