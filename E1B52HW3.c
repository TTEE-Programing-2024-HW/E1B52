#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define size 9

// Function Prototypes
void initializeSeats(char seats[size][size]);
void displaySeats(char seats[size][size]);
void autoChooseSeat(char seats[size][size], int n);
void chooseSeats(char seats[size][size]);
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

    int password;
    int count = 0;
    char seats[size][size];

    while (count < 3)
    {
        printf("請輸入密碼：");
        scanf("%d", &password);

        if (password == 2024)
        {
            printf("密碼正確，歡迎進入此程式!\n");

            char choice;
            do
            {
                printf("----[Booking System]----\n");
                printf("| a.Available seats    |\n");
                printf("| b.Arrange for you    |\n");
                printf("| c.Choose by yourself |\n");
                printf("| d.Exit               |\n");
                printf("------------------------\n");
                printf("請選擇操作：");
                scanf(" %c", &choice);

                switch (choice)
                {
                case 'a':
                    clearScreen();
                    initializeSeats(seats);
                    displaySeats(seats);
                    printf("按下任意鍵返回主選單...");
                    getchar(); 
                    getchar(); // Wait for the user to enter any character
                    clearScreen();
                    break;
                case 'b':
                    clearScreen();
                    autoChooseSeat(seats, 4);
                    printf("按下任意鍵返回主選單...");
                    getchar(); 
                    getchar(); // Wait for the user to enter any character
                    clearScreen();
                    break;
                case 'c':
                    clearScreen();
                    chooseSeats(seats);
                    printf("按下任意鍵返回主選單...");
                    getchar(); 
                    getchar(); // Wait for the user to enter any character
                    clearScreen();
                    break;
                case 'd':
                    printf("程式結束\n");
                    break;
                default:
                    printf("無效的選項，請重新選擇。\n");
                }
            } while (choice != 'd');

            break; // If the password is correct, jump out of the loop
        }
        else
                {
            printf("密碼錯誤!\n\a");
            count++; // The number of errors is increased by one
            if (count >= 3)
            {
                printf("密碼錯誤，程式結束\n");
                break; // If the number of errors exceeds three times, the loop is jumped
            }
        }
    }

    return 0;
}

void initializeSeats(char seats[size][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            seats[i][j] = '-';
        }
    }
    for (i = 0; i < 10; i++)
    {
        int row = rand() % size;
        int col = rand() % size;
        seats[row][col] = '*';
    }
}

void displaySeats(char seats[size][size])
{
    int i, j;
    printf("  1 2 3 4 5 6 7 8 9\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", i + 1);
        for (j = 0; j < size; j++)
        {
            printf("%c ", seats[i][j]);
        }
        printf("\n");
    }
    system("pause");
    system("cls");
}

void autoChooseSeat(char seats[size][size], int n)
{
	int k;
	printf("請問需要幾個座位:\n");
	scanf("%d",&k);
    while (1)
    {
        int row = rand() % size;
        int col = rand() % size;
        int k;
        if (n == 4)
        {
            if (seats[row][col] == '-' && seats[row][col + 1] == '-' && seats[row + 1][col] == '-' && seats[row + 1][col + 1] == '-' && (col + 1) < size)
            {
                seats[row][col] = '@';
                seats[row][col + 1] = '@';
                seats[row + 1][col] = '@';
                seats[row + 1][col + 1] = '@';
                printf("System has arranged your seats!\n");
                displaySeats(seats);
                char sat;
                printf("Satisfied? (y/n)");
                while (1)
                {
                    fflush(stdin);
                    scanf("%c", &sat);

                    if (sat == 'y')
                    {
                        seats[row][col] = '*';
                        seats[row][col + 1] = '*';
                        seats[row + 1][col] = '*';
                        seats[row + 1][col + 1] = '*';
                        return;
                    }
                    else if (sat == 'n')
                    {
                        seats[row][col] = '-';
                        seats[row][col + 1] = '-';
                        seats[row + 1][col] = '-';
                        seats[row + 1][col + 1] = '-';
                        break;
                    }
                    else
                    {
                        printf("Satisfied? (y/n): ");
                    }
                }
            }
        }
        if (n >= 1 && n <= 4)
        {
            for (k = 0; k < n; k++)
            {
                if (seats[row][col + k] != '-' || (col + k) >= size)
                {
                    break;
                }
            }
            if (k == n)
            {
                for (k = 0; k < n; k++)
                {
                    seats[row][col + k] = '@';
                }
                printf("System has arranged your seats!\n");
                displaySeats(seats);
                char sat;
                printf("Satisfied? (y/n)");
                while (1)
                {
                    fflush(stdin);
                    scanf("%c", &sat);
                    if (sat == 'y')
                    {
                        for (k = 0; k < n; k++)
                        {
                            seats[row][col + k] = '*';
                        }
                        return;
                    }
                    else if (sat == 'n')
                    {
                        for (k = 0; k < n; k++)
                        {
                            seats[row][col + k] = '-';
                        }
                        break;
                    }
                    else
                    {
                        printf("Satisfied? (y/n): ");
                    }
                }
            }
        }
    }
}

void chooseSeats(char seats[size][size])
{
    char input[100];
    while (1)
    {
        int i = 0, j = 0;
        printf("Please input the seats and input '0' for the end (for example \"1-2 2-9 0\"): ");
        fflush(stdin);
        fgets(input, sizeof(input), stdin);
        char *box = strtok(input, " ");
        while (box != NULL)
        {
            if (box[0] == '0')
            {
                break;
            }
            else if (strlen(box) != 3 || box[1] != '-' || box[0] < '1' || box[0] > '9' || box[2] < '1' || box[2] > '9')
            {
                i++;
                printf("wrong input format\n");
                break;
            }
            else
            {
                if (seats[box[0] - '1'][box[2] - '1'] == '@' || seats[box[0] - '1'][box[2] - '1'] == '*')
                {
                    i++;
                    printf("Seat [%d,%d] has already been chosen\n", (box[0] - '1') + 1, (box[2] - '1') + 1);
                    break;
                }
                else
                {
                    seats[box[0] - '1'][box[2] - '1'] = '@';
                }
            }
            box = strtok(NULL, " ");
        }
        if (i == 0)
        {
            displaySeats(seats);
            for (i = 0; i < size; i++)
            {
                for (j = 0; j < size; j++)
                {
                    if (seats[i][j] == '@')
                    {
                        seats[i][j] = '*';
                    }
                }
            }
            return;
        }
        else
        {
            for (i = 0; i < size; i++)
            {
                for (j = 0; j < size; j++)
                {
                    if (seats[i][j] == '@')
                    {
                        seats[i][j] = '-';
                    }
                }
            }
        }
    }
}

void clearScreen()
{
    system("cls");
}

}
void clearScreen() {
    system("cls"); // Windows 系統下清除螢幕的方法
}
\\心得:我學到了將程式劃分為多個函數，每個函數負責不同的任務，這樣做有助於提高程式的結構化和可讀性以及使用陣列處理資料、使用迴圈和條件語句，這次練習結合了整學期所學，我覺得因為用的函數很多所以很複雜，須細心才能讓程式正確執行，但我覺得太難了。
