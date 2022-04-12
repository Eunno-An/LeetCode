1차 22-03-29 
Success
Details
소요시간:35분
Runtime: 12 ms, faster than 46.03% of C++ online submissions for Remove Duplicates from Sorted List II.
Memory Usage: 11.7 MB, less than 10.30% of C++ online submissions for Remove Duplicates from Sorted List II.
    
2차 22-04-12
Success
Details 
소요시간:40
Runtime: 11 ms, faster than 54.32% of C++ online submissions for Remove Duplicates from Sorted List II.
Memory Usage: 11 MB, less than 99.61% of C++ online submissions for Remove Duplicates from Sorted List II.
회고:
아래 코드 첨부. 훨씬 간결하게 코드 짬. 하지만 생각치 못한 예외가 있었음. 0 1 1 같은것임. 바로 뒤에 중복이 걸리는 경운데 이는 
if(dup){
                head=head->next;
                if(head == NULL)
                    prev->next = NULL;
                continue;
            }
head 가 NULL일 때 prev의 next를 NULL에 연결해 주는 것으로 해결하였음.
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
    /*
    문제: 
    정렬된 링크드리스트의 헤더가 주어진다.
    중복된 노드를 갖는 모든 요소들을 없애라.
    뿐만아니라 링크드리스트는 정렬되어 있어야 한다.
    
    제한: 
    
    해결방법:
    unordered_map<int, int> 로 값들을 저장한다.
    pprev, prev, head 세개의 포인터를 사용한다. 왜냐하면 2 3 3 같은 경우 처음 3을 보면 두번째 3이 중복인지 모르기 때문에 2를 가르키는 무언가가 있어야 한다. 그게 pprev이다.
    
    
    회고
    - 1차
      ->list가 null일때, 하나만 있을 때에 대한 예외처리를 생각 안해주었음.
      ->그리고 반드시 next는 지정해주어야 한다. pprev에 대한 next를 지정해주지않으면 값이 뜨는게 없음. 얘도 애초에 포인터니까 일일히 next를 가르켜주어야 함.
      ->좋은 풀이 밑에 첨부하였음. 그리고 이런 유형을 Sentinel Head + Predecessor라고 한다.
*/
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* prev = head;
        ListNode* pprev = new ListNode(-1);
        ListNode* ret = pprev;
        
        
        unordered_map<int, int> bucket;
        bucket[head->val] = 1;
        
        head = head->next;
        prev->next = head;
        pprev->next = prev;
        while(head != NULL){
            int nowVal = head->val;
            //cout << nowVal << endl;
            if(bucket.find(nowVal) == bucket.end()){
                bucket.insert(make_pair(nowVal, 1));//bucket의 nowVal 등장 빈도를 저장하고
                pprev->next = prev;
                pprev = prev;
                prev->next = head;
                prev = head;//prev를 head로 바꾼다.
                head = head->next;
                //cout << pprev->val << ' ' << prev->val << ' ' << head->val << endl;
            }
            else{//2 3 3같은 상황이 발생된 경우
                while(head != NULL && bucket.find(head->val) != bucket.end()){//이어줄 곳을 찾는다.
                    head = head->next;
                }
                if(head != NULL){
                    
                    bucket[head->val]++;
                    prev = head;
                    head = head->next;
                    pprev->next = prev;
                    //cout << pprev->val << ' ';
                    //cout << prev->val << ' ';
                    //cout << head->val << endl;
                }
                else{
                    pprev->next = NULL;
                    //cout << pprev->val << endl;
                }
            }
            
        }
        return ret->next;
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next = head;
        while(head!=NULL){
            bool dup = false;
            while(head->next != NULL and head->val == head->next->val){
                dup=true;//중복 발생! 얘는 아얘 없애줄꺼니까 나중에 한번 더 next시켜야 함.
                head=head->next;
            }    
            if(dup){
                head=head->next;
                if(head == NULL)
                    prev->next = NULL;
                continue;
            }
            prev->next=head;
            prev=head;
            head=head->next;
            //cout << head->val << endl;
        }
        
        return dummy->next;
    }
};
