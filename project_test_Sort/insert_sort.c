#include "sort.h"

void insertionSort(int *array, int len){
	int i, temp, p;
	for(i = 1; i < len; ++i){
		temp = array[i];
		p = i - 1;
		while(p >= 0 && temp < array[p]){
			array[p+1] = array[p];
			p--;
		}
	}
	array[p+1] = temp;
}
