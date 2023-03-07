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


// ALTERNATE SOLUTION - Also O(n)

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* curr = head;
    int count = 0;

    while(curr) {
        curr = curr->next;
        count++;
    }

    int nodePos = count - n + 1;

    curr = head;
    ListNode* prev = NULL;
    for(int i = 1; i < nodePos; i++) {
        prev = curr;
        curr = curr->next;
    }

    if(curr != NULL && prev != NULL)
        prev->next = curr->next;
    else if(prev == NULL)
        return head->next;

    return head;
}
