# include <iostream>
using namespace std;

class Node{
    public:
        int key, data;
        Node* next;
        Node* prev;

        Node(){}

        Node(int key, int data = 0, Node* prev = nullptr, Node* next = nullptr){
            this->key = key;
            this->data = data;
            this->prev = prev;
            this->next = next;
        }

        void show(){
            cout << "Key: " << key << "\tData: " << data << endl;
        }
};


class DoublyLinkedList{

    private:
        Node* head;
        int size;

    public:
        DoublyLinkedList();
        void append(int key, int data);
        void prepend(int key, int data);
        int getSize();
        bool isEmpty();
        void traverse();
        bool search(int key);
        bool update(int key, int data);
        void insert(int keyA, int key, int data);
        bool remove(int key);
};

DoublyLinkedList :: DoublyLinkedList(){
    this->head = nullptr;
    this->size = 0;
}

int DoublyLinkedList :: getSize(){
    return size;
}

bool DoublyLinkedList :: isEmpty(){
    return size == 0;
}

void DoublyLinkedList :: traverse(){
    Node* ptr = head;
    while (ptr != nullptr){
        ptr->show();
        ptr = ptr->next;
    }
}

bool DoublyLinkedList :: search(int key){
    Node *ptr = head;
    while (ptr != nullptr){
        if (ptr->key == key)
            return true;
        ptr = ptr->next;
    }
    return false;
}

bool DoublyLinkedList :: update(int key, int data){
    Node *ptr = head;
    while (ptr != nullptr){
        if (ptr->key == key){
            ptr->data = data;
            return true;
        }
        ptr = ptr->next;
    }
    return false;

}

void DoublyLinkedList :: append(int key, int data = 0){
    Node* node = new Node(key, data);

    if (isEmpty()){
        head = node;
    }
    else{
        Node* ptr = head;
        while (ptr->next != nullptr){
            ptr = ptr->next;
        }

        ptr->next = node;
        node->prev = ptr;
    }

    size++;
}

void DoublyLinkedList :: prepend(int key, int data=0){
    Node* node = new Node(key, data);

    if(isEmpty()){
        head = node;
    }
    else{
        node->next = head;
        head->prev = node;
        head = node;
    }
    size++;
}


int main()
{
    cout << "Hello, World!"<<endl;
    DoublyLinkedList L;
    return 0;
}
