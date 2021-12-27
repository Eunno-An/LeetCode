//fail. Bad Code에 참고.
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
