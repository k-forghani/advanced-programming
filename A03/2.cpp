#include <iostream>

using namespace std;

class Queue {
    private:
        int capacity;
        int number = 0;
        int* array;
        int front = 0;
        int back = 0;
    
    public:
        Queue (int capacity) : capacity(capacity) {
            array = new int[capacity];
        }

        ~Queue () {
            delete [] array;
        }

        void push (int value) {
            array[back] = value;
            back++;
            if (back == capacity) {
                back = 0;
            }
            number++;
            if (number > capacity) {
                front++;
                if (front == capacity) {
                    front = 0;
                }
                number = capacity;
            }
        }

        int pop () {
            if (!isempty()) {
                int value = array[front];
                front++;
                if (front == capacity) {
                    front = 0;
                }
                number--;
                return value;
            }
            return -1;
        }

        int size () const {
            return number;
        }

        void reverse () {
            if (!isempty()) {
                int length = back - front;
                if (length <= 0) {
                    length = capacity + length;
                }
                length /= 2;
                for (int i = 0; i < length; i++) {
                    int l = (front + i) % capacity;
                    int u = ((back - i - 1) % capacity + capacity) % capacity;
                    swap(array[l], array[u]);
                }
            }
        }

        int find (int value) const {
            int index = -1;
            if (!isempty()) {
                if (back > front) {
                    for (int i = front; i < back; i++) {
                        if (array[i] == value) {
                            index = i - front + 1;
                            break;
                        }
                    }
                } else {
                    int counter = 0;
                    int i = front;
                    while (i != (back - 1)) {
                        if (array[i] == value) {
                            break;
                        }
                        counter++;
                        i++;
                        if (i == capacity) {
                            i = 0;
                        }
                    }
                    index = counter + 1;
                }
            }
            return index;
        }

        bool isfull () const {
            return number == capacity;
        }

        bool isempty () const {
            return number == 0;
        }
};

void printBoolean (bool value) {
    if (value) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << endl;
}

int main () {
    Queue q(100);

    while (true) {
        string c;
        int a;
        cin >> c;
        if (c == "push") {  
            cin >> a;
            q.push(a);
        } else if (c == "find") {
            cin >> a;
            cout << q.find(a) << endl;
        } else if (c == "size") {
            cout << q.size() << endl;
        } else if (c == "pop") {
            cout << q.pop() << endl;
        } else if (c == "isempty") {
            printBoolean(q.isempty());
        } else if (c == "isfull") {
            printBoolean(q.isfull());
        } else if (c == "reverse") {
            q.reverse();
        } else if (c == "exit") {
            exit(0);
        } else {
            cout << "Error: Invalid command!" << endl;
        }
        cin.ignore();
    }

    return 0;
}
