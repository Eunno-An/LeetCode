1차 22-04-17
Success
Time: 07분
Details 
Runtime: 4 ms, faster than 97.05% of C++ online submissions for Path Sum II.
Memory Usage: 19.8 MB, less than 82.16% of C++ online submissions for Path Sum II.
class Solution {
public:
    /*
    문제:
    targetSum과 같은 path Sum을 지니는 경로를 모두 리턴해라.
    
    제한:
    
    해결방법:
    이전 문제와 예외처리 물론 같다.
    */
    vector<vector<int>> ret;
    void help(TreeNode* root, int targetSum, vector<int>& now){
        if(root->left == NULL && root->right == NULL && targetSum == root->val){
            now.push_back(root->val);
            ret.push_back(now);
            now.pop_back();
            return;
        }
        now.push_back(root->val);
        if(root->left != NULL)
            help(root->left, targetSum-root->val, now);
        if(root->right != NULL)
            help(root->right, targetSum-root->val ,now);
        now.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return ret;
        vector<int> now = {root->val};
        if(root->left == NULL && root->right == NULL){
            ret.push_back(now);
            return root->val == targetSum ? ret : vector<vector<int>>();
        }
        if(root->left != NULL)
            help(root->left, targetSum-root->val, now);
        if(root->right != NULL)
            help(root->right, targetSum-root->val, now);
        return ret;
    }
};
