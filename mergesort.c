#include <stdio.h>
#include <stdlib.h>
// b[100];
int a[100];
void merge(int a[], int l, int mid, int h)
{
    int b[100];
    int i = l, k = l, j = mid + 1;
    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    while (i < mid + 1)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = l; i <= h; i++)
    {
        a[i] = b[i];
    }

}

void mergesort(int a[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = l+(h-l)/2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

void main()
{
    int n;
    printf("enter the no of elements\n");
    scanf("%d",&n);
   printf("enter the elements \n");
      for (int i = 0; i < n; i++)
    {
        scanf("%d ", &a[i]);
    }
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
