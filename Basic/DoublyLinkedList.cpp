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
        void insertAfter(int keyA, int key, int data);
        void insertBefore(int keyB, int key, int data);
        int getSize();
        bool isEmpty();
        void traverse();
        bool search(int key);
        bool update(int key, int data);
        bool remove(int key);
        ~DoublyLinkedList();
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

void DoublyLinkedList :: insertAfter(int keyA, int key, int data = 0){
    Node* ptr = head;
    bool found = false;

    while (ptr != nullptr){
        if (ptr->key == keyA){
            found = true;
            break;
        }
        ptr = ptr->next;
    }

    if (!found){
        append(key, data);
    }
    else{
        Node* node = new Node(key, data, ptr, ptr->next);
        
        if (ptr->next != nullptr)
            ptr->next->prev = node;
        
        ptr->next = node;
        size++;
    }
}

void DoublyLinkedList :: insertBefore(int keyB, int key, int data = 0){
    Node* ptr = head;
    bool found = false;

    while (ptr != nullptr){
        if (ptr->key == keyB){
            found = true;
            break;
        }
        ptr = ptr->next;
    }


    if (!found){
        prepend(key, data);
    }
    else{
        Node* node = new Node(key, data, ptr->prev, ptr);

        if (ptr->prev != nullptr){
            ptr->prev->next = node;
        }
        else{
            head = node;
        }

        ptr->prev = node;
        size++;

    }
}

bool DoublyLinkedList :: remove(int key){
    Node* ptr = head;
    bool found = false;

    while (ptr != nullptr){
        if (ptr->key == key){
            found = true;
            break;
        }
        ptr = ptr->next;
    }

    if (!found){
        return false;
    }
    else if (getSize() == 1){
        head = nullptr;
    }
    else if (ptr == head){
        ptr->next->prev = nullptr;
    }
    else if(ptr->next == nullptr){
        ptr->prev->next = nullptr;
    }
    else{
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    delete ptr;
    size--;
    return true;
}

DoublyLinkedList :: ~DoublyLinkedList(){
    while (head != nullptr){
        Node* ptr = head;
        head = head->next;
        delete ptr;
    }
}


int main()
{
    cout << "Hello, World!"<<endl;
    DoublyLinkedList L;

    for (int i = 2; i < 20; i+=2)
    {
        L.append(i, i*i);
    }
    L.prepend(0, 0);
    L.insertAfter(0, 1, 1);
    L.insertAfter(4, 5, 25);
    L.insertBefore(0, -1, 1);
    L.insertAfter(18, 20, 400);

    L.remove(-1);
    L.remove(20);
    L.remove(5);
    L.remove(7);
    
    cout << "Size of the DoublyLinkedList is: " << L.getSize() << endl;
    L.traverse();
    return 0;
}
