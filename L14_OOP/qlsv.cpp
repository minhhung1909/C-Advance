#include <iostream>
#include<string>
#include<vector>
#include<assert.h>

using namespace std;

void menu();
void menuUpdate();
float inputCheckScore(float score);
typedef enum{
    EXCELLENT, 
    GOOD,
    AVERAGE, 
    BELOWAVERAGE
}grades;

class Student{
    private:
        int id;
        string name;
        float math;
        float physics;
        float chemistry;
        float avegare;
        string grade;
    public:
        Student(string name, float math, float physics, float chemistry);
        void displayInfo();

        int getID();
        string getName();
        float getMath();
        float getPhysics();
        float getChemistry();
        float getAvegare();
        grades getGrade();

        void setName(string name);
        void setScoreMath(float math);
        void setScoreChemistry(float chemistry);
        void setScorePhysics(float physics);
};

class StudentManager{
    private:
        vector<Student> Database;
    public:
        void addStudent();
        void updateStudentById(int id);
        void deleteStudentById(int id);
        void findStudentById(const int id);
        void sortStudentsByName();
        void sortStudentsByAverage(); 
        void sortStudentsById();
        void displayAllStudents();
};

int main(){
    StudentManager studentmg;
    int option, id_use;
    while (true)
    {
        menu();
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            int check;
            do{            
                studentmg.addStudent();
                cout << "Enter 0 is continue Input infomation.\nEnter any key for stop input\n";
                cin >> check;
            }while(check == 0);
            break;
        case 2:
            cout << "Enter your id you want chage: ";
            cin >> id_use;
            studentmg.updateStudentById(id_use);
            break;
        case 3:
            cout << "Enter your id you want Delete: ";
            cin >> id_use;
            studentmg.deleteStudentById(id_use);
            break;
        case 4:
            cout << "Enter your id you want Find: ";
            cin >> id_use;
            studentmg.findStudentById(id_use);
            break;
        case 5:
            studentmg.sortStudentsById();
            cout << "Sort by ID succes!!" << endl;
            break;
        case 6:
            studentmg.sortStudentsByName();
            cout << "Sort by Name succes!!" << endl;
            break;
        case 7:
            studentmg.sortStudentsByAverage();
            cout << "Sort by Avg succes!!" << endl;
            break;
        case 8:
            studentmg.displayAllStudents();
            break;
        default:
            break;
        }
    }
    return 0;
}

float inputCheckScore(float score){
    int cnt = 0;
    do{
        if (cnt > 0){
            cout << "Your score input not vaild!!!.\n Enter again:";
        } 
        cnt++;
        cin >> score;
    }while(score < 0 || score > 10);
    return score;
}

void StudentManager::addStudent(){
    string name;
    float math, physics, chemistry;

    cout << "Enter Student Name: ";
    cin >> name;

    cout << "Enter score math: ";
    math = inputCheckScore(math);

    cout << "Enter score physics: ";
    physics = inputCheckScore(physics);

    cout << "Enter score chemistry: ";
    chemistry = inputCheckScore(chemistry);

    Student sv(name, math, physics, chemistry);

    this->Database.push_back(sv);
}

void menu(){
    cout << "\n----------------------------------------------" << endl;
    cout << "\t 1. Add Student" << endl;
    cout << "\t 2. Update Information Student with ID" << endl;
    cout << "\t 3. Delete Information Student by ID" << endl;
    cout << "\t 4. Find Student By ID" << endl;
    cout << "\t 5. Sort Students By ID" << endl;
    cout << "\t 6. Sort Students By Name" << endl;
    cout << "\t 7. Sort Students By Average" << endl;
    cout << "\t 8. Display All Students" << endl;
}

void menuUpdate(){
    cout << "\n-------------Information Update---------------" << endl;
    cout << "The information do you want edit?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Score Math" << endl;
    cout << "3. Score Physics" << endl;
    cout << "4. Score Chemistry" << endl;
    cout << "Press any Number to exit"<< endl;
}

int Student::getID(){
    return this->id;
}

string Student::getName(){
    return this->name;
}

float Student::getMath(){
    return this->math;
}

float Student::getChemistry(){
    return this->chemistry;
}

