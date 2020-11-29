#include <stdio.h>
#include <string.h>
#include "myBank.h"

int main(void) {
    char menu_loop = 'M';
    menu();
    while (menu_loop != 'E')
    {
        scanf("%c",&menu_loop);
        if (menu_loop == 'O') {
            openAccount();
            menu();
        }
        if (menu_loop == 'B') {
            int acc_num;
            printf("Please enter account number: ");
            scanf("%d",&acc_num);
            balance(acc_num);
            menu();
        }
        if (menu_loop == 'D') {
            int acc_num;
            printf("Please enter account number: ");
            scanf("%d",&acc_num);
            depositTrans(acc_num);
            menu();
        }
        if (menu_loop == 'W') {
            int acc_num;
            printf("Please enter account number: ");
            scanf("%d",&acc_num);
            withdraw(acc_num);
            menu();
        }
        if (menu_loop == 'C') {
            int acc_num;
            printf("Please enter account number: ");
            scanf("%d",&acc_num);
            close(acc_num);
            menu();
        }
        if (menu_loop == 'I') {
            interest();
            menu();
        }
        if (menu_loop == 'P') {
            printaccs();
            menu();
        }
    }
}