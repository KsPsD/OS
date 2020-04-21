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
		NULL,// 기본 보안 속성
		0,// 스택 크기
		summation,// 스레드 함수
		&Param1,// 스레드 함수의 파리미터
		0,// 스레드 플래그
		&ThreadId1);// 스레드 식별자

	ThreadHandle = CreateThread(
		NULL,// 기본 보안 속성
		0,// 스택 크기
		Prime,// 스레드 함수
		&Param2,// 스레드 함수의 파리미터
		0,// 스레드 플래그
		&ThreadId2);// 스레드 식별자

	ThreadHandle = CreateThread(
		NULL,// 기본 보안 속성
		0,// 스택 크기
		Factorial,// 스레드 함수
		&Param3,// 스레드 함수의 파리미터
		0,// 스레드 플래그
		&ThreadId3);// 스레드 식별자


	if (ThreadHandle != NULL) {
		// 스레드 종료 대기
		WaitForSingleObject(ThreadHandle, INFINITE);

		// 스레드 핸들 닫기
		CloseHandle(ThreadHandle);

		printf("Sum = %d\n", sum);
		printf("Prime count = %d\n", count);
		printf("factorial value = %d\n", fact_v);

		printf("");
	}
	
}
