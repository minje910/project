#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> // Sleep 함수 사용을 위한 헤더

char students[40][20] = {0};            // 학생 이름 저장용 배열
char fixed_students_name[40][20] = {0}; // 고정된 학생 이름 저장용 배열
int fixed_seats[40] = {0};              // 고정된 자리 표시용 배열
int student_count = 0;                  // 학생 수 확인용 변수                   
char temp_students[40][20];             // push용 임시 함수

void input_name();        // 학생 등록 함수
void input_myClassName(); // 1-4반 학생 등록 함수
void random_seat();       // 자리 랜덤 교체 함수
void load_seat();         // 현재 자리 불러오기 함수
void exchange_seat();     // 자리 상호 교체 함수
void fix_seat();          // 자리 고정 함수
void add_student();       // 학생 추가 함수
void remove_student();    // 학생 제거 합수
void write();             // 자리 배치 저장 함수
void easter_egg();        // ^-^

void push(int n)          // 삭제된 학생 자리 채우기용
{
    char x[20];
    for (int i = 0; i < n; i++)
    {
        if (strcmp(temp_students[i], "1") == 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                strncpy(x, temp_students[j + 1], sizeof(x) - 1);
                x[sizeof(x) - 1] = '\0';
                strncpy(temp_students[j], x, sizeof(temp_students[j]) - 1);
                temp_students[j][sizeof(temp_students[j]) - 1] = '\0';
            }
            strncpy(temp_students[n - 1], "1", sizeof(temp_students[n - 1]) - 1);
            temp_students[n - 1][sizeof(temp_students[n - 1]) - 1] = '\0';
        }
    }
}

int main()
{
    int temp_menu = 0;
    int menu = 0;
    srand((unsigned int)time(NULL));
    printf("╔══════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║  ██╗      ██╗  ██╗    ███████╗███████╗ █████╗ ████████╗    ███████╗██╗   ██╗███████╗ ║\n");
    printf("║ ███║      ██║  ██║    ██╔════╝██╔════╝██╔══██╗╚══██╔══╝    ██╔════╝╚██╗ ██╔╝██╔════╝ ║\n");
    printf("║ ╚██║█████╗███████║    ███████╗█████╗  ███████║   ██║       ███████╗ ╚████╔╝ ███████╗ ║\n");
    printf("║  ██║╚════╝╚════██║    ╚════██║██╔══╝  ██╔══██║   ██║       ╚════██║  ╚██╔╝  ╚════██║ ║\n");
    printf("║  ██║           ██║    ███████║███████╗██║  ██║   ██║       ███████║   ██║   ███████║ ║\n");
    printf("║  ╚═╝           ╚═╝    ╚══════╝╚══════╝╚═╝  ╚═╝   ╚═╝       ╚══════╝   ╚═╝   ╚══════╝ ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════╝\n");

    while (1)
    {
        printf("════════════════════════════════════════════════════════════════════════════════════════\n");
        printf("╔ 0. 학생 등록              ╗\n");
        printf("║ 1. 1-4반 학생 자동 등록   ║\n");
        printf("║ 2. 자리 랜덤 교체         ║\n");
        printf("║ 3. 현재 자리 불러오기     ║\n");
        printf("║ 4. 자리 상호 교체         ║\n");
        printf("║ 5. 자리 고정              ║\n");
        printf("║ 6. 학생 추가              ║\n");
        printf("║ 7. 학생 제거              ║\n");
        printf("║ 8. 자리 배치도 내보내기   ║\n");
        printf("╚ 9. 프로그램 종료          ╝\n");
        printf("════════════════════════════════════════════════════════════════════════════════════════\n");
        printf("메뉴를 선택하세요> ");

        if (scanf("%d", &temp_menu) != 1)
        {
            printf("숫자만 입력하실 수 있습니다.\n");
            while (getchar() != '\n')
                ;
            continue;
        } // 숫자 외 입력 시 무한루프 방지

        if ((temp_menu >= 0 && temp_menu <= 9) || temp_menu == 524)
        {
            menu = temp_menu;
        }
        else
        {
            printf("잘못된 입력입니다. 다시 선택하세요.\n\n");
            continue;
        } // 없는 메뉴 입력 시 무한루프 방지

        switch (menu)
        {
        case 0:
            input_name();
            break;
        case 1:
            input_myClassName();
            break;
        case 2:
            random_seat();
            break;
        case 3:
            load_seat();
            int back = 1;
            while (back)
            {
                printf("메인 화면으로 돌아가려면 0을 입력하세요> ");
                if (scanf("%d", &back) != 1)
                {
                    while (getchar() != '\n')
                        ;
                }
            }
            break;
        case 4:
            exchange_seat();
            break;
        case 5:
            fix_seat();
            break;
        case 6:
            add_student();
            break;
        case 7:
            remove_student();
            break;
        case 8:
            write();
            break;
        case 9:
            printf("프로그램을 종료합니다.\n");
            return 0;
        case 524:
            easter_egg();
            break;
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            break;
        }
        printf("\n");
    }
}

