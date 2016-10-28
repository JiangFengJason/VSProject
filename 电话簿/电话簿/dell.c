#include <stdio.h>
#include <string.h>

int  menu();
void add();
void lookup();
int main()
{
	char choice;
	do
	{
		choice = menu();
		switch (choice)
		{
		case 'a':add();
			break;
		case '1':lookup();
			break;
		}
	} while (choice != 'q');
	return 0;
}
/*display menu and get request*/
int  menu()
{
	int isPrime = 1;
	char ch;
	for (; isPrime = 1;)
	{
		printf("(A)dd,(L)ookup,or (Q)uit:");
		ch = tolower(getchar());
		printf("\n");
		if (ch != 'q'&&ch != 'a'&&ch != 'l')
			isPrime = 1;
		isPrime = 0;
	}
	return (ch);
}
/*add a name and number to the director*/
void add()
{
	FILE *fp;
	char name[80];
	int num;
	if ((fp = fopen("name", "a")) == NULL)
	{
		printf("can't open directory file\n");
		exit(1);
	}
	printf("enter name and number:\n");
	fscanf_s(stdin, "%s%d", name, &num);
	fscanf_s(stdin, "%*c");/*remove <cr>*/
	fprintf(fp, "%s %d", name, num);
	fclose(fp);
}
/*fine a number given a name*/
void lookup()
{
	FILE *fp;
	char name[80], name1[80];
	int num;
	if ((fp = fopen("name", "r")) == NULL)
	{
		printf("can't open directory file\n");
		exit(1);
	}
	printf("name?");
	scanf_s("%s", name);
	/*look for number*/
	while (!feof(fp))
	{
		fscanf_s(fp, "%s%d", name1, &num);
		if (!strcmp(name, name1))
		{
			printf("%s %d", name, num);
			break;
		}
	}
	printf("\n");
	fclose(fp);
}