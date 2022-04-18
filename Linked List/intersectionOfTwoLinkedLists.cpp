/*
    Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
    If the two linked lists have no intersection at all, return null.
    
    The test cases are generated such that there are no cycles anywhere in the entire linked structure.
    
    Example 1:
      Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
      Output: Intersected at '8'
      Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
        From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; 
        There are 3 nodes before the intersected node in B.
    
    Example 2:
      Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
      Output: Intersected at '2'
      Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
        From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. 
        There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;

    ListNode* a = headA;
    ListNode* b = headB;

    while(a != b) {
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }

    return a;
}

// Time Complexity = O(n); Space Complexity = O(1)
