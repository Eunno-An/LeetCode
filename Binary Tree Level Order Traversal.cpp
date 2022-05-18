1차 22-04-09 
Success
Details 
Runtime: 7 ms, faster than 49.78% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 13.2 MB, less than 14.20% of C++ online submissions for Binary Tree Level Order Traversal.
회고:
  map을 안사용해도 되고 while문 내부에서 처리가 가능하다.
  아래 코드 첨부.

2차  22-05-18
Time: 08분 26초
Success
Details 
Runtime: 8 ms, faster than 36.81% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 12.6 MB, less than 32.63% of C++ online submissions for Binary Tree Level Order Traversal.
회고:
비교적 깔끔하게 
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
  /*
  문제:
  같은 레벨(높이)에 있는 것들끼리만 묶어서 리턴해라
  
  제한:
  
  해결방법:
  BFS. 단, map을 통해 높이를 따로 저장하였음.
  
  
  */
    vector<vector<int>> ret;
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return ret;
        
        queue<pair<TreeNode*, int>> q;
        map<int, vector<int>> bucket;
        q.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*, int> t = q.front(); q.pop();
            if(bucket.find(t.second) == bucket.end()){
                bucket.insert({t.second, {t.first->val}});
            }else{
                bucket[t.second].push_back(t.first->val);
            }
            if(t.first->left != NULL)
                q.push({t.first->left, t.second + 1});
            if(t.first->right != NULL)
                q.push({t.first->right, t.second + 1});
        }
        for(auto it : bucket)
            ret.push_back(it.second);
        
        return ret;
    }
};
/*map 사용 안한거*/
class Solution {
     public:
        vector<vector<int>> levelOrder(TreeNode* root) {
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
          return ans;
        }
     };
