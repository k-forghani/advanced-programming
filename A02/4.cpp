#include <iostream>
#include <algorithm>

using namespace std;

class Course {
    private:
        string title;
        int units;
        double score;
    
    public:
        Course (string title = "", int units = 1, double score = 0) {
            setTitle(title);
            setUnits(units);
            setScore(score);
        }

        void setTitle (string title) {
            this -> title = title;
        }

        void setUnits (int units) {
            if (units <= 0) {
                cout << "Error: The number of units must be a positive number!" << endl;
                return;
            }
            this -> units = units;
        }

        void setScore (double score) {
            if (score < 0 || score > 20) {
                cout << "Error: Score must be in range [0, 20]!" << endl;
                return;
            }
            this -> score = score;
        }

        string getTitle () const {
            return title;
        }

        int getUnits () const {
            return units;
        }

        double getScore () const {
            return score;
        }

        friend class Student;
};

class Student {
    private:
        string name;
        string id;
        Course* courses;
        Course* cursor;

    public:
        Student (string name = "", string id = "", int courses = 0) {
            setName(name);
            setID(id);
            this -> courses = new Course[courses];
            this -> cursor = this -> courses;
        }

        void setName (string name) {
            this -> name = name;
        }

        void setID (string id) {
            this -> id = id;
        }

        string getName () const {
            return name;
        }

        string getID () const {
            return id;
        }

        void addCourse (const Course& course) {
            *cursor = course;
            cursor++;
        }

        Course* getCourses () const {
            return courses;
        }

        double getGPA () const {
            double gpa = 0;
            int units = 0;
            for (Course* p = cursor - 1; p >= courses; p--) {
                units += p->units;
                gpa += p->units * p->score;
            }
            gpa /= units;
            return gpa;
        }

        void display () const {
            cout << id << " " << name << "\t" << getGPA() << endl;
        }

        bool operator > (const Student& right) const {
            return getGPA() > right.getGPA();
        }

        friend class CS;
};

class CS {
    private:
        Student* students;
        Student* cursor;

    public:
        CS (int number) {
            this -> students = new Student[number];
            this -> cursor = this -> students;
        }

        void addStudent (const Student& student) {
            *cursor = student;
            cursor++;
            sort(students, cursor, greater<>());
        }

        Student* getStudents () const {
            return students;
        }

        double getAverage () const {
            double average = 0;
            for (Student* s = students; s < cursor; s++) {
                average += s->getGPA();
            }
            average /= cursor - students;
            return average;
        }

        void displaySorted () const {
            for (Student* s = students; s < cursor; s++) {
                s->display();
            }
        }

        void displayBest (int n = 3) const {
            int counter = 0;
            for (Student* s = students; s < cursor && counter < n; s++) {
                s->display();
                counter++;
            }
        }

        void displayProbationary () const {
            for (Student* s = students; s < cursor; s++) {
                if (s->getGPA() < 12) {
                    s->display();
                }
            }
        }

        void removeProbationary () {
            Student* newCursor = NULL;
            for (Student* s = cursor - 1; s >= students; s--) {
                newCursor = s;
                if (s->getGPA() > 12) {
                    break;
                }
                *newCursor = Student();
            }
            cursor = newCursor + 1;
        }
};

int main () {
    cout << "How many students do you have? ";

    int s;
    cin >> s;

    cout << "How many courses does each student have? ";

    int c;
    cin >> c;

    cout << "Enter lesson title and the number of its units:" << endl;

    string courses[c];
    int units[c];

    for (int i = 0; i < c; i++) {
        cout << i + 1 << ": ";
        cin >> courses[i] >> units[i];
    }

    cout << endl << "Enter students:" << endl;

    CS cs(s);
    
    for (int i = 0; i < s; i++) {
        cin.clear();
        
        string name, id;

        cout << i + 1 << ":" << endl;

        cout << "\tName: ";
        cin >> name;

        cout << "\tID: ";
        cin >> id;

        Student student(name, id, c);

        cout << "\tScores: ";

        for (int j = 0; j < c; j++) {
            int t;
            cin >> t;
            student.addCourse(
                Course(courses[j], units[j], t)
            );
        }

        cs.addStudent(student);

        cout << endl;
    }

    while (true) {
        cout << ">> Operation: ";
        int o;
        cin >> o;

        switch (o) {
            case 1:
                cout << "Average: " << cs.getAverage() << endl;
                break;
            case 2:
                cs.displayBest(3);
                break;
            case 3:
                cs.displaySorted();
                break;
            case 4:
                cs.displayProbationary();
                break;
            case 5:
                cs.removeProbationary();
                break;
            default:
                break;
        }
    }
    

    return 0;
}