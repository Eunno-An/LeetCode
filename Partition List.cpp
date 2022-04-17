1차
Success
시간:35분 30초
Details 
Runtime: 17 ms, faster than 5.70% of C++ online submissions for Partition List.
Memory Usage: 10.5 MB, less than 13.38% of C++ online submissions for Partition List.
  
2차 22-04-17
Success
Time: 33분 33초
Details 
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Partition List.
Memory Usage: 10.3 MB, less than 33.30% of C++ online submissions for Partition List.
회고:
->벡터를 사용하지 않고 했다. 리스트 안에서 해결하는 방법 사용했음.
class Solution {
public:
  /*
  문제:
  리스트 파티셔닝
  제한:
  해결방법:
  -> 리스트 안에서 해결하기(중도 실패)->2차는 리스트 안에서 해결하는 방법으로 성공하였음.
  -> 벡터에 넣고 해결하기(성공) 단, 40번째 줄 없으면 에러난다! 반드시 처리해주어야 함.
    ->아니면 그냥 리스트 두개를 만들어도 될듯. 벡터 굳이 안하고.
  */
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        ListNode* ret = dummy;
        vector<ListNode*> a, b;
        while(head != NULL){
            if(head->val < x)
                a.push_back(head);
            else
                b.push_back(head);
            head = head->next;
        }
        
        for(int i=0; i<a.size(); i++){
            dummy->next = a[i];
            dummy = dummy->next;//dummy = a[i];
            cout << dummy->val << endl;
        }
        
        for(int i=0; i<b.size(); i++){
            dummy->next = b[i];
            dummy = dummy->next;
            cout << dummy->val << endl;
        }
        dummy->next = NULL;//이게 없으면 런타임에러나네
        return ret->next;
    }
  //2차 해결방법
 class Solution {
public:
    /*
    해결방법:
    start 노드를 따로 잡고, 
    만약 head->val < x인 경우, 
    prev->next = head->next;
    head->next = start->next;
    start->next = head;
    start = start->next;
    위와 같은 네단계를 걸쳐서 옮겨준다.
    쉽게 생각하면 x보다 작은 node는 왼쪽으로 옮겨주는데
    그 왼쪽의 기준이 start라는 Node인 것이다.
    */
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        
        ListNode *prev = dummyNode;
        
        ListNode *start = dummyNode;
        while(head != NULL){
            if(head->val < x){
                prev->next = head->next;
                head->next = start->next;
                start->next = head;
                start = start->next;
            }
            prev = head;
            head=head->next;
        }
        return dummyNode->next;
    }
};
};
