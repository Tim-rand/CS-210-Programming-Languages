/*
 * CS 210 Project Two
 * Airgead Banking Investment Application
 * Name: Tim Randall
 *
 * This file implements the Investment class and calculates
 * investment growth with and without monthly deposits.
 */

#include "Investment.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Initializes an Investment object with the user's input values.
Investment::Investment(double t_initialInvestment, double t_monthlyDeposit,
    double t_annualInterest, int t_numberOfYears) {
    m_initialInvestment = t_initialInvestment;
    m_monthlyDeposit = t_monthlyDeposit;
    m_annualInterest = t_annualInterest;
    m_numberOfYears = t_numberOfYears;
}

// Calculates the interest earned during one month.
double Investment::calculateMonthlyInterest(double t_balance) const {
    return t_balance * ((m_annualInterest / 100.0) / 12.0);
}

// Displays yearly investment growth without additional monthly deposits.
void Investment::displayWithoutMonthlyDeposits() const {
    double balance = m_initialInvestment;

    cout << endl;
    cout << "     Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "============================================================" << endl;
    cout << left << setw(10) << "Year"
        << setw(25) << "Year End Balance"
        << "Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = calculateMonthlyInterest(balance);

            balance += monthlyInterest;
            yearlyInterest += monthlyInterest;
        }

        cout << left << setw(10) << year
            << "$" << setw(24) << fixed << setprecision(2) << balance
            << "$" << fixed << setprecision(2) << yearlyInterest << endl;
    }
}

// Displays yearly investment growth with additional monthly deposits.
void Investment::displayWithMonthlyDeposits() const {
    double balance = m_initialInvestment;

    cout << endl;
    cout << "      Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "============================================================" << endl;
    cout << left << setw(10) << "Year"
        << setw(25) << "Year End Balance"
        << "Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            // The current month's deposit does not earn interest
            // until the following month.
            double monthlyInterest = calculateMonthlyInterest(balance);

            balance += monthlyInterest;
            yearlyInterest += monthlyInterest;

            balance += m_monthlyDeposit;
        }

        cout << left << setw(10) << year
            << "$" << setw(24) << fixed << setprecision(2) << balance
            << "$" << fixed << setprecision(2) << yearlyInterest << endl;
    }
}