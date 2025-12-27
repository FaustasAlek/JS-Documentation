#include <stdio.h>
 #include "css_modifier.h"

void menu();

int main(){

    menu();
    return 0;
}

void menu(){

    int choice;

    while(1){
        printf("\n====== MENU ======\n");
        printf("0 - Website Appearance\n");
        printf("1 - Exit\n");

        if (scanf("%d", &choice) != 1) {
            printf("Wrong input. Please enter a valid number\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 0:
                int colorChoice;
                printf("Change background color:\n");
                printf("0 - red\n");
                printf("1 - blue\n");
                printf("2 - yellow\n");
                printf("3 - green\n");
                printf("Enter choice: ");


                if (scanf("%d", &colorChoice) != 1) {
                    printf("Invalid color choice.\n");
                    while(getchar() != '\n');
                    break;
                }

                if(colorChoice == 0){
                    modify_css_background("red");
                } else if(colorChoice == 1){
                    modify_css_background("blue");
                } else if(colorChoice == 2){
                    modify_css_background("yellow");
                } else if(colorChoice == 3){
                    modify_css_background("green");
                } else {
                    printf("Unknown color.\n");
                }
                break;

            case 1:
                printf("Exiting.\n");
                return;
        
            default:
                printf("Wrong Input. \n");
                break;
        }
    }
}