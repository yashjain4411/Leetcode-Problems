#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) {
            return head;
        }
        int lengthOfList = 0;
        ListNode *temp = head;
        ListNode *last = head;
        while (temp != NULL) {
            last = temp;
            temp = temp->next;
            lengthOfList++;
        }
        k %= lengthOfList;
        if (k == 0) {
            return head;
        }
        int numberOfVisitedNodes = 0;
        temp = head;
        while (numberOfVisitedNodes < lengthOfList - k - 1) {
            numberOfVisitedNodes++;
            temp = temp->next;
        }
        last->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};