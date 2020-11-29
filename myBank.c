#include <stdio.h>
#include "myBank.h"

static double accs_arr[50][3];
static char* menu_text = "Please choose a transaction type: "
    "\n O-Open Account"
    "\n B-Balance Inquiry" 
    "\n D-Deposit"
    "\n W-Withdrawal" 
    "\n C-Close Account" 
    "\n I-Interest" 
    "\n P-Print" 
    "\n E-Exit"
    "\n";

void openAccount() {
    int counter = 0;
    int arr_size = sizeof(accs_arr);
    for (int i=0; i<arr_size; i++) {
        if (accs_arr[i][0]==1) {
            counter++;
        }
        else {
            accs_arr[i][0]=1;
            int acc_num;
            double dsum;
            acc_num = accs_arr[i][1]+901;
            dsum = deposit();
            accs_arr[i][2]+=dsum;
            printf("New account number is: %d \n",acc_num);
            return;
        }
        if (counter == 50) {
            printf("This bank can't hold more than 50 accounts and is currently full");
            return;
        }
    }
}

double deposit() {
    double deposit_amount;
    printf("Please enter amount for deposit: ");
    scanf("%lf", &deposit_amount);
    return deposit_amount;
}

void balance(int acc_num) {
    if (acc_num > 950 || acc_num < 901) {
        printf("Please enter a legal account number between the range 901-950");
        return;
    }
    else {
        printf("The balance of account number %d is: %.2f ",acc_num,accs_arr[acc_num-901][2]);
        printf("\n");
        return;
    }
}

void depositTrans(int acc_num) {
    if (acc_num > 950 || acc_num < 901) {
        printf("Please enter a legal account number between the range 901-950");
        return;
    }
    if (accs_arr[acc_num-901][0] != 1) {
        printf("This account is not active");
        return;
    }
    else {
        accs_arr[acc_num-901][2] += deposit();
    }
}

void menu() {
    printf("%s",menu_text);
}