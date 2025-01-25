
void myqsort(int *arr, int left, int right)
{
    if (left <= right)
    {
        int pivot = arr[(left + right) / 2];
        int L = left, R = right;
        while (L <= R)
        {
            while (arr[L] < pivot)
                L++;
            while (arr[R] > pivot)
                R--;
            if (L <= R)
            {
                int t = arr[L];
                arr[L] = arr[R];
                arr[R] = t;
                L++;
                R--;
            }
        }
        
        myqsort(arr, left, R);
        myqsort(arr, L, right);
    }
}