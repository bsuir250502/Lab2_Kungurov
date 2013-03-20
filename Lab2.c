#include <stdlib.h>
#include <stdio.h>
//#include <stdio_ext.h>
#include <string.h>
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
} students;


int get_int(int *j){
	char str[10];
	fgets(str,8,stdin);
	*j=atoi(str);
	return *j;
}

int get_float(float *j){
	char str[10];
	fgets(str,8,stdin);
	*j=atof(str);
	return *j;
}


void get_height_weight(students *student){
	char *adress;
printf("Enter height\n");
get_float(&student->med.hw.height);
while (!get_float(&student->med.hw.height)) { puts("Good job!You are stupid\n"); }
printf("Enter weight\n");
get_float(&student->med.hw.height);
while (!get_float(&student->med.hw.weight)) { puts("Good job!You are stupid\n"); }


fflush(stdin);

}
void get_info(students *student){
	int j;
char *adress;
printf("Enter name\n");
fgets(student->snp.name,30,stdin);
if (adress=strchr(student->snp.name,'\n')){
 *adress='\0';}
fflush(stdin);
printf("Enter surname\n");
fgets(student->snp.surname,30,stdin);
if (adress=strchr(student->snp.surname,'\n')){
 *adress='\0';}
fflush(stdin);
printf("Enter patronymic\n");
fgets(student->snp.patronymic,30,stdin);
if (adress=strchr(student->snp.patronymic,'\n')){
 *adress='\0';}
fflush(stdin);
puts("A || B");
while (!get_int(&j)) { puts("Good job!You are stupid\n"); }
if (j==1) { get_height_weight(student);)
printf("%d",j);
}




void display_info(students *student){
puts(student->snp.name);
puts(student->snp.surname);
puts(student->snp.patronymic);
}

int main()
{
	int i=0;
	students student[number_of_students];
	while(i<number_of_students){
	get_info(&student[i]);
	i++;
	}
	i=0;
	while(i<number_of_students){
	display_info(&student[i]);
	i++;
	}
	return 0;
	
}


























