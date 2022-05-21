1차 22-05-21
Success
Time:11분 35초
Details 
Runtime: 7 ms, faster than 96.94% of C++ online submissions for Linked List Cycle.
Memory Usage: 7.8 MB, less than 96.15% of C++ online submissions for Linked List Cycle.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    문제:
    링크드 리스트의 head가 주어지면, 리스트에 cycle이 있는지 확인해라.
    
    Follow-up:
    O(1)의 extra memory에 해결할 수 있는가?
    
    제한:
    
    해결방법:
    1) unordered_map을 써서 할 수 있겠지. 근데 추가 메모리는 O(n)..
    2) 노드의 개수를 세는데, 만약 while문이 노드 최대 개수인 10000보다 많이 돌 경우 리턴한다.
    
    */
    bool hasCycle(ListNode *head) {
        int maxCount = 10001;
        int count = 0;
        while(head != NULL && count < maxCount){
            head = head->next;
            count++;
        }
        return count == maxCount ? true : false;
        
    }
};
