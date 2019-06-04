#include <iostream>
using namespace std;

class Person{
    public:
        void input(){
            cin >> name >> sex >> age;
        };
        void display();
    private:
        char name[20];
        char sex[2];
        int age;
};


class Student:Person{
    public:
        void display();
        void input();
    private:
        int studentId;
        int classId;
        int score;
};


class Teacher:Person{
    public:
        void display();
        void input();
    private:
        int zgh;
        char jobposition[20];
        char department[20];
};

void Person::display(){
    cout << "姓名：" << name << "性别" << sex << "年龄" << age << endl;
}

void Student::display(){
    Person::display();
    cout << "学号" << studentId << endl;
    cout << "班级号" << classId << endl;
    cout << "分数" << score << endl;
}

void Student::input(){
    Person::input();
    cin >> studentId >> classId >> score;
}

void Teacher::input(){
    Person::input();
    cin >> zgh >> jobposition >> department;
}

void Teacher::display(){
    Person::display();
    cout << "职工号" << zgh << endl;
    cout << "职称" << jobposition << endl;
    cout << "系别" << department << endl;
}

int main(){
    cout << "哈哈哈" << endl;
    Student stu1 = Student(), stu2 = Student();
    Teacher teacher1 = Teacher(), teacher2 = Teacher();
    stu1.input();stu1.display();
    stu2.input();stu2.display();
    teacher1.input();teacher1.display();
    teacher2.input();teacher2.display();
    return 0;
}