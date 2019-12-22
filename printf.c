#include <stdio.h>

main()
{
	printf("%c\n", 'a');		// prints a character
	printf("%d\n", 17);			// prints an integer
	printf("%i\n", 15);			// prints an integer
	printf("%e\n", 14.05);		// prints floating point in e notation
	printf("%E\n", 14.05);		// prints floating point in E notation
	printf("%f\n", 24.44);		// prints floating point
	printf("%g\n", 17.77);		// prints shorter of e or floating point notation
	printf("%g\n", 17000000.0);
	printf("%o\n", 32);			// prints octal representation of unsigned integer (not including preceding 0)
	printf("%s\n", "Prakhar");	// prints character string
	printf("%u\n", 24u);		// prints unsigned integer
	printf("%x\n", 15);			// prints hexadecimal representation of unsigned integer (not including 0x)
	printf("%X\n", 15);			// same as above except (A-F) in uppercase
	printf("%a\n", 10.0);		// hexadecimal floating point, lowercase
	printf("%A\n", 12.12);		// hexadecimal floating point, uppercase
	int a[10];
	printf("%p\n", a);			// prints pointer address in hexadecimal notation (including 0x)
	// Note: an integer is in octal representation if it has preceding 0 and in hexadecimal notation if it has preceding 0x
	
	// Flags
	printf("%-3d%d\n", 17, 25);	//"-": left justify in the given field width (right justify is default)
	printf("%+d\n", 16);		// Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.
	printf("% d\n", 17);		// If no sign is going to be written, a blank space is inserted before the value.
	printf("%#o\n", 9);			// Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
	printf("%#X\n", 15);
	double b = 15.0;
	printf("%#g\n", b);			// Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.
	printf("%05d\n", 17);		// Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier)
	
	// width	value is not truncated if result is longer
	// If the period is specified without an explicit value for precision, 0 is assumed.
	printf("%3d\n", 17);
	printf("%3d\n", 1700);
	// precision
	printf("%.0d\n", 0);		// For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.
	printf("%.3f\n", 12.0126);	// For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6).
	printf("%.3g\n", 12.1314);	// For g and G specifiers: This is the maximum number of significant digits to be printed.
	printf("%.3s\n", "Prakhar");// For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.
	
	// * case
	int width = 5, precision = 2;
	double number = 4.232;
	printf("%*.*f\n", width, precision, number);
	
	// length
	// h (i,d,o,u,x,X)
	// l (i,d,o,u,x,X,s,c)
	// L (e,E,f,g,G)
	
	return 0;
}
