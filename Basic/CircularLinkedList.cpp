#include <iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;

        Node(){}

        Node(int key, int data = 0, Node* next = nullptr){
            this -> key = key;
            this -> data = data;
            this -> next = next;
        }

        void show(){
            cout << "Key: " << key << "Data: " << data << endl;
        }
};

class CircularLinkedList{

    private:
        Node* head;
        int size;

    public:
        CircularLinkedList();
        ~CircularLinkedList();
        int getSize();
        bool isEmpty();
        void append(int key, int data);
        void prepend(int key, int data);
        bool remove(int key);
        void insertAfter(int keyA, int key, int data);
        void insertBefore(int keyB, int key, int data);
        void traverse();
        bool search(int key);
        bool update(int key, int data);
};

CircularLinkedList :: CircularLinkedList(){
    this->head = nullptr;
    this->size = 0;
}

CircularLinkedList :: ~CircularLinkedList(){
    Node* ptr = head;
    while (ptr != nullptr){
        Node* node = ptr;
        ptr = ptr->next;
        delete node;
    }
}

int CircularLinkedList :: getSize(){
    return size;
}

bool CircularLinkedList :: isEmpty(){
    return size == 0;
}

void CircularLinkedList :: traverse(){
    Node* ptr = head;
    bool flag = (ptr == nullptr);

    while (!flag){
        ptr -> show();
        ptr = ptr->next;
        flag = (ptr == head);
    }
}

bool CircularLinkedList :: search(int key){
    Node* ptr = head;
    bool flag = (ptr == nullptr);

    while (!flag){
        if (ptr->key == key)
            return true;
        ptr = ptr->next;
        flag = (ptr == head);
    }
    return false;
}

bool CircularLinkedList :: update(int key, int data){
    Node* ptr = head;
    bool flag = (ptr == nullptr);

    while (!flag){
        if (ptr->key == key){
            ptr->data = data;
            return true;
        }
        ptr = ptr->next;
        flag = (ptr == head)
    }
    return false;
}

void CircularLinkedList :: append(int key, int data = 0){
    Node node = new Node(key, data);
    if (head == nullptr){
        head = node;
        head->next = head;
    }
    else{
        Node* ptr = head;
        bool flag = true;

        while (flag){
            ptr = ptr->next;
            flag = (ptr->next != head);
        }

        ptr->next = node;
        node->next = head;
    }
    size++;
}




int main(){
    cout << "Hello, World!\n";

    CircularLinkedList L;

    return 0;
}