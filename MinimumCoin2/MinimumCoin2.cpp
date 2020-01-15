#include<iostream>
#include<cstring>

using namespace std;


class Coin //동전 클래스
{
private:
	int n; //동전 가짓수
	int k; //금액
	int c; //동전의 갯수
	int* C_array;
	int* A_array;
	int aL;
public:
	Coin()
		:n(0),k(0),c(0),aL(0)
	{}
	void setn() //동전 가짓수 입력받는 함수
	{
		printf("동전의 가짓수를 입력하세요:");
		scanf("%d", &n);
		printf("\n");
		if (n < 1 || n>100) {
			printf("Wrong n\n");
			exit(-1);
		}
		return;
	}
	void setk() //금액 입력하는 함수
	{
		printf("목표 금액을 입력하세요:");
		scanf("%d", &k);
		printf("\n");
		if (k < 1 || k>10000) {
			printf("Wrong k\n");
			exit(-1);
		}
		return;
	}
	void Set_C_array() //C_array 입력받는 함수
	{
		C_array = new int[n];
		memset(C_array, 0, n);
		printf("동전의 종류를 입력하세요:\n");
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &C_array[i]);
		}
		return;
	}
	void sort_C_array() //C_array를 정렬하는 함수
	{
		for (int i = 0; i < n-1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (C_array[i] < C_array[j])
					swap(C_array[i], C_array[j]);
			}
		}
	}

	void get_Coin_num() //필요 코인 갯수 구하는 함수
	{
		A_array = new int[100];
		int end = 0;
		int start = 0;
		while (end == 0)
		{
			int kk = k;
			c = 0;
			int quotient = 0;
			for (int i = start; i < n; i++)
			{
				quotient = kk / C_array[i];
				kk -= C_array[i] * quotient;
				c += quotient;
			}
			if (kk == 0)
			{
				A_array[aL] = c;
				aL++;
			}
			else
			{
				A_array[aL] = 9999; //나누어 떨어지지 않는 경우
				aL++;
			}
			if (start == n - 1)
			{
				end = 1;
			}
			start += 1;
		}
	}

	void printc() //동전갯수 출력
	{
		if (c == 9999)
		{
			printf("필요한 동전의 최소 갯수는 -1개 입니다\n");
		}
		else
			printf("필요한 동전의 최소 갯수는 %d개 입니다\n",c);
	}

	void swap(int& x, int& y) //교환
	{
		int temp = x;
		x = y;
		y = temp;
	}

	void printcarray() //정렬 제대로 되었는지 확인하는 함수
	{
		cout << "this is C_carry" << endl;
		for (int i = 0; i < n; i++)
		{
			printf("%d\n", C_array[i]);
		}
	}

	void get_Min()
	{
		int Min = A_array[0];
		for (int i = 1; i < aL; i++)
		{
			if (A_array[i] < Min)
				Min = A_array[i];
		}
		c = Min;
	}
	
	void printa_array()
	{
		for (int i = 0; i < aL; i++)
		{
			printf("%d\n", A_array[i]);
		}
	}
};


int main() {

	Coin Ctest;
	Ctest.setn();
	Ctest.setk();
	Ctest.Set_C_array();
	Ctest.sort_C_array();
	Ctest.get_Coin_num();
	Ctest.get_Min();
	Ctest.printc();
	//Ctest.printcarray();
	//Ctest.printa_array();
	return 0;

}