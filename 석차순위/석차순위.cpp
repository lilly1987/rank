#include <iostream> //std
#include <string> //getline
#include <time.h>
#include "배열출력.h"
#include "배열회전.h"
#include "배열할당.h"
#include "정렬.h"
#include "자료.h"

using namespace std;

int main(int argc, char* argv[]) {

	unsigned int c0, c1;//r:행,c:열

	do
	{
		// 단순히 모양 출력용으로 cout 반복으로 쓰는건 성능상 좋지 않음
		// 수학적으로 쓸일이 있다면 모를까
		// 변수에 미리 처리후 한번만 출력하는게 젤 좋음

		// 입력 받기
		cout << "숫자만 입력." << endl;
		cout << "0 입력시 종료" << endl;
		cout << "배열1 갯수:";
		cin >> c0;
		if (c0 == 0)
		{
			break;
		}

		int *arr0 = new int[c0];//원본1
		int *rnk = new int[c0] ;//랭크

		// 초기화
		arr_rnd(arr0, c0, c0 * 10);//랜덤값으로 초기화
		//memset(rnk, 1, c0);// memset은 바이단위로 해당 값으로 초기화..new 로 만든 동적 배열에도 사용하면 안됨. http://beautyrain.tistory.com/7
		arr_set(rnk,c0,1);
		//arr_rnd(arr1, c1, c1 * 3);

		arr_out(arr0, c0);
		arr_out(rnk, c0);

		clock_t begin, end, t0, t1, t2, t3, t4, t5, t6, t7, t8;//시간 측정용
				
		begin = clock();
		f_rnk(arr0, rnk, c0);//순위
		end = clock();          // 시간설정		
		t0 = end - begin;

		arr_out(arr0, c0);
		arr_out(rnk, c0);

		cout << "수행시간 : " << t0 << endl;
		//cout << "수행시간 : " << t1 << endl;
		//cout << "수행시간 : " << t2 << endl;
		//cout << "수행시간 : " << t3 << endl;
		//cout << "수행시간 : " << t4 << endl;
		//cout << "수행시간 : " << t5 << endl;
		//cout << "수행시간 : " << t6 << endl;
		//cout << "수행시간 : " << t7 << endl;
		//cout << "수행시간 : " << t8 << endl;

		delete arr0;//, arr1, arr2, arr3;
		//delete arr0, arr1, arr2, arr3;

	} while (true);
}