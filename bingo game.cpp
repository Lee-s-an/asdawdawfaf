#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	//1~25���� ���ڸ� �־��ش�.
	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	//���ڸ� �����ش�.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true)
	{
		system("cls");

		//���ڸ� 5x5�� ����Ѵ�.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << "���ڸ� �Է��ϼ���(0 : ����) :";
		int ilnput;
		cin >> ilnput;

		if (ilnput == 0)
			break;

		else if (ilnput < 1 || ilnput > 25)
			continue;

		//�ߺ��Է��� üũ�ϱ� ���� �����̴�. �⺻������ �ߺ��Ǿ��ٶ��
		//�ϱ� ���� true�� ����־���.
		bool bAcc = true;

		//��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ�
		//�ִ����� ã�Ƴ���.
		for (int i = 0; i < 25; ++i)
		{
			//���� ���ڰ� ���� ���
			if (ilnput == iNumber[i])
			{
				//���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ�
				//bAcc ������ false�� ������ش�.
				bAcc = false;

				//���ߤ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
				iNumber[i] = INT_MAX;

				//���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ�
				//for���� ����������.
				break;
			}
		}
		
		//bAcc������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *��
		//�ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue ���ش�.
		if (bAcc)
			continue;
	}
	return 0;

}