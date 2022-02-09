/*
    Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure
    and node values of subRoot and false otherwise.

    A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants.
    The tree tree could also be considered as a subtree of itself.
    
    Input: root = [3,4,5,1,2], subRoot = [4,1,2]
    Output: true
*/

bool isSameTree(TreeNode* root, TreeNode* subRoot) {
    if(root == NULL || subRoot == NULL)
        return root == NULL && subRoot == NULL;
    else if(root->val == subRoot->val)
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);

    return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root == NULL)
        return false;
    else if(isSameTree(root, subRoot))
        return true;
    else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// Time Complexity = O(n)
