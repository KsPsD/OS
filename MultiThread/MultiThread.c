#include <Windows.h>
#include <stdio.h>

DWORD  sum;
DWORD  WINAPI  summation(LPVOID  Param)
{
	DWORD  Upper = *(DWORD*)Param;
	for (DWORD i = 0; i <= Upper; i++) {
		sum += i;
		Sleep(100);
		printf("%d\n", sum);
		printf("--- \n");
	}
	return 0;
}

DWORD count;
DWORD WINAPI Prime(LPVOID Param)
{
	DWORD i;
	DWORD j;
	DWORD Upper = *(DWORD*)Param;
	for (i = 1; i <= Upper; i++)
	{
		for (j = 2; j < i; j++)
		{
			
			if (i % j == 0){
				break;
			}
		}
		if (i == j) {
			count++;
			printf("%d\n", i);
			Sleep(100);
		}

		printf("---\n");
		
			

	}
	return 0;

}

DWORD fact_v=1;
DWORD WINAPI Factorial(LPVOID Param)
{
	DWORD Upper = *(DWORD*)Param;
	for (DWORD i = 1; i <= Upper; i++) {
		fact_v = fact_v * i;
		printf("%d\n", fact_v);
		Sleep(1000);
		printf("---\n");

	}


	return 0;
}

int main(void)
{
	DWORD  ThreadId1;
	DWORD	ThreadId2;
	DWORD	ThreadId3;

	HANDLE  ThreadHandle;


	int    Param1= 100;
	int    Param2 = 100;
	int    Param3 = 10;


	ThreadHandle = CreateThread(
		NULL,// �⺻ ���� �Ӽ�
		0,// ���� ũ��
		summation,// ������ �Լ�
		&Param1,// ������ �Լ��� �ĸ�����
		0,// ������ �÷���
		&ThreadId1);// ������ �ĺ���

	ThreadHandle = CreateThread(
		NULL,// �⺻ ���� �Ӽ�
		0,// ���� ũ��
		Prime,// ������ �Լ�
		&Param2,// ������ �Լ��� �ĸ�����
		0,// ������ �÷���
		&ThreadId2);// ������ �ĺ���

	ThreadHandle = CreateThread(
		NULL,// �⺻ ���� �Ӽ�
		0,// ���� ũ��
		Factorial,// ������ �Լ�
		&Param3,// ������ �Լ��� �ĸ�����
		0,// ������ �÷���
		&ThreadId3);// ������ �ĺ���


	if (ThreadHandle != NULL) {
		// ������ ���� ���
		WaitForSingleObject(ThreadHandle, INFINITE);

		// ������ �ڵ� �ݱ�
		CloseHandle(ThreadHandle);

		printf("Sum = %d\n", sum);
		printf("Prime count = %d\n", count);
		printf("factorial value = %d\n", fact_v);

		printf("");
	}
	
}
