1차 22-04-05 Fail

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
2진트리 중위순회한 결과 찾아

Follow-up:
재귀 말고 반복함수로 풀어봐 ㅎ

제한:

해결방법:
1)recursive는 흔하다
2)재귀로 실패
3)Morris Algorithm
-> O(n)의 t.c , O(1)의 space complexity로 풀 수 있다.
-> 너무 어려우므로.. 일단 이런게 있다는것 정도만 알아두자.
    
*/
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        while(root || !s.empty()){
            if(root != NULL){//루트가 기존에 있으면
                s.push(root);//루트는 stack에다가 넣어둬. 나중에 볼거야.
                root = root->left;//그리고 root를 left로 넘어가!
            }
            else{
                root = s.top();
                s.pop();
                v.push_back(root->val);
                root = root->right;
            }
        }
        return ret;
    }
};