float Student::getPhysics(){
    return this->physics;
}

float Student::getAvegare(){
    return this->avegare = (this->math + this->chemistry + this->physics) / 3;
}

grades Student::getGrade(){
    if(this->avegare >= 9) return EXCELLENT;
    else if(this->avegare >= 7) return GOOD;
    else if(this->avegare >= 5) return AVERAGE;
    else return BELOWAVERAGE;
}

void Student::displayInfo(){
    cout << this->getID() << "\t" << this->getName() << "\t" << this->getMath() << "\t" << this->getPhysics() << "\t\t" << this->getChemistry() << "\t" << this->getAvegare() << "\t" << this->getGrade() << "\t" << endl;
}

void Student::setName(string name){
    this->name = name;
}

void Student::setScoreMath(float math){
    this->math = math;
}
void Student::setScoreChemistry(float chemistry){
    this->chemistry = chemistry;
}
void Student::setScorePhysics(float physics){
    this->physics = physics;
}

// float checkPointVaild(float point){
//    assert(point >= 0 && point <= 10 && " Point in ranre [0,10]");
//    return point; 
// }

Student::Student(string name, float math, float physics, float chemistry){
    static int id = 0;
    this->id = id;
    id++;
    this->name = name;
    this->math = math;
    this->physics = physics;
    this->chemistry = chemistry;
}

void StudentManager::updateStudentById(int id){
    int flag = 0;
    string nameEdit;
    float scoreEdit;
    int option;
    for(Student index: this->Database){
        if(index.getID() == id){
            flag++;
            cout << "Found Student with ID: " << id << endl;
            while (true)
            {
                menuUpdate();
                cout << "Enter your option: ";
                cin >> option;
                switch (option)
                {
                case 1:
                    cout << "Enter name want edit: ";
                    cin >> nameEdit;
                    index.setName(nameEdit);
                    break;
                case 2:
                    cout << "Enter score Math want edit: ";
                    cin >> scoreEdit;
                    index.setScoreMath(scoreEdit);
                    break;
                case 3:
                    cout << "Enter score Physics want edit: ";
                    cin >> scoreEdit;
                    index.setScorePhysics(scoreEdit);
                    break;
                case 4:
                    cout << "Enter score Chemistry want edit: ";
                    cin >> scoreEdit;
                    index.setScoreChemistry(scoreEdit);
                    break;
                default:
                    break;
                }
            }
        }
    }
    if(flag == 0) printf("Not Found Student");
}


void StudentManager::displayAllStudents(){
    cout << "-------------------------------------------------------------" << endl;
    cout << "ID\tName   Math    Physics    Chemistry    Avg    Grade" << endl;
    for(Student index: this->Database){
        index.displayInfo();
    }
}

void StudentManager::findStudentById(const int id){
    int flag;
    for(Student index : this->Database){
        if(index.getID() == id){
            flag = 1;
            index.displayInfo();
        }
    }
    if(flag != 1) cout << "ID find not Found!";
}

void StudentManager::sortStudentsByAverage(){
    int i,j, min;
    for(i = 0; i <Database.size() - 1; ++i){
        min = i;
        for(j = 0; j < Database.size();++j){
            if(Database[j].getAvegare() < Database[min].getAvegare()) min = j;
        }
        swap(Database[i],Database[min]);
    }
}

void StudentManager::sortStudentsById(){
    int i,j, min;
    for(i = 0; i <Database.size() - 1; ++i){
        min = i;
        for(j = 0; j < Database.size();++j){
            if(Database[j].getID() < Database[min].getID()) min = j;
        }
        swap(Database[i],Database[min]);
    }
}

void StudentManager::sortStudentsByName(){
    int i,j, min;
    for(i = 0; i <Database.size() - 1; ++i){
        min = i;
        for(j = 0; j < Database.size();++j){
            if(Database[j].getName() < Database[min].getName()) min = j;
        }
        swap(Database[i],Database[min]);
    }
}

void StudentManager::deleteStudentById(int id) {
    vector<Student>::iterator it = Database.begin();
    for(int i = 0; i < Database.size(); ++i){
        if(Database[i].getID() == id){
            Database.erase(it);
        }
        it++;
    }
}