#include <iostream>
#include <string>
using namespace std;
class ATM
{
private:
    int pin = 1234;
    double balance = 10000.0;

public:
    void checkPin()
    {
        int enteredPin;
        cout << "Enter your ATM PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin)
        {
            menu();
        }
        else
        {
            cout << "Incorrect PIN! Access Denied.\n";
        }
    }
    void menu()
    {
        int choice;
        do
        {
            cout << "\n===== ATM MANAGEMENT SYSTEM =====\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                checkBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                cout << "Thank you for using the ATM!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
            }

        } while (choice != 4);
    }

    void checkBalance()
    {
        cout << "\nCurrent Balance: Rs. " << balance << endl;
    }

    void depositMoney()
    {
        double amount;
        cout << "\nEnter amount to deposit: Rs. ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit Successful!\n";
            cout << "Updated Balance: Rs. " << balance << endl;
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    void withdrawMoney()
    {
        double amount;
        cout << "\nEnter amount to withdraw: Rs. ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount!\n";
        }
        else if (amount > balance)
        {
            cout << "Insufficient Balance!\n";
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
            cout << "Remaining Balance: Rs. " << balance << endl;
        }
    }
};

int main()
{
    ATM atm;
    atm.checkPin();

    return 0;
}
