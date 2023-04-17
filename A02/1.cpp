#include <iostream>

using namespace std;

class Stack {
    private:
        int size;
        char* top;
        char* values;
    
    public:
        Stack (int size) {
            this -> size = size;
            this -> values = new char[size];
            this -> top = values;
        }

        ~Stack () {
            delete [] values;
        }

        bool isfull () const {
            return top == &values[size];
        }

        bool isempty () const {
            return top == values;
        }

        void push (char value) {
            if (isfull()) {
                cout << "Error: Stack is full!" << endl;
                return;
            }
            *top = value;
            top++;
        }

        char pop () {
            if (isempty()) {
                cout << "Error: Stack is empty!" << endl;
                return ' ';
            }
            top--;
            return *top;
        }

        void display () const {
            for (char* cursor = top - 1; cursor >= values; cursor--) {
                cout << *cursor << endl;
            }
        }
};


int main () {
    string value;
    cin >> value;

    int l = value.length() / 2;

    Stack stack(l);

    for (int i = 0; i < l; i++) {
        stack.push(value[i]);
    }

    for (int i = l; i < 2 * l; i++) {
        if (value[i] != stack.pop()) {
            cout << "No" << endl;
            exit(0);
        }
    }
    
    cout << "Yes" << endl;

    return 0;
}
