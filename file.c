#include <stdio.h>
#define max_int 2147483647;
int solve()
{
    int n, m;

    scanf("%d", &n);
    int arr_1[n + 1];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr_1[i]);
    arr_1[n] = max_int;

    scanf("%d", &m);
    int arr_2[m + 1];
    for (int j = 0; j < m; j++)
        scanf("%d", &arr_2[j]);
    arr_2[m] = 2147483647;
    int a = 0, b = 0;

    int merge[n + m];

    for (int i = 0; i < n + m; i++)
    {

        if (arr_1[a] < arr_2[b])
        {
            merge[i] = arr_1[a];
            if (a < n)
            {
                a++;
            }
        }
        else
        {
            merge[i] = arr_2[b];
            if (b < m)
                b++;
        }
    }

    for (int i = 0; i < n + m; i++)
        printf("%d ", merge[i]);

    printf("\n");
}
void d_arr(int *arr[],size_t t);
int main()
{

     

   // solve();
   int *arr[4] = {1,2,3,4};
   d_arr( arr,4);
    return 0;
}

void d_arr(int *arr[], size_t t)
{

    for (size_t i = 0; i < t; i++)
    {
        /* code */
        scanf("%d", arr[i]);
        printf("x(%ld) : %d\n", i+1,*arr[i]);
    }

}

// *x => x = [address of x]
//*x = value in x address
