class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        /* To store the result */
        vector<vector<int>> res;
        
        /* vector of pairs. Each pair's 1st element represent to distance from origin,
           2nd element of pair represent to index of corresponding points
        */
        vector<pair<int,int>> dist;
        for(int i=0; i<points.size(); i++)
        {
            int len = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            dist.push_back({len,i});
        }
        
        /* Sorting the dist vector */
        sort(dist.begin(), dist.end());
        
        /* Storing the first K closest points */
        for(int i=0; i<K; i++)
        {
            int index = dist[i].second;
            res.push_back({points[index][0],points[index][1]});
        }
        return res;
    }
};
