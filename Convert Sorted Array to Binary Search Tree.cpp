1차 22-04-14
Success
Time: 17분 50초
Details 
Runtime: 15 ms, faster than 76.28% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
Memory Usage: 21.5 MB, less than 40.90% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
회고: mid를 nums[(s+e)/2]로 해서 시간을 잡아먹음. (s+e)/2인데..
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
nums가 주어진다. 정수배열이고 오름차순 정렬되어있다.
이걸 balanced-binary search tree로 만들어라.

제한:

해결방법:
각 재귀 단계마다 leftSubTree와 rightSubTree로 나눈다.
그리고 가운데 인덱스를 루트노드로 설정한다.

[-10,-3,0,5,9]
0, 4: 0 root, mid : 2
    0, 1: -10 root, mid : 0
        0, -1: NULL
        1, 1: -3: mid: 1
            
    3, 4: 5 root
        3, 2: null
        4, 4: 9
            
        
    */
    TreeNode* makeTree(vector<int>& nums, int s, int e){
        //cout << s << ' ' <<e << endl;
        if(s > e)
            return NULL;
        if(s == e)
            return new TreeNode(nums[s]);
        int mid = (s+e)/2;
        //cout << mid << endl;
        TreeNode* Root = new TreeNode(nums[mid]);
        Root->left = makeTree(nums, s, mid-1);
        Root->right = makeTree(nums, mid+1, e);
        return Root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums, 0, nums.size()-1);
    }
};
