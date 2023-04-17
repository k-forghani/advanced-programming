#include <iostream>
#include <cmath>

using namespace std;

class Point {
    private:
        double x, y, z;

    public:
        Point () : x(0.0), y(0.0), z(0.0) {}

        Point (double x, double y, double z) : x(x), y(y), z(z) {}

        Point negative () const {
            return Point(-x, -y, -z);
        }

        double norm () const {
            return sqrt(x * x + y * y + z * z);
        }

        Point operator + (const Point& p) const {
            return Point(x + p.x, y + p.y, z + p.z);
        }

        void print () const {
            cout << "(" << x << ", " << y << ", " << z << ")" << endl;
        }
};

int main () {
    cout << "Point is:" << endl;
    cout << "\t(x, y, z) = ";

    double x, y, z;
    cin >> x >> y >> z;

    Point p(x, y, z);

    cout << endl << "Distance from (0, 0, 0) is:" << endl;
    cout << "\td = ";

    cout << p.norm() << endl;

    cout << endl << "P1 is:" << endl;
    cout << "\t(x1, y1, z1) = ";

    Point p1 = p.negative();
    p1.print();

    cout << endl << "P2 is:" << endl;
    cout << "\t(x2, y2, z2) = ";

    double x2, y2, z2;
    cin >> x2 >> y2 >> z2;

    Point p2(x2, y2, z2);

    cout << endl << "P1 + (x2, y2, z2) is:" << endl;
    cout << "\t(x3, y3, z3) = ";

    Point p3 = p1 + p2;
    p3.print();

    return 0;
}