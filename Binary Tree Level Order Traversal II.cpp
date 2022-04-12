1차 2022-04-12
이건 1 문제와 너무 비슷해서 Skip. 
단순히 reverse하면 된다.
그런데 reverse안쓰고 하려면?
  1. 일단 트리의 전체 높이를 구한다
  2. 트리의 높이만큼 vector<vector<int>> ans resize한다.
  3. 똑같은 로직으로 구한 다음, ans[depth-level-1]에 push_back하면 된다.
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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            if(root==NULL)
               return {};
           vector<vector<int>> ans; 
            queue<TreeNode*> q;
            q.push(root);
            TreeNode *temp;
            int len;
            while(!q.empty()){
               len=q.size();
		       vector<int> v;
               for(int i=0;i<len;i++){
                    temp=q.front();
                    q.pop();
                    v.push_back(temp->val);

                   if(temp->left) q.push(temp->left);
                   if(temp->right) q.push(temp->right);
                }
		        ans.push_back(v);
            }
            reverse(ans.begin(), ans.end());
          return ans;
        }
     
};
