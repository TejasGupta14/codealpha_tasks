#include <stdio.h>
#include <stdlib.h>

struct Account
{
    int accNo;
    char name[50];
    float balance;
};

void createAccount();
void deposit();
void withdraw();
void balanceEnquiry();

int main()
{
    int choice;

    do
    {
        printf("\n==================================");
        printf("\n BANK ACCOUNT MANAGEMENT SYSTEM");
        printf("\n==================================");
        printf("\n1. Create Account");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Balance Enquiry");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                balanceEnquiry();
                break;

            case 5:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}

void createAccount()
{
    FILE *fp;
    struct Account acc;

    fp = fopen("bank.dat", "ab");

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.accNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", acc.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("\nAccount Created Successfully!\n");
}

void deposit()
{
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;
    float amount;

    fp = fopen("bank.dat", "rb+");

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    while(fread(&acc, sizeof(acc), 1, fp))
    {
        if(acc.accNo == accNo)
        {
            acc.balance += amount;

            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("\nDeposit Successful!");
            printf("\nUpdated Balance = %.2f\n", acc.balance);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nAccount Not Found!\n");

    fclose(fp);
}

void withdraw()
{
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;
    float amount;

    fp = fopen("bank.dat", "rb+");

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);

    while(fread(&acc, sizeof(acc), 1, fp))
    {
        if(acc.accNo == accNo)
        {
            if(acc.balance >= amount)
            {
                acc.balance -= amount;

                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);

                printf("\nWithdrawal Successful!");
                printf("\nRemaining Balance = %.2f\n", acc.balance);
            }
            else
            {
                printf("\nInsufficient Balance!\n");
            }

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nAccount Not Found!\n");

    fclose(fp);
}

void balanceEnquiry()
{
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;

    fp = fopen("bank.dat", "rb");

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    while(fread(&acc, sizeof(acc), 1, fp))
    {
        if(acc.accNo == accNo)
        {
            printf("\nAccount Number : %d", acc.accNo);
            printf("\nAccount Holder : %s", acc.name);
            printf("\nCurrent Balance: %.2f\n", acc.balance);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nAccount Not Found!\n");

    fclose(fp);
}
