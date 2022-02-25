/*
    Given the roots of two binary trees p and q, write a function to check if they are the same or not.
    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

    Example 1:
      Input: p = [1,2,3], q = [1,2,3]
      Output: true
    
    Example 2:
      Input: p = [1,2], q = [1,null,2]
      Output: false
*/

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL)
        return true;
    else if(p == NULL || q == NULL || p->val != q->val)
        return false;

    return (isSameTree(p->left, q->left) & isSameTree(p->right, q->right));
}

// Time Complexity = O(h) <= 'h' is the height of the smaller tree or both the trees if they are same.
