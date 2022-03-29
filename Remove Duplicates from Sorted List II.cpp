1차 22-03-29 
Success
Details
소요시간:35분
Runtime: 12 ms, faster than 46.03% of C++ online submissions for Remove Duplicates from Sorted List II.
Memory Usage: 11.7 MB, less than 10.30% of C++ online submissions for Remove Duplicates from Sorted List II.
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
