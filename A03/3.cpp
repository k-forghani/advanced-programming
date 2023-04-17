#include <iostream>

using namespace std;

struct Book {
    string name;
    Book* next = NULL;
};

class LinkedList {
    private:
        Book* first;
        Book* last;
        int number = 0;
    
    public:
        LinkedList () : first(NULL), last(NULL) {}

        ~LinkedList () {
            delete first;
            delete last;
        }

        void insertFirst (string name) {
            if (first == NULL) {
                first = new Book();
                first -> name = name;
            } else {
                Book* book = new Book();
                book -> name = name;
                book -> next = first;
                first = book;
            }
            if (last == NULL) {
                last = first;
            }
            number++;
        }

        void insertLast (string name) {
            if (last == NULL) {
                last = new Book();
                last -> name = name;
            } else {
                Book* book = new Book();
                book -> name = name;
                last -> next = book;
                last = book;
            }
            if (first == NULL) {
                first = last;
            }
            number++;
        }

        void removeFirst () {
            if (first != NULL) {
                if (first -> next == NULL) {
                    delete first;
                    first = NULL;
                    last = NULL;
                } else {
                    Book* buffer = first -> next;
                    delete first;
                    first = buffer;
                }
                number--;
            }
        }

        int count () const {
            return number;
        }

        void display () const {
            for (Book* cursor = first; cursor != NULL; cursor = cursor -> next) {
                cout << cursor -> name << endl;
            }
        }
};

int main () {
    LinkedList* list = new LinkedList();

    int n;
    cin >> n;

    cin.ignore();

    while (n--) {
        string name;
        getline(cin, name);
        list -> insertLast(name);
    }

    while (true) {
        string c;
        cin >> c;
        cin.ignore();
        if (c == "AddLeft") {
            string name;
            getline(cin, name);
            list -> insertFirst(name);
        } else if (c == "AddRight") {
            string name;
            getline(cin, name);
            list -> insertLast(name);
        } else if (c == "DeleteLeft") {
            list -> removeFirst();
        } else if (c == "Exit") {
            cout << list -> count() << endl;
            list -> display();
            delete list;
            exit(0);
        } else {
            cout << "Error: Invalid command!" << endl;
        }
    }
    
    return 0;
}