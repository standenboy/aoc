#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *f = fopen("./input", "r");
	char *line = malloc(256);

	int *leftlist = malloc(sizeof(int) * 1000);
	int *rightlist = malloc(sizeof(int) * 1000);

	char *tok;	
	
	int counter = 0;
	while (fgets(line, 256, f) != NULL){
		tok = strtok(line, " ");	
		leftlist[counter] = atoi(tok);

		tok = strtok(NULL, " \n");	
		rightlist[counter] = atoi(tok);

		counter++;
	}

	int total = 0;
	for (int i = 0; i < 1000; i++){
		int instancecount = 0;
		for (int j = 0; j < 1000; j++)
			if (rightlist[j] == leftlist[i]) instancecount++;
		total += leftlist[i] * instancecount;
	}
	printf("%d\n", total);

	free(line);
	free(leftlist);
	free(rightlist);
	fclose(f);
}
