#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
                  size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Merge two subarrays into a sorted array.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 *
 * Description: Merges two sorted subarrays into one sorted array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
                  size_t back)
{
	size_t i = front, j = mid, k = 0;

	while (i < mid && j < back)
		buff[k++] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];

	while (i < mid)
		buff[k++] = subarr[i++];

	while (j < back)
		buff[k++] = subarr[j++];

	for (k = 0, i = front; i < back; ++i, ++k)
		subarr[i] = buff[k];
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 *
 * Description: Recursively applies merge sort on subarrays.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	if (back - front > 1)
	{
		size_t mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *              using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
