1차 22-04-09 Fail
2차 22-05-18 Fail
회고
in-order를 통해서 벡터에 담아서 대칭인지 볼려고 했는데... 벡터에 값들이 원하는대로 안담겨서 대칭인지 파악을 못하였음.
다시 문제 보니까 Iterative로도 풀라고 해서 Iterative 코드 첨부하였음.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    문제:
    symmetric한지 아닌지를 리턴해라!
    거울이 가운데 있다고 생각하고 좌우가 같아야 한다.
    
    회고
    ->p와 q가 null일 때 어떻게 처리를 해주어야 할 지를 정하지 못했음. 
    */
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetricTest(root->left, root->right);
    }
    
    bool isSymmetricTest(TreeNode* p, TreeNode* q){
        if(p == NULL and q == NULL)
            return true;
        else if(p == NULL || q == NULL)
            return false;
        else if(p->val != q->val)
            return false;
        return isSymmetricTest(p->left, q->right) and 
            isSymmetricTest(p->right, q->left);
    }
};
//Iterative
class Solution
{
public:
	// recursive : 12 ms 16.7 MB
	bool isSymmetric(TreeNode* root) {
		return !root || isEquivalent(root->left, root->right);
	}

	bool isEquivalent(TreeNode* leftNode, TreeNode* rightNode)
	{
		if (!leftNode && rightNode || leftNode && !rightNode) return false;

		return !leftNode || leftNode->val == rightNode->val && isEquivalent(leftNode->left, rightNode->right) && isEquivalent(leftNode->right, rightNode->left);
	}

	// iterative : 4 ms	16.9 MB
	bool isSymmetric3(TreeNode* root) {
		if (!root) return true;
		queue<TreeNode*> pending({ root->left, root->right });

		while (!pending.empty())
		{
			TreeNode* l = pending.front();
			pending.pop();
			TreeNode* r = pending.front();
			pending.pop();

			if (!l && r || l && !r) return false;
			if (l)
			{
				if (l->val != r->val) return false;
				pending.push(l->left);
				pending.push(r->right);
				pending.push(l->right);
				pending.push(r->left);
			}
		}

		return true;
	}
};
