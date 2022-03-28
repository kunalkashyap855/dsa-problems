/*
    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example 1:
      Input: l1 = [2,4,3], l2 = [5,6,4]
      Output: [7,0,8]
      Explanation: 342 + 465 = 807
    
    Example 2:
      Input: l1 = [0], l2 = [0]
      Output: [0]
    
    Example 3:
      Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
      Output: [8,9,9,9,0,0,0,1]
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        
    ListNode* ans = new ListNode();
    ans->val = l1->val + l2->val;

    int carry = 0;
    if(ans->val > 9) {
        carry = ans->val / 10;
        ans->val = ans->val % 10;
    }

    ListNode* temp1 = l1->next;
    ListNode* temp2 = l2->next;

    ListNode* temp3 = ans;
    while(temp1 != NULL || temp2 != NULL) {
        ListNode* newNode = new ListNode();

        if(temp1 != NULL && temp2 != NULL) {
            newNode->val = temp1->val + temp2->val + carry;
        } else if(temp1 != NULL)
            newNode->val = temp1->val + carry;
        else newNode->val = temp2->val + carry;

        carry = 0;

        if(newNode->val > 9) {
            carry = newNode->val/10;
            newNode->val = newNode->val % 10;
        }

        temp3->next = newNode;
        temp3 = newNode;

        if(temp1)
            temp1 = temp1->next;

        if(temp2)
            temp2 = temp2->next;

    }

    if(carry > 0)
        temp3->next = new ListNode(carry);

    return ans;
}

// Time Complexity = O(n) <= 'n' is the length of the longer input Linked List.
