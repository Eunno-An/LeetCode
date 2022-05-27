1차 22-05-27 Fail
이유? Recursive는 쉬운데 Iterative가 어려움.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        TreeNode* curr = root;
        stack<TreeNode*> s;
        if(root==NULL)
        {
            return ans;
        }
        while(curr!=NULL || !s.empty()) // curr가 NULL이고 s가 비어있으면 종료한다.
        {
            if(curr!=NULL)//만약 현재 노드가 NULL이 아니라면?
            {
                s.push(curr);//스택에 집어넣고
                curr = curr->left;//왼쪽으로 이동한다.
            }
            else//만약 현재 노드가 NULL, 즉 어떤 노드부터 시작해서 왼쪽 끝으로 이동했을 때
            {
                TreeNode* temp = s.top()->right;//s의 top은 현재 왼쪽 끝 노드. 이 노드의 오른쪽 노드를 temp라고 저장하자.
                if(temp !=NULL)//오른쪽 노드가 존재한다면?
                {
                    curr = temp;//현재 노드를 temp라고 하자.
                }
                else//만약 오른쪽 노드가 없으면? 얘는 ans에 집어넣을 수 있다.
                {
                    temp = s.top();//temp는 s의 top.
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && temp == s.top()->right)//temp의 오른쪽 노드들을 쭉 보겠다! 
                    {
                        temp = s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }     
                }
            }
        }
        return ans;
    }
};
