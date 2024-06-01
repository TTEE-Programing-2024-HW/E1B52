#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#define MAX_STUDENTS 10
#define MIN_STUDENTS 5

using namespace std;

struct Student {
    string name;
    int id;
    int math;
    int physics;
    int english;
    float average;
};

vector<Student> students;
int student_count = 0;

void clear_screen() {
    system("cls||clear");
}

void pause_screen() {
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
}

void enter_grades() {
    clear_screen();
    int n;
    printf("Enter the number of students (5-10): ");
    scanf("%d", &n);
    while (n < MIN_STUDENTS || n > MAX_STUDENTS) {
        printf("Invalid input. Please enter a number between 5 and 10: ");
        scanf("%d", &n);
    }
    student_count = n;
    students.resize(n);
    for (int i = 0; i < student_count; i++) {
        printf("Enter student %d name: ", i + 1);
        cin >> students[i].name;
        printf("Enter student %d ID (6 digits): ", i + 1);
        scanf("%d", &students[i].id);
        while (students[i].id < 100000 || students[i].id > 999999) {
            printf("Invalid ID. Please enter a 6-digit number: ");
            scanf("%d", &students[i].id);
        }
        printf("Enter student %d math grade (0-100): ", i + 1);
        scanf("%d", &students[i].math);
        while (students[i].math < 0 || students[i].math > 100) {
            printf("Invalid grade. Please enter a number between 0 and 100: ");
            scanf("%d", &students[i].math);
        }
        printf("Enter student %d physics grade (0-100): ", i + 1);
        scanf("%d", &students[i].physics);
        while (students[i].physics < 0 || students[i].physics > 100) {
            printf("Invalid grade. Please enter a number between 0 and 100: ");
            scanf("%d", &students[i].physics);
        }
        printf("Enter student %d english grade (0-100): ", i + 1);
        scanf("%d", &students[i].english);
        while (students[i].english < 0 || students[i].english > 100) {
            printf("Invalid grade. Please enter a number between 0 and 100: ");
            scanf("%d", &students[i].english);
        }
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
}

void display_grades() {
    clear_screen();
    printf("Student Grades:\n");
    for (int i = 0; i < student_count; i++) {
        printf("Name: %s, ID: %d, Math: %d, Physics: %d, English: %d, Average: %.1f\n", students[i].name.c_str(), students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }
    pause_screen();
}

void search_grades() {
    clear_screen();
    string name;
    printf("Enter the name to search: ");
    cin >> name;
    bool found = false;
    for (int i = 0; i < student_count; i++) {
        if (students[i].name == name) {
            printf("Name: %s, ID: %d, Math: %d, Physics: %d, English: %d, Average: %.1f\n", students[i].name.c_str(), students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
    pause_screen();
}

void grade_ranking() {
    clear_screen();
    vector<Student> temp_students = students;
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (temp_students[i].average < temp_students[j].average) {
                swap(temp_students[i], temp_students[j]);
            }
        }
    }
    printf("Grade Ranking:\n");
    for (int i = 0; i < student_count; i++) {
        printf("Name: %s, ID: %d, Average: %.1f\n", temp_students[i].name.c_str(), temp_students[i].id, temp_students[i].average);
    }
    pause_screen();
}

int main() {
    printf("***************************************************\n");
    printf(" \n");
    printf(" 程式作業四\n");
    printf(" E1B52連昱瑄\n");
    printf(" \n");
    printf("********* ** ********* ******* ******* \n");
    printf("********* ** ** ** ******* ******* \n");
    printf("** ** ** ** ** ** \n");
    printf("** ** ** * ** ** \n");
    printf("******* ** ******* ******* ******* \n");
    printf("******* ** ******* ******* ******* \n");
    printf("** ** ** * ** ** \n");
    printf("** ** ** ** ** ** \n");
    printf("********* ** ** ** ******** ******* \n");
    printf("********* ** ********* ******** ******* \n");
    printf(" \n");
    printf("***************************************************\n");
    
    int password;
    int count = 0;
    while (count < 3) {
        printf("請輸入密碼：");
        scanf("%d", &password);
        if (password == 2024) {
            printf("密碼正確，歡迎進入此程式!\n");
            pause_screen();
            clear_screen();
            while (true) {
                char choice;
                printf("----------[Grade System]-------------\n");
                printf("| a. Enter student grades |\n");
                printf("| b. Display student grades |\n");
                printf("| c. Search for student grades |\n");
                printf("| d. Grade ranking |\n");
                printf("| e. Exit system |\n");
                printf("-------------------------------------\n");
                printf("Please enter your choice: ");
                scanf(" %c", &choice);
                switch (choice) {
                    case 'a':
                        enter_grades();
                        break;
                    case 'b':
                        display_grades();
                        break;
                    case 'c':
                        search_grades();
                        break;
                    case 'd':
                        grade_ranking();
                        break;
                    case 'e':
                        printf("Are you sure you want to exit? (y/n): ");
                        char exit_choice;
                        scanf(" %c", &exit_choice);
                        if (exit_choice == 'y' || exit_choice == 'Y') {
                            return 0;
                        }
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
                clear_screen();
            }
        } else {
            printf("密碼錯誤!\n\a");
            count++;
            if (count >= 3) {
                printf("密碼錯誤，程式結束\n");
                break;
            }
        }
    }
    return 0;
}
/*心得: 這次的程式作業真的是一個挑戰！我花了很多時間學習 C++ 的語法和標準庫，並且慢慢地建立了這個學生成績管理系統。在開發這個程式的過程中，我學到了很多有用的東西。首先是對於程式結構的理解。我明白了如何把一個大的問題分解成小的、可管理的部分，然後用函數來組織這些部分。這樣做不僅讓我的程式碼更加清晰易讀，而且也方便了後續的修改和擴展
