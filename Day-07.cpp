/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        //vector of size 2 storing level of x and its parents
        vector<int> xInfo = getDepthAndParent(root,x,0,-1);
        
        //vector of size 2 storing level of y and its parents
        vector<int> YInfo = getDepthAndParent(root,y,0,-1);
        
        // checking, x and y are Cousins
        return (xInfo[0]==YInfo[0] && (xInfo[1]!=YInfo[1]));
    }
    
    // function returns vector of size two
    // 1st element represents level at which key is present
    // and 2nd element represents to parent of the key
    vector<int> getDepthAndParent(TreeNode* node, int key, int level, int parent)
    {
        if(!node)
            return {};
        
        if(node->val==key)
            return {level,parent};
        else
        {
            parent = node->val;
            vector<int> leftPart = getDepthAndParent(node->left,key,level+1,parent);
            vector<int> rightPart = getDepthAndParent(node->right,key,level+1,parent);
            
            if(leftPart.empty())
                return rightPart;
            else
                return leftPart;
        }
    }
};