void input_name()
{
    int back = 1;

    for (int i = 0; i < 40; i++)
    {
        fixed_seats[i] = 0;
        fixed_students_name[i][0] = '\0';
    } // 고정된 자리 초기화

    do
    {
        printf("※ 성명이 두 글자인 경우 성과 이름 사이에 공백을 추가해주세요 ※\n");
        printf("※ 성명이 네 글자 이상인 경우 세 글자 까지만 입력해주세요 ※\n");
        printf("학생 수 입력(1~40)> ");
        if (scanf("%d", &student_count) != 1)
        {
            student_count = -1;
        }
        while (getchar() != '\n')
            ;
    } while (student_count < 1 || student_count > 40); // 학생 수 입력 범위 확인

    for (int i = 0; i < student_count; i++)
    {
        int duplicate = 0;

        printf("%d번 학생 이름 입력> ", i + 1);
        fgets(students[i], 20, stdin);
        students[i][strcspn(students[i], "\n")] = '\0';

        for (int j = 0; j < i; j++)
        {
            if (strcmp(students[i], students[j]) == 0)
            {
                duplicate = 1;
                break;
            }
        } // 중복된 이름 확인

        if (duplicate)
        {
            printf("이미 등록된 이름입니다. 다시 입력해주세요.\n");
            i--;
            continue;
        } // 중복된 이름이 있을 경우 다시 입력
    } // 학생 이름 입력 완료

    printf("\n학생 등록이 완료되었습니다.\n");

    while (back)
    {
        printf("메인 화면으로 돌아가려면 0을 입력하세요> ");
        if (scanf("%d", &back) != 1)
        {
            while (getchar() != '\n')
                ;
        }
    }
}

void input_myClassName()
{
    int back = 1;

    char temp_names[30][20] = {
        "고희성", "곽현진", "김건우", "김나연", "김도윤", "김서윤",
        "김수훈", "나윤아", "류경민", "박시우", "박유찬", "박진서",
        "방재원", "손지원", "신동화", "신의진", "양하준", "오승후",
        "유하람", "이민제", "이유진", "이준서", "이지환", "정현우",
        "차예린", "최민영", "최성빈", "최정우", "현태윤", "홍의준"};

    for (int i = 0; i < 40; i++)
    {
        fixed_seats[i] = 0;
        fixed_students_name[i][0] = '\0';
    }

    for (int i = 0; i < 30; i++)
    {
        strcpy(students[i], temp_names[i]);
    } // 1-4반 학생 이름을 students 배열에 복사

    student_count = 30;
    printf("1-4반 학생 목록을 자동으로 등록하였습니다.\n");

    while (back)
    {
        printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");

        if (scanf("%d", &back) != 1)
        {
            while (getchar() != '\n')
                ;
        }
    }
}

