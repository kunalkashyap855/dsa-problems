/*
    Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

    Example 1:
      Input: head = [1,2,3,4]
      Output: [2,1,4,3]
*/

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* left = head;
    ListNode* right = head->next;

    ListNode* nextHead = right->next;        
    right->next = left;
    left->next = swapPairs(nextHead);


    return right;
}

// Time Complexity = O(n)
