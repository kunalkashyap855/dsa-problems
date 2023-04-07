"""
    Given the root of a binary tree, flatten the tree into a "linked list":
      The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer 
      is always null.
      
      The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
    Example 1:
      Input: root = [1,2,5,3,4,null,6]
      Output: [1,null,2,null,3,null,4,null,5,null,6]
"""

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> TreeNode:
        if root.left == None and root.right == None:
            return root

        if root.left and root.right:
            return self.dfs(root.right)
        elif root.left:
            return self.dfs(root.left)

        return self.dfs(root.right)
        

    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root or (root.left == None and root.right == None):
            return
        
        if root.left and root.right:
            self.flatten(root.left)
            self.flatten(root.right)
            temp = root.right
            root.right = root.left
            root.left = None
            last = self.dfs(root.right)
            last.right = temp
            return
        elif root.left:
            root.right = root.left
            root.left = None
            self.flatten(root.right)
            return
        
        self.flatten(root.right)

# Time Complexity = O(N) where N is the number of node
# Space Complexity = O(1)
