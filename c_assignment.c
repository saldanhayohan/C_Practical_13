#include <stdio.h>
#include <string.h>

int main()
{
    char name[50];
    float loanAmount, annualRate, monthlyRate, emi, result = 1;
    int duration, totalInstallments, i;

    // Enter customer details
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Loan Amount: ");
    scanf("%f", &loanAmount);

    printf("Enter Annual Rate of Interest: ");
    scanf("%f", &annualRate);

    printf("Enter Loan Duration (in years): ");
    scanf("%d", &duration);

    // Calculate monthly interest rate
    monthlyRate = annualRate / (12 * 100);

    // Calculate total number of monthly installments
    totalInstallments = duration * 12;

    // Calculate (1 + monthlyRate)^totalInstallments
    for(i = 1; i <= totalInstallments; i++)
    {
        result = result * (1 + monthlyRate);
    }

    // Calculate EMI
    emi = (loanAmount * monthlyRate * result) / (result - 1);

    // Display loan summary
    printf("\n----- LOAN SUMMARY -----\n");
    printf("Customer Name: %s\n", name);
    printf("Loan Amount: %.2f\n", loanAmount);
    printf("Annual Interest Rate: %.2f%%\n", annualRate);
    printf("Loan Duration: %d years\n", duration);
    printf("Monthly Interest Rate: %.4f\n", monthlyRate);
    printf("Total Monthly Installments: %d\n", totalInstallments);
    printf("Estimated Monthly EMI: %.2f\n", emi);

    return 0;
}