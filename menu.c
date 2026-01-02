#include <stdio.h>
#include "css_modifier.h"

void menu();
void handle_appearance_menu();
void handle_text_color_menu();
void handle_card_menu();
void handle_muted_menu();
void handle_code_bg_menu();
void handle_code_text_menu();
void handle_font_menu();
void handle_font_size_menu();

int main(){
    menu();
    return 0;
}

void menu(){
    int choice;
    while(1){
        printf("\n====== MENU ======\n");
        printf("0 - Website Appearance\n");
        printf("1 - Website text color\n");
        printf("2 - Card color\n");
        printf("3 - Muted text color\n");
        printf("4 - Code background color\n");
        printf("5 - Code text color\n");
        printf("6 - Website font family\n");
        printf("7 - Website font size\n");
        printf("9 - Exit\n");

        if (scanf("%d", &choice) != 1) {
            printf("Wrong input. Please enter a valid number\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 0:
                handle_appearance_menu();
                break;
            case 1:
                handle_text_color_menu();
                break;
            case 2:
                handle_card_menu();
                break;
            case 3:
                handle_muted_menu();
                break;
            case 4:
                handle_code_bg_menu();
                break;
            case 5:
                handle_code_text_menu();
                break;
            case 6:
                handle_font_menu();
                break;
            case 7:
                handle_font_size_menu();
                break;
            case 9:
                printf("Exiting.\n");
                return;
            default:
                printf("Wrong Input. \n");
                break;
        }
    }
}

void handle_appearance_menu() {
    int colorChoice;
    printf("Change background color:\n");
    printf("0 - red\n");
    printf("1 - blue\n");
    printf("2 - yellow\n");
    printf("3 - green\n");
    printf("4 - default\n");
    printf("Enter choice: ");

    if (scanf("%d", &colorChoice) != 1) {
        printf("Invalid color choice.\n");
        while(getchar() != '\n');
        return;
    }

    if(colorChoice == 0){
        modify_css_background("red");
    } else if(colorChoice == 1){
        modify_css_background("blue");
    } else if(colorChoice == 2){
        modify_css_background("yellow");
    } else if(colorChoice == 3){
        modify_css_background("green");
    } else if(colorChoice == 4){
        modify_css_background("#f3f5f9");
    } else {
        printf("Unknown color.\n");
    }
}

void handle_text_color_menu() {
    int textColor;
    printf("Change the heading color:\n");
    printf("0 - red\n");
    printf("1 - blue\n");
    printf("2 - yellow\n");
    printf("3 - black\n");
    printf("4 - default\n");
    printf("Enter choice: ");

    if (scanf("%d", &textColor) != 1) {
        printf("Invalid color choice.\n");
        while(getchar() != '\n');
        return;
    }
    
    if(textColor == 0){
        modify_css_text_color("red");
    } else if(textColor == 1){
        modify_css_text_color("blue");
    } else if(textColor == 2){
        modify_css_text_color("yellow");
    } else if(textColor == 3){
        modify_css_text_color("black");
    } else if(textColor == 4){
        modify_css_text_color("#1f2933");
    } else {
        printf("Unknown color.\n");
    }
}

void handle_card_menu() {
    int colorChoice;
    printf("Change card color:\n");
    printf("0 - white\n");
    printf("1 - lightgray\n");
    printf("2 - beige\n");
    printf("3 - default\n");
    printf("Enter choice: ");

    if (scanf("%d", &colorChoice) != 1) {
        printf("Invalid color choice.\n");
        while(getchar() != '\n');
        return;
    }
    
    if(colorChoice == 0){
        modify_css_card_color("white");
    } else if(colorChoice == 1){
        modify_css_card_color("lightgray");
    } else if(colorChoice == 2){
        modify_css_card_color("beige");
    } else if(colorChoice == 3){
        modify_css_card_color("#ffffff");
    } else {
        printf("Unknown color.\n");
    }
}

void handle_muted_menu() {
    int colorChoice;
    printf("Change muted text color:\n");
    printf("0 - gray\n");
    printf("1 - darkgray\n");
    printf("2 - lightblue\n");
    printf("3 - default\n");
    printf("Enter choice: ");

    if (scanf("%d", &colorChoice) != 1) {
        printf("Invalid color choice.\n");
        while(getchar() != '\n');
        return;
    }
    
    if(colorChoice == 0){
        modify_css_muted_color("gray");
    } else if(colorChoice == 1){
        modify_css_muted_color("darkgray");
    } else if(colorChoice == 2){
        modify_css_muted_color("lightblue");
    } else if(colorChoice == 3){
        modify_css_muted_color("#52606d");
    } else {
        printf("Unknown color.\n");
    }
}

void handle_code_bg_menu() {
    int colorChoice;
    printf("Change code background color:\n");
    printf("0 - lightgray\n");
    printf("1 - black\n");
    printf("2 - darkblue\n");
    printf("3 - default\n");
    printf("Enter choice: ");

    if (scanf("%d", &colorChoice) != 1) {
        printf("Invalid color choice.\n");
        while(getchar() != '\n');
        return;
    }
    
    if(colorChoice == 0){
        modify_css_code_bg_color("lightgray");
    } else if(colorChoice == 1){
        modify_css_code_bg_color("black");
    } else if(colorChoice == 2){
        modify_css_code_bg_color("darkblue");
    } else if(colorChoice == 3){
        modify_css_code_bg_color("#f6f8fb");
    } else {
        printf("Unknown color.\n");
    }
}

void handle_code_text_menu() {
    int colorChoice;
    printf("Change code text color:\n");
    printf("0 - black\n");
    printf("1 - white\n");
    printf("2 - red\n");
    printf("3 - default\n");
    printf("Enter choice: ");

    if (scanf("%d", &colorChoice) != 1) {
        printf("Invalid color choice.\n");
        while(getchar() != '\n');
        return;
    }
    
    if(colorChoice == 0){
        modify_css_code_text_color("black");
    } else if(colorChoice == 1){
        modify_css_code_text_color("white");
    } else if(colorChoice == 2){
        modify_css_code_text_color("red");
    } else if(colorChoice == 3){
        modify_css_code_text_color("#1f2933");
    } else {
        printf("Unknown color.\n");
    }
}

void handle_font_menu() {
    int fontChoice;
    printf("Change font family:\n");
    printf("0 - default sans\n");
    printf("1 - serif\n");
    printf("2 - mono\n");
    printf("3 - rounded sans\n");
    printf("Enter choice: ");

    if (scanf("%d", &fontChoice) != 1) {
        printf("Invalid font choice.\n");
        while(getchar() != '\n');
        return;
    }

    if(fontChoice == 0){
        modify_css_font("\"Segoe UI\", \"Helvetica Neue\", Arial, sans-serif");
    } else if(fontChoice == 1){
        modify_css_font("\"Georgia\", \"Times New Roman\", serif");
    } else if(fontChoice == 2){
        modify_css_font("\"SFMono-Regular\", Consolas, \"Liberation Mono\", Menlo, monospace");
    } else if(fontChoice == 3){
        modify_css_font("\"Trebuchet MS\", \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif");
    } else {
        printf("Unknown font.\n");
    }
}

void handle_font_size_menu() {
    int sizeChoice;
    printf("Change font size:\n");
    printf("0 - 14px\n");
    printf("1 - 16px\n");
    printf("2 - 18px\n");
    printf("3 - 20px\n");
    printf("4 - default\n");
    printf("Enter choice: ");

    if (scanf("%d", &sizeChoice) != 1) {
        printf("Invalid size choice.\n");
        while(getchar() != '\n');
        return;
    }

    if(sizeChoice == 0){
        modify_css_font_size("14px");
    } else if(sizeChoice == 1){
        modify_css_font_size("16px");
    } else if(sizeChoice == 2){
        modify_css_font_size("18px");
    } else if(sizeChoice == 3){
        modify_css_font_size("20px");
    } else if(sizeChoice == 4){
        modify_css_font_size("16px");
    } else {
        printf("Unknown size.\n");
    }
}
