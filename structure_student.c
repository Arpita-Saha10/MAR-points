#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
struct Student
{
	long int Roll_Number;
	char Name[15];
	char Dept[15];
	char Course[15];
	int Year_Of_Joining;
}*std;
int no_of_students;
void std_in_a_year(int year)
{
	int i;
	for(i=0;i<no_of_students;i++)
	{
		if(std[i].Year_Of_Joining == year)
		{
			puts(std[i].Name);
			printf("\n\n");
		}
	}
}
void print_details(int roll)
{
	int i;
	for(i=0;i<no_of_students;i++)
	{
		if(std[i].Roll_Number == roll)
		{
			printf("\nThe details of the student is \n\n");
			printf("Name : %s\n",std[i].Name);
			printf("Department : %s\n",std[i].Dept);
			printf("Course : %s\n",std[i].Course);
			printf("Year Of Joining : %d\n",std[i].Year_Of_Joining);
			break;
		}
	}
}
int main()
{
	int i,year;
	long int roll; 
	printf("Enter the Number of students\n");
	scanf("%d",&no_of_students);
	std = (struct Student *)malloc(no_of_students * sizeof(struct Student));
	for(i=0;i<no_of_students;i++)
	{
		printf("Student %d :\n",i+1);
		printf("Enter Roll Number\n");
		scanf("%d",&std[i].Roll_Number);
		fflush(stdin);
		printf("Enter Name\n");
		gets(std[i].Name);
		fflush(stdin);
		getchar();
		printf("Enter Department\n");
		gets(std[i].Dept);
		fflush(stdin);
		getchar();
		printf("Enter Course\n");
		gets(std[i].Course);
		fflush(stdin);
		getchar();
		printf("Enter Year Of Joining\n");
		scanf("%d",&std[i].Year_Of_Joining);
		fflush(stdin);
	}
	printf("Enter Year Of Joining of students whose names are to be displayed\n");
	scanf("%d",&year);
	std_in_a_year(year);
	printf("Enter Roll Number of student whose details is to be displayed\n");
	scanf("%d",&roll);
	print_details(roll);
	return EXIT_SUCCESS;
}
