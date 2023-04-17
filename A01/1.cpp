#include <iostream>

using namespace std;

class Complex {
    private:
        double i, j;

        int to_int (string value) {
            bool negative = false;
            if (value[0] == '+' || value[0] == '-') {
                if (value[0] == '-') {
                    negative = true;
                }
                value = value.substr(1);
            }
            int n = stoi(value);
            if (negative) {
                n = -n;
            }
            return n;
        }

        void input () {
            string value;
            cin >> value;

            string x = "", y = "";

            bool real = true;

            for (int i = 0; i < value.length(); i++) {
                if (value[i] == 'i' && y.length() == 1) {
                    y += "1";
                    continue;
                } 
                if (i != 0 && (value[i] == '+' || value[i] == '-')) {
                    real = false;
                }
                if (real) {
                    x += value[i];
                } else {
                    y += value[i];
                }
            }

            i = to_int(x);
            j = to_int(y);
        }
    
    public:
        Complex () {
            input();
        }

        Complex (double x, double y) : i(x), j(y) {}

        void add (const Complex& c) {
            i += c.i;
            j += c.j;
        }

        void subtract (const Complex& c) {
            i -= c.i;
            j -= c.j;
        }

        void multiply (const Complex& c) {
            double it = c.i * i - c.j * j;
            double jt = i * c.j + j * c.i;
            i = it;
            j = jt;
        }

        void divide (const Complex& c) {
            if (c.i == 0 && c.j == 0) {
                cout << "Error: Division by zero is undefined!" << endl;
                return;
            }

            double it = (c.i * i + c.j * j) / (c.i * c.i + c.j * c.j);
            double jt = (c.i * j - c.j * i) / (c.i * c.i + c.j * c.j);
            i = it;
            j = jt;
        }

        void conjugate () {
            j = -j;
        }

        void display () {
            cout << i;
            if (j >= 0) {
                if (j == 1) {
                    cout << "+";
                } else {
                    cout << "+" << j;
                }
            } else {
                if (j == -1) {
                    cout << "-";
                } else {
                    cout << "-" << -j;
                }
            }
            cout << "i" << endl;
        }
};

void perform () {
    int op;
    cin >> op;

    if (op == 5) {
        Complex c;
        c.conjugate();
        c.display();
    } else {
        Complex c1;
        Complex c2;
        
        switch (op) {
            case 1:
                c1.add(c2);
                break;
            case 2:
                c1.subtract(c2);
                break;
            case 3:
                c1.multiply(c2);
                break;
            case 4:
                c1.divide(c2);
                break;
            default:
                break;
        }

        c1.display();
    }
}

int main () {
    int t;
    cin >> t;

    while (t--) {
        perform();
    }

    return 0;
}
