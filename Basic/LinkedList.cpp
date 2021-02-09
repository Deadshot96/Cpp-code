# include <iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;

        Node(){}

        Node(int key, int data = 0, Node* next = nullptr){
            this->key = key;
            this->data = data;
            this->next = next;
        }

        void show(){
            cout<<"Key: "<<key<<"\tData: "<<data<<endl;
        }
};

class LinkedList{
    private:
        Node* head;
        int size;

    public:
        LinkedList();
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
        Node* getLinkedListHead();
        ~LinkedList();
};

LinkedList :: LinkedList(){
    head = nullptr;
    size = 0;
}

LinkedList :: ~LinkedList(){
    while(head != nullptr){
        Node* node = head;
        head = head->next;
        delete node;
    }
}


int LinkedList :: getSize(){
    return size;
}

bool LinkedList :: isEmpty(){
    return size == 0;
}

void LinkedList :: append(int key, int data = 0){
    Node* node = new Node(key, data);

    if (isEmpty()){
        head = node;
    }
    else{
        Node* ptr = head;

        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = node;
    }
    size++;
}

void LinkedList :: prepend(int key, int data = 0){
    Node* node = new Node(key, data);
    node -> next = head;
    head = node;
    size++;
}

void LinkedList :: traverse(){
    Node* ptr = head;
    while (ptr != nullptr){
        cout << "key: " << ptr->key << "\t" << "data: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

bool LinkedList :: search(int key){
    Node* ptr = head;
    while (ptr != nullptr){
        if (ptr->key == key)
            return true;
        ptr = ptr->next;
    }
    return false;
}

bool LinkedList :: update(int key, int data){
    Node* ptr = head;
    while (ptr != nullptr){
        if (ptr->key == key){
            ptr->data = data;
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

bool LinkedList :: remove(int key){
    if (isEmpty()){
        return false;
    }
    else{
        Node* ptr = head;
        Node* prev = nullptr;
        while (ptr != nullptr){
            if (ptr->key == key)
                break;
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr == nullptr){
            return false;
        } else if(prev == nullptr){
            Node* node = ptr;
            head = ptr -> next;
            delete node;
            size--;
            return true;
        }
        else{
            prev->next = ptr->next;
            delete ptr;
            size--;
            return true;
        }   
        return false;
    }
}

void LinkedList :: insertAfter(int keyA, int key, int data = 0){
    
    Node* ptr = head;

    while (ptr != nullptr){
        if (ptr->key == keyA)
            break;
        ptr = ptr->next;
    }

    if (ptr == nullptr){
        append(key, data);
    }
    else{
        Node* node = new Node(key, data);
        node->next = ptr->next;
        ptr->next = node;
        size++;
    }

}

void LinkedList :: insertBefore(int keyB, int key, int data = 0){
    Node* ptr = head;
    Node* prev = nullptr;


    while (ptr != nullptr){
        if (ptr->key == keyB)
            break;
        prev = ptr;
        ptr = ptr->next;
    }

    if (prev == nullptr){
        prepend(key, data);
    }
    else if(ptr == nullptr){
        append(key, data);
    }
    else{
        Node* node = new Node(key, data);
        node->next = ptr;
        prev->next = node;
        size++;
    }
}

Node* LinkedList :: getLinkedListHead(){
    return head;
}

Node* mergeLists(Node* l1, Node* l2){
    Node* out;
    while ((l1 != nullptr) && (l2 != nullptr)){

    }
}



int main(){
    cout << "Hello, World!" << endl;
    // LinkedList L;
    
    // for (int i = 2; i < 20; i+=2)
    // {
    //     L.append(i, i*i);
    // }
    // L.prepend(0);
    // L.insertBefore(0, -1, 1);
    // L.insertAfter(0, 1, 1);

    // L.remove(18);

    // cout << "Size of the Linked List: " << L.getSize() << "\n";
    // L.traverse();
    return 0;
}