#include "sort.h"
#include <iostream>
#include "_array_.h"
size_t sort (size_t massiv[], int length) {

	// проверка и перемещени€ элементов между собой
		for (size_t i=0; i<length-1;i++)
		{
			for (size_t j = 0; j < length-i-1; j++)
			{
				if (massiv[j] > massiv[j+1])
				{
					std::swap(massiv[j], massiv[j + 1]);
				}
				
			}

		}
		return (*massiv);
}