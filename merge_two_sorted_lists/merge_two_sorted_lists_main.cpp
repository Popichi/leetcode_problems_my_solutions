// This file is used to debug while solving the LeetCode problems!

#include <iostream>
#include <vector>

#define RECURSIVE_VERSION

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

#ifndef RECURSIVE_VERSION
        // Linear (Iterative) version
        ListNode* mergedListHead {};
        ListNode* currentNode {};

        while (list1 || list2) {
            if (list1 == nullptr) {
                if (currentNode == nullptr) {
                    mergedListHead = currentNode = list2;
                } else {
                    currentNode->next = list2;
                    currentNode = currentNode->next;
                }
                list2 = list2->next;
            } else if (list2 == nullptr) {
                if (currentNode == nullptr) {
                    mergedListHead = currentNode = list1;
                } else {
                    currentNode->next = list1;
                    currentNode = currentNode->next;
                }
                list1 = list1->next;
            } else if (list1->val > list2->val) {
                if (currentNode == nullptr) {
                    mergedListHead = currentNode = list2;
                } else {
                    currentNode->next = list2;
                    currentNode = currentNode->next;
                }
                list2 = list2->next;
            } else if (list1->val <= list2->val) {
                if (currentNode == nullptr) {
                    mergedListHead = currentNode = list1;
                } else {
                    currentNode->next = list1;
                    currentNode = currentNode->next;
                }
                list1 = list1->next;
            }
        }

        return mergedListHead;

#else
        // Recursive version
        // To make clear how the recursive version works, I followed the algorithm by hand using 
        // the test case 1 in the main, where List1 = [1, 2, 4] and List2 = [1, 3, 4]. This 
        // solution by hand can be found in the PDF filed named "LeetCode, 21 Merge Two Sorted 
        // Lists, Recursive Solution.pdf". It can be found in the same folder under where this 
        // solution is located.
        if (!list1 || !list2) {
            return list1 ? list1 : list2;
        }

        if (list1->val > list2->val) {
            std::swap(list1, list2);
        }

        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
#endif
    }
};

void printList(const std::vector<int>& nums) {
    std::cout << "[";
    for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
        std::cout << *it << ((it + 1 != nums.cend()) ? ", " : "");
    }
    std::cout << "]";
}

void printList(ListNode* head) {
    ListNode* current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->val;
        current = current->next;
        if (current != nullptr) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

ListNode* createList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;

    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    return head;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution sol;

    // Test Case 1
    std::vector<int> nums1 = {1, 2, 4};
    std::vector<int> nums2 = {1, 3, 4};
    ListNode* list1 = createList(nums1);
    ListNode* list2 = createList(nums2);

    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    std::cout << "Test Case 1:" << std::endl;
    std::cout << "List1: ";
    printList(nums1);
    std::cout << std::endl;
    std::cout << "List2: ";
    printList(nums2);
    std::cout << std::endl;
    std::cout << "Merged List: ";
    printList(mergedList);
    std::cout << std::endl << std::endl;

    // Clean up memory
    deleteList(mergedList);

    // Additional Test Cases

    // Test Case 2: Both lists are empty
    list1 = nullptr;
    list2 = nullptr;
    mergedList = sol.mergeTwoLists(list1, list2);
    std::cout << "Test Case 2:" << std::endl;
    std::cout << "List1: []" << std::endl;
    std::cout << "List2: []" << std::endl;
    std::cout << "Merged List: ";
    printList(mergedList);
    std::cout << std::endl << std::endl;

    // Test Case 3: One list is empty
    nums1 = {};
    nums2 = {0};
    list1 = createList(nums1);
    list2 = createList(nums2);
    mergedList = sol.mergeTwoLists(list1, list2);
    std::cout << "Test Case 3:" << std::endl;
    std::cout << "List1: ";
    printList(nums1);
    std::cout << std::endl;
    std::cout << "List2: ";
    printList(nums2);
    std::cout << std::endl;
    std::cout << "Merged List: ";
    printList(mergedList);
    std::cout << std::endl << std::endl;

    deleteList(mergedList);

    // Test Case 4: Different lengths
    nums1 = {1, 3, 5, 7};
    nums2 = {2, 4, 6};
    list1 = createList(nums1);
    list2 = createList(nums2);
    mergedList = sol.mergeTwoLists(list1, list2);
    std::cout << "Test Case 4:" << std::endl;
    std::cout << "List1: ";
    printList(nums1);
    std::cout << std::endl;
    std::cout << "List2: ";
    printList(nums2);
    std::cout << std::endl;
    std::cout << "Merged List: ";
    printList(mergedList);
    std::cout << std::endl << std::endl;

    deleteList(mergedList);

    // Test Case 5: Lists with negative values
    nums1 = {-10, -5, 0, 5};
    nums2 = {-6, -3, 2, 8};
    list1 = createList(nums1);
    list2 = createList(nums2);
    mergedList = sol.mergeTwoLists(list1, list2);
    std::cout << "Test Case 5:" << std::endl;
    std::cout << "List1: ";
    printList(nums1);
    std::cout << std::endl;
    std::cout << "List2: ";
    printList(nums2);
    std::cout << std::endl;
    std::cout << "Merged List: ";
    printList(mergedList);
    std::cout << std::endl << std::endl;

    deleteList(mergedList);

    return 0;
}
