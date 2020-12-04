#include <stdio.h>
#include "myBank.h"

static double accs_arr[50][3];
static int accs_size = sizeof(accs_arr)/sizeof(accs_arr[0]);

static char* menu_text = "\nPlease choose a transaction type:"
    "\n O-Open Account"
    "\n B-Balance Inquiry" 
    "\n D-Deposit"
    "\n W-Withdrawal" 
    "\n C-Close Account" 
    "\n I-Interest" 
    "\n P-Print" 
    "\n E-Exit"
    "\n";

void menu() {
    printf("%s",menu_text);
}

void openAccount() {
    int counter = 0;
    for (int i=0; i<accs_size; i++) {
        if (accs_arr[i][0]==1) {
            counter++;
        }
        else {
            int acc_num;
            double dsum;
            dsum = deposit();
            if (dsum == -1) {
                printf("Failed to read the amount");
                printf("\n");
                return;
            }
            if (dsum < 0) {
                printf("Invalid Amount");
                printf("\n");
                return;
            }
            accs_arr[i][0] = 1;
            accs_arr[i][1] = i+901;
            accs_arr[i][2]+=dsum;
            acc_num = accs_arr[i][1];
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
    int validate = scanf("%lf", &deposit_amount);
    if (validate == 0) {
        return -1;
    }
    return deposit_amount;
}

void balance(int acc_num) {
    if (accs_arr[acc_num-901][0] != 1) {
        printf("This account is closed");
        printf("\n");
        return;
    }
    else if (acc_num > 950 || acc_num < 901) {
        printf("Invalid account number");
        printf("\n");
        return;
    }
    else {
        printf("The balance of account number %d is: %.2f",acc_num,accs_arr[acc_num-901][2]);
        printf("\n");
        return;
    }
}

void depositTrans(int acc_num) {
    if (acc_num > 950 || acc_num < 901) {
        printf("Invalid account number");
        printf("\n");
        return;
    }
    if (accs_arr[acc_num-901][0] != 1) {
        printf("This account is closed");
        printf("\n");
        return;
    }
    else {
        double deposit_amount;
        printf("Please enter amount for deposit: ");
        int validate = scanf("%lf", &deposit_amount);
        if (validate == 0) {
            printf("Failed to read the amount");
            printf("\n");
        }
        else if (deposit_amount < 0) {
            printf("Cannot deposit a negative amount");
            printf("\n");
        }
        else {
            accs_arr[acc_num-901][2] += deposit_amount;
            printf("The new balance is: %.2f",accs_arr[acc_num-901][2]);
            printf("\n");
        }   
    }
}

void withdraw(int acc_num) {
    if (acc_num > 950 || acc_num < 901) {
        printf("Invalid account number");
        return;
    }
    if (accs_arr[acc_num-901][0] != 1) {
        printf("This account is not active");
        return;
    }
    else {
        double w_sum;
        printf("Please enter the amount to withdraw: ");
        scanf("%lf", &w_sum);
        if (accs_arr[acc_num-901][2] < w_sum) {
            printf("Cannot withdraw more than the balance");
            printf("\n");
            return;
        }
        else {
            accs_arr[acc_num-901][2] -= w_sum;
            printf("The new balance is: %.2f",accs_arr[acc_num-901][2]);
            printf("\n");
        }
    }
}

void close(int acc_num) {
    if (acc_num > 950 || acc_num < 901) {
        printf("Invalid account number");
        printf("\n");
        return;
    }
    if (accs_arr[acc_num-901][0] != 1) {
        printf("This account is not active");
        printf("\n");
        return;
    }
    else {
        accs_arr[acc_num-901][0] = 0;
        accs_arr[acc_num-901][2] = 0;
        int closed_acc = accs_arr[acc_num-901][1];
        printf("Closed account number %d", closed_acc);
        printf("\n");
    }
}

void interest() {
    double interest_r;
    printf("Please enter interest rate: ");
    int validate = scanf("%lf", &interest_r);
    if (validate == 0) {
        printf("Failed to read the interest rate");
        printf("\n");
        return;
    } else if (interest_r < 0) {
        printf("Invalid interest rate");
        printf("\n");
    } else {
        for (int i=0; i<accs_size; i++) {
        if (accs_arr[i][0] == 1) {
            accs_arr[i][2] *= ((interest_r*0.01)+1);
            }
        }
    }
}

void printaccs() {
    for (int i=0; i<accs_size; i++) {
        if (accs_arr[i][0] == 1) {
            int acc_num;
            acc_num = accs_arr[i][1];
            printf("The balance of account number %d is: %.2f",acc_num,accs_arr[acc_num-901][2]);
            printf("\n");
        }
    } 
}