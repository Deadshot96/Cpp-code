# include <iostream>
using namespace std;

class Node{
    public:
        int key, data;
        Node *prev, *next;

        Node(){
            key = 0;
            data = 0;
            prev = nullptr;
            next = nullptr;
        }

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

class DoublyCircularLinkedList{
    private:
        Node* head;
        int size;

    public:
        DoublyCircularLinkedList();
        int getSize();
        bool isEmpty();
        void traverse();
        bool search(int key);
        bool update(int key, int data);
        void append(int key, int data);
        void prepend(int key, int data);
        void insertAfter(int keyA, int key, int data);
        void insertBefore(int keyB, int key, int data);
        bool remove(int key);
        ~DoublyCircularLinkedList();

};

DoublyCircularLinkedList :: DoublyCircularLinkedList(){
    this->head = nullptr;
    this->size = 0;
}

DoublyCircularLinkedList :: ~DoublyCircularLinkedList(){
    while (head != nullptr){
        Node* ptr = head;
        head = head->next;
        delete ptr;
    }
}

int DoublyCircularLinkedList :: getSize(){
    return size;
}

bool DoublyCircularLinkedList :: isEmpty(){
    return size == 0;
}

bool DoublyCircularLinkedList :: traverse(){
    Node* ptr = head;
    bool flag = (ptr == nullptr);

    while (!flag){
        ptr->show();
        ptr = ptr->next;
        flag = (ptr == head);
    }
}


int main()
{
    cout << "Hello, World!" << endl;
    DoublyCircularLinkedList L;


    return 0;
}
