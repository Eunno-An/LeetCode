1차 22-04-17 Fail
회고: 쉬운 문제지만, 처리해야 할 예외가 좀 있다. 그리고 각 루트의 left와 right가 null이 아닐 때 재귀가 돌게 해야 한다!(왜냐하면 null인 경우는 path로 안들어가야하므로), 
근데 그걸 고려하지 않고 null일 때도 재귀를 들어가버려서 예외에서 걸렸다. ex) [1, 2], targetSum = 1



class Solution {
public:
  /*
  트리의 path sum이 targetSum인게 있으면 true, 아니면 false
  */
    bool help(TreeNode* root, int targetSum){
        //cout << root->val << ": " << targetSum << '\n';
        if(root->left == NULL && root->right == NULL)
            return targetSum == root->val ? true : false;
        
        bool left = false, right = false;
        if(root->left != NULL)
            left = help(root->left, targetSum - root->val);
        if(root->right != NULL)
            right = help(root->right, targetSum - root->val);
        return left || right;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
            return targetSum == root->val ? true : false;
        bool left=false, right=false;
        if(root->left != NULL)
            left = help(root->left, targetSum-root->val);
        if(root->right != NULL)
            right = help(root->right, targetSum-root->val);
        
        return left || right;
    }
};  
