#include "sort.h"

void selectionSort(int *array, int len){
	int min = 0;
	for(int i = 0; i < len - 1; ++i){
		min = i;
		for(int j = i + 1; j < len; ++j ){
			if(array[min] > array[j])
			{
				min = j;
			}
		}
	
		if( min != i ){
			int tmp = array[min];
			array[min] = array[i];
			array[i] = tmp;	
		}
	}
}
