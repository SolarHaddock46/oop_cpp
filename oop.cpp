#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    string name;
public:
    Person(string name) : name(name) {}
    string get_name() {
        return name;
    }
};

class Student : public Person {
public:
    Student(string name) : Person(name) {}
};

class Course {
private:
    string name;
    Person* teacher;
    vector<Student*> students;
public:
    Course(string name, Person* teacher) : name(name), teacher(teacher) {}
    void add_student(Student* student) {
        students.push_back(student);
    }
    string get_info() {
        string info = "Course: " + name + "\nTeacher: " + teacher->get_name() + "\nStudents:\n";
        for (Student* student : students) {
            info += "- " + student->get_name() + "\n";
        }
        return info;
    }
};

int main() {
    Person* teacher = new Person("Roman Rogatkin");
    Course* course = new Course("iOS development from Alfa-Bank", teacher);
    Student* student1 = new Student("Vladimir Matsnev");
    Student* student2 = new Student("Not Vladimir Matsnev");
    course->add_student(student1);
    course->add_student(student2);
    cout << course->get_info();
    delete teacher;
    delete course;
    delete student1;
    delete student2;
    return 0;
}
