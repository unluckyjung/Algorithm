#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pages[100000];
int frames[100000];




void belady(int total_frames, int pcount) {


	int a = 0, b = 0;
	int pagefault = 0;
	int pagehit = 0;

	int find[1001];



	for (int i = 0; i < total_frames; i++)
		frames[i] = -1;




	for (int m = 0; m < pcount; m++) {
		a = 0, b = 0;
		for (int n = 0; n < total_frames; n++) {
			if (pages[m] == frames[n]) {
				pagehit++;
				a = 1, b = 1;
				break;
			}
		}

		if (a == 0) { //page hit가 나지않아서 a와 b는 여전히 0인 상황.
			for (int i = 0; i < total_frames; i++) { //앞에서부터 프레임 전체를 찾기 시작함
				if (frames[i] == -1) { //-1인 공간 , 즉 프레임의 빈공간을 찾았으면
					frames[i] = pages[m]; //그 공간에다가 페이지 값을 넣어줌.
					b = 1; //b의 값을 1로 바꾸어서 다른 if문이 돌아가지 않게함
					break; //더 이상의 작업이 필요없기 때문에 break함.
				}
			}
			pagefault++; //page fault가 낫으므로 값을 증가시킴
		}
		if (b == 0) { //page fault가 났는데, 빈공간도 없는 상황.
			int z = 0;
			for (int i = 0; i < 1001; i++)
				find[i] = -1;

			for (int i = 0; i < total_frames; i++) {
				for (int j = m; j < pcount; j++) {
					if (frames[i] == pages[j]) {
						find[(frames[i])] = j;
						break;
					}
				}
			}

			/*
			printf("\n\n");
			printf("find 0 = %d \n", find[0]);
			printf("find 1 = %d \n", find[1]);
			printf("find 2 = %d \n", find[2]);
			printf("find 3 = %d \n", find[3]);
			printf("\n\n");
			*/


			for (int i = 0; i < total_frames; i++) {
				if (find[(frames[i])] == -1) {
					frames[i] = pages[m];
					z = 1;
					break;
				}
			}
			if (z == 0) {
				int far = -1;
				int k = 0;
				for (int i = 0; i < total_frames; i++) {
					if (find[(frames[i])] > far) {
						far = find[(frames[i])];
						k = frames[i];
					}
				}
				//printf("far is %d\n" ,far);
				//frames[(find[far])] = pages[m];
				for (int i = 0; i < total_frames; i++) {
					if (frames[i] == k) {
						frames[i] = pages[m];
						break;
					}
				}
			}

		}
	}







	printf("Page hits : %d \n", pagehit);
	printf("Page faults : %d \n", pagefault);
	double rate = ((double)pagefault / (double)pcount);
	printf("Page fault rate %d / %d : %f \n", pagefault, pcount, rate * 100);


	printf("frame[0] = %d \n", frames[0]);
	printf("frame[1] = %d \n", frames[1]);
	printf("frame[2] = %d \n", frames[2]);
	printf("frame[3] = %d \n", frames[3]);
	//printf("frame[4] = %d \n", frames[4]);



	/*
	for (int i = 0; i < 1001; i++) { // 0~1000 까지의 수가 있는것을 알기때문에 1~1000까지 for문을 돌림
	int samecount = 0; //pages 배열내에서
	for (int j = 0; j < pcount; j++) {
	if (pages[j] == i)
	samecount++;
	}
	num[i] = samecount;
	}
	*/


	//printf("1000 spotted : %d \n", num[1000]);

}


