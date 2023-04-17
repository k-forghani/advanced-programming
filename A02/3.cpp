#include <iostream>
#include <algorithm>

using namespace std;

class Character {
    protected:
        double salaryInJob1;
        double salaryInJob2;
        double salaryInJob3;
        double salaryInBestJob;

        double getBenefit (int months, int salary, double tax) const {
            return months * salary * (1 - tax);
        }

        void setSalaryInBestJob () {
            salaryInBestJob = max(
                {
                    salaryInJob1,
                    salaryInJob2,
                    salaryInJob3
                }
            );
        }

    public:
        string name;
        int age;

        Character (string name, int age) {
            this -> name = name;
            this -> age = age;
        }

        friend string getBest(const Character& character);
        friend void buy(int price, const Character& c1, const Character& c2);
};

class Human : public Character {
    public:
        Human (string name, int age) : Character(name, age) {
            salaryInJob1 = getBenefit(10, 250, 0.05);
            salaryInJob2 = getBenefit(9, 400, 0.05);
            salaryInJob3 = getBenefit(11, 350, 0.05);

            setSalaryInBestJob();
        }
};

class Alien : public Character {
    public:
        Alien (string name, int age) : Character(name, age) {
            salaryInJob1 = getBenefit(12, 300, 0.25);
            salaryInJob2 = getBenefit(10, 350, 0.20);
            salaryInJob3 = getBenefit(10, 400, 0.35);

            setSalaryInBestJob();
        }
};

string getBest (const Character& character) {
    if (character.salaryInBestJob == character.salaryInJob1) {
        return "Job1";
    } else if (character.salaryInBestJob == character.salaryInJob2) {
        return "Job2";
    } else {
        return "Job3";
    }
}       

void buy (int price, const Character& c1, const Character& c2) {
    if (c1.salaryInBestJob + c2.salaryInBestJob >= price) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main () {
    int price;
    cin >> price;

    Human human("human", 18);
    Alien alien("alien", 18);

    buy(price, human, alien);

    cout << getBest(human) << endl;
    cout << getBest(alien) << endl;    

    return 0;
}