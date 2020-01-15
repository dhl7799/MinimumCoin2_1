#include<iostream>
#include<cstring>

using namespace std;


class Coin //���� Ŭ����
{
private:
	int n; //���� ������
	int k; //�ݾ�
	int c; //������ ����
	int* C_array;
	int* A_array;
	int aL;
public:
	Coin()
		:n(0),k(0),c(0),aL(0)
	{}
	void setn() //���� ������ �Է¹޴� �Լ�
	{
		printf("������ �������� �Է��ϼ���:");
		scanf("%d", &n);
		printf("\n");
		if (n < 1 || n>100) {
			printf("Wrong n\n");
			exit(-1);
		}
		return;
	}
	void setk() //�ݾ� �Է��ϴ� �Լ�
	{
		printf("��ǥ �ݾ��� �Է��ϼ���:");
		scanf("%d", &k);
		printf("\n");
		if (k < 1 || k>10000) {
			printf("Wrong k\n");
			exit(-1);
		}
		return;
	}
	void Set_C_array() //C_array �Է¹޴� �Լ�
	{
		C_array = new int[n];
		memset(C_array, 0, n);
		printf("������ ������ �Է��ϼ���:\n");
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &C_array[i]);
		}
		return;
	}
	void sort_C_array() //C_array�� �����ϴ� �Լ�
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

	void get_Coin_num() //�ʿ� ���� ���� ���ϴ� �Լ�
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
				A_array[aL] = 9999; //������ �������� �ʴ� ���
				aL++;
			}
			if (start == n - 1)
			{
				end = 1;
			}
			start += 1;
		}
	}

	void printc() //�������� ���
	{
		if (c == 9999)
		{
			printf("�ʿ��� ������ �ּ� ������ -1�� �Դϴ�\n");
		}
		else
			printf("�ʿ��� ������ �ּ� ������ %d�� �Դϴ�\n",c);
	}

	void swap(int& x, int& y) //��ȯ
	{
		int temp = x;
		x = y;
		y = temp;
	}

	void printcarray() //���� ����� �Ǿ����� Ȯ���ϴ� �Լ�
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