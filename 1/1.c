#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
	int A = *(int *)a;
	int B = *(int *)b;
	if (A < B) return -1;
	else if (A == B) return -0;
	else return 1;
}


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

	qsort(leftlist, 1000, sizeof(int), &cmp);
	qsort(rightlist, 1000, sizeof(int), &cmp);

	int total = 0;
	for (int i = 0; i < 1000; i++){
		total += abs(leftlist[i] - rightlist[i]);
	}
	printf("%d\n", total);

	free(line);
	free(leftlist);
	free(rightlist);
	fclose(f);
}
