1차 22-04-11 Fail...
흑흑 너무 피곤하다...그냥 푹 쉴껄 그랬다..
회고:
아얘 생각 조차 못했음. 이런 유형은 꼭 알아놓자.

2차 22-05-25 Fail
아이디어 생각했고 인덱스까지 이용하는 방법 생각했으나
인덱스로 하면 넘 어려울꺼라고 생각했는데 아니였음
사실 이때 김창완선배님이랑 전화함 
엄빠 문제로 너무 머리가 터질거같다 어렵고 힘들어
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
    전위 순회와 중위순회가 주어질 때, 원래 트리가 무엇인지 리턴해라.
    
    제한:
    
    
    해결방법:
    전위는 root->left->right 순서대로 순회한다. 그러면 우린 preorder[0]이 root라는건 확신할 수 있다.
    중위는 left->root->right로 순회한다.따라서 우리는 root의 위치를 알면 재귀적으로 전체 array를 두개의 subTree들로
    split할 수 잇따.
    
    */
   
    int preIdx =0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder, 0, inorder.size()-1);    
    }
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end)
            return NULL;
        TreeNode* node = new TreeNode(preorder[preIdx++]);
        int pos;
        for(int i=start ; i<= end; i++)
            if(inorder[i] == node->val){
                pos = i;
                break;
            }
        
        node->left=  createTree(preorder, inorder, start, pos-1);
        node->right = createTree(preorder, inorder, pos+1, end);
        return node;
    }
};
