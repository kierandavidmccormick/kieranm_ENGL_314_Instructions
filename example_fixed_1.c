#include <stdio.h>
#include <stdlib.h>

/* 
 * This example program takes in a list of integers, sorts the list, and returns it
 * Input should be in the following format: "example.out 1 2 0 3 4 -5"
 * Output should look like: "Sorted list: -5 0 1 2 3 4"
 */

void sort(int* list, int len);

int main(int argc, char**argv) {

	int list_len = argc - 1;						// Length of the input list
	int* vals = malloc(sizeof(int) * list_len);		// Array holding the input list - /* *** CHANGED *** */

	// Write the input values into the list, converting them from strings to integers
	for (int i = 1; i < argc; i++) {
		vals[i-1] = atoi(argv[i]);
	}

	// Sort the list
	sort(vals, list_len);

	// Print out the sorted list
	printf("Sorted list: ");
	for (int i = 0; i < list_len; i++) {
		printf("%d ", vals[i]);
	}
	printf("\n");
}

// Sorts the provided list
// Implemented using bubblesort
void sort(int* list, int len) {

	// Do enough iterations (n-1) to guarantee the list is sorted
	for (int i = 0; i < len - 1; i++) {

		// Iterate through the list, swapping elements if they are out of order
		for (int j = 0; j < len; j++) {

			// Swap elements of the list if needed
			if (list[j] > list[j - 1]) {
				int temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
			}

		}
	}
}