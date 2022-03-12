/*
    Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

    Example 1:
      Input: root = [3,1,4,null,2], k = 1
      Output: 1
*/

void inorderTraversal(vector<int> &inorder, TreeNode* root) {
    if(root == NULL)
        return;

    inorderTraversal(inorder, root->left);     
    inorder.push_back(root->val);
    inorderTraversal(inorder, root->right);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> inorder;

    // Store tree as an inorder traversal vector
    inorderTraversal(inorder, root);

    return inorder[k-1];
}

// Time Complexity = O(h)
