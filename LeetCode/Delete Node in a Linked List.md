# Delete Node in a Linked List

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *nextNode = node->next;
        *node = *nextNode;
        delete nextNode;
    }
};
```

- 문제 해석이 난해한 trash problem 이었다.
- 앞으로는 vote수 보고 문제를 걸러야겠다...