#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "Lab4_data.h"
#include "Lab4_sort.h"

//二维数组比较函数
int cmp_arr(const void* a, const void* b) {
	const int* pa = *(const int**)a;
	const int* pb = *(const int**)b;
	return pa[2] - pb[2];
}

//结构体比较函数
int cmp_struct(const void* a, const void* b) {
	return ((DATAITEM*)a)->item3 - ((DATAITEM*)b)->item3;
}

//结构体指针数组比较函数
int cmp_pstruct(const void* a, const void* b) {
	return (*(DATAITEM**)a)->item3 - (*(DATAITEM**)b)->item3;
}

// Function to get the length of the linked list
int getLength(struct Node* head) {
	int len = 0;
	struct Node* curr = head;
	while (curr != NULL) {
		len++;
		curr = curr->next;
	}
	return len;
}

// Function to perform bubble sort on the linked list
struct Node* bubbleSort_p(struct Node* head) {
	struct Node* currNode = head;
	int len = getLength(head);
	int itr = 0;
	int swapped;

	// Iterating over the whole linked list
	while (itr < len) {
		struct Node* traverseNode = head;
		struct Node* prevNode = head;
		swapped = 0;

		while (traverseNode->next != NULL) {

			// Temporary pointer to store the next
			// pointer of traverseNode
			struct Node* ptr = traverseNode->next;
			if (traverseNode->data.item3 > ptr->data.item3) {
				swapped = 1;
				if (traverseNode == head) {

					// Performing swap operations and
					// updating the head of the linked list
					traverseNode->next = ptr->next;
					ptr->next = traverseNode;
					prevNode = ptr;
					head = prevNode;
				}
				else {

					// Performing swap operation
					traverseNode->next = ptr->next;
					ptr->next = traverseNode;
					prevNode->next = ptr;
					prevNode = ptr;
				}
				continue;
			}
			prevNode = traverseNode;
			traverseNode = traverseNode->next;
		}

		// If no swap occurred, break the loop
		if (!swapped) {
			break;
		}

		++itr;
	}

	// Returning the head of the linked list
	return head;
}

// Function to perform bubble sort on the linked list
struct Node* bubbleSort_r(struct Node* head) {
	struct Node* currNode = head;
	int len = getLength(head);
	int itr = 0;
	int swapped;

	// Iterating over the whole linked list
	while (itr < len) {
		struct Node* traverseNode = head;
		struct Node* prevNode = head;
		swapped = 0;

		while (traverseNode->next != NULL) {

			// Temporary pointer to store the next
			// pointer of traverseNode
			struct Node* ptr = traverseNode->next;
			if (traverseNode->data.item3< ptr->data.item3) {
				swapped = 1;
				if (traverseNode == head) {

					// Performing swap operations and
					// updating the head of the linked list
					traverseNode->next = ptr->next;
					ptr->next = traverseNode;
					prevNode = ptr;
					head = prevNode;
				}
				else {

					// Performing swap operation
					traverseNode->next = ptr->next;
					ptr->next = traverseNode;
					prevNode->next = ptr;
					prevNode = ptr;
				}
				continue;
			}
			prevNode = traverseNode;
			traverseNode = traverseNode->next;
		}

		// If no swap occurred, break the loop
		if (!swapped) {
			break;
		}

		++itr;
	}

	// Returning the head of the linked list
	return head;
}


// Returns the last node of the list
struct Node* getTail(struct Node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the first element as the pivot
struct Node* partition_p(struct Node* head, struct Node* tail) {

    // Select the first node as the pivot node
    struct Node* pivot = head;

    // 'pre' and 'curr' are used to shift all 
    // smaller nodes' data to the left side of the pivot node
    struct Node* pre = head;
    struct Node* curr = head;

    // Traverse the list until you reach the node after the tail
    while (curr != tail->next) {

        // If current node's data is less than the pivot's data
        if (curr->data.item3 < pivot->data.item3) {

            // Swap the data between 'curr' and 'pre->next'
            DATAITEM temp = curr->data;
            curr->data = pre->next->data;
            pre->next->data= temp;

            // Move 'pre' to the next node
            pre = pre->next;
        }
        // Move 'curr' to the next node
        curr = curr->next;
    }

    // Swap the pivot's data with 'pre' data
    DATAITEM currData = pivot->data;
    pivot->data = pre->data;
    pre->data = currData;

    // Return 'pre' as the new pivot
    return pre;
}

// Helper function for quick sort
void quickSortHelper_p(struct Node* head, struct Node* tail) {

    // Base case: if the list is empty or consists of a single node
    if (head == NULL || head == tail) {
        return;
    }

    // Call partition to find the pivot node
    struct Node* pivot = partition_p(head, tail);

    // Recursive call for the left part 
      // of the list (before the pivot)
    quickSortHelper_p(head, pivot);

    // Recursive call for the right part 
      // of the list (after the pivot)
    quickSortHelper_p(pivot->next, tail);
}

// The main function for quick sort. This is a
// wrapper over quickSortHelper
struct Node* quickSort_p(struct Node* head) {

    // Find the tail of the list
    struct Node* tail = getTail(head);
    // Call the helper function to sort the list
    quickSortHelper_p(head, tail);
    return head;
}


// Partitions the list taking the first element as the pivot
struct Node* partition_r(struct Node* head, struct Node* tail) {

    // Select the first node as the pivot node
    struct Node* pivot = head;

    // 'pre' and 'curr' are used to shift all 
    // smaller nodes' data to the left side of the pivot node
    struct Node* pre = head;
    struct Node* curr = head;

    // Traverse the list until you reach the node after the tail
    while (curr != tail->next) {

        // If current node's data is less than the pivot's data
        if (curr->data.item3 > pivot->data.item3) {

            // Swap the data between 'curr' and 'pre->next'
            DATAITEM temp = curr->data;
            curr->data = pre->next->data;
            pre->next->data = temp;

            // Move 'pre' to the next node
            pre = pre->next;
        }
        // Move 'curr' to the next node
        curr = curr->next;
    }

    // Swap the pivot's data with 'pre' data
    DATAITEM currData = pivot->data;
    pivot->data = pre->data;
    pre->data = currData;

    // Return 'pre' as the new pivot
    return pre;
}

// Helper function for quick sort
void quickSortHelper_r(struct Node* head, struct Node* tail) {

    // Base case: if the list is empty or consists of a single node
    if (head == NULL || head == tail) {
        return;
    }

    // Call partition to find the pivot node
    struct Node* pivot = partition_r(head, tail);

    // Recursive call for the left part 
      // of the list (before the pivot)
    quickSortHelper_r(head, pivot);

    // Recursive call for the right part 
      // of the list (after the pivot)
    quickSortHelper_r(pivot->next, tail);
}

// The main function for quick sort. This is a
// wrapper over quickSortHelper
struct Node* quickSort_r(struct Node* head) {

    // Find the tail of the list
    struct Node* tail = getTail(head);
    // Call the helper function to sort the list
    quickSortHelper_r(head, tail);
    return head;
}