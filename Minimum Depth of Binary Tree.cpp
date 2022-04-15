1차 22-04-15
Success
Time: 6분 26초
Details 
Runtime: 249 ms, faster than 81.88% of C++ online submissions for Minimum Depth of Binary Tree.
Memory Usage: 144.7 MB, less than 42.09% of C++ online submissions for Minimum Depth of Binary Tree.
회고:
갱신할 때, 최소값을 갱신하는 경우, leftH와 rightH가 둘 다 초기값인 (100001)인 경우, leftH, rightH에 대한 예외처리를 따로 해주지 않으면 초기값을 리턴하게 됨. 결과는 잘못됨.
  return min(leftH, rightH) == 1000001 ? h + 1: min(leftH, rightH);
이 코드를 통해 예외처리를 해주어야 한다.
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
    이진트리가 주어지면, 최소 depth를 찾아라. 루트에서부터 shortest path의 노드 개수를 세는 것임.
    
    제한:
    
    해결방법:
    각 재귀마다 minH를 갱신한다.
    */
    
    int minDepth(TreeNode* root, int h=0){
        if(root == NULL)
            return h;
        
        int leftH=1000001, rightH=1000001;
        if(root->left != NULL)
            leftH = min(leftH, minDepth(root->left, h+1)); 
        if(root->right != NULL)
            rightH = min(rightH, minDepth(root->right, h+1));
        return min(leftH, rightH) == 1000001 ? h + 1: min(leftH, rightH);
    }
};
