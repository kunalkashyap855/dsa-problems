/*
    Given the root of a binary tree, flatten the tree into a "linked list":
      The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer 
      is always null.
      
      The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
    Example 1:
      Input: root = [1,2,5,3,4,null,6]
      Output: [1,null,2,null,3,null,4,null,5,null,6]
*/

TreeNode* dfs(TreeNode* root) {
    if(root->left == NULL && root->right == NULL)
        return root;

    if(root->left && root->right)
        return dfs(root->right);
    else if(root->left)
        return dfs(root->left);

    return dfs(root->right);
}

void flatten(TreeNode* root) {
    if(!root || (root->left == NULL && root->right == NULL))
        return;

    if(root->left && root->right) {
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        flatten(root->right);
        TreeNode* last = dfs(root->right);
        flatten(temp);
        last->right = temp;
        return;
    } else if(root->left) {
        root->right = root->left;
        root->left = NULL;
        flatten(root->right);
        return;
    }

    flatten(root->right);
}

// Time Complexity = O(N) where N is the number of node
// Space Complexity = O(1)
