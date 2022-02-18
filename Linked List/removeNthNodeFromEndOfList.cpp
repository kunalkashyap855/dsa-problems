/*
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    Example 1:
      Input: head = [1,2,3,4,5], n = 2
      Output: [1,2,3,5]
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* left = dummy;
    ListNode* right = head;

    while(n > 0 && right != NULL) {
        right = right->next;
        n--;
    }

    while(right != NULL) {
        left = left->next;
        right = right->next;
    }

    left->next = left->next->next;

    return dummy->next;
}

// Time Complexity = O(n) and we solve the problem in just one pass of the Linked List
