#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <iostream>
using namespace std;

void qs(int* s_arr, int first, int last)
{
    int i = first, j = last, x = s_arr[(first + last) / 2]; //факсируем первый, последний и опорный элементы
 
    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;
 
        if(i <= j) {
            if (i < j) swap(s_arr[i], s_arr[j]); //меняем элементы местами, если минимальный больше максимального
            i++;
            j--;
        }
    } while (i <= j);
 
    if (i < last)
        qs(s_arr, i, last);//рекурсивный повтор
    if (first < j)
        qs(s_arr, first,j);//рекурсивный повтор
}

int main ()
{
	int n;
	printf ("Enter number:  "); //выпытываем количество элементов у пользователя
	scanf ("%d", &n);
	int *A;
	A = (int*)malloc(n*sizeof(int)); //выделяем память под массив
	srand(time(NULL));
	for (int i = 0; i<n; ++i)
	{//рандомно заполняем массив и выводим на экран
		A[i] = rand()%100;
		if (A[i]<10) printf (" ");
		printf ("%d ", A[i]);
		if ((i+1)%10==0) printf ("\n");
	}
	qs (A, 0, n-1); //вызываем функцию быстрой сортировки
	printf ("\nNEW MASS\n");
	for (int i = 0; i<n; ++i)
	{ //Выводим на экран полученный массив
		if (A[i]<10) printf (" ");
		printf ("%d ", A[i]);
		if ((i+1)%10==0) printf ("\n");
	}
	return 0;
}