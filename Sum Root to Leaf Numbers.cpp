1차 22-05-15
Success
Time: 06분 24초
Details 
Runtime: 4 ms, faster than 44.70% of C++ online submissions for Sum Root to Leaf Numbers.
Memory Usage: 9.2 MB, less than 84.59% of C++ online submissions for Sum Root to Leaf Numbers.
회고:
재귀적인 방법으로 풀었지만, iterative solution도 알아놓자. stack으로 해결했다.
class Solution {
public:
    /*
    문제:
    이진 트리의 root가 주어진다. 이진트리는 0에서 9까지의 숫자만을 갖고 있다.
    root에서 leaf 까지의 path는 각 숫자를 나타낸다.
    root-to-leaf 숫자의 모든 total sum을 리턴해라.
    32비트 정수 형식에 맞게 테스트케이스가 주어진다.
    
    
    제한:
    
    해결방법:
    
    */
    int ret = 0;
    void calRootToLeaf(TreeNode* root, int sum){
        if(root->left == NULL && root->right == NULL){
            ret += sum;
            return ;
        }
        if(root->left != NULL)
            calRootToLeaf(root->left, sum*10 + root->left->val);
        if(root->right != NULL)
            calRootToLeaf(root->right, sum*10 + root->right->val);
        return ;
    }
    int sumNumbers(TreeNode* root) {
        calRootToLeaf(root, root->val);
        return ret;
    }
};
//iterative solution
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum=0;
        stack<pair<TreeNode*,int>> stck;
        stck.push({root,0});
        while(!stck.empty()){
            pair<TreeNode*,int> p=stck.top();
            stck.pop();
            TreeNode* cur_node=p.first;
            int cur_sum=p.second;
            if(cur_node!=NULL){
                cur_sum=cur_sum*10+cur_node->val;
                if(cur_node->left==NULL and cur_node->right==NULL){
                    totalSum+=cur_sum;
                }
                else{
                    if(cur_node->right){
                        stck.push({cur_node->right,cur_sum});
                    }
                    if(cur_node->left){
                        stck.push({cur_node->left,cur_sum});
                    }
                }
            }
        }
        return totalSum;
    }
};
