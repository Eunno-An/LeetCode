1차 Fail 22-04-06
  너무 어려웠다.. 코드만 보면 별거 아니지만 트리쪽에 좀 약한거같다. 몇번을 봐도 아직 완벽하게 이해는 못했다.
2차 Fail 22-05-15
  요번에도 아얘 접근도 못함.
  https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/1440190/C%2B%2B-Python-Simple-and-Short-Recursive-Solutions-With-Explanation
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
    가능한 모든 BST를 만들어라! 1부터 n까지의 수들을 이용해서!
    제한:
    해결방법:
    
    */
    vector<TreeNode*> generateTrees(int n, int s = 1) {
        vector<TreeNode*> ans;
        
        if(n < s)
            return {nullptr};
        
        //s부터 n까지 모든걸 모든 root로 고려해라.
        for(int i=s; i<=n; i++){
            
            //range [s, i)의 모든 가능 한 trees를 생성해라.
            for(auto left : generateTrees(i-1, s)){
                //range(i, e]의 모든 가능한 trees를 생성해라.
                for(auto right : generateTrees(n, i+1))
                    ans.push_back(new TreeNode(i, left, right));
            }
        }
        return ans;
    }
};
