#ifndef AIRGEADBANKING_INVESTMENT_H_
#define AIRGEADBANKING_INVESTMENT_H_

/*
 * CS 210 Project Two
 * Airgead Banking Investment Application
 * Name: Tim Randall
 *
 * This class stores investment information and provides
 * functions for displaying investment growth reports.
 */

class Investment {
public:
    // Constructor
    Investment(double t_initialInvestment, double t_monthlyDeposit,
        double t_annualInterest, int t_numberOfYears);

    // Displays investment growth without monthly deposits.
    void displayWithoutMonthlyDeposits() const;

    // Displays investment growth with monthly deposits.
    void displayWithMonthlyDeposits() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

    // Calculates one month of earned interest.
    double calculateMonthlyInterest(double t_balance) const;
};

#endif // AIRGEADBANKING_INVESTMENT_H_