#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int gt(const void *a, const void *b){
	int A = *(int *)a;
	int B = *(int *)b;

	if (a < b) return -1;
	else if (a == b) return 0;
	else return 1;
}

bool issafe(int *arr, int len){
	int size = sizeof(int) * len;
	int *sorted = malloc(size);
	memcpy(sorted, arr, size);

	qsort(sorted, len, sizeof(int), &gt);
	if (memcmp(sorted, arr, size) == 0){
		int prev = arr[0];
		for (int i = 1; i < len; i++){
			if (!((abs(arr[i] - prev)) <= 3 && (abs(arr[i] - prev)) >= 1))
				return false;
			prev = arr[i];
		}
		return true;
	}
	else{
		int prev = arr[0];
		for (int i = 1; i < len; i++){
			if (!((arr[i] - prev) <= 3 && (arr[i] - prev) >= 1))
				return false;
			prev = arr[i];
		}
		return true;
	}
		
	return false;
}

int main(){
	FILE *f = fopen("test", "r");
	char *line = malloc(256);

	while (fgets(line, 256, f) != NULL){
		int *arr = malloc(sizeof(int) * 16);
		char *tok = strtok(line, " ");
		int i = 0;

		do {
			arr[i] = atoi(tok);
			i++;
			tok = strtok(NULL, " ");
		} while (tok != NULL);

		printf("%d\n", issafe(arr, i));

		free(arr);
	}

	free(line);
	fclose(f);
}
