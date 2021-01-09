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

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
