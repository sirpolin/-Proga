#include <iostream>

#include <stdlib.h>
#include <cstring>
#include <stdio.h>

using namespace std;

struct IntMore {
    bool operator () (int x, int y) const { return x > y; }
};

template <class T>
void my_swap(T & a, T & b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T, class Comparer>
void my_sort(T * beg, T * end, Comparer cmp) {
    T* i = beg;
    T* j = end;
    T* x = beg + (end - beg) / 2;
    do {
        while ((*i) < (*x))
            i += sizeof(T);
        while ((*j) > (*x))
            j -= sizeof(T);
        if(i <= j) {
            if (i < j)
                swap((*i), (*j));
            i += sizeof(T);
            j -= sizeof(T);
        }
    } while (i <= j);

    if (i < end)
       my_sort(i, end, cmp);
    if (beg < j)
       my_sort(beg, j, cmp);

    //    int i = 0, j = (end - beg) / sizeof(T), x = j / 2;
    //     while (i <= j) {
    //        while (beg[i] < beg[x])
    //            i++;
    //        while (beg[j] > beg[x])
    //            j--;
    //        if(i <= j) {
    //            if (i < j) {
    //                my_swap(beg[i], beg[j]);
    //                int newbase = x;
    //                if (i == x)
    //                    newbase = j;
    //                if (j == x)
    //                    newbase = i;
    //                x = newbase;
    //            }
    //            i++;
    //            j--;
    //        }

    //    }
    //    if (i < (end - beg) / sizeof(T))
    //        my_sort(beg + i * sizeof(T), end, cmp);
    //    if (0 < j)
    //        my_sort(beg, beg + j * sizeof(T), cmp);
}

void check_NULL(void* pointer)
{
    if (pointer == NULL)
    {
        printf("Error!\n");
        exit(666);
    }
    return;
}

void swap(void* a, void* b, int size)
{
    void* c = malloc(size);
    check_NULL(c);
    memmove(c, a, size);
    memmove(a, b, size);
    memmove(b, c, size);
    free(c);
    return;
}

int compare_int(const void* a, const void* b)
{
    int a_int = *((int*)a);
    int b_int = *((int*)b);
    if (a_int > b_int)
        return 1;
    if (a_int < b_int)
        return -1;
    return 0;
}

void quicksort(void* arr, int first, int last, int size, int (*compare)(const void* a, const void* b))
{
    if (last == 0)
        return;
    char* a = (char*) arr;
    int i = first;
    int j = last;
    int base = (first + last) / 2;
    while(i <= j)
    {
        while (compare(a+i*size, a+base*size) < 0 )
            i++;
        while (compare(a+j*size, a+base*size) > 0)
            j--;
        if(i <= j)
        {
            if (i < j)
            {
                swap(a+i*size, a+j*size, size);
                int newbase = base;
                if (i == base)
                    newbase = j;
                if (j == base)
                    newbase = i;
                base = newbase;
            }
            i++;
            j--;
        }
    }
    if (i < last)
        quicksort(a, i, last, size, compare);
    if (first < j)
        quicksort(a, first, j, size, compare);
    return;
}

int main() {
    int n;
    cin >> n;
    int * a = new int [n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    my_sort(a, a + n - 1, IntMore());
//    quicksort(a, 0, n-1, sizeof(int), compare_int);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    return 0;
}
