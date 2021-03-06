#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "mystdlib.h"
#define number_of_students 2
struct names {
    char name[30];
    char surname[30];
    char patronymic[30];
};
struct height_weight {
    float height;
    float weight;
};
struct height_weight_xxx {
    float height;
    float weight;
    int brain_size;
    char sex[7];
};
union medicine {
    struct height_weight hw;
    struct height_weight_xxx hwxxx;
};
typedef struct {
    struct names snp;
    union medicine med;
    int med_parameters;
} students;
int get_int()
{
    char str[10];
    my_gets(str, 10);
    return atoi(str);
}

float get_float()
{
    char str[10];
    my_gets(str, 10);
    return atof(str);
}

char get_sex(char *j)
{
    char str[10];
    while (1) {
        my_gets(str, 8);
        if (strcmp(str, "male") == 0) {
            strncpy(j, str, 7);
            return *j;
        } else if (strcmp(str, "female") == 0) {
            strncpy(j, str, 7);
            return *j;
        } else {
            puts("Unknown sex!Try again");
            continue;
        }
    }
}

void enter_valid_float(char *message, float *target)
{
    puts(message);
    *target = get_float();
    while (!target) {
        puts("Input error. Try again");
    }
}

void enter_valid_char(char *message, char *target)
{
    puts(message);
    while (!get_sex(target)) {
        puts("Input error. Try again");
    }
}

void enter_valid_int(char *message, int *target)
{
    puts(message);
    *target = get_int();
    while (!target) {
        puts("Input error. Try again\n");
    }
}

void get_height_weight(students * student)
{
    enter_valid_float("Enter height", &student->med.hw.height);
    enter_valid_float("Enter weight", &student->med.hw.weight);
}

void get_height_weight_xxx(students * student)
{
    enter_valid_float("Enter height", &student->med.hwxxx.height);
    enter_valid_float("Enter weight", &student->med.hwxxx.weight);
    enter_valid_int("Enter brain size", &student->med.hwxxx.brain_size);
    enter_valid_char("Enter sex", &student->med.hwxxx.sex[0]);
}

void get_info(students * student)
{
    int j;
    printf("Enter name\n");
    my_gets(student->snp.name, 30);
    printf("Enter surname\n");
    my_gets(student->snp.surname, 30);
    printf("Enter patronymic\n");
    my_gets(student->snp.patronymic, 30);
    puts("Enter '1' if you want to enter only height and weight or '2' if you want to enter more parameters \n");
    while (1) {
        j = get_int();
        while (!j) {
            puts("Input error. Try again\n");
            j = get_int();
        }
        if (j == 1) {
            get_height_weight(student);
            student->med_parameters = 1;
            break;
        } else if (j == 2) {
            get_height_weight_xxx(student);
            student->med_parameters = 2;
            break;
        } else {
            puts("Bad decision!Try again");
            continue;
        }
    }
}

void display_info(students * student)
{
    puts(student->snp.name);
    puts(student->snp.surname);
    puts(student->snp.patronymic);
    if (student->med_parameters == 1) {
        printf("    %.2f   ", student->med.hw.height);
        printf("%.2f\n", student->med.hw.weight);
    }
    if (student->med_parameters == 2) {
        printf("   %.2f   ", student->med.hwxxx.height);
        printf("%.2f   ", student->med.hwxxx.weight);
        printf("%d   ", student->med.hwxxx.brain_size);
        puts(student->med.hwxxx.sex);
    }
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if ((strcmp(argv[1], "-h")) == 0) {
            puts("Instructions for use:");
            puts("1.Start the program (cd drive :/ place / location / file / -> make -> ./lab1).");
            puts("2. Company name. Our offers to enter the business name, type a name (no more than 30 characters)");
            puts("then click <enter>. Entering stop when you enter the 50 firms, or if you need a stop earlier,");
            puts("just type 'end' (without the quotes). You will then proceed to enter personal information");
            puts("for each firm.");
            puts("3. PERSONAL INFORMATION FOR EACH OF COMPANIES.");
            puts("    3.1. To offer input tax (tax), enter the number (not more than 7 digits).");
            puts("    3.2. Next, enter the date of the offer closing date (deadline), type the date in");
            puts("        format DD MMM YYYY (Ex. 01 jan 1970) or write the month when you enter a fully");
            puts("        (Ex. 01 january 1970). If you enter the wrong program will tell you.");
            puts("    3.3. Next on the proposal to introduce the date of actual payment, enter the date (see section 3.2)");
            puts("    or '0' (zero), if the payment of the tax has not been made.");
            puts("Items 3.1 - 3.2 is repeated for all input firms.");
            puts("4. DATE AT THE TIME TRACKING be produced by the debtor. The proposal to introduce");
            puts("date monitoring of debtors (monitor_date), enter in the mentioned format (see section 3.2).");
            return 0;
        }
    }
    int i = 0;
    students student[number_of_students];
    while (i < number_of_students) {
        get_info(&student[i]);
        i++;
    }
    i = 0;
    while (i < number_of_students) {
        display_info(&student[i]);
        i++;
    }
    return 0;
}
