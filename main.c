#include <stdio.h>
#include <string.h>
#include "myBank.h"

int main(void) {
    char menu_loop = 'M';
    while (menu_loop != 'E')
    {
        menu();
        scanf("%c",&menu_loop);
        if (menu_loop == "O") {
            openAccount();
        }
    }
}