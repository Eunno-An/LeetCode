//첫번째 풀이: fail. Bad Code에 참고.
//틀린 이유: 1->2->3->4에서 결과가 2->1->3이 나옴. 왜냐하면 2->1을 수행하고 난 후, 1->3을 가리키게 되는데 그 과정에서 3이 NULL을 가르키게 됨.
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
class Solution {
public:
    //문제를 부분문제로 잘게 쪼개야 하는 이유.
    
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp;
        temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        
        return temp;
    }
};

//두번째 복습 2022-02-02 
//소요시간: 13분 09
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
Memory Usage: 7.5 MB, less than 54.81% of C++ online submissions for Swap Nodes in Pairs.
회고: 첫 풀이때 헷갈렸던 부분을 차분하게 구현한 것 같다.
*/
ListNode* swapPairs(ListNode* head) {
        ListNode* ret = new ListNode(0);
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* one = head;
        ListNode* two = one->next;
        ListNode* before = new ListNode(0);
        ret->next = two;
        while(one!=NULL && two!=NULL){
            before->next = two;
            one->next = two->next;
            two->next = one;
            before = one;
            one = one->next;
            if(one == NULL)
                break;
            two = one->next;
            //cout << one->val << ' ' << two->val << endl;
        }
        return ret->next;
    }
