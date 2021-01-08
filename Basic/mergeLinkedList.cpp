#include <iostream>
using namespace std;

class Node{
    public:
        int percentage;
        Node* next;
    
        Node(){

        }

        Node(int percentage, Node* next = nullptr){
            this->percentage = percentage;
            this->next= next;
        }

        void show(){
            cout << percentage;
        }
};

class LinkedList{


    private:
        Node* head;
        int size;


    public:
        LinkedList(){
            this-> head = nullptr;
            this-> size = 0;
        }

        int getLinkedListSize(){
            return size;
        }

        void traverse(){
            Node* ptr = head;
            while (ptr != nullptr){
                cout << ptr->percentage << endl;
                ptr = ptr->next;
            }
        }

        void append(int percentage){
            Node* node = new Node(percentage);
            if (getLinkedListSize() == 0){
                head = node;
            }
            else{
                Node* ptr = head;
                while (ptr->next != nullptr){
                    ptr = ptr->next;
                }
                
                ptr->next = node;
            }
            size++;
        }

        void prepend(int percentage){
            Node* node = new Node(percentage);
            node->next = head;
            head = node;
            size++;
        }

    

};


int main(){
    cout<<"Hello, World!"<<endl;
    LinkedList a;
    a.append(90);
    a.append(80);
    a.append(78);
    a.prepend(96);
    cout << a.getLinkedListSize() << endl;
    a.traverse();
    return 0;
}
