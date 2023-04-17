#include <iostream>

using namespace std;

class Node {
    private:
        int item;
        Node* next;
    
    public:
        Node () : next(NULL) {}
    
    friend class LinkedList;
};

class LinkedList {
    private:
        Node* head;
    
    public:
        LinkedList () : head(NULL) {}

        void insert (int value) {
            if (head == NULL) {
                head = new Node();
                head -> item = value;
            } else {
                Node* cursor = head;
                while (cursor -> next != NULL) {
                    cursor = cursor -> next;
                }
                cursor -> next = new Node();
                cursor -> next -> item = value;
            }
        }

        void remove (int value) {
            if (head != NULL) {
                if (head -> item == value) {
                    Node* p = head;
                    head = head -> next;
                    delete p;
                } else {
                    for (Node* cursor = head; cursor -> next != NULL; cursor = cursor -> next) {
                        if (cursor -> next -> item == value) {
                            Node* l = cursor -> next -> next;
                            delete cursor -> next;
                            cursor -> next = l;
                            break;
                        }
                    }
                }
            }
        }

        void remove () {
            if (head == NULL) {
                return;
            } else {
                Node* p = head;
                head = head -> next;
                delete p;
            }
        }

        int search (int value) const {
            int counter = -1;
            for (Node* cursor = head; cursor != NULL; cursor = cursor -> next) {
                counter++;
                if (cursor -> item == value) {
                    return counter;
                }
            }
            return -1;
        }

        void display () const {
            for (Node* cursor = head; cursor != NULL; cursor = cursor -> next) {
                cout << cursor -> item << " ";
            }
            cout << endl;
        }
};

int main () {
    LinkedList l;

    while (true) {
        string c;
        int a;
        cin >> c;
        if (c == "Insertion") {
            cin >> a;
            l.insert(a);
        } else if (c == "Deletion") {
            l.remove();
        } else if (c == "Display") {
            l.display();
        } else if (c == "Search") {
            cin >> a;
            cout << l.search(a) << endl;
        } else if (c == "Delete") {
            cin >> a;
            l.remove(a);
        } else if (c == "exit") {
            exit(0);
        } else {
            cout << "Error: Invalid command!" << endl;
        }
    }
    
    return 0;
}