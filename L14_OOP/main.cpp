#include<iostream>
#include<string>
#include<cmath>

using namespace std;
// Inheritance (kế thừa)
class DoiTuong{
    protected:
        int ID;
        string TEN;
    public:
        DoiTuong();                 // Constructor
        void input(string ten);
        void Display();
};

DoiTuong::DoiTuong(){
    static int id = 100;
    ID = id;
    id++;
}

void DoiTuong:: input(string name){
    TEN = name;
}

void DoiTuong::Display(){
    cout << "ID: " << ID << endl;
    cout << "Name: " << TEN << endl;
}

class SinhVien : public DoiTuong{
    private:
        string LOP;
        string HOCKY;
    public:
        void input(string ten, string lop, string hocky);   // Override
        void Display();
};

void SinhVien::input(string ten, string lop, string hocky){
    TEN = ten;
    LOP = lop;
    HOCKY = hocky;
}

void SinhVien::Display(){
    cout << "ID: " << ID << endl;
    cout << "Name: " << TEN << endl;
    cout << "Class: " << LOP << endl;
    cout << "Semester: " << HOCKY << endl;
}

// Vitrual Function 
class Parent{
    public:
        virtual char* word(){
            return (char*) "Parent Class\n";
        }
        void display(){
            cout << "Display: " << word() << endl;
        }
};

class Child : public Parent{
    public:
        char* word(){                        //Override
            return (char*) "Child Class\n";
        }
};

// Abstraction(Đóng gói)

class GiaiPhuongTrinh
{
    private:
        double a, b, c, x1, x2, delta;
        void tinhNghiem();
    public:
        void enterNumber(double num_a, double num_b, double num_c);
        void printResult();
};

void GiaiPhuongTrinh::tinhNghiem()
{
    delta = b*b - 4*a*c;
    if (delta < 0){
        delta = -1;
    }  
    else if (delta == 0){
        x1 = x2 = -b/ (2*a);
    }
    else if (delta > 0){
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
    }
}

void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c){
    a = num_a;
    b = num_b;
    c = num_c;
}

void GiaiPhuongTrinh::printResult()
{
    tinhNghiem();
    if (delta == -1){
        cout << "PT vo nghiem" << endl;
    }
    else if (delta == 0){
        cout << "PT co nghiem chung: " << x1 << endl;
    }
    else if (delta > 0){
        cout << "PT co 2 nghiem: \n";
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    }    
}

// Polymorphism
class caculate{
    private:
        int a,b;
    public:
        void sum(int a, int b);
        void sum(int a, int b, int c);
        double sum(int a, double b);
};

void caculate::sum(int a, int b){
    cout << "Sum 2 number: " << a + b << endl;
}

void caculate::sum(int a, int b, int c){
    cout << "Sum 3 number: " << a + b + c << endl;
}

double caculate::sum(int a, double b){
    return a + b;
}

int main(int argc, char const *argv[]){
    // DoiTuong td;
    // td.input("Hung");
    // td.Display();
    // cout << "---------------------------" << endl;
    // SinhVien sv;
    // sv.input("Minh", "IOT17", "HKI");
    // sv.Display();

    // Parent p;
    // p.display();

    // Child c;
    // c.display();

    // GiaiPhuongTrinh pt1;
    // pt1.enterNumber(1,5,4);
    // pt1.printResult();
    caculate s;
    s.sum(10,10);
    s.sum(10,10,10);
    cout << "sum with double: "<< s.sum(10, 1.1);
    return 0;
}