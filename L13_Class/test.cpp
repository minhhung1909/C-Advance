#include <iostream>
#include <string>
using namespace std;

typedef enum{
    NO, YES
}insurance;


class SinhVien{
    public:
        SinhVien(string name, string classroom);    // init Constructor
        void Display(insurance insuaranceState); // init Method
    private:
        int ID;         // Protective
        string NAME;    // Protective
        string CLASS;   // Protective
};


SinhVien::SinhVien(string name, string classroom){
    static int id = 15;
    SinhVien::ID = id;
    id++;

    SinhVien::NAME =  name;
    SinhVien::CLASS = classroom;


}

void SinhVien::Display(insurance insuaranceState = YES){
    cout << "MSSV: " << ID << endl;
    cout << "Name: " << NAME << endl;
    cout << "Class: " << CLASS << endl;
    cout << "State Insurance: " << insuaranceState <<endl;
}

int main(int argc, char const* argv[])
{
    SinhVien sv1("Hung", "AIOT"), sv2("Hoa", "KT");
    sv1.Display(NO);
    sv2.Display();
    return(0);
}