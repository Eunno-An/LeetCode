1차 22-04-08 Fail.
이유?
아이디어 생각도 못했음. 트리 너무 헤메는듯.
https://leetcode.com/problems/recover-binary-search-tree/discuss/32535/No-Fancy-Algorithm-just-Simple-and-Powerful-In-Order-Traversal
회고:
-> Valid BST 문제의 확장버전. 
-> 모리스 알고리즘 뭐시기라는데, 그거보다는 그냥 in-order traversal이 bst에서 어떤 결과를 내는지 생각해서 풀기.
-> 그리고 prev를 저렇게 초기화 할 경우, 두개의 if문제 등호를 붙이면 안되는 이유를 생각하기.
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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    //nullptr에러를 피하기 위해 이렇게 초기화해준다.
    TreeNode* prev = new TreeNode(INT_MIN);
    void traverse(TreeNode* root){
        if(root == NULL)
            return;
        
        traverse(root->left);
        
        //"do some business"
        
        //첫번째 요소가 아직 발견되지 않았으면,
        //prev에다가 first를 할당한다.
        if(first == NULL && prev->val > root->val)
            first = prev;
        
        //첫번째 요소가 발견되면, 
        //root에 두번째 요소를 할당한다.
        if(first != NULL && prev->val > root->val)
            second = root;
        
        prev = root;
        
        traverse(root->right);
    }
    void recoverTree(TreeNode* root) {
        traverse(root);
        
        int temp = first->val;
        first->val =second->val;
        second->val = temp;
    }
};
