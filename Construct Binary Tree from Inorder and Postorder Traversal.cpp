1차 Fail
2022-04-12
회고:
    아이디어는 생각했으나.... 매개변수를 inorder의 is, ie만 생각하고 함수를 짰음.
    is, ie 두개만 변수를 설정할 경우, postorder의 마지막 값이 inorder[is:ie]사이에 없을 수 도 있음. 거기서 버그가 걸렸음.
    근데 여기서 헷갈릴 수 있는 부분.
    postorder의 vector도 start와 end를 나눠야 하는데
    단순히 크기로 나누면 된다! 
    leftSubTree의 end는
    ps(postorder의 start)부터, (le-ls)만큼이 왼쪽 subtree이고
    rightSubTree의 start는 leftpe에 1을 더한것,
    그리고 end는 pe -1이다.(루트가 끝에서 빠지므로!)
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
    중위와 후위의 순회결과가 주어지면 
    binary tree를 리턴해라.
    
    제한:
    
    해결방법:
    중위: 좌 중 우 순서
    후위: 좌 우 중 순서
    
    
    
    현재 재귀의 루트노드: postorder의 마지막
    현재 재귀의 왼쪽 서브트리: inorder에서 루트노드값 왼쪽
    현재 재귀의 오른쪽 서브트리: inorder에서 루트노드값 오른쪽
    
    
    
    */
    TreeNode* rec(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe){
        if(is > ie || ps > pe)
            return NULL;
        
        int val = postorder[pe];
        int i = is;
        while(inorder[i] != val) i++;
        TreeNode* root = new TreeNode(val);
        root->left = rec(inorder, postorder, is, i-1, ps, ps+i-is-1);
        root->right = rec(inorder, postorder, i+1, ie, pe-(ie-i), pe-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        return rec(inorder, postorder, 0, size-1, 0, size-1);
    }
};
