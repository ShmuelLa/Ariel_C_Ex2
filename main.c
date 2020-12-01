#include <stdio.h>
#include <string.h>
#include "myBank.h"

int main(void) {
    int validate;
    char ui = 'M';
    menu();
    while (ui != 'E')
    {
        validate = scanf("%s", &ui);
        if (ui == 'O') {
            openAccount();
            menu();
        }
        if (ui == 'B') {
            int acc_num;
            printf("Please enter account number: ");
            scanf("%d", &acc_num);
            balance(acc_num);
            menu();
        }
        if (ui == 'D') {
            int acc_num;
            printf("Please enter account number: ");
            scanf("%d", &acc_num);
            depositTrans(acc_num);
            menu();
        }
        if (ui == 'W') {
            int acc_num;
            printf("Please enter account number: ");
            scanf("%d", &acc_num);
            withdraw(acc_num);
            menu();
        }
        if (ui == 'C') {
            int acc_num;
            printf("Please enter account number: ");
            scanf("%d", &acc_num);
            close(acc_num);
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
            printf("Invalid transaction type");
            printf("\n");
            menu();
        }
    }
}