#include <stdio.h>
int main(int argc, char* argv[]) {
	char a;
	while (1) {
		a = getchar();
		if (a == ';')
			putchar('\n');
		else
			putchar(a);
	}
	return 0;
}
