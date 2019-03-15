#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

bool LinkedList::addData(const MyData &data)
{
    Node* newNode;
    newNode = new Node();
    if (newNode == nullptr) {
        return false;
    }

    newNode->data = data;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
    return true;
}

bool LinkedList::isEmpty()
{
    return head == nullptr;
}


bool LinkedList::deleteNode(Node* node)
{
    if (node == nullptr) {
        return false;
    }
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }
    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }
    delete node;
    return true;
}

Node * LinkedList::findData(const int &key) const {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data.a == key) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool LinkedList::printNode(const Node *const node) const {
    if (node == nullptr) {
        return false;
    }
    node->data.output();
    return true;
}

void LinkedList::printAll() const {
    Node *temp = head;
    while (temp != nullptr) {
        temp->data.output();
        temp = temp->next;
    }
}

Node *LinkedList::findMax() const {
    if (head == nullptr) {
        return nullptr;
    }
    
    Node *max = head;
    Node *temp = head->next;

    while (temp != nullptr) {
        if (temp->data.a > max->data.a) {
            max = temp;
        }

        temp = temp->next;
    }
    return max;
}

Node *LinkedList::findMin() const {
    if (head == nullptr) {
        return nullptr;
    }
    
    Node *min = head;
    Node *temp = head->next;

    while (temp != nullptr) {
        if (temp->data.a < min->data.a) {
            min = temp;
        }

        temp = temp->next;
    }
    return min;
}

bool LinkedList::update(Node *const node, const MyData &data) {
    if (node == nullptr) {
        return false;
    }
    node->data = data;
    return true;
}