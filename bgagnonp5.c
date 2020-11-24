/*------------------------------------------------------------------------------
Program file: bgagnonp5.c
Author:       Brett Gagnon
Date:         4/4/2019
Assignment:   Program #5
Objective:    Write a C program that prompts the user to enter some data regarding 
some clients to a business. The user should prompt for customer account number 
(a positive integer between 1 and 1000), a last name (a string), and their account 
balance (a positive floating point number) as shown below...
Once the user has completed entering the data, the program should then SORT THE
DATA IN ASCENDING ORDER BY ACCOUNT NUMBER, and then output the client
data in table form             
------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>
 
 
int main (void)
{
 
/* Declare variables */
/*----------------------------------------------------------------------------*/ 
    int i, j, k;
    int temp = 0;
    int account_number[5];
    int no_account;
    char last_name[5][30];
    char name_temp;
    float account_balance[5];
    float balance_temp = 0;
    bool valid;
 
/* Prompt user for account number, last name, and balance */
/*----------------------------------------------------------------------------*/ 
    printf ("Enter account number, last name, and balance.\n");
    printf ("Enter -999 to end input.\n");
    printf ("\n");
     
/* Loop to get all necessary account information */
/*----------------------------------------------------------------------------*/     
    for (i = 0; i < 6; i++)
    {
        printf ("? ");
        scanf ("%i", &account_number[i]);
         
        valid = true;
 
/* Ensure information is input properly */
/*----------------------------------------------------------------------------*/ 
        if (account_number[i] == -999)
        {
            break;
        }
         
        if (account_number[i] < 1 || account_number[i] > 1000)
        {
            printf ("*** Invalid account number. Please enter 1 - 1000 or -999 to exit ***\n");
            valid = false;
        }
         
        scanf ("%s", last_name[i]);
        scanf ("%f", &account_balance[i]);
              
        if (account_balance[i] < 0)
        {
            printf ("*** Invalid balance amount. Please enter a positive value. ***\n");
            valid = false;
        }
/* If conditions not met, de-increment i variable to re-enter info */
/*----------------------------------------------------------------------------*/         
        if(valid == false)
        {
            i--;
        }
 
        no_account = i + 1;
         
    } /* End for loop */
    
/* For loops to sort info by account number */
/*----------------------------------------------------------------------------*/     
    for(i = 0; i < no_account - 1; i++) 
    {
                 
        for(j = i + 1; j < no_account; j++) 
        {
/* Swap logic for account number */
/*----------------------------------------------------------------------------*/        	
            if(account_number[i] > account_number[j])
            {
                temp = account_number[i];
                account_number[i] = account_number[j];
                account_number[j] = temp;
                 
/* Swap logic for last name */
/*----------------------------------------------------------------------------*/
                for (k = 0; k < 30; k++)
                {
                    name_temp = last_name[i][k];
                    last_name[i][k] = last_name[j][k];
                    last_name[j][k] = name_temp;
                }
                 
/* Swap logic for account balance */
/*----------------------------------------------------------------------------*/
                balance_temp = account_balance[i];
                account_balance[i] = account_balance[j];
                account_balance[j] = balance_temp;
     
            }
        }
    }/* End for loop */
     
    printf("\nACCOUNT \t LAST NAME \t\t         BALANCE\n");
/* For loop to print account information */
/*----------------------------------------------------------------------------*/     
    for (i = 0; i < account_number[i]; i++)
    {
        printf("%i \t\t %-30s %8.2f\n", account_number[i], last_name[i], account_balance[i]);
    }
         
    getchar();
     
    return 0;
     
} /* End main */
