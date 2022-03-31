1차
Success
시간:35분 30초
Details 
Runtime: 17 ms, faster than 5.70% of C++ online submissions for Partition List.
Memory Usage: 10.5 MB, less than 13.38% of C++ online submissions for Partition List.
class Solution {
public:
  /*
  문제:
  리스트 파티셔닝
  제한:
  해결방법:
  -> 리스트 안에서 해결하기(중도 실패)
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
  //두번째 해결방법 벡터 안쓰고 그냥 포인터끼리 합치기.
  ListNode* partition(ListNode* head, int x) {
        ListNode *fdum = new ListNode(0), *bdum = new ListNode(0),
                 *front = fdum, *back = bdum, *curr = head;
        while (curr) {
            if (curr->val < x) front->next = curr, front = curr;
            else back->next = curr, back = curr;
            curr = curr->next;
        }
        front->next = bdum->next, back->next = nullptr;
        return fdum->next;
    }
  };
};
