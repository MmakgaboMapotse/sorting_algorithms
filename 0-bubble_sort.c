#include <stdio.h>

void bubble_sort(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
	for (size_t j = 0; j < size - i - 1; j++)
	{
	if (array[j] > array[j + 1])
	{
		int temp = array[j];

		array[j] = array[j + 1];
		array[j + 1] = temp;

		printf("Array after swap: ");
		for (size_t k = 0; k < size; k++)
		{
		printf("%d ", array[k]);
		}
		printf("\n");
		}
	}
	}
}

int main(void)
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	printf("Original array: ");
	for (size_t i = 0; i < size; i++)
	{
	printf("%d ", arr[i]);
	}
	printf("\n");

	bubble_sort(arr, size);

	printf("Sorted array: ");
	for (size_t i = 0; i < size; i++)
	{
	printf("%d ", arr[i]);
	}
	printf("\n");

	return (0);
}
