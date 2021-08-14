#include <stdio.h>;
#define MAXSIZE 50

void input_fun(int a[], int n);
void selection_sort(int a[], int n);
void bubble_sort(int a[], int n);
void linear_search(int a[], int n);
void binary_search(int a[], int n);

void main(void)
{
	int data[MAXSIZE];
	int operation;
	int count;
	char again = 'y';
	while (again == 'Y' || again == 'y')
	{
		printf("Enter Index < 50: ");
		scanf_s("%d", &count);
		if (count < 50)
		{
			input_fun(data, count);
			printf(" The Menu is:\n 1- Search. \n 2- Sort. \n");
			printf(" Choose the process you want (1, 2): ");
			scanf_s("%d", &operation);

			if (operation == 1)
			{
				int operation;
				printf(" 1- Binary Search. \n");
				printf(" 2- Linear Search. \n");
				scanf_s(" %d", &operation);
				if (operation == 1)
				{
					printf(" ----------------------------------------------------------------------------------\n");
					printf(" Be careful, to ensure correct results, you must check the order of the values.\n");
					printf(" ----------------------------------------------------------------------------------\n");
					binary_search(data, count);
				}
				else if (operation == 2)
				{
					linear_search(data, count);
				}
				else
					printf(" Invalid Operation.\n");
			}
			else if (operation == 2)
			{
				int operation;
				printf(" 1- Selection Sort. \n");
				printf(" 2- Bubble Sort. \n");
				scanf_s(" %d", &operation);
				if (operation == 1)
				{
					selection_sort(data, count);
				}
				else if (operation == 2)
				{
					bubble_sort(data, count);
				}
				else
					printf(" Invalid Operation.\n");
			}
			else
				printf(" Enter a valid value. \n");
		}
		else
			printf(" Enter a valid index. \n");
		printf(" Do you want to use again? (y - n): ");
		again = getche();
		printf("\n");
	}
	
}
void input_fun(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf(" Value [%d]: ", i);
		scanf_s(" %d", &a[i]);
	}
}
void selection_sort(int a[], int n)
{
	int i, j;
	printf(" The Data After Sorted: \n");
	printf(" ======================\n");

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int swap;
				swap = a[j];
				a[j] = a[i];
				a[i] = swap;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf(" Data [%d] is: %d\n", i, a[i]);
	}
}
void bubble_sort(int a[], int n)
{
	int check;
	int i;
	printf(" The Data After Sorted: \n");
	printf(" ======================\n");
	do
	{
		check = 1;
		for (i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				int swap;
				swap = a[i];
				a[i] = a[i + 1];
				a[i + 1] = swap;
				check = 0;
			}
		}
	} while (check == 0);
	for (i = 0; i < n; i++)
	{
		printf(" Data [%d] is: %d\n", i, a[i]);
	}
}
void linear_search(int a[], int n)
{
	int position;
	int i;
	printf(" Enter Number To Search: ");
	scanf_s(" %d", &position);

	for (i = 0; i < n; i++)
	{
		if (a[i] == position)
		{
			printf(" Your Number in Locate: %d \n", i);
			break;
		}
	}
}
void binary_search(int a[], int n)
{
	int mid, lower, upper;
	int position;
	int find;
	printf(" Enter The Number To Find Located: ");
	scanf_s(" %d", &find);
	lower = 0;
	upper = n - 1;
	position = -1;
	do
	{
		mid = (lower + upper) / 2;

		if (find == a[mid])
		{
			position = mid;
			break;
		}
		else if (find < a[mid])
			upper = mid - 1;

		else
			lower = mid + 1;
	} while (lower <= upper);

	if (position == -1)
	{
		printf(" The Number Not Avalibale.\n");
	}
	else
		printf(" The Number Located in: %d\n", position);
}