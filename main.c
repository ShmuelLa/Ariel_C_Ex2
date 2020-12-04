#include <stdio.h>
#include <string.h>
#include "myBank.h"

int main(void) {
    int validate;
    char ui = 'M';
    menu();
    while (ui != 'E')
    {
        validate = scanf(" %c" , &ui);
        if (ui == 'O') {
            openAccount();
            menu();
        }
        if (ui == 'B') {
            int acc_num;
            printf("Please enter account number: ");
            if (scanf("%d", &acc_num) == 1) {
                balance(acc_num);
            }
            else {
                printf("Failed to read the account number\n");
            }
            menu();
        }
        if (ui == 'D') {
            int acc_num;
            printf("Please enter account number: ");
            if (scanf("%d", &acc_num) == 1) {
                depositTrans(acc_num);
            }
            else {
                printf("Failed to read the account number\n");
            }
            menu();
        }
        if (ui == 'W') {
            int acc_num;
            printf("Please enter account number: ");
            if (scanf("%d", &acc_num) == 1) {
                withdraw(acc_num);
            }
            else {
                printf("Failed to read the account number\n");
            }
            menu();
        }
        if (ui == 'C') {
            int acc_num;
            printf("Please enter account number: ");
            if (scanf("%d", &acc_num) == 1) {
                close(acc_num);
            }
            else {
                printf("Failed to read the account number\n");
            }
            menu();
        }
        if (ui == 'I') {
            interest();
            menu();
        }
        if (ui == 'P') {
            printaccs();
            menu();
        }
        else if ((ui!='O'&&ui!='B'&&ui!='P'&&ui!='I'&&ui!='C'&&ui!='W'&&ui!='D'&&ui!='E')||(validate==0)) {
            printf("Invalid transaction type\n");
            menu();
        }
    }
}