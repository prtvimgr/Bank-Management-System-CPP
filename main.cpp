#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class BankAccount
{
private:
    int accountNumber;
    string name;
    float balance;
public:
    void createAccount()
    {
        cout << "\nEnter Account Number : ";
        cin >> accountNumber;
        cin.ignore();
        cout << "Enter Customer Name : ";
        getline(cin, name);
        cout << "Enter Initial Deposit : ";
        cin >> balance;
    }
    void showAccount()
    {
        cout << "\n-----------------------------";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nCustomer Name  : " << name;
        cout << "\nBalance        : " << balance;
        cout << "\n-----------------------------";
    }
    int getAccountNumber()
    {
        return accountNumber;
    }
    float getBalance()
    {
        return balance;
    }
    void deposit()
    {
        float amount;
        cout << "\nEnter Amount to Deposit : ";
        cin >> amount;
        balance += amount;
        cout << "\nAmount Deposited Successfully.";
    }
    void withdraw()
    {
        float amount;
        cout << "\nEnter Amount to Withdraw : ";
        cin >> amount;
        if(amount <= balance)
        {
            balance -= amount;
            cout << "\nWithdrawal Successful.";
        }
        else
        {
            cout << "\nInsufficient Balance.";
        }
    }
    void writeToFile()
    {
        ofstream file("accounts.txt", ios::app);
        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;
        file.close();
    }
};
int main()
{
    BankAccount account;
    int choice;
    do
    {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Display Account";
        cout << "\n5. Exit";
        cout << "\n\nEnter Choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                account.createAccount();
                account.writeToFile();
                cout << "\nAccount Created Successfully.\n";
                break;
            case 2:
                account.deposit();
                break;
            case 3:
                account.withdraw();
                break;
            case 4:
                account.showAccount();
                break;
            case 5:
                cout << "\nThank You!\n";
                break;
            default:
                cout << "\nInvalid Choice!";
        }
    } while(choice != 5);
    return 0;
}
