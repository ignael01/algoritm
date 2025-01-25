#include "assert_test.h"
#include < assert.h> 
#include <iostream>
#include "sort.h"
#include "..\task2\poisk.h"
void assert_test() {

	size_t massiv[] = {1,5,2,7,5};
	size_t massiv_copy[5] ;
	size_t ext[] = { 1,2,5,5,7 };
	

	std::memcpy(massiv_copy, massiv, 5 * sizeof(size_t));
	bubble_sorting(massiv_copy, 5);
	assert(proverka_sort(massiv_copy,5));

	std::memcpy(massiv_copy, massiv, 5 * sizeof(size_t));
	mergeSort<size_t>(massiv_copy,0,5);
	assert(proverka_sort(massiv_copy,5));

	std::memcpy(massiv_copy, massiv, 5 * sizeof(size_t));
	quickSort(massiv_copy, 0, 5);
	assert(proverka_sort(massiv_copy,5));

	std::memcpy(massiv_copy, massiv, 5 * sizeof(size_t));
	shellSort(massiv, 5);
	assert(proverka_sort(massiv_copy,5));


	for (size_t i = 0; i < 5; ++i) {
		assert(massiv[i] == ext[i]);
	}
	
	assert(search(massiv, 5, 5) == 1);
	assert(search(massiv, 10, 5) == -1);
	assert(binary_search(massiv_copy, 2,0,5) == 1);


}