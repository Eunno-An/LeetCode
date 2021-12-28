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
    ListNode* getNodeAfterK(ListNode* head, int k) {//사실 이것도 이렇게 하기보단, 리스트의 길이가 k를 넘어가는지 안넘어가는지로 따지는게 더 맞음.
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
    int getLengthOfLinkedList(ListNode* head){
        ListNode* ptr = head;
        int cnt = 0;
        while(ptr){
            cnt++;
            ptr = ptr->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return NULL;
        int len = getLengthOfLinkedList(head);
        if(len < k)
            return head;
        
        int numberOfGrouptsToReverse = len/k;
        
        //진짜 dummyNode는 나중에 쉽게 결과값을 리턴하기 위해서 쓰인다!! 
        //이제 반복문에 실제로 필요한 노드는 start, 그리고 우리가 재귀에서 쓰던 prev, curr, next임!!!!
        //start는 재귀에서 쓰던 head같은 느낌인거지.
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* start = dummyNode;
        
        ListNode* pre, *remaining, *nxt;
        for(int i=0; i<numberOfGrouptsToReverse; i++){
            pre = NULL;
            remaining = head;
            for(int j=0; j<k; j++){
                nxt = head->next;
                head->next = pre;
                pre=head;
                head=nxt;
            }
            
            start->next=pre;
            remaining->next = head;
            start = remaining;
        }
        return dummyNode->next;
        
    }
};
