#include <stdio.h>
#include <string.h>

main()
{
	char months[12][4] = { "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC", "JAN", "FEB"};
	int starting_day[] = {3, 6, 1, 4, 6, 2, 5, 0, 3, 5, 1, 4};
	int days[] = {31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28};
	int year;
	char month[3 + 1];
	int i, date, space_for_date1, j, temp_year;

	scanf("%d %s", &year, month);

	temp_year = year;
	if (strcmp(month, "JAN") == 0 || strcmp(month, "FEB") == 0)
		temp_year -= 1;

	int remainder_divided_by_400 = temp_year % 400;
	int no_of_100s = remainder_divided_by_400 / 100;
	int no_of_days = (remainder_divided_by_400 + no_of_100s * 24 + (remainder_divided_by_400 - no_of_100s * 100) / 4) % 7;
	
	printf("\t    %s-%d\n", month, year);
	printf("SUN MON TUE WED THU FRI SAT\n");
	
	for (i = 0; i < 12; ++i) {
		if(strcmp(months[i], month) == 0) {
			starting_day[i] += no_of_days;
			if (starting_day[i] > 6)
				starting_day[i] -= 7;
			break;
		}
	}
	space_for_date1 = starting_day[i];
	while (space_for_date1 > 0) {
		printf("    ");
		space_for_date1 -= 1;
	}

	date = 1;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		days[11]++;
	}
	j = i;
	i = starting_day[i];
	while (date <= days[j]) {
		for ( ; i <= 6 && date <= days[j]; i++) {
			if (date > 9)
				printf(" %d ", date);
			else
				printf(" %d  ", date);
			date++;
		}
		i = 0;
		putchar('\n');
	}
}
