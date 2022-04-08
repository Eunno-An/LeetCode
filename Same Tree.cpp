100번 문제이다!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1차 22-04-08 Success
시간: 6분
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Same Tree.
Memory Usage: 10.1 MB, less than 7.39% of C++ online submissions for Same Tree.
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
    p와 q라는 binary tree가 주어진다.
    둘이 같은지 아닌지를 판별하는 코드를 작성해라.
    
    제한:
    
    해결방법:
    
    회고:
    iterative solution도 첨부하였음.
    */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q != NULL)
            return false;
        if(p != NULL && q == NULL)
            return false;
        if(p == NULL && q == NULL)
            return true;
        
//cout << p->val << ' ' << q->val << endl;
        if(p->val != q->val)
            return false;
        
        bool ret;
        ret = isSameTree(p->left, q->left);
        if(ret == false)
            return false;
        ret = isSameTree(p->right, q->right);
        if(ret == false)
            return false;
        return true;
    }
  //iterative

  
      bool isSameTree(TreeNode* p, TreeNode* q) {
          queue<TreeNode *> queue;
          queue.push(p);
          queue.push(q);
          while (queue.size()!=0){
              TreeNode * q2=queue.front();
              queue.pop();
              TreeNode * q1=queue.front();
              queue.pop();
              if (q1==nullptr && q2==nullptr) continue;
              if (q1==nullptr || q2==nullptr) return false;
              if (q1->val!=q2->val) return false;
              queue.push(q1->left);
              queue.push(q2->left);
              queue.push(q1->right);
              queue.push(q2->right);
          }
          return true;
      }
  
};
