#include <time.h>
#include <iterator>

// �ڵ尡 �ܼ��Ҽ��� �ڵ� ���� ���̰� �ӵ����̷� �̾���
// swap�� �Լ����� �׳� �ڵ��� �ϴ°� �� ����
// �Լ��� ȣ���ϴ°� ��ü�� �ӵ� ����
// for,while�� ���� ���� �������� ����. ���� ������ ������ �ۿ��� �����ϴ°� ����
/* �⺻ �����ϴ� swap ����
�迭 ����:40000
����ð� : 22694
����ð� : 1687
����ð� : 30715
����ð� : 30620
����ð� : 21504
����ð� : 1109
����ð� : 622
�迭 ����:20000
����ð� : 6751
����ð� : 430
����ð� : 8006
����ð� : 8049
����ð� : 5472
����ð� : 283
����ð� : 159
�迭 ����:10000
����ð� : 1671
����ð� : 107
����ð� : 1912
����ð� : 1921
����ð� : 1358
����ð� : 70
����ð� : 37
�迭 ����:5000
����ð� : 431
����ð� : 27
����ð� : 481
����ð� : 476
����ð� : 358
����ð� : 22
����ð� : 10
*/

/* ������ �̿��� swap��
�迭 ����:40000
����ð� : 4612
����ð� : 1681
����ð� : 4525
����ð� : 4474
����ð� : 9748
����ð� : 1161
����ð� : 659
�迭 ����:20000
����ð� : 1178
����ð� : 432
����ð� : 1085
����ð� : 1073
����ð� : 2409
����ð� : 281
����ð� : 158
�迭 ����:10000
����ð� : 285
����ð� : 103
����ð� : 248
����ð� : 240
����ð� : 601
����ð� : 68
insertion_sort2 ����ð� : 38
*/
// ��ü
template<typename T>
void swap_my(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}

#pragma once
// ��Ŀ���� �ű��� ���ڰ� �ٸ������� swap�� �Ͼ
// ���⵵ O(n^{2})
// 2���� 1190ms
template<typename T>
void sort_Select(T *&arr, const unsigned int length) {
	T t;
	unsigned int i, j;
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (arr[i] > arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
				//swap(arr[i], arr[j]);
			}
		}
	}
}

// https://ko.wikipedia.org/wiki/%EC%84%A0%ED%83%9D_%EC%A0%95%EB%A0%AC
// ��Ŀ���� �ű涧���� swap �� �ѹ��� �Ͼ
// ���⵵ O(n^{2}) ������ swap Ƚ�����̷� ���� �ӵ��� ������
// 2���� 433ms
template<typename T>
void sort_Select2(T *&list, const unsigned int n) {
	int indexMin;
	T t;
	unsigned int i, j;
	for (i = 0; i < n - 1; i++)
	{
		indexMin = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[indexMin])
			{
				indexMin = j;
			}
		}
		t = list[indexMin];
		list[indexMin] = list[i];
		list[i] = t;
		//swap(list[indexMin], list[i]);
	}
}

// ���⵵ O(n^{2})
// 2���� 1117ms
template<typename T>
void sort_Bubble(T *&list, const unsigned int c) {
	T t = 0;
	unsigned int loop, i;
	for (loop = 0; loop < c - 1; loop++) {
		for (i = 0; i < c - 1 - loop; i++) {
			if (list[i] > list[i + 1]) {
				t = list[i];
				list[i] = list[i + 1];
				list[i + 1] = t;
				//swap(list[i], list[i + 1]);
			}
		}
	}
}

// ������ �� ������쿡 �н��� ��ǻ� �� ������ ������ ����
// 2���� 1079ms
template<typename T>
void sort_Bubble2(T *&arr, const unsigned int c) {
	T t;
	unsigned int j, i, f = 1;
	for (i = c - 1; f > 0; i--)
	{
		f = 0;
		for (j = 0; j < i; j++)// ���⿡�� if ���� �ѹ��� ���� ���ϸ� ���� �� �Ǿ��ٴ¶�
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				//swap(arr[j], arr[j + 1]);
				f = 1;
			}
		}
	}
}

// �¿� ���� ����
// 2���� 825ms
template<typename T>
void sort_Bubble3(T *&arr, const unsigned int c) {
	T t;
	unsigned int i, s, st = 0, ed = c - 1;
	while (st < ed)
	{
		for (i = st; i < ed; i++)
		{
			//cout << arr[i] << "\t" << arr[i + 1];
			if (arr[i] > arr[i + 1])
			{
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				//swap(arr[i], arr[i + 1]);
				s = i;
				//cout << "\t" << s;
			}
			//cout << endl;
		}
		ed = s;
		//arr_out(arr, c);
		for (i = ed; i > st; i--)
		{
			//cout << arr[i - 1] << "\t" << arr[i];
			if (arr[i - 1] > arr[i])
			{
				t = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = t;
				swap(arr[i - 1], arr[i]);
				s = i;
				//cout << "\t" << s;
			}
			//cout << endl;
		}
		st = s;
		//arr_out(arr, c);
	}
}

//2���� 286
template<typename T>
void insertion_sort(T *&arr, int c)
{
	int i, j;
	T remember;
	for (i = 1; i < c; i++)
	{
		//cout << "i:" << i << endl;
		//arr_out(arr, c);
		remember = arr[(j = i)];
		while (--j >= 0 && remember < arr[j]) {
			//cout << "j :"<< j << endl;
			arr[j + 1] = arr[j];
			arr[j] = remember;
			//arr_out(arr, c);
		}
	}
}

//2���� 162
template<typename T>
void insertion_sort2(T *&data, int n)
{
	int i, j;
	T remember;
	i = n - 1;
	while (i-- > 0)
	{
		remember = data[(j = i)];
		while (++j < n && remember > data[j]);

		if (--j == i) continue;
		memcpy(data + i, data + i + 1, sizeof(*data) * (j - i));
		data[j] = remember;
	}
}

// �̰� ��� ���°��ΰ�
template<typename T>
void insertion_sort3(T begin, T end)
{
	T bond = begin;
	for (++bond; bond != end; ++bond)
	{
		typename std::iterator_traits<T>::value_type key = *bond;
		T ins = bond;
		T pre = ins;
		for (--pre; ins != begin && *pre > key; *ins-- = *pre--);
		*ins = key;
	}
}
