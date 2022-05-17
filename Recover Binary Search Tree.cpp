1차 22-04-08 Fail.
이유?
아이디어 생각도 못했음. 트리 너무 헤메는듯.
https://leetcode.com/problems/recover-binary-search-tree/discuss/32535/No-Fancy-Algorithm-just-Simple-and-Powerful-In-Order-Traversal
회고:
-> Valid BST 문제의 확장버전. 
-> 모리스 알고리즘 뭐시기라는데, 그거보다는 그냥 in-order traversal이 bst에서 어떤 결과를 내는지 생각해서 풀기.
-> 그리고 prev를 저렇게 초기화 할 경우, 두개의 if문제 등호를 붙이면 안되는 이유를 생각하기.
    
2차 22-05-17 Fail
회고
아이디어 생각하고 코드까지 짰음.
그러나... 문제는 정확히 "두개의 노드"를 실수로 바꿨다고 했음.
근데 코드 짠건 어떤 서브트리의 루트와, 그 서브트리에 속한 노드간의 관계만 비교했음. 아얘 다른 로직임.

아래 코드 정확히 이해함. 근데 이 코드 문제는 요구하는 O(1) extra space가 아님. recursion에 필요한 stack space가 필요하기 때문임.     
Morris 알고리즘에 대해 배워야할듯. 아래 코드는 그냥 이런 풀이가 있다 정도?
    
    in-order를 하는 이유? 일단 문제 자체가 "정확히 두개"의 노드만 뒤바뀌었다고 하였음.
    그렇다면 우린 틀린 부분 두군데를 찾으면 되는거임.
    즉, in-order를 하면서 전역변수로 이전에 탐색했던 node인 prevNode를 선언해줌. 이 prevNode와 root의 관계는 정상적인 BST라면 항상 prevNode.val < root.val임.
    근데 이렇지 않은 부분이 있을것이란 말임. 만약 처음 발견한거라면? 이때는 prevElement가 first가 됨!
    
    
    그 뒤에도 순회를 하면서 잘못된 부분을 또 발견한다면? 이때는 root가 second가 됨! 
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
