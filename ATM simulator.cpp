#include<iostream>
#include<windows.h>
using namespace std;
    int main(){
        int choice=0;
        HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
        int userPin;
        int enteredPin;
        int deposits=0;
        int withdrawals=0;
        int attempts=0;
        double balance=1000.000;
        double amount=0;
            cout<<"Maria's ATM!"<<endl;
            cout<<"-----------------------------------------------------------------------------------"<<endl;
            cout<<"To continue set a 4-digit pin!"<<endl;
            cin>>userPin;
            while(attempts<3){
            cout<<"To access the ATM please login with your pin"<<endl;
            cin>>enteredPin;
            if(enteredPin==userPin){
                    SetConsoleTextAttribute(h, FOREGROUND_GREEN);
                cout<<"Pin correct access granted"<<endl;
                break;
            }
            else{
                SetConsoleTextAttribute(h, FOREGROUND_RED);
                cout<<"Incorrect pin, access denied"<<endl;
                attempts++;
                return 0;
            }

            }


    while(true){
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            cout<<"Select one of the following choices(1,2,3,4)"<<endl;
            cout<<"Check balance(1)"<<endl;
            cout<<"Deposit money(2)"<<endl;
            cout<<"Withdraw money(3)"<<endl;
            cout<<"View deposit and withdrawal menu(4)"<<endl;
            cout<<"Exit(5)"<<endl;
            cout<<"Enter your choice"<<endl;
            cin>>choice;
            system("cls");

    if(choice==1){
            SetConsoleTextAttribute(h, FOREGROUND_BLUE);
        cout << "Your balance is "  << balance << endl;
    }
   else if(choice==2){
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE);
        cout<<"Enter amount to deposit"<<endl;
        cin>>amount;
        balance=balance+amount;
        deposits++;
    }
    else if(choice==3){
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout<<"Choose amount to withdraw"<<endl;
        cin>>amount;
        withdrawals++;
        if(amount<=balance){
            cout<<"Please take your money"<<endl;
            balance=balance-amount;
}            else{
                SetConsoleTextAttribute(h, FOREGROUND_RED);
               cout <<"Not enough balance, please take less money"<<endl;
            }
        }
        else if(choice==4){
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
            cout<<"You have made "<< deposits << "Deposit(s)"<<endl;
            cout<<"You have made "<< withdrawals <<"Withdrawal(s)"<<endl;
        }

   else if(choice==5){
        cout<<"Thank you for using Maria's ATM"<<endl;
        break;
   }




    else {
            SetConsoleTextAttribute(h, FOREGROUND_RED);
        cout<<"Invalid choice, please select a number 1-5"<<endl;
    }

    }

    return 0;
    }
