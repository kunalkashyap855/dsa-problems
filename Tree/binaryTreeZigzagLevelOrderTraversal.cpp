/*
    Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, 
    then right to left for the next level and alternate between).
    
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[20,9],[15,7]]
*/

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if(root == NULL)
        return ans;

    int leftToRight = true;

    deque<TreeNode*> Q;
    Q.push_back(root);

    while(!Q.empty()) {
        vector<int> temp;
        deque<TreeNode*> dq;
        int currSize = Q.size();
        for(int i = 0; i < currSize; i++) {
            TreeNode* front = Q.front();
            Q.pop_front();

            temp.push_back(front->val);

            if(leftToRight) {
                if(front->left != NULL)
                    dq.push_front(front->left);

                if(front->right != NULL)
                    dq.push_front(front->right);
            } else {
                if(front->right != NULL)
                    dq.push_front(front->right);

                if(front->left != NULL)
                    dq.push_front(front->left);
            }
        }

        Q.insert(Q.end(), dq.begin(), dq.end());

        leftToRight = !leftToRight;
        ans.push_back(temp);
    }

    return ans;
}

// Time Complexity = O(n)
