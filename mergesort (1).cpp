#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <iostream>
#include <conio.h>
using namespace std;

#define maxn 500

void mergeSort(int *a, int l, int r) // �������
{
    if (r == l)
        return;
    if (r - l == 1)
	{ 
        if (a[r] < a[l])
            swap(a[r], a[l]); // ���������� ������� 
        return;
    }
    int m = (r + l) / 2; // ��������� �� ��� �����
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    int buf[maxn]; // �������������� ������ , ����� � ���� ���������� ����������� ������� �� ����� � ������ �����
    int xl = l; //�����
    int xr = m + 1;//������
    int cur = 0;
    while (r - l + 1 != cur) //������������
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
        a[i + l] = buf[i]; //������������ ���������� � ��������
}


int main ()
{
	int n;
	printf ("Enter number:  "); //���������� ���������� ���������
	scanf ("%d", &n);
	int *A;
	A = (int*)malloc(n*sizeof(int)); //�������� ������
	srand(time(NULL));
	for (int i = 0; i<n; ++i)
	{
		A[i] = rand()%100; //�������� ��������� � ������� �� �����
		if (A[i]<10) printf (" ");
		printf ("%d ", A[i]);
		if ((i+1)%10==0) printf ("\n");
	}
	mergeSort(A, 0, n-1); //�������� ������� ����������
	printf ("\nNEW MASS\n"); //������� �� ����� ����� ������
	for (int i = 0; i<n; ++i)
	{
		if (A[i]<10) printf (" ");
		printf ("%d ", A[i]);
		if ((i+1)%10==0) printf ("\n");
	}
}