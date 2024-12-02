#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cmp(const void *a, const void *b){
	int A = *(int *)a;
	int B = *(int *)b;

	if (A < B) return -1;
	else if (A == B) return 0;
	else return 1;
}

void reverse(int *arr, int len){
	int *tmp = malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++){
		tmp[i] = arr[(len - i) - 1];
	}

	memcpy(arr, tmp, len * sizeof(int));
	free(tmp);
}

int *removen(int *arr, int len, int n){
	int *out = malloc(sizeof(int) * len - 1);

	int index = 0;
	for (int i = 0; i < len; i++){
		out[index] = arr[i];
		if (i != n) index++;
	}

	return out;
}


bool issafe(int *arr, int len){
	int size = sizeof(int) * len;
	int *sorted = malloc(size);
	int *rsorted = malloc(size);

	memcpy(sorted, arr, size);
	qsort(sorted, len, sizeof(int), &cmp);

	memcpy(rsorted, sorted, size);
	reverse(rsorted, len);

	if (memcmp(sorted, arr, size) == 0){
		int prev = sorted[0];
		for (int i = 1; i < len; i++){
			if (!((sorted[i] - prev) >= 1 && (sorted[i]- prev) <= 3))
				return false;	
			prev = sorted[i];
		}
		return true;
	} else if (memcmp(rsorted, arr, size) == 0){
		int prev = rsorted[0];
		for (int i = 1; i < len; i++){
			if (!((prev - rsorted[i]) >= 1 && (prev - rsorted[i]) <= 3))
				return false;	
			prev = rsorted[i];
		}
		return true;
	} 
	return false;
}

int main(){
	FILE *f = fopen("input", "r");
	char *line = malloc(256);

	int total = 0;
	while (fgets(line, 256, f) != NULL){
		int *arr = malloc(sizeof(int) * 16);
		char *tok = strtok(line, " ");
		int i = 0;

		do {
			arr[i] = atoi(tok);
			i++;
			tok = strtok(NULL, " ");
		} while (tok != NULL);

		bool result = issafe(arr, i);	
		if (result != true) {
			for (int x = 0; x < i; x++){
				int *tmp = removen(arr, i, x);
				result = issafe(tmp, i - 1);
				free(tmp);
				if (result == true) break;
			}
		}
		total += result;

		free(arr);
	}

	printf("%d\n", total);

	free(line);
	fclose(f);
}
