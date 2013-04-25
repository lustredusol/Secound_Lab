#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <iostream>
#include <conio.h>
using namespace std;

#define maxn 500

void mergeSort(int *a, int l, int r) // слияние
{
    if (r == l)
        return;
    if (r - l == 1)
	{ 
        if (a[r] < a[l])
            swap(a[r], a[l]); // обмениваем местами 
        return;
    }
    int m = (r + l) / 2; // разбиваем на две части
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    int buf[maxn]; // дополнительный массив , чтобы в него записывать минимальный элемент из левой и правой части
    int xl = l; //левая
    int xr = m + 1;//правая
    int cur = 0;
    while (r - l + 1 != cur) //перемешиваем
	{
        if (xl > m)
            buf[cur++] = a[xr++];
        else if (xr > r)
            buf[cur++] = a[xl++];
        else if (a[xl] > a[xr])
            buf[cur++] = a[xr++];
        else buf[cur++] = a[xl++];
 
    }
    for (int i = 0; i < cur; i++)
        a[i + l] = buf[i]; //Перемешанный записываем в основной
}


int main ()
{
	int n;
	printf ("Enter number:  "); //определяем количество элементов
	scanf ("%d", &n);
	int *A;
	A = (int*)malloc(n*sizeof(int)); //выделяем память
	srand(time(NULL));
	for (int i = 0; i<n; ++i)
	{
		A[i] = rand()%100; //рандомно заполняем и выводим на экран
		if (A[i]<10) printf (" ");
		printf ("%d ", A[i]);
		if ((i+1)%10==0) printf ("\n");
	}
	mergeSort(A, 0, n-1); //вызываем функцию сортировки
	printf ("\nNEW MASS\n"); //выводим на экран новый массик
	for (int i = 0; i<n; ++i)
	{
		if (A[i]<10) printf (" ");
		printf ("%d ", A[i]);
		if ((i+1)%10==0) printf ("\n");
	}
}