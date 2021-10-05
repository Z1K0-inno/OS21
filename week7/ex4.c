#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* Realloc(void* ptr, size_t new_size, size_t old_size)
{
    if(ptr == NULL)
    {
        return malloc(new_size);
    }

    if(new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(new_size);
	if(new_ptr == NULL)
		return NULL;

	size_t min_size = old_size < new_size ? old_size : new_size;
	memcpy(new_ptr, ptr, min_size);

	free(ptr);

	return new_ptr;
}

int main() // Code from ex3.c to test
{
    printf("Enter original array size: ");
    int n1 = 0;
    scanf("%d", &n1);
    int *a1 = malloc(n1 * sizeof(int));
    if(a1 == NULL)
    {
        printf("Error allocating memory!\n");
        return 1;
    }

    for(int i=0; i<n1; i++)
    {
        a1[i] = 100;
        printf("%d ", a1[i]);
    }

    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    a1 = Realloc(a1, n2 * sizeof(int), n1 * sizeof(int));

    if(n2 > n1)
    {
        for(int i=n1; i<n2; i++)
            a1[i] = 0;
    }

    for(int i=0; i<n2; i++)
    {
        printf("%d ", a1[i]);
    }
    printf("\n");

    free(a1);

    return 0;
}
