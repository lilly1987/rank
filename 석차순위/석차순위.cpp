#include <iostream> //std
#include <string> //getline
#include <time.h>
#include "�迭���.h"
#include "�迭ȸ��.h"
#include "�迭�Ҵ�.h"
#include "����.h"
#include "�ڷ�.h"

using namespace std;

int main(int argc, char* argv[]) {

	unsigned int c0, c1;//r:��,c:��

	do
	{
		// �ܼ��� ��� ��¿����� cout �ݺ����� ���°� ���ɻ� ���� ����
		// ���������� ������ �ִٸ� �𸦱�
		// ������ �̸� ó���� �ѹ��� ����ϴ°� �� ����

		// �Է� �ޱ�
		cout << "���ڸ� �Է�." << endl;
		cout << "0 �Է½� ����" << endl;
		cout << "�迭1 ����:";
		cin >> c0;
		if (c0 == 0)
		{
			break;
		}

		int *arr0 = new int[c0];//����1
		int *rnk = new int[c0] ;//��ũ

		// �ʱ�ȭ
		arr_rnd(arr0, c0, c0 * 10);//���������� �ʱ�ȭ
		//memset(rnk, 1, c0);// memset�� ���̴����� �ش� ������ �ʱ�ȭ..new �� ���� ���� �迭���� ����ϸ� �ȵ�. http://beautyrain.tistory.com/7
		arr_set(rnk,c0,1);
		//arr_rnd(arr1, c1, c1 * 3);

		arr_out(arr0, c0);
		arr_out(rnk, c0);

		clock_t begin, end, t0, t1, t2, t3, t4, t5, t6, t7, t8;//�ð� ������
				
		begin = clock();
		f_rnk(arr0, rnk, c0);//����
		end = clock();          // �ð�����		
		t0 = end - begin;

		arr_out(arr0, c0);
		arr_out(rnk, c0);

		cout << "����ð� : " << t0 << endl;
		//cout << "����ð� : " << t1 << endl;
		//cout << "����ð� : " << t2 << endl;
		//cout << "����ð� : " << t3 << endl;
		//cout << "����ð� : " << t4 << endl;
		//cout << "����ð� : " << t5 << endl;
		//cout << "����ð� : " << t6 << endl;
		//cout << "����ð� : " << t7 << endl;
		//cout << "����ð� : " << t8 << endl;

		delete arr0;//, arr1, arr2, arr3;
		//delete arr0, arr1, arr2, arr3;

	} while (true);
}