class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> color(N, -1);
        vector<vector<int>> adj(N, vector<int>());
        
        for(vector<int> temp: dislikes)
        {
            adj[temp[0]-1].push_back(temp[1]-1);
            adj[temp[1]-1].push_back(temp[0]-1);
        }
        
        for(int i=0; i<N; i++)
            if(color[i]==-1 && !dfs(adj, color, i, 0))
                return false;
        
        return true;
    }
    
    bool dfs(vector<vector<int>>& adj, vector<int>& color, int index, int col)
    {
        if(color[index]==-1)
            color[index] = col;
        else
            return color[index] == col;
        
        for(int n: adj[index])
            if(!dfs(adj, color, n, 1-col))
                return false;
        
        return true;
    }
};
