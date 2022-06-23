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
    
    int averageOfSubtree(TreeNode* root) {
        queue<TreeNode*> q1;//q1은 트리의 전체 노드에 대해 순회하는 것
        q1.push(root);
        int ret = 0;
        while(!q1.empty()){
            TreeNode* now = q1.front(); q1.pop();
            if(now->left != NULL)
                q1.push(now->left);
            if(now->right != NULL)
                q1.push(now->right);
            
            queue<TreeNode*> q2;//평균과 값을 비교해 보기 위한 것.
            q2.push(now);
            int sum = 0;
            int count = 0;
            while(!q2.empty()){
                TreeNode* tempNow = q2.front(); q2.pop();
                sum+=tempNow->val;
                count++;
                if(tempNow->left != NULL)
                    q2.push(tempNow->left);
                if(tempNow->right != NULL)
                    q2.push(tempNow->right);
            }
            if(now->val == sum / count)
                ret++;
        }
        return ret;
    }
};


//Discussion Good Code
int count=0;
pair<int,int> valueSum(TreeNode* root){
	if(root==NULL) return {0,0};
	auto left=valueSum(root->left);
	auto right=valueSum(root->right);
	int sum=(left.first+right.first+root->val);
	int n=(left.second+right.second+1);        
	count+=((sum/n)==root->val);
	return {sum,n};
}
int averageOfSubtree(TreeNode* root) {
	auto p1=valueSum(root);
	return count;
}
