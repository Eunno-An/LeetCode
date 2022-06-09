1차 22-04-14
Time: 19분 20초
Success
Details 
Runtime: 16 ms, faster than 99.52% of C++ online submissions for Convert Sorted List to Binary Search Tree.
Memory Usage: 28.4 MB, less than 32.85% of C++ online submissions for Convert Sorted List to Binary Search Tree.
    
2차 22-06-09
코틀린으로 풀이하였음. 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    "링크드리스트"가 주어진다. 오름차순으로 정렬되어있다.
    balanced binary search tree로 만들어라.
    
    제한:
    
    해결방법:
    각 재귀마다 왼쪽 오른쪽 나누어서 돌린다.
    단, size라는 변수를 두어 mid를 찾기 쉽게 한다.
    또한 base case는 size로 비교하면 size가 네개일 때 재귀를 돌리다보면 size는 1인데 leftTree의 노드가 두개인 경우가 발생한다.(ex -10, 4, 5, 6)
    그래서 l과 r로 바로 비교한다. 그게 더 정확하다.
    */
    TreeNode* makeTree(ListNode* l, ListNode* r, int size){
        if(l == r)
            return new TreeNode(l->val);
        if(l->next == r){
            TreeNode *ret = new TreeNode(l->val);
            TreeNode* right = new TreeNode(r->val);
            ret->right = right;
            return ret;
        }
        ListNode* mid =l;
        
        ListNode *beforeMid, *afterMid;
        for(int i=0; i<size/2-1; i++)
            mid = mid->next;
        
        
        beforeMid = mid;
        mid = mid->next;
        TreeNode* midTreeNode = new TreeNode(mid->val);
        afterMid = mid->next;
        midTreeNode->left = makeTree(l, beforeMid, (size-1)/2);
        midTreeNode->right = makeTree(afterMid, r, (size-1)/2);
        
        return midTreeNode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        int listSize = 0;
        ListNode* l = head;
        ListNode* r;
        while(head->next!=NULL)
            listSize++, head=head->next;
        r = head;
        cout << l->val << ' ' << r->val << ' ' << listSize+1 << endl;
        return makeTree(l, r, listSize+1);
    }
};
