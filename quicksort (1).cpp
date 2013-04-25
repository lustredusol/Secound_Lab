#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <iostream>
using namespace std;

void qs(int* s_arr, int first, int last)
{
    int i = first, j = last, x = s_arr[(first + last) / 2]; //��������� ������, ��������� � ������� ��������
 
    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;
 
        if(i <= j) {
            if (i < j) swap(s_arr[i], s_arr[j]); //������ �������� �������, ���� ����������� ������ �������������
            i++;
            j--;
        }
    } while (i <= j);
 
    if (i < last)
        qs(s_arr, i, last);//����������� ������
    if (first < j)
        qs(s_arr, first,j);//����������� ������
}

int main ()
{
	int n;
	printf ("Enter number:  "); //���������� ���������� ��������� � ������������
	scanf ("%d", &n);
	int *A;
	A = (int*)malloc(n*sizeof(int)); //�������� ������ ��� ������
	srand(time(NULL));
	for (int i = 0; i<n; ++i)
	{//�������� ��������� ������ � ������� �� �����
		A[i] = rand()%100;
		if (A[i]<10) printf (" ");
		printf ("%d ", A[i]);
		if ((i+1)%10==0) printf ("\n");
	}
	qs (A, 0, n-1); //�������� ������� ������� ����������
	printf ("\nNEW MASS\n");
	for (int i = 0; i<n; ++i)
	{ //������� �� ����� ���������� ������
		if (A[i]<10) printf (" ");
		printf ("%d ", A[i]);
		if ((i+1)%10==0) printf ("\n");
	}
	return 0;
}