#include <iostream>

using namespace std;

class Node {

public:

    int data;

    Node* next;

    Node* prev;

};

void addFront(Node** head_ref, int new_data) {

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    new_node->prev = NULL;

    if ((*head_ref) != NULL)

        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;

}

void addAfter(Node* prev_node, int new_data) {

    if (prev_node == NULL) {

        cout << "The given previous node cannot be NULL";

        return;

    }

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != NULL)

        new_node->next->prev = new_node;

}

void addEnd(Node** head_ref, int new_data) {

    Node* new_node = new Node();

    Node* last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL) {

        *head_ref = new_node;

        new_node->prev = NULL;

        return;

    }

    while (last->next != NULL) {

        last = last->next;

    }

    last->next = new_node;

    new_node->prev = last;

}

// Helper function to print the linked list

void printList(Node* node) {

    while (node != NULL) {

        cout << node->data << " ";

        node = node->next;

    }

    cout << endl;

}

int main() {

    Node* head = NULL;

    addEnd(&head, 10);

    addFront(&head, 5);

    addEnd(&head, 20);

    addAfter(head->next, 15);

    cout << "Linked list: ";

    printList(head);

    return 0;

}
