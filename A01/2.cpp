#include <iostream>

using namespace std;

class Article {
    private:
        string name;
        string author;
        int year;
        string context;

        bool validateArticleName (string value) {
            return value.length() <= 30;
        }

        bool validateAuthorName (string value) {
            return value.length() <= 30;
        }

        bool validateYear (int value) {
            return value >= 1000 && value <= 9999;
        }

        bool validateContext (string value) {
            return value.length() <= 500;
        }
    
    public:
        void setArticleName (string value) {
            if (validateArticleName(value)) {
                name = value;
            } else {
                cout << "Error: Article name is too long!" << endl;
            }
        }

        void setAuthorName (string value) {
            if (validateAuthorName(value)) {
                author = value;
            } else {
                cout << "Error: Author name is too long!" << endl;
            }
        }

        void setYear (int value) {
            if (validateYear(value)) {
                year = value;
            } else {
                cout << "Error: Year must be four digits!" << endl;
            }
        }

        void setContext (string value) {
            if (validateContext(value)) {
                context = value;
            } else {
                cout << "Error: Context is too long!" << endl;
            }
        }

        string getArticleName () {
            return name;
        }

        string getAuthorName () {
            return author;
        }

        int getYear () {
            return year;
        }

        string getContext () {
            return context;
        }

};

int main () {
    Article article;
    article.setArticleName("This is a test!");
    article.setAuthorName("Kazem Forghani");
    article.setYear(2023);
    article.setContext("As I mentioned before, this is just a test!");

    cout << "Article Name: " << article.getArticleName() << endl;
    cout << "Author Name: " << article.getAuthorName() << endl;
    cout << "Year: " << article.getYear() << endl;
    cout << "Context: " << article.getContext() << endl;

    return 0;
}