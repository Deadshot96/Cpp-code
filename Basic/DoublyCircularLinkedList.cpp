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

void DoublyCircularLinkedList :: traverse(){
    Node* ptr = head;
    bool flag = (ptr == nullptr);

    while (!flag){
        ptr->show();
        ptr = ptr->next;
        flag = (ptr == head);
    }
}

bool DoublyCircularLinkedList :: search(int key){
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

bool DoublyCircularLinkedList :: update(int key, int data){
    Node* ptr = head;
    bool flag = (ptr == nullptr);

    while (!flag){
        if (ptr->key == key){
            ptr->data = data;
            return true;
        }
        ptr = ptr->next;
        flag = (ptr == head);
    }
    return false;
}

void DoublyCircularLinkedList :: append(int key, int data = 0){
    Node* node = new Node(key, data);

    if (isEmpty()){
        head = node;
        head->prev = head;
        head->next = head;
    }
    else{
        Node* tail = head->prev;
        node->prev = tail;
        node->next = head;
        tail->next = node;
        head->prev = node;
    }

    size++;
}

void DoublyCircularLinkedList :: prepend(int key, int data = 0){
    if (isEmpty()){
        head = new Node(key, data);
        head->next = head;
        head->prev = head;
    }
    else{
        Node* node = new Node(key, data, head->prev, head);
        head->prev->next = node;
        head->prev = node;
        head = node;
    }
    size++;
}

void DoublyCircularLinkedList :: insertAfter(int keyA, int key, int data = 0){
    Node* ptr = head;
    bool flag = (ptr == nullptr), found = false;

    while (!flag){
        if (ptr->key == keyA){
            found = true;
            break;
        }
        ptr = ptr->next;
        flag = (ptr == head);
    }

    if (!found){
        append(key, data);
    }
    else{
        Node* node = new Node(key, data, ptr, ptr->next);
        ptr->next->prev = node;
        ptr->next = node;
        size++;
    }

}

int main()
{
    cout << "Hello, World!" << endl;
    DoublyCircularLinkedList L;

    for (int i = 2; i < 20; i+=2){
        L.append(i, i*i);
    }
    L.prepend(0, 0);
    L.insertAfter(18, 19, 19*19);
    L.insertAfter(0, 1, 1);
    L.insertAfter(4, 5, 5*5);


    cout << "Size of List: " << L.getSize() << endl;
    L.traverse();
    cout << "Done!";
    return 0;
}
