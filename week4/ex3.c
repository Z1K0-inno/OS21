#include <stdio.h>
#include <unistd.h>
	int main (){
	printf("> ");
	while (1) {
		char command[255];
		scanf("%s", command);
		printf("> ");
		system(command);
	}
	return 0;
}
