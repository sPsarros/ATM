#include <iostream>
enum GENDER{Male, Female, Other};
typedef unsigned short int usint;
using namespace std;

class User{
    private:
    string fullname;
    usint password; 
    string sex;
    string address;
    long int phoneNumber;
    string email;

    public:
    User(){
        getline(cin,fullname);
        cout<<"Hey "<<fullname<<" !";
    };
};