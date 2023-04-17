#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <time.h>

using namespace std;

void setup () {
    srand(time(0)); 
    cout << fixed << setprecision(2);
}

double randdbl (double lower, double upper) {
    return lower + (double)(rand() % (int)(100 * (upper - lower) + 1)) / 100;
}

int randint (int lower, int upper) {
    return lower + rand() % (upper - lower + 1);
}

class Joint {
    private:
        double balance = 1000000;

        void changeBalance (double value) {
            balance += value;
        }
    
    public:
        double getBalance () const {
            return balance;
        }
    
    friend class Single;
};

class Single {
    protected:
        double balance = 0;
    
    public:
        double getBalance () const {
            return balance;
        }

        void changeBalance (double value) {
            balance += value;
        }

        double invest (Joint& joint, Single& colleague, double rate) {
            double benefit;

            if (joint.getBalance() >= 10000) {
                benefit = (rate - 1) * randint(10000, joint.getBalance());

                if (benefit >= 0) {
                    changeBalance(benefit / 2);
                    joint.changeBalance(benefit / 2);
                } else {
                    joint.changeBalance(benefit);
                    if (getBalance() > 0) {
                        double value = getBalance();
                        if (value > -benefit) {
                            value = -benefit;
                        }
                        changeBalance(-value);
                    } else {
                        double value = joint.getBalance();
                        if (value > -benefit) {
                            value = -benefit;
                        }
                        joint.changeBalance(-value);
                    }
                    colleague.changeBalance(-benefit);
                }
            }

            if (joint.getBalance() < 10000 || joint.getBalance() >= 2000000) {
                changeBalance(joint.getBalance() / 2);
                colleague.changeBalance(joint.getBalance() / 2);
                joint.changeBalance(-joint.getBalance());
            }

            return benefit;
        }
};

class One : public Single {
    public:
        string name = "Mohammad";
};

class Two : public Single {
    public:
        string name = "Abbas";
};

int main () {
    setup();

    Joint joint;
    One one;
    Two two;

    double lower, upper;
    cin >> lower >> upper;
    
    Single* investor = &one;
    Single* colleague = &two;

    int turns = 0;

    cout << one.getBalance() << " " << two.getBalance() << " " << joint.getBalance() << endl;    

    while (true) {
        double benefit = investor->invest(
            joint,
            *colleague,
            randdbl(lower, upper)
        );

        if (benefit < 0) {
            swap(investor, colleague);
            turns++;
        }

        cout << one.getBalance() << " " << two.getBalance() << " " << joint.getBalance() << endl;

        if (joint.getBalance() <= 0 || turns >= 1000) {
            break;
        }
    }

    if (one.getBalance() > two.getBalance()) {
        cout << one.name << endl;
    } else if (two.getBalance() > one.getBalance()) {
        cout << two.name << endl;
    } else {
        cout << "Equal Balance!" << endl;
    }

    return 0;
}