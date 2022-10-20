#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#define MENU_SIZE 3
#define MENU_SIZE_1 2
#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

void GenerateMass(int size, int* mass) {
    int i;
    for (i = 0; i < size; i++) {
        mass[i] = rand() % 100;
    }

}

void PrintMass(int size, int* mass) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", mass[i]);
    }
}


void SettingMenu(int size, int* mass) {
    system("title Application");


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);


    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

    system("cls");


    int choose_pos_1;
    int iKey_1;
    int exit_flag_1;
    int i;


    COORD cursorPos;

    char* menu_1[MENU_SIZE_1] = { "Задать массив", "Посмотреть текущий"};


    exit_flag_1 = 0;
    choose_pos_1 = 0;

    while (!exit_flag_1) {



        system("cls");
        iKey_1 = 67;
        cursorPos = (COORD){ 0, 0 };
        SetConsoleCursorPosition(hStdOut, cursorPos);


        while (iKey_1 != KEY_EXIT && iKey_1 != KEY_ENTER) {
            switch (iKey_1) {
            case KEY_ARROW_UP:
                choose_pos_1--;
                break;
            case KEY_ARROW_DOWN:
                choose_pos_1++;
                break;
            }

            system("cls");


            if (choose_pos_1 < 0) { choose_pos_1 = MENU_SIZE_1 - 1; }
            if (choose_pos_1 > MENU_SIZE_1 - 1) { choose_pos_1 = 0; }

            for (int i = 0; i < MENU_SIZE_1; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", menu_1[i]);
            }


            cursorPos = (COORD){ 0, choose_pos_1 };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey_1);
            cursorPos = (COORD){ strlen(menu_1[choose_pos_1]) + 3 + 1, choose_pos_1 };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");


            iKey_1 = _getch();
        }


        switch (choose_pos_1) {
        case 0:
            system("cls");
            GenerateMass(size, mass);
            system("pause");
            break;
        case 1:
            system("cls");
            PrintMass(size, mass);
            system("pause");
            break;
        }
    }
}


int main() {

    system("title Application");

    
    SetConsoleCP(1251);         
    SetConsoleOutputCP(1251);   

    
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

   
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);


    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

    system("cls");


    int choose_pos;                    
    int iKey;                          
    int exit_flag;
    int size;
    int* mass;
    printf("Введите размер массива - ");
    scanf_s("%d", &size);
    
    mass = (int*)malloc(sizeof(int) * size);

    COORD cursorPos;                   

    char* menu[MENU_SIZE] = { "Алгоритмы", "Настройки", "Выход" };


    exit_flag = 0;
    choose_pos = 0;

    while (!exit_flag) {



        system("cls");
        iKey = 67;
        cursorPos = (COORD){ 0, 0 };
        SetConsoleCursorPosition(hStdOut, cursorPos);


        while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
            switch (iKey) {
            case KEY_ARROW_UP:
                choose_pos--;
                break;
            case KEY_ARROW_DOWN:
                choose_pos++;
                break;
            }

            system("cls");


            if (choose_pos < 0) { choose_pos = MENU_SIZE - 1; }
            if (choose_pos > MENU_SIZE - 1) { choose_pos = 0; }

            for (int i = 0; i < MENU_SIZE; i++) {
                cursorPos = (COORD){ 3, i };
                SetConsoleCursorPosition(hStdOut, cursorPos);
                printf("%s \n", menu[i]);
            }


            cursorPos = (COORD){ 0, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("<<", iKey);
            cursorPos = (COORD){ strlen(menu[choose_pos]) + 3 + 1, choose_pos };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf(">>");


            iKey = _getch();
        }


        switch (choose_pos) {
        case 0:
            system("cls");
            printf("Game part in development\n");
            system("pause");
            break;
        case 1:
            system("cls");
            SettingMenu(size, mass);
            system("pause");
            break;
        case 2:
            exit_flag = 1;
            break;
        }
    }


    system("cls");
    printf("Goodbay!\n");


    system("pause");
    return 0;
}