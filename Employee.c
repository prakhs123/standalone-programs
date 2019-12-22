#include <stdio.h>

#define MAXSIZE		100
#define MAXNUMBER	50
struct person {
	char manager[MAXSIZE];
	char name[MAXSIZE];
};
struct person employees[MAXNUMBER];
int n;
int countEmployeesUnder(char employeeName[])
{
	int i;
	int counter = 0;
    for (i = 0; i < n; ++i)
    {
        if(strcmp(employees[i].manager,employeeName) == 0)
        {
        	printf("%s\n", employees[i].name);
            counter = counter + 1;
            counter = counter + countEmployeesUnder(employees[i].name);
        }
    }
    return counter;
}
main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", employees[i].name);
		scanf("%s", employees[i].manager);
	}
	printf("%d\n", countEmployeesUnder("Veronica"));
}
