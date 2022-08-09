/*
    Given a binary tree, determine if it is height-balanced.
    
    For this problem, a height-balanced binary tree is defined as: 
    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

    Example 1:
      Input: root = [3,9,20,null,null,15,7]
      Output: true
    
    Example 2:
      Input: root = [1,2,2,3,3,null,null,4,4]
      Output: false
*/

bool ans = true;
    
int depth(TreeNode* root) {
    if(root == NULL)
        return 0;

    int left = depth(root->left);
    int right = depth(root->right);

    if(abs(left-right) > 1)
        ans = false;

    return 1 + max(left, right);
}

bool isBalanced(TreeNode* root) {
    if(root == NULL)
        return true;

    depth(root);

    return ans;
}

// Time Complexity = O(n)
