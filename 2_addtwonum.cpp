#include <iostream>
#include <unordered_map>
#include <vector>

// Ref: https://leetcode.com/problems/add-two-numbers/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

inline int add(ListNode* node, int a, int b, int carry) {
  int sum = a + b + carry;
  int mod = sum % 10;
  carry = (sum / 10) % 10;
  node->val = mod;
  return carry;
}

void printList(ListNode* node) {
  if (node == nullptr) return;
  printList(node->next);
  std::cout << node->val << "";
}

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* head = nullptr;
    ListNode* node = nullptr;

    while (l1 && l2) {
      ListNode* tempNode = new ListNode();
      carry = add(tempNode, l1->val, l2->val, carry);

      if (head == nullptr) {
        head = tempNode;
        node = head;
      } else {
        node->next = tempNode;
        node = node->next;
      }
      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1) {
      ListNode* tempNode = new ListNode();
      carry = add(tempNode, l1->val, 0, carry);
      node->next = tempNode;
      node = node->next;
      l1 = l1->next;
    }

    while (l2) {
      ListNode* tempNode = new ListNode();
      carry = add(tempNode, 0, l2->val, carry);
      node->next = tempNode;
      node = node->next;
      l2 = l2->next;
    }

    if (carry > 0) {
      ListNode* tempNode = new ListNode(carry);
      node->next = tempNode;
      node = node->next;
    }
    return head;
  }
};

void printEquation(ListNode* a, ListNode* b) {
  Solution* sol;
  printList(a);
  std::cout << " + ";
  printList(b);
  std::cout << " = ";
  printList(sol->addTwoNumbers(a, b));
  std::cout << std::endl;
}

int main() {

  // Test Case 1
  // 342 + 465 = 807
  ListNode* case1a = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode* case1b = new ListNode(5, new ListNode(6, new ListNode(4)));
  printEquation(case1a, case1b);

  // Test Case 2
  // 9 + 9 = 18
  ListNode* case2a = new ListNode(9);
  ListNode* case2b = new ListNode(9);
  printEquation(case2a, case2b);

  // Test Case 3
  // 99 + 9 = 108
  ListNode* case3a = new ListNode(9, new ListNode(9));
  ListNode* case3b = new ListNode(9);
  printEquation(case3a, case3b);
}