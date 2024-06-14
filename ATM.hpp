//Basic functions of an ATM
//machine with a simple way to 
//authenticate the user
//Supports only one user

#include <iostream>
typedef unsigned short int USHORT;
using namespace std;

class Atm{
    private://User's info
    const int pass=1234;
    const long int cardNumber=123456789;
    const string fullname="David Smith";
    double money=100;
    double *const ptr=&money;
    
    //Declaring functions
    bool checkUser();   
    void deposit(double *,double);
    void getChoice();
    void displayMenu() const;
    void userInfo() const;
    void withdraw(double *amount,double insert);

    bool checkPin(){
        USHORT pin;
        cout<<"Please enter card's pin: ";
        cin>>pin;
        
        if(pin==pass)
            return true;
        else
            return false;
    }

    public:
    Atm()
    {  
        if(checkUser()==1)
        {
            cout<<"Welcome back "<<fullname<<endl;
            displayMenu();
            getChoice();
        }
        else 
        {
            cout<<"You are not an authenticated user!";
            return;
        }
       
    }

};

void Atm::displayMenu() const{
    cout<<"1) Deposit\n";
    cout<<"2) Withdraw\n";
    cout<<"3) User's information\n";
    cout<<"4) View the menu\n";
    cout<<"5) Exit\n";
}

void Atm::userInfo() const{
    cout<<"Name: "<<fullname<<endl;
    cout<<"Balance: "<<money<<endl;
}

void Atm::getChoice(){
    int choice;

    while(1){
        POINT: //reset point in case there's no match
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
                case 1:
                    double num1;
                    cout<<"Insert the amount of money you want to deposit: ";
                    cin>>num1;
                    deposit(ptr, num1);
                    cout<<"Your balance is: "<<*ptr<<"\n";
                    break;
                case 2:
                    double num2;
                    cout<<"Insert the amount of money you want to deposit: ";
                    cin>>num2;
                    withdraw(ptr, num2);
                    cout<<"Your balance is: "<<*ptr<<"\n";
                    break;
                case 3:
                    userInfo();
                    break;
                case 4:
                    displayMenu();
                    break;
                case 5:
                    return;
                default: 
                    cout<<"Something went wrong...\n";             
                    goto POINT;
        }
    
    }
    

}

void Atm::deposit(double *amount,double insert){
     if(checkPin()==1)
        *amount+=insert; 
    else 
        cout<<"Wrong pin!\n";
}

void Atm::withdraw(double *amount,double insert){
    if(checkPin()==1){
        if((*amount-insert)<0){
        cout<<"You can not withdraw that much money...\n";
        }
        else
            *amount-=insert; 
    }else
        cout<<"Wrong pin!\n";

}

bool Atm::checkUser(){
    
    long int num;
    USHORT tries=3;

    while(tries!=0)
    {
        cout<<"Please insert your card's number: ";
        cin>>num;
        
        if(tries!=0 && num==cardNumber)
            return 1;
        
        tries--;
    }
    
    return 0;

}