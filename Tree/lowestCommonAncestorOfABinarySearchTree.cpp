/*
    Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node 
    in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

    Example 1:
      Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
      Output: 6
      Explanation: The LCA of nodes 2 and 8 is 6.
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* LCA = NULL;

    if(p->val > root->val && q->val > root->val && root->right != NULL) {
        LCA = root->right;
        return lowestCommonAncestor(LCA, p, q);
    }

    if(p->val < root->val && q->val < root->val && root->left != NULL) {
        LCA = root->left;
        return lowestCommonAncestor(LCA, p, q);
    }

    return root;
}

// Time Complexity = O(h)
