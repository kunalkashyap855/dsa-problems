/*
    Given the head of a singly linked list, return true if it is a palindrome.

    Example 1:
      Input: head = [1,2,2,1]
      Output: true
    
    Example 2:
      Input: head = [1,2]
      Output: false
*/

bool isPalindrome(ListNode* head) {
    if(head->next == NULL)
        return true;

    ListNode* slow = head;
    ListNode* fast = head;

    // get to middle of LL
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // reverse second half of LL
    ListNode* prev = NULL;
    while(slow) {
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // check for palindrome
    ListNode* left = head;
    ListNode* right = prev;
    while(right) {
        if(left->val != right->val)
            return false;

        left = left->next;
        right = right->next;
    }

    return true;
}

// Time Complexity = O(n); Space Complexity = O(1)
// Here, we use the concepts of fast and slow pointers and reversing a linked list in-place. With the help of two pointers we can identify the mid-point
// of the linked list, and then we can reverse the second half of the linked list and then simply check for palindrome in the two halves.
// A less space efficient way is to copy the LL, reverse it completely, and compare for palindrome in the two linked lists.
