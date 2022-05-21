1차 22-04-10
Time: 14 분 17초
Success
Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 11.9 MB, less than 93.28% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
    
2차 22-05-21
Time: 16분
Success
Details
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12.2 MB, less than 47.10% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
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
    이진 트리의 루트가 주어지면,
    지그재그로 순회했을 때 level에 따라 노드를 묶은 결과를 리턴해라.
    
    제한:
    
    해결방법:
    BFS를 통해서 해결한다.
    이전 문제와 비슷하게 해결했다. 
    1. while문안에 for문을 qSize를 통해 같은층의 노드들을 한번에 처리해줌으로서 메모리 사용을 줄이는 방법(map을 사용 안해도 됨)
    2. 그리고 trav라는 flag를 통해서 지그재그를 구현
    
    회고:
    trav != trav와 trav = !trav는 다른 의미이다! 아얘 동작이 다름. 앞에거는 그냥 비교연산일 뿐임..
    */
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        
        bool trav = false;//if false: left to right, true : right to left
        while(!q.empty()){
            TreeNode* f = q.front();
            int qSize = q.size();
            vector<int> temp;
            for(int i=0; i<qSize; i++){
                cout <<f->val << endl;
                if(f->left != NULL)
                    q.push(f->left);
                if(f->right != NULL)
                    q.push(f->right);
                
                temp.push_back(f->val);
                q.pop();
                f = q.front();
            }
            if(trav == true)
                reverse(temp.begin(), temp.end());
            trav = !trav;
            ret.push_back(temp);
                
        }
        return ret;
    }
};
