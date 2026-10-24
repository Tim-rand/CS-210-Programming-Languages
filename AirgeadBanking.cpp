/*
 * CS 210 Project Two
 * Airgead Banking Investment Application
 * Name: Tim Randall
 *
 * This program collects investment information from the user
 * and displays investment growth with and without monthly deposits.
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include "Investment.h"

using namespace std;

// Gets a valid non-negative number from the user.
double getPositiveDouble(const string& t_prompt) {
    double value;

    while (true) {
        cout << t_prompt;

        if (cin >> value && value >= 0.0) {
            return value;
        }

        cout << "Invalid input. Please enter a non-negative number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Gets a valid positive whole number from the user.
int getPositiveInt(const string& t_prompt) {
    int value;

    while (true) {
        cout << t_prompt;

        if (cin >> value && value > 0) {
            return value;
        }

        cout << "Invalid input. Please enter a positive whole number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    char userChoice = 'Y';

    // Allow the user to test multiple investment scenarios.
    while (userChoice == 'Y' || userChoice == 'y') {
        double initialInvestment;
        double monthlyDeposit;
        double annualInterest;
        int numberOfYears;

        // Display the data input screen.
        cout << "**********************************" << endl;
        cout << "********** Data Input ************" << endl;

        initialInvestment =
            getPositiveDouble("Initial Investment Amount: $");
        monthlyDeposit =
            getPositiveDouble("Monthly Deposit: $");
        annualInterest =
            getPositiveDouble("Annual Interest: %");
        numberOfYears =
            getPositiveInt("Number of Years: ");

        cout << endl;
        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        // Create the investment using the user's information.
        Investment investment(initialInvestment, monthlyDeposit,
            annualInterest, numberOfYears);

        // Display both required investment reports.
        investment.displayWithoutMonthlyDeposits();
        investment.displayWithMonthlyDeposits();

        cout << endl;
        cout << "Would you like to test another investment scenario? (Y/N): ";
        cin >> userChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << endl;
    }

    cout << "Thank you for using the Airgead Banking Investment Calculator."
        << endl;

    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}