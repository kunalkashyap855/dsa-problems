/*
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

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

bool areSymmetric(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL && root2 == NULL)
        return true;
    else if((root1 == NULL) != (root2 == NULL) || root1->val != root2->val)
        return false;
    else {
        return (areSymmetric(root1->left, root2->right) && areSymmetric(root1->right, root2->left));
    }
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL) 
        return true;

    return areSymmetric(root->left, root->right);
}

// Time Complexity = O(n)
