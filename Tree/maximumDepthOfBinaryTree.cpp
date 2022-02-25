/*
    Given the root of a binary tree, return its maximum depth.
    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    Example:
      Input: root = [3,9,20,null,null,15,7]
      Output: 3
*/

int maxDepth(TreeNode* root) {
    if(root == NULL)
        return 0;

    int depth = 1;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    depth += max(left, right);

    return depth;
}

// Time Complexity = O(h) <= 'h' is the height of the tree
