/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<string.h>
#define DATAFILE "BankApplication.lst"
struct Bank
{
	char BankName[15];
	char BankBranch[15];
	char AccountHolder[20];
	int AccountNumber;
	int Balance;

};
int Options();
void AccountCreation();
void PrintAccount();
// void AccountUpdation();
void CloseAccount();
void SearchAccount();
FILE *fpBank;
struct Bank b;
int Choice;
void main()
{
	do
	{
		Options();
		switch(Choice)
		{
			case 1:
			AccountCreation();
			break;

			case 2:
			PrintAccount();
			break;

			case 3:
			// AccountUpdation();
			break;

			case 4:
			CloseAccount();
			break;

			case 5:
			SearchAccount();
			break;

			case 6:
			exit();
			break;
		}
	}while(Choice <= 6);
}
int Options()
{
	printf("1. Create an account.\n");
	printf("2. print the account.\n");
	printf("3. Update the account.\n");
	printf("4. Close the account.\n");
	printf("5. Search an account.\n");
	printf("6. Exit\n");
	printf("Enter your choice:\n");
	scanf("%d", &Choice);
	return;	
}
void AccountCreation()
{
	printf("Enter the name of the bank      : ");
	fflush(stdin);
	gets(b.BankName);
	printf("Which branch?                    ");
	gets(b.BankBranch);
	printf("Enter the account number        : ");
	scanf("%d", &b.AccountNumber);
	printf("Enter the name of account holder: ");
	fflush(stdin);
	gets(b.AccountHolder);
	printf("Enter the available balance     : ");
	scanf("%d", &b.Balance);
	printf("Account is Created.\n\n");
	fpBank = fopen(DATAFILE, "a");
	fwrite(&b, sizeof(b), 1, fpBank);
	fclose(fpBank);
}
void PrintAccount()
{
	int Counter = 0;
	fpBank = fopen(DATAFILE, "r");
	do
	{
		printf("No Accounts to show.\n");
	}while(fread == -1);
	while(fread(&b, sizeof(b), 1, fpBank) > 0)
	{
		Counter++;
		printf("Account holder-%d details:\n", Counter);
		printf("_________________________\n\n");
		printf("Bank Name          : %s\n", b.BankName);
		printf("Branch             : %s\n", b.BankBranch);
		printf("Account number     : %d\n", b.AccountNumber);
		printf("Account holder Name: %s\n", b.AccountHolder);
		printf("Available balance  : %d\n", b.Balance);
		printf("\n");
	}
	fclose(fpBank);
}
void SearchAccount()
{
	int AccNum;
	printf("Enter the account number to search: ");
	scanf("%d", &AccNum);
	fpBank = fopen(DATAFILE, "r");
	while(fread(&b, sizeof(b), 1, fpBank)>0)
	{
		if(AccNum == b.AccountNumber)
		{
			printf("The details are:\n");
			printf("Bank Name          : %s\n", b.BankName);
			printf("Branch             : %s\n", b.BankBranch);
			printf("Account number     : %d\n", b.AccountNumber);
			printf("Account holder Name: %s\n", b.AccountHolder);
			printf("Available balance  : %d\n", b.Balance);
		}
	}
	fclose(fpBank);
}
// void AccountUpdation()
// {
// 	int x;
// 	printf("Enter the account number to update your account: ");
// 	scanf("%d", &x);
// 	fpBank = fopen(DATAFILE, "r");
// 	while(fread(&b, sizeof(b), 1, fpBank))
{
	fseek(fpBank, 0, SEEK_CUR);
}
printf("")
// } 
void CloseAccount()
{
	int x, Found;
	printf("Enter the account number: ");
	scanf("%d", &x); 
	fpBank = fopen(DATAFILE, "r");
	while(fread(&b, sizeof(b), 1, fpBank) > 0)
	{
		if (strcmp(x, b.AccountNumber) == 0)
		{
			printf("A record with requested name found and deleted.\n\n");
			Found=1;
		} 
		// else
		// {
		// 	fwrite(&b, sizeof(b), 1, fpBank);
		// }
	}
	if (! Found)
	{
		printf("No account found with the requested number: %s\n\n", x);
	}

		fclose(fpBank);
	}