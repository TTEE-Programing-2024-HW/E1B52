#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 函數原型
void initializeSeats(char seats[][9]);
void displaySeats(char seats[][9]);
void chooseSeats(char seats[][9]);
void clearScreen();

int main(void)
{
    printf("***************************************************\n");
    printf(" \n");
    printf("                   程式作業三\n");
    printf("                   E1B52連昱瑄\n");
    printf(" \n");
    printf("*********    **    *********    *******    *******   \n");
    printf("*********    **    **     **    *******    ******* \n");
    printf("**           **    **      **   **              **  \n");
    printf("**           **    **     *     **              **     \n");
    printf("*******      **    *******      *******    *******      \n");
    printf("*******      **    *******      *******    *******     \n");
    printf("**           **    **     *          **    **      \n");
    printf("**           **    **     **         **    **      \n");
    printf("*********    **    **      **  ********    *******         \n");
    printf("*********    **    *********   ********    *******         \n");
    printf(" \n");
    printf("***************************************************\n");

    const char Password[] = "2024";
    char inputPassword[6]; 
    int attempts = 0;
    char seats[9][9];

    while (attempts < 3) {
        printf("請輸入密碼：");
        scanf("%s", inputPassword);

        if (strcmp(inputPassword, Password) == 0) {
            printf("密碼正確，歡迎進入此程式!\n");

            char choice;
            do {
                printf("----[Booking System]----\n");
                printf("| a.Available seats    |\n");
                printf("| b.Arrange for you    |\n");
                printf("| c.Choose by yourself |\n");
                printf("| d.Exit               |\n");
                printf("------------------------\n");
                printf("請選擇操作：");
                scanf(" %c", &choice);

                switch (choice) {
                    case 'a':
                        clearScreen();
                        initializeSeats(seats);
                        displaySeats(seats);
                        printf("按下任意鍵返回主選單...");
                        getchar(); // 捕獲前一個'\n'
                        getchar(); // 等待用戶輸入任意字符
                        clearScreen();
                        break;
                    case 'b':
                        clearScreen();
                        // 將您的其他功能代碼放在這裡
                        printf("按下任意鍵返回主選單...");
                        getchar(); // 捕獲前一個'\n'
                        getchar(); // 等待用戶輸入任意字符
                        clearScreen();
                        break;
                    case 'c':
                        clearScreen();
                        chooseSeats(seats);
                        printf("按下任意鍵返回主選單...");
                        getchar(); // 捕獲前一個'\n'
                        getchar(); // 等待用戶輸入任意字符
                        clearScreen();
                        break;
                    case 'd':
                        printf("程式結束\n");
                        break;
                    default:
                        printf("無效的選項，請重新選擇。\n");
                }
            } while (choice != 'd');

            break; // 如果密碼正確，跳出迴圈
        } 
        else 
        {
            printf("密碼錯誤!\n\a");
            attempts++; // 錯誤次數加一
            if(attempts >= 3)
            {
                printf("密碼錯誤，程式結束\n");
                break; // 如果錯誤次數超過三次，跳出迴圈
            }
        }
    }

    return 0;
}

const int ROWS = 9;
const int COLS = 9;
const int NUM_RESERVED_SEATS = 10;

void displaySeats(char seats[][9]) {
    printf("  123456789\n");
    for (int i =8; i>=0;--i) {
        printf("%d ", i + 1);
        for (int j = 0; j < 9; ++j) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

void chooseSeats(char seats[][9]) {
    char input[10];
    int row, col;
    int selected = 0;

    do {
        printf("請輸入座位選擇（格式如1-2）：");
        scanf("%s", input);

        if (sscanf(input, "%d-%d", &row, &col) != 2 || row < 1 || row > 9 || col < 1 || col > 9) {
            printf("無效的座位選擇。\n");
            continue;
        }

        if (seats[row-1][col-1] == '@') {
            printf("座位 [%d-%d] 已被選擇，請重新選擇。\n", row, col);
            continue;
        }

        seats[row-1][col-1] = '@';
        selected++;

        displaySeats(seats);
        printf("按下任意鍵繼續選擇，按下'd'結束選擇：");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'd') {
            break;
        }
    } while (selected < 9);

    // 將已選擇的座位記錄下來
}

void clearScreen() {
    system("cls"); // Windows 系統下清除螢幕的方法
}
