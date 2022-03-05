/*
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:
      The left subtree of a node contains only nodes with keys less than the node's key.
      The right subtree of a node contains only nodes with keys greater than the node's key.
      Both the left and right subtrees must also be binary search trees.
      
    Example 1:
      Input: root = [2,1,3]
      Output: true
      
    Example 2:
      Input: root = [5,1,4,null,null,3,6]
      Output: false
      Explanation: The root node's value is 5 but its right child's value is 4.
*/

void inorderTraversal(vector<int> &inorder, TreeNode* root) {
    if(root == NULL)
        return;

    inorderTraversal(inorder, root->left);     
    inorder.push_back(root->val);
    inorderTraversal(inorder, root->right);
}

bool isValidBST(TreeNode* root) {
    if(root == NULL)
        return true;

    vector<int> inorder;

    // Store tree as an inorder traversal vector
    inorderTraversal(inorder, root);

    // Check if inorder traversal vector is sorted in ascending order or not (for BST, inorder will be sorted in ascending order always)
    for(int i = 1; i < inorder.size(); i++) {
        if(inorder[i] <= inorder[i-1])
            return false;
    }

    return true;
}

// Time Complexity = O(h)