void random_seat()
{
    int back = 1;

    if (student_count == 0)
    {
        printf("학생을 먼저 등록해주세요.\n");
        while (back)
        {
            printf("메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    }

    char result[40][20] = {0};
    char remain[40][20];
    int remain_count = 0;

    for (int i = 0; i < student_count; i++)
    {
        int is_fixed_student = 0;

        for (int j = 0; j < student_count; j++)
        {
            if (fixed_seats[j] &&
                strcmp(students[i], fixed_students_name[j]) == 0)
            {
                is_fixed_student = 1;
                break;
            }
        }

        if (!is_fixed_student)
        {
            strcpy(remain[remain_count++], students[i]);
        }
    }

    for (int i = remain_count - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        char temp[20];
        strcpy(temp, remain[i]);
        strcpy(remain[i], remain[j]);
        strcpy(remain[j], temp);
    }

    for (int i = 0; i < student_count; i++)
    {
        if (fixed_seats[i])
        {
            strcpy(result[i], fixed_students_name[i]);
        }
    }

    int idx = 0;

    for (int i = 0; i < student_count; i++)
    {
        if (!fixed_seats[i])
        {
            strcpy(result[i], remain[idx++]);
        }
    }

    printf("\n[랜덤 자리 배치 완료]\n");

    for (int i = 0; i < student_count; i++)
    {
        if ((i + 1) % 6 == 0)
        {
            printf("| %2d. %-6s |\n", i + 1, result[i]);
        }
        else
        {
            printf("| %2d. %-6s |", i + 1, result[i]);
        }
    }

    printf("\n");

    for (int i = 0; i < student_count; i++)
    {
        strcpy(students[i], result[i]);
    }

    while (back)
    {
        printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");

        if (scanf("%d", &back) != 1)
        {
            while (getchar() != '\n')
                ;
        }
    }
}

void load_seat()
{
    if (student_count == 0)
    {
        printf("등록된 학생이 없습니다.\n");
        return;
    } // 학생이 등록되지 않은 경우 자리 불러오기 불가

    printf("\n[현재 자리 배치]\n");
    for (int i = 0; i < student_count; i++)
    {
        if ((i + 1) % 6 == 0)
        {
            printf("| %2d. %-6s |\n", i + 1, students[i]);
        } // 6번째 자리마다 줄바꿈
        else
        {
            printf("| %2d. %-6s |", i + 1, students[i]);
        } // 자리 번호와 학생 이름 출력
    } // 현재 자리 배치 출력 완료
    printf("\n");
}

void exchange_seat()
{
    int back = 1;
    int a, b;

    if (student_count == 0)
    {
        printf("학생을 먼저 등록해주세요.\n");
        while (back)
        {
            printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    } // 학생 등록 여부 확인

    for (int i = 0; i < student_count; i++)
    {
        if ((i + 1) % 6 == 0)
        {
            printf("| %2d. %-6s |\n", i + 1, students[i]);
        } // 6번째 자리마다 줄바꿈
        else
        {
            printf("| %2d. %-6s |", i + 1, students[i]);
        } // 자리 번호와 학생 이름 출력
    } // 확인용 현재 자리 배치 출력 완료

    printf("\n서로 교체할 자리 번호 두 개를 입력하세요(예> 1 3)> ");
    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("잘못된 입력입니다. 두 숫자를 입력해야 합니다.\n");
        while (getchar() != '\n')
            ;
        while (back)
        {
            printf("메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    }

    if (a < 1 || a > student_count || b < 1 || b > student_count)
    {
        printf("잘못된 번호입니다. 1부터 %d 사이의 번호를 입력하세요.\n", student_count);
        while (back)
        {
            printf("메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    } // 입력된 자리 번호가 유효한지 확인

    if (fixed_seats[a - 1] || fixed_seats[b - 1])
    {
        printf("고정된 자리는 교환할 수 없습니다.\n");
        while (back)
        {
            printf("메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    } // 고정된 자리인지 확인

    char tmp[20];
    strcpy(tmp, students[a - 1]);
    strcpy(students[a - 1], students[b - 1]);
    strcpy(students[b - 1], tmp); // 자리 교환 완료

    printf("\n[자리 상호 교체 완료]\n");
    for (int i = 0; i < student_count; i++)
    {
        if ((i + 1) % 6 == 0)
        {
            printf("| %2d. %-6s |\n", i + 1, students[i]);
        } // 6번째 자리마다 줄바꿈
        else
        {
            printf("| %2d. %-6s |", i + 1, students[i]);
        } // 자리 번호와 학생 이름 출력
    }
    printf("\n");

    while (back)
    {
        printf("메인 화면으로 돌아가려면 0을 입력하세요> ");
        if (scanf("%d", &back) != 1)
        {
            while (getchar() != '\n')
                ;
        }
    }
}

void fix_seat()
{
    int back = 1;
    int n;

    if (student_count == 0)
    {
        printf("학생을 먼저 등록해주세요.\n");
        while (back)
        {
            printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    } // 학생 등록 여부 확인

    for (int i = 0; i < 40; i++)
    {
        fixed_seats[i] = 0;
        fixed_students_name[i][0] = '\0';
    } // 고정된 자리 초기화

    printf("※ 기존 고정 기록은 모두 삭제됩니다 ※\n");
    printf("고정하고 싶은 학생 수를 입력하세요(1~%d)> ", student_count);
    if (scanf("%d", &n) != 1)
    {
        printf("잘못된 입력입니다.\n");
        while (getchar() != '\n')
            ;
        while (back)
        {
            printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    }
    while (getchar() != '\n')
        ;

    if (n < 1 || n > student_count)
    {
        printf("고정 학생 수는 1~%d명만 가능합니다.\n", student_count);
        while (back)
        {
            printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    } // 고정 학생 수 유효 여부 확인

    for (int i = 0; i < n; i++)
    {
        int seat_num;
        char student_name[20];
        int found = 0;

        printf("\n[%d번째 고정 설정]\n", i + 1);

        printf("고정할 자리 번호(1~%d)를 입력하세요> ", student_count);
        if (scanf("%d", &seat_num) != 1)
        {
            printf("숫자만 입력 가능합니다.\n");
            while (getchar() != '\n')
                ;
            i--;
            continue;
        }
        while (getchar() != '\n')
            ;

        if (seat_num < 1 || seat_num > student_count)
        {
            printf("유효하지 않은 자리 번호입니다.\n");
            i--;
            continue;
        } // 자리 번호 유효 여부 확인

        if (fixed_seats[seat_num - 1])
        {
            printf("이미 고정된 자리입니다.\n");
            i--;
            continue;
        } // 이미 고정된 자리인지 확인

        printf("고정할 학생 이름을 입력하세요> ");
        fgets(student_name, 20, stdin);
        student_name[strcspn(student_name, "\n")] = '\0';

        for (int j = 0; j < student_count; j++)
        {
            if (strcmp(student_name, students[j]) == 0)
            {
                found = 1;
                break;
            } // 입력된 학생 이름이 등록된 학생 목록에 있는지 확인
        }

        if (!found)
        {
            printf("등록되지 않은 학생입니다.\n");
            i--;
            continue;
        } // 입력된 학생 이름이 등록된 학생 목록에 없는 경우 다시 입력

        for (int j = 0; j < student_count; j++)
        {
            if (fixed_seats[j] && strcmp(fixed_students_name[j], student_name) == 0)
            {
                printf("이미 다른 자리에 고정된 학생입니다.\n");
                found = 0;
                break;
            }
        } // 입력된 학생 이름이 이미 다른 자리에 고정된 학생인지 확인

        if (!found)
        {
            i--;
            continue;
        } // 입력된 학생 이름이 이미 다른 자리에 고정된 학생인 경우 다시 입력

        fixed_seats[seat_num - 1] = 1;
        strcpy(fixed_students_name[seat_num - 1], student_name);

        printf("%s 학생이 %d번 자리에 고정되었습니다.\n",
               student_name, seat_num);
    } // 자리 고정 설정 완료

    while (back)
    {
        printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");

        if (scanf("%d", &back) != 1)
        {
            while (getchar() != '\n')
                ;
        }
    }
}

void add_student()
{
    int back = 1;
    char plstudent[20];
    if (student_count >= 40)
    {
        printf("제한 인원 40명으로 학생 추가가 불가능합니다.\n");
        while (back)
        {
            printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    } // 학생 수가 40명 이상인 경우 추가 불가
    getchar(); // 버퍼 초기화
    memcpy(temp_students, students, sizeof(temp_students)); // 기존 학생 배열을 임시 배열에 복사

    while (1)
    {
        printf("※ 성명이 두 글자인 경우 성과 이름 사이에 공백을 추가해주세요 ※\n");
        printf("※ 성명이 네 글자 이상인 경우 세 글자 까지만 입력해주세요 ※\n");
        printf("추가할 학생 입력> ");
        fgets(plstudent, 20, stdin);
        plstudent[strcspn(plstudent, "\n")] = '\0';

        int is_duplicate = 0;
        for (int j = 0; j < student_count; j++)
        {
            if (strcmp(students[j], plstudent) == 0)
            {
                is_duplicate = 1;
                break;
            }
        }

        if (is_duplicate)
        {
            printf("이미 등록된 이름입니다. 다시 입력해주세요.\n\n");   // 같은 번호를 다시 입력받도록 되돌림
            continue;
        }
        else
        {
            break;
        }
    } // 학생 이름 중복 확인 및 입력 완료

    strncpy(temp_students[student_count], plstudent, sizeof(temp_students[student_count]) - 1); 
    temp_students[student_count][sizeof(temp_students[student_count]) - 1] = '\0';

    memcpy(students, temp_students, sizeof(students));
    student_count++;
    load_seat();

    while (back)
    {
        printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
        if (scanf("%d", &back) != 1)
        {
            while (getchar() != '\n')
                ;
        }
    }
}

void remove_student()
{
    int back = 1;
    if (student_count == 0)
    {
        printf("제거 가능한 학생이 없습니다.\n");
        while (back)
        {
            printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    } // 학생 수가 0명인 경우 제거 불가
    load_seat();
    char rmname[20];
    getchar();
    memcpy(temp_students, students, sizeof(temp_students));
    int roof = 1;
    while (roof)
    {
        printf("\n제거할 학생을 입력하세요(종료하려면 '0' 입력): ");
        fgets(rmname, 20, stdin);
        rmname[strcspn(rmname, "\n")] = '\0';

        if (strcmp(rmname, "0") == 0)
        {
            break;
        }

        int found = 0;
        for (int i = 0; i < student_count; i++)
        {
            if (strcmp(temp_students[i], rmname) == 0)
            {
                fixed_seats[i] = 0;
                fixed_students_name[i][0] = '\0';

                strncpy(temp_students[i], "1", sizeof(temp_students[i]) - 1);
                push(student_count);
                student_count--;
                found = 1;
                roof = 0;
                break;
            }
        }
        if (!found)
        {
            printf("등록되어 있지 않은 학생입니다. 다시 입력해주세요.\n");
        }
    } // 학생 제거 완료 후 자리 재배치
    memcpy(students, temp_students, sizeof(students));
    load_seat();

    while (back)
    {
        printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
        if (scanf("%d", &back) != 1)
        {
            while (getchar() != '\n')
                ;
        }
    }
}

void write()
{
    int back = 1;
    FILE *fp;

    fp = fopen("student_seat.txt", "w");

    if(fp == NULL){
        printf("파일열기 실패\n");
        return;
    } else {
        printf("파일열기 성공\n");
    }

    fprintf(fp, "[자리 배치도]\n");

    int count = 0;
    for(int i = 0; i < student_count / 6; i++){
        for(int j = 0; j < 6; j++){
            fprintf(fp, "| %2d. %s |", count + 1, students[count]);
            count++;
        }
        fprintf(fp, "\n");
    }
    
    if(student_count % 6 != 0){
        for(int i = 0; i < student_count % 6; i++){
            fprintf(fp, "| %2d. %s |", count + 1, students[count]);
            count++;
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    
    while (back)
    {
        printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
        if (scanf("%d", &back) != 1)
        {
            while (getchar() != '\n');
        }
    }
}

void easter_egg()
{
    int back = 1;
    FILE *fp = fopen("skyman.txt", "r");

    if (fp == NULL)
    {
        printf("이스터에그 파일을 찾을 수 없습니다.\n");
        while (back)
        {
            printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
            if (scanf("%d", &back) != 1)
            {
                while (getchar() != '\n')
                    ;
            }
        }
        return;
    }

    printf("\n");

    int ch;
    int count = 0;

    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
        fflush(stdout);

        count++;

        if (count >= 5)
        {
            Sleep(1);
            count = 0;
        }
    }

    fclose(fp);
    printf("\n");

    while (back)
    {
        printf("\n메인 화면으로 돌아가려면 0을 입력하세요> ");
        if (scanf("%d", &back) != 1)
        {
            while (getchar() != '\n')
                ;
        }
    }
}