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
            
2차 22-06-14 
Fail
로직은 생각 했으나 이를 함수로 어케 해야될지 생각이 안났음.
코틀린으로 풀어봄
왜 58번째 줄에서 leftH와 rightH를 MAX인지 check하는가?
1을 root로 갖고 왼쪽과 오른쪽이 길게 2 3 4 5 를 길게 갖는 트리라고 생각해 보자. 대충 이런 모양이다(/ \)
그럼 맨 밑에서 올라올 때 lh와 rh의 높이 차가 2인게 생기는데, 이때 잘못되었다고 flag를 세워야 한다.
그게 MAX의 역할이다.
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
