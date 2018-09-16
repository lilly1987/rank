#pragma once

// �̹� ���ĵ� �� �迭 ����
template<typename T>
void merge_sort(T *&a, T *&b, T *&c, const unsigned int an, const unsigned int bn) {
	unsigned int i = 0, j = 0, k = 0, p;
	while (true)
	{
		if (a[i] < b[j]) {// a:n , b:m

			c[k++] = a[i++];
			if (i >= an)
			{
				for (T p = j; p < bn; p++)
				{
					c[k++] = b[p];
				}
				break;
			}
		}
		else {
			c[k++] = b[j++];
			if (j >= bn)
			{
				for (T p = i; p < an; p++)
				{
					c[k++] = a[p];
				}
				break;
			}
		}

	}

}
// �̹� ���ĵ� �� �迭 ����. ��ȯ ���. �̰� ����
template<typename T>
T* merge_sort(T *&a, T *&b, const unsigned int an, const unsigned int bn) {
	T *c = new T[an + bn];
	merge_sort(a, b, c, an, bn);
	return c;
}

// ��ŷ ��ȣ �ο��ϱ�
template<typename T>
void f_rnk(T *&data, T *&rank, const unsigned int c) {
	unsigned int i, j;
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (data[i] < data[j])
			{
				rank[i] ++;
			}
		}
	}
}