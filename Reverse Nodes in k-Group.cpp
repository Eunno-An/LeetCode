//fail
//두개씩 노드를 swap하는 것의 일반화된 문제로서, k그룹씩 묵어서 swap하면 어떻게 되는지에 대한 문제.
//굉장히 깔끔하고 좋은 재귀 짜는 문제인 것 같다. 저번에 2Sum 3Sum.. 그리고 kSum과도 관련되는 일반화 문제이기도 하다.
//재귀로 푸는 방법과 반복문으로 푸는 방법이 있는데 
//Follow-up에는 추가 메모리 공간이 O(1)이므로, 재귀로 인한 풀이는 여기서 요구하는 바가 아니다.
//반복문으로 풀어야 한다.
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
    ListNode* getNodeAfterK(ListNode* head, int k) {
        while(head != NULL && --k != 0){//--k로 해야함.
            head = head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* afterK = getNodeAfterK(head, k);
        
        if(afterK == NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        for(int i=0; i<k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        
        head->next = reverseKGroup(curr, k);
        return prev;//왜 prev를 리턴하는지 알아놓을것.
    }
};
