#include <stdio.h>
#include <stdlib.h>
void palindroms(int n, int base);
int main() {
	// octal
	palindroms(0120, 8);

	// decimal
	palindroms(120, 10);

	// hex
	palindroms(0x120, 16);
	return 0;
}

// 10 = decimal, 8 = octal, 16 = hex
void palindroms(int n, int base) {
	if(base != 8 && base !=10 && base != 16) {
		printf("Invalid numeral system");
		return;
	}

	if(n>base) {
		printf("Palindroms: \n");	
		for (int i=base;i<n;i++) {

			int number = i;			
			int reverse = 0;

			while (number != 0) {
				int remainder = number % base;
				reverse = reverse * base + remainder;
				number = number / base;
			}

			if (i == reverse) {
				switch(base) {
					case 8:
						printf("%o\n", i);
						break;

					case 10:		
						printf("%d\n", i);
						break;

					case 16:
						printf("%X\n", i);
						break;

				}
			}
		}

	} else {
		printf("No palindroms.\n");		
	}
}
