1차 22-04-15 
Success
Time: 27분 17초
Details 
Runtime: 4 ms, faster than 99.42% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 21.8 MB, less than 10.49% of C++ online submissions for Balanced Binary Tree.
회고:
1.처음에 balanced의 개념을 단순하게만 생각해서 각 재귀마다 좌우 높이를 비교하게 안짰음. 로직 에러났음.
2.로직은 수정했으나, 마지막 
if(leftH == MAX || rightH == MAX || abs(leftH-rightH) > 1)
            return false;
이 부분에서 abs(leftH-rightH)>1를 붙이지 않았음. 그래서 에러났었음.
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
  binary tree가 balanced인지 확인해라!
  
  해결방법:
  재귀로 돌면서 "각각의 재귀마다 루트의 좌 우 서브트리의 높이가 1 차이나는지 확인해 주어야 한다!"
  MAX를 통해 만약 각 재귀마다 balanced의 조건을 어긋난 경우 MAXH를 리턴해주도록 한다.
 
  */
    const int MAX = 100001;
    int getH(TreeNode* root, int h){
        if(root == NULL)
            return h;
        int left = 0, right = 0;
        left = max(left, getH(root->left, h+1));
        right = max(right, getH(root->right, h+1));
        if(abs(left- right) <= 1)
            return max(left, right);
        else
            return MAX;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int leftH = getH(root->left, 1);
        int rightH = getH(root->right, 1);
        if(leftH == MAX || rightH == MAX || abs(leftH-rightH) > 1)
            return false;
        return true;
    }
};
