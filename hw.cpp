
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class BankAccount {
    string name;
    int accNumber;
    double balance;
    static int nextAccNumber;

public:
    BankAccount(string n, double initialBalance) {
        name = n;
        balance = initialBalance;
        accNumber = nextAccNumber++;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void showDetails() {
        cout << "Name: " << name << " | Account Number: " << accNumber << " | Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void openFDR(double amount, int years, double interestRate = 6.5) {
        double maturity = amount + (amount * interestRate * years) / 100.0;
        cout << "FDR opened for $" << amount << " at " << interestRate << "% for " << years << " years. Maturity Amount: $" << fixed << setprecision(2) << maturity << endl;
    }

    void openDPS(double monthly, int years, double interestRate = 5.5) {
        int months = years * 12;
        double totalDeposit = monthly * months;
        double maturity = totalDeposit + (totalDeposit * interestRate * years) / 100.0;
        cout << "DPS opened: $" << monthly << "/month for " << years << " years at " << interestRate << "% interest. Maturity Amount: $" << fixed << setprecision(2) << maturity << endl;
    }
};

int BankAccount::nextAccNumber = 1001;

int main() {
    vector<BankAccount> users;

    // Creating 10 user accounts
    for (int i = 1; i <= 10; ++i) {
        users.push_back(BankAccount("User" + to_string(i), 1000.0));
    }

    // Sample operations
    cout << " Showing All Account Details \n";
    for (auto &user : users) {
        user.showDetails();
    }

    cout << "\n Performing Transactions for User1 \n";
    users[0].deposit(500);
    users[0].withdraw(300);
    users[0].openFDR(2000, 3);
    users[0].openDPS(100, 5);

    return 0;
}
