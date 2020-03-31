#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Contact
{
	char Name[15];
	long long unsigned Telephone_Number;
};
int t=-1;
void Add_Contact(struct Contact cnt[])
{
	++t;
	printf("Enter Name :\n");
	fflush(stdin);
	gets(cnt[t].Name);
	fflush(stdin);
	printf("Enter Telephone Number\n");
	fflush(stdin);
	scanf("%llu",&cnt[t].Telephone_Number);
}
void Delete_Contact(struct Contact cnt[])
{
	int i,j;
	long long unsigned telph;
	if(t==-1)
	{
		printf("\nContact list is empty!!\n\n");
		return;
	}
	else
	{
		printf("Enter the telephone number to be deleted :\n");
		scanf("%llu",&telph);
		for(i=0;i<=t;i++)
		{
			if(cnt[i].Telephone_Number == telph)
			{
				for(j=i;j<=t;j++)
				{
					strcpy(cnt[j].Name,cnt[j+1].Name);
					cnt[j].Telephone_Number = cnt[j+1].Telephone_Number;
				}
				t--;
				printf("\nContact Deleted\n");
				break;
			}
			if(i>t)
				printf("\nContact not found!!\n\n");
		}
	}
}
void Search(struct Contact cnt[])
{
	int i;
	char name[15];
	if(t==-1)
	{
		printf("\nContact list is empty!!\n\n");
		return;
	}
	else
	{
		printf("\nEnter Name to be searched\n");
		gets(name);
		fflush(stdin);
		getchar();
		for(i=0;i<=t;i++)
			if(strcmp((cnt[i].Name),name))
				{
					printf("\n\nName : %s\n",cnt[i].Name);
					printf("Telephone Number : %llu\n\n",cnt[i].Telephone_Number);
					break;
	    		}
	    	if(i>t)
	    		printf("\nContact does not exist!!\n\n");
	}
}
void Browse(struct Contact cnt[])
{
	int i;
	if(t==-1)
		printf("\nContact list is empty!!\n");
	else	
		for(i=0;i<=t;i++)
		{
			printf("Name : %s\t\tTelephone Number : %llu\n",cnt[i].Name,cnt[i].Telephone_Number);
		}
}
int main()
{
	struct Contact contacts[100];
	int opt;
	do
	{
		printf("Enter an option :\n\n1.ADD CONTACT\n2.DELETE CONTACT\n3.SEARCH\n4.BROWSE\n0.EXIT\n\n");
		fflush(stdin);
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: Add_Contact(contacts);
					break;
			case 2: Delete_Contact(contacts);
					break;
			case 3: Search(contacts);
					break;
			case 4: Browse(contacts);
					break;
			case 0: break;
			default:printf("Entered option is invalid!!\n\n"); 
		}
	}while(opt);
	return EXIT_SUCCESS;
}
