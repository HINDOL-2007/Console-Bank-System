#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
    string accountHolderName;
    string accountNumber;
    string pin;
    double balance = 0.0;
    bool check_pin();
public:
    void setup_account(string name, string number, string user_pin);
    void deposit(double amount);
    void withdraw(double amount);
    void display();
};
void BankAccount ::setup_account(string name, string number, string user_pin)
{
    accountHolderName = name;
    accountNumber = number;
    pin = user_pin ;
    while(pin.length() != 4){
        cout<<"PIN should be 4 digits long. Please set a valid PIN."<<endl;
        cout << "Enter your PIN : ";
        cin >> pin;
    }
}
void BankAccount ::deposit(double amount)
{
    balance += amount;
}
void BankAccount ::withdraw(double amount)
{
    if (check_pin() == true)
    {

        if (amount > balance)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            balance -= amount;
        }
    }
    else
    {
        cout << "Incorrect PIN" << endl;
    }
}
void BankAccount ::display()
{
    cout << "Account Holder Name: " << accountHolderName << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
}
bool BankAccount ::check_pin()
{
    string entered_pin;
    cout << "Enter your PIN: ";
    cin >> entered_pin;
    if (entered_pin == pin)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    BankAccount my_account;
    int a;
    cout << "Press 1 if you have a account in bank : \nPress 2 if you want to create a new account : " << endl;
    cout << "Enter your choice : ";
    cin >> a;
    cin.ignore(); // To ignore the newline character left in the input buffer after reading 'a'
    if (a == 1 || a == 2)
    {
        string name, number, set_pin;
        cout << "Enter your account holder name : ";
        getline(cin, name);
        cout << "Enter your account number : ";
        cin >> number;
        cout << "Enter your PIN : ";
        cin >> set_pin;
        my_account.setup_account(name, number, set_pin);
    }
    else
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    my_account.display();
    int choice;
    do
    {
        cout << endl;
        cout << "Press :1--->Deposit\nPress :2--->Withdraw\nPress :3--->Display\nPress :4--->Exit" << endl;
        cout << "Enter your Choice :- ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        { // use braces to create a new scope for the variable deposit_amount
            double deposit_amount;
            cout << "Enter the amount you want to deposite :- ";
            cin >> deposit_amount;
            my_account.deposit(deposit_amount);
            break;
        }
        case 2:
        {
            double withdraw_amount;
            cout << "Enter the amount you want to withdraw :- ";
            cin >> withdraw_amount;
            my_account.withdraw(withdraw_amount);
            break;
        }
        case 3:
            my_account.display();
            break;
        case 4:
            cout << "Thank you for using our banking services." << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
