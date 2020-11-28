#include <stdio.h>

static int accs_arr[50][3];
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
    if (acc_num > 950 || acc_num < 901) {
        printf("The given account number is out of the banks bounds, Please enter a number between 901-950");
        return;
    }
    if (accs_arr[acc_num-901][0]==1) {
        printf("This account number is already taken. Please choose another number within the range 901-950");
        return;
    }
    accs_arr[acc_num-901][0] = 1;
}

void menu() {
    printf("%s",menu_text);
}