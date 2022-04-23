1차 22-04-23 Fail
회고:
세부 구현에서 막힘. 아이디어는 알았는데..
Follow up 구현 실패.. ㅠ
class Solution {
public:

/*
문제: 이진 트리에서 level order순으로 링크드리스트 만들고 ,리스트의 헤더 리턴해라
Follow up: 추가 상수 공간만 사용해라.
*/
    Node* connect(Node* root) {
        // support variables
        Node *currParent = root, *baseChild, *currChild, *nextChild;
        while (currParent) {
            // skipping childless parents - get a family - up to the last node
            while (currParent->next && !currParent->left && !currParent->right) currParent = currParent->next;
            // setting the new basechild, provided we have one at all
            
            //cout << currParent->val << endl;
            currChild = baseChild = currParent->left ? currParent->left : currParent->right;
            
            //cout << currChild->val << ' ' << baseChild->val << endl;
            //현재 level에서 child들의 next를 수정해준다.
            while (currChild) {
                // getting nextChild - either the right sibling of currChild or...
                if (currParent->right && currChild != currParent->right) nextChild = currParent->right;
                // the child of a following parent
                else {
                    // moving to the nextParent, if any
                    currParent = currParent->next;
                    // moving parents, if we have too
                    while (currParent && !currParent->left && !currParent->right) currParent = currParent->next;
                    // setting nextChild to be the next left/right child, if any; NULL otherwise
                    nextChild = currParent ? currParent->left ? currParent->left : currParent->right : currParent;
                }
                currChild->next = nextChild;
                currChild = nextChild;
            }
            //currParent를 baseChild로 바꿔준다.
            // preparing for the next loop
            currParent = baseChild;
        }
        return root;
    }
};
