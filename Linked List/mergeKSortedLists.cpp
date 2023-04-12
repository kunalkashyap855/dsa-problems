/*
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

    Merge all the linked-lists into one sorted linked-list and return it.

    Example 1:
      Input: lists = [[1,4,5],[1,3,4],[2,6]]
      Output: [1,1,2,3,4,4,5,6]
      Explanation: The linked-lists are:
      [
        1->4->5,
        1->3->4,
        2->6
      ]
      merging them into one sorted list:
      1->1->2->3->4->4->5->6
*/

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0)
        return NULL;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < lists.size(); i++) {
        ListNode* temp = lists[i];
        while(temp != NULL) {
            pq.push(temp->val);
            temp = temp->next;
        }
    }

    if(pq.empty())
        return NULL;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    while(!pq.empty()) {
        int newVal = pq.top();
        pq.pop();

        ListNode* temp = new ListNode(newVal);

        if(!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    if(tail)
        tail->next = NULL;

    return head;
}

// Time Complexity = O(NlogN)
