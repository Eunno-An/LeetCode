1차 22-04-18
Success
Time: 17분 10초
Details 
Runtime: 7 ms, faster than 72.33% of C++ online submissions for Flatten Binary Tree to Linked List.
Memory Usage: 13.2 MB, less than 8.15% of C++ online submissions for Flatten Binary Tree to Linked List.
회고:
-> O(1) extra space code 첨부하였음. 읽어보자.
class Solution {
public:
    /*
    문제:
    "이진 트리"의 root가 주어지면, 링크드 리스트처럼 flatten 시켜라.
    right 자식 노드로만 연결되어 있어야 한다. left 자식 포인터는 항상 null을 가르켜야 한다.
    전위 순회와 같은 순서로 linked list가 연결되어 있어야 한다.
    
    제한:
    
    Follow-up:
    O(1)의 extra space로 구현할 수 있냐?
    
    해결방법:
    전위 순회로 탐색한 결과들을 쭉 이어 붙인다. 
    1) 추가 메모리 N(tree size)를 사용
    ->구현 easy
    2) 미사용
    ->좀 어렵다. 모리스 트레버설 이라고 하는데 읽으면 이해는 간다; 구현 참 쉽게도 한다 외국 고수님들..
    */
    vector<TreeNode*> l;
    void help(TreeNode* root){
        if(root == NULL)
            return;
        l.push_back(root);
        help(root->left);
        help(root->right);
        return;
    }
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* dummyNode = root;
        help(root);
        for(int i=1; i<l.size(); i++){
            root->left = NULL;
            root->right = l[i];
            root = root->right;
        }
        root = dummyNode;
        
    }
  
  //extraSpace O(1) code
  void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* runner = curr->left;
                while (runner->right != nullptr) runner = runner->right;
                runner->right = curr->right, curr->right = curr->left, curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
