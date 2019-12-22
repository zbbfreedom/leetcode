//
// Created by suzumiya on 2019/12/22.
//

#include "add_two_number.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// 41805  76285  180901
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    bool needAddOne = false;
    ListNode *result = new ListNode(0);
    ListNode *ret_value = result;
    ListNode *preNode = nullptr;
    while (l1 != nullptr && l2 != nullptr) {
        int addL1AndL2 = l1->val + l2->val + (needAddOne ? 1 : 0);
        if (addL1AndL2 >= 10) {
            needAddOne = true;
        } else {
            needAddOne = false;
        }
        addL1AndL2 = addL1AndL2 - (addL1AndL2 / 10) * 10;
        if (result == nullptr) {
            result = new ListNode(addL1AndL2);
        } else {
            result->val = addL1AndL2;
        }
        if (preNode != nullptr) {
            preNode->next = result;
        }
        preNode = result;
        result = result->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr) {
        int l1Num = l1->val + (needAddOne ? 1 : 0);
        if (l1Num >= 10) {
            needAddOne = true;
        } else {
            needAddOne = false;
        }
        l1Num = l1Num - (l1Num / 10) * 10;
        if (result == nullptr) {
            result = new ListNode(l1Num);
        } else {
            result->val = l1Num;
        }
        if (preNode != nullptr) {
            preNode->next = result;
        }
        preNode = result;
        result = result->next;

        l1 = l1->next;
    }
    while (l2 != nullptr) {
        int l2Num = l2->val + (needAddOne ? 1 : 0);
        if (l2Num >= 10) {
            needAddOne = true;
        } else {
            needAddOne = false;
        }
        l2Num = l2Num - (l2Num / 10) * 10;
        if (result == nullptr) {
            result = new ListNode(l2Num);
        } else {
            result->val = l2Num;
        }
        if (preNode != nullptr) {
            preNode->next = result;
        }
        preNode = result;
        result = result->next;

        l2 = l2->next;
    }

    if (needAddOne) {
        preNode->next = new ListNode(1);
    }

    return ret_value;

}

void add_two_number::test() {
    ListNode *left;
    {
        ListNode *n1 = new ListNode(1);
        ListNode *n2 = new ListNode(2);
        ListNode *n3 = new ListNode(3);
        ListNode *n5 = new ListNode(5);
        ListNode *n6 = new ListNode(6);
        ListNode *n7 = new ListNode(7);
        ListNode *n8 = new ListNode(8);

        ListNode *n0 = new ListNode(0);

        left = new ListNode(4);
        left->next = n1;
        n1->next = n8;
        n8->next = n0;
        n0->next = n5;

    }
    ListNode *right;
    {
        ListNode *n1 = new ListNode(1);
        ListNode *n2 = new ListNode(2);
        ListNode *n3 = new ListNode(3);
        ListNode *n5 = new ListNode(5);
        ListNode *n6 = new ListNode(6);
        ListNode *n7 = new ListNode(7);
        ListNode *n8 = new ListNode(8);

        ListNode *n0 = new ListNode(0);

        right = new ListNode(7);
        right->next = n6;
        n6->next = n2;
        n2->next = n8;
        n8->next = n5;

    }

    addTwoNumbers(left, right);
    int a = 0;


}