void LRU(int total_frames, int pcount) {
	//printf("hello %d \n", total_frames);
	//printf("page 0 is %d\n", pages[0]);

	int a = 0, b = 0;
	int pagefault = 0;
	int pagehit = 0;
	int tmp;

	for (int i = 0; i < total_frames; i++)
		frames[i] = -1; // total_frames 만큼의 frame공간들을 -1로 초기화

	for (int m = 0; m < pcount; m++) { //page와 frame을 비교하기 위해서, 전체 페이지를 읽기위한 for문
		a = 0, b = 0; //a와 b는 page fault가 난것과 안난것을 구별하기 위한 if문을 위한 변수.
		for (int n = 0; n < total_frames; n++) { //page와 frame을 비교하기위해서, 전체 프레임을 읽기위한 for문
			if (pages[m] == frames[n]) { //페이지와 frame을 비교했을때 같다면
				pagehit++; //page hit가 난것으로 pagehit를 변수를 증가
				for (int i = total_frames - 1; i >= 0; i--) { //frame 배열의 뒤에서부터 -1이 아닌부분을 찾음.
					if (frames[i] != -1) { //만약 -1이 아니라면, 그 부분이 frame이 차있는 가장 마지막,뒷 부분.
						tmp = frames[n]; //hit가 난 변수를, 뒤로 놓아야 하기때문에(demand가 나중에 일어나야하기때문에)일단 임시 변수에 저장해 둠.
						for (int i = n; i < total_frames - 1; i++) //page hit가 난부분부터 끝까지, 전체 frame을 한칸씩 당김
							frames[i] = frames[i + 1]; //배열을 한칸씩 앞으로 미는 과정
						frames[i] = tmp; //아까 저장해둔, 즉 page hit가 난부분을 저장되어있던 가장 뒷부분 프레임의 위치로 넣어줌.
						break; //더 이상의 작업이 필요없기 때문에 break함.
					}
				}

				a = 1, b = 1; //page hit가 났으므로, fault부분의 if문을 돌릴 필요가 없게.
				break; //더 이상의 작업이 필요없기 때문에 break함.
			}
		}

		if (a == 0) { //page hit가 나지않아서 a와 b는 여전히 0인 상황.
			for (int i = 0; i < total_frames; i++) { //앞에서부터 프레임 전체를 찾기 시작함
				if (frames[i] == -1) { //-1인 공간 , 즉 프레임의 빈공간을 찾았으면
					frames[i] = pages[m]; //그 공간에다가 페이지 값을 넣어줌.
					b = 1; //b의 값을 1로 바꾸어서 다른 if문이 돌아가지 않게함
					break; //더 이상의 작업이 필요없기 때문에 break함.
				}
			}
			pagefault++; //page fault가 낫으므로 값을 증가시킴
		}

		if (b == 0) { //page fault가 났는데, 빈공간도 없는상황

			for (int i = 0; i < total_frames - 1; i++) //프레임 전체를 돌기 시작함.
				frames[i] = frames[i + 1]; //전체 프레임을 앞으로 한칸씩 미는 작업.
			frames[total_frames - 1] = pages[m]; //전부 앞으로 한칸씩 밀었다면, 가장 앞에 있는 값은 밀려나서 삭제되었을것이고, 
												 //맨 뒷공간은 남게 되었을것임. 해당공간에 페이지 값을 넣어줌
		}

	}
	printf("Page hits : %d \n", pagehit);
	printf("Page faults : %d \n", pagefault);
	double rate = ((double)pagefault / (double)pcount);
	printf("Page fault rate %d / %d : %f \n", pagefault, pcount, rate * 100);


	printf("frame[0] = %d \n", frames[0]);
	printf("frame[1] = %d \n", frames[1]);
	printf("frame[2] = %d \n", frames[2]);
	printf("frame[3] = %d \n", frames[3]);
	printf("frame[4] = %d \n", frames[4]);

	//printf("tmp = %d \n", tmp);



}


int main(void) {


	//int total_frames = atoi(argv[2]);
	int total_frames = 100; //3 이라고 가정
	int temp = -1;
	char tempi[10];


	int pcount = 0;
	int wcount = 0;
	int rcount = 0;

	//int pages[100000];
	//int frames[10000];



	FILE *fp;

	fp = fopen("2.txt", "r");

	while (EOF != fscanf(fp, "%d %s", &temp, tempi)) {
		//while (!feof(fp)) {
		//fscanf(fp, "%d %s", &temp, tempi);

		if (temp != -1)
			pcount++;
		if (!strcmp(tempi, "read"))
			rcount++;
		if (!strcmp(tempi, "write"))
			wcount++;
		pages[pcount - 1] = temp;

	}
	printf("Total number of access %d\n", pcount);
	printf("Total number of read: %d\n", rcount);
	printf("Total number of write: %d\n", wcount);

	/*
	for (int i = 0; i <= pcount; i++) {
	printf("Page %d is %d \n",i, pages[i]);
	}
	*/

	fclose(fp);


	LRU(total_frames, pcount);
	belady(total_frames, pcount);



	/*
	if (!strcmp(argv[1], "LRU"))
	LRU(total_frames, pcount);
	else
	printf("ERROR \n");
	*/

	return 0;

}
