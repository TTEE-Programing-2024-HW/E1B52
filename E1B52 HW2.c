#include <stdio.h>
#include <stdlib.h>

void menu(void);
void picture(void);

int main(void) {
  //定義變量
    int count = 0;
    int password = 2024;
    char MENU, c, OPTION;
    int n, i, j;
    
    while (count < 3) {
        printf("請輸入密碼:\n");
        scanf("%d", &password);
        count++;
        if (password == 2024) {
            printf("輸入正確\n");
            break;
        } else {
            printf("輸入錯誤\n");
            if (count == 3)
                printf("已連續錯誤3次\n");
          return 0;
        }
    }

    system("CLS"); // 清除螢幕

    while (1) {
        menu();
        printf("    請輸入想執行的選項: ");
        fflush(stdin);
        scanf(" %c", &MENU); 

        switch (MENU) {
            case 'a':
            case 'A':
                system("CLS");
                do {
                    printf("    請輸入一個'a'到'n'的字元: ");
                    fflush(stdin);
                    scanf(" %c", &c); 
                    if (c < 'a' || c > 'n') {
                        printf("輸入錯誤!請重新輸入~\n");
                    }
                } while (c < 'a' || c > 'n');
                for (char A = c; A >= 'a'; A--) {
                    for (char space = 'a'; space < A; space++) {
                        printf(" ");
                    }
                    for (char B = A; B <= c; B++) {
                        printf("%c", B);
                    }
                    printf("\n");
                }
                getchar(); 
                system("CLS");
                break;
            case 'b':
            case 'B':
                system("cls");
                do {
                    printf("請輸入一個1至9的整數n：");
                    fflush(stdin);
                    scanf("%d", &n);
                    if (n < 1 || n > 9) {
                        printf("輸入錯誤!請重新輸入~\n");
                    }
                } while (n < 1 || n > 9);
                printf("乘法表：\n");
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n; j++) {
                        printf("  %d * %d = %2d  ", i, j, i * j);
                    }
                    printf("\n");
                }
                getchar(); // 吸收上一次輸入的換行符
                system("CLS");
                break;
            case 'c':
            case 'C':
                do {
                    printf("是否要繼續執行程式? [是] 請輸入(Y or y)，[否] 請輸入(N or n) :\n");
                    fflush(stdin);
                    scanf(" %c", &OPTION); // 空格以避免吸收上一次輸入的換行符
                    if (OPTION == 'y' || OPTION == 'Y') {
                        system("CLS");
                        break;
                    } else if (OPTION == 'n' || OPTION == 'N') {
                        return 0;
                    } else {
                        printf("輸入錯誤\n");
                    }
                } while (OPTION != 'y' && OPTION != 'Y' && OPTION != 'n' && OPTION != 'N');
                break;
        }
    }
    
    system("PAUSE");
    return 0;
}

void picture(void) {
    printf("**********************************\n");
    printf("         歡迎進入程式設計作業!\n");
    printf("**********************************\n");
    printf("          今天是2024年5月5日\n");
    printf("**********************************\n");
    printf("           '\\我是E1B52'\\\n \a");
    printf("**********************************\n");
}

void menu(void) {
    printf("\n\n");
    printf("         |**********************************|\n");
    printf("         |                                  |\n");
    printf("         |    ***              ***          |\n");
    printf("         |     **  E1B52       **           |\n");
    printf("         |      *              *            |\n");
    printf("         |__________________________________|\n");
    printf("         |                                  |\n");
    printf("         |      *        MENU        *      |\n");
    printf("         |                                  |\n");
    printf("         |    * **a. 畫出直角三角形 **  *   |\n");
    printf("         |     * **b. 顯示乘法表   ** *     |\n");
    printf("         |      * **c. 結束      ** *       |\n");
    printf("         |                                  |\n");
    printf("         |                                  |\n");
printf("心得:這次作業結合了很多老師上課的內容，經過這次的練習讓我對更多指令熟悉了。/n") ;
printf("因為編輯了很多次都無法執行，讓我知道下次撰寫程式時要更細心。");
