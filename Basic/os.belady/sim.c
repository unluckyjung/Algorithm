#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pages[1000000]; //pages 배열을 임시로 잡아둔것, 넉넉히 100만으로 잡음.
int frames[1000000]; //frames 배열을 임시로 잡아둔것, 넉넉히 100만으로 잡음.




void belady(int total_frames, int pcount) { //belady 알고리즘
											//프레임안의 것중 뒤를 보았을때 가장 안쓰이는 놈을 빼는 방식


	int a = 0, b = 0; //if문을 컨트롤할 변수들
	int pagefault = 0; //pagefault값을 0으로 초기화
	int pagehit = 0; //pagehit 값을 0으로 초기화

	int find[1001]; //find배열. 해당 프레임이 얼마나 안쓰이는지 확인할때 필요한 배열
					//우리는 지금 0~1000까지 1001가지의 숫자만 사용하는것을 "안다는" 가정하에 짜는 알고리즘
					//이기 때문에 해당 배열을 크기를 다음과 같이 잡음.



	for (int i = 0; i < total_frames; i++)
		frames[i] = -1; // total_frames 만큼의 frame공간들을 -1로 초기화




	for (int m = 0; m < pcount; m++) { //page와 frame을 비교하기 위해서, 전체 페이지를 읽기위한 for문
		a = 0, b = 0; //a와 b는 page fault가 난 경우의 수를 구별하기위한 if문을 위한 변수.
		for (int n = 0; n < total_frames; n++) { //page와 frame을 비교하기위해서, 전체 프레임을 읽기위한 for문
			if (pages[m] == frames[n]) { //페이지와 frame을 비교했을때 같다면
				pagehit++; //page hit가 난것으로 pagehit를 변수를 증가
				a = 1, b = 1; //page hit가 났으므로, fault부분의 if문을 돌릴 필요가 없게됌.
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
		if (b == 0) { //page fault가 났는데, 빈공간도 없는 상황.
			int z = 0; //page fault가 난 상황에서 두가지 경우의 수를 구별하기 위한 if문을 제어하는 변수
			for (int i = 0; i < 1001; i++) //find 배열을 전부 -1로 초기화
				find[i] = -1;

			for (int i = 0; i < total_frames; i++) { //전체 프레임을 읽기위한 for문
				for (int j = m; j < pcount; j++) { //page fault가 난 지점부터, 페이지를 탐색함 
					if (frames[i] == pages[j]) { //프레임 안의 어느 숫자가 , 나중에 등장할 페이지 숫자와 같다면
						find[(frames[i])] = j; //find 배열안에 어느 숫자가 , 맨앞에서부터 몇번째 탐색번째에 발견되었는지를 저장함.
						break; //예시를 들면 find[2] = 8 이 된다면, 2번이라는 숫자는 페이지의 맨 앞에서부터 탐색해 들어갔을때 9번째에 등장했다는 이야기(시작이 0 이니)
					}          //어차피 j의 값은 fault난 부분의 m의 이상이기 때문에 앞에 등장한놈은 상관이없음.
				}
			}
			//여기서 굳이 find[(frames[i])] 방식으로 접근하는 이유는, i의 값이 1000을 초과 할시, 문제가 생길 수 있기 때문에
			//frame의 몇번째에 뭐가 있는 방식이 아니고, 어차피 우리는 숫자가 0~1000까지인것을 알기 때문에, 
			//숫자 몇번이 앞에서부터 탐색해 들어갔을때 몇번째에 등장하는지를 이용함.




			for (int i = 0; i < total_frames; i++) {
				if (find[(frames[i])] == -1) { //만약 find를 쭉 읽는데, find값이 -1이란 이야기는 해당 숫자는 뒤에서 사용되어진적이 없다는 이야기.
					frames[i] = pages[m]; // 그냥 발견되어진 놈을 빼버림, 어차피 뒤에 접근 안한 다른 숫자가 있더라도 , 그놈을 뺴나 이놈을 빼나 
										  // 다시 접근할 일이 없는 놈들이기 때문에 hit, fault값은 동일함.
					z = 1; // 타 if문을 돌아가지 않기위해서 변경
					break; // 더 이상의 작업이 필요없기 때문에 break . 여기서 필요없다고 하는것들은 = 하면 안된다 라는 말과도 동치함
				}
			}
			if (z == 0) { //pagefault가 났고, 안에 빈 공간도 없고, 더 이상 등장 안하는놈도 없는 상황
				int far = -1; //far 변수를 선언과 초기화함. 이놈은 가장 먼놈을 찾기위한 변수, page의 맨앞서부터 가장 멀리 떨어진 거리.
				int k = 0; //k는 가장 먼놈을 찾기위한 변수인데 해당 숫자를 찾기위한 변수.
				for (int i = 0; i < total_frames; i++) {
					if (find[(frames[i])] > far) { //어느 숫자가 이전 어느 숫자보다 더 멀리 떨어져있다면
						far = find[(frames[i])]; //해당 떨어진 거리와
						k = frames[i]; //해당 숫자를 k에 저장해둠
					}
				}
				//예를들어 숫자 4가 들어가야하는데 공간이 없다. 지금 들어가있는 숫자중 2 는 8(find[2]의 값)번째에 등장하고, 3이 9(find[3]의 값)번째에 등장한다면?
				//3이 늦게 등장하므로 3을 빼고 4를 넣는다.

				for (int i = 0; i < total_frames; i++) { //전체 프레임을 탐색함
					if (frames[i] == k) { //프레임의 안의 어느 숫자가, 가장 멀리 떨어져 있던 숫자라면?
						frames[i] = pages[m]; //해당 프레임을 fault난 부분의 page로 교체함.
						break;
					}
				}
			}

		}
	}







	printf("Page hits: %d \n", pagehit); //page hit 수를 출력하기 위함
	printf("Page faults: %d \n", pagefault); //page fault 수를 출력하기 위함
	double rate = ((double)pagefault / (double)pcount); //fault 확률을 실수형으로 계산하기 위함
	printf("Page fault rate: %d / %d = %f%% \n", pagefault, pcount, rate * 100); //fault 확률을 출력하기 위함


}


void lru(int total_frames, int pcount) { //lru 알고리즘


	int a = 0, b = 0;
	int pagefault = 0;
	int pagehit = 0;
	int tmp;

	for (int i = 0; i < total_frames; i++)
		frames[i] = -1; // total_frames 만큼의 frame공간들을 -1로 초기화

	for (int m = 0; m < pcount; m++) { //page와 frame을 비교하기 위해서, 전체 페이지를 읽기위한 for문
		a = 0, b = 0; //a와 b는 page fault가 난 경우의 수를 구별하기위한 if문을 위한 변수.
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

				a = 1, b = 1; //page hit가 났으므로, fault부분의 if문을 돌릴 필요가 없게됌.
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
	printf("Page hits: %d \n", pagehit); //page hit 수를 출력하기 위함
	printf("Page faults: %d \n", pagefault); //page fault 수를 출력하기 위함
	double rate = ((double)pagefault / (double)pcount); //fault 확률을 실수형으로 계산하기 위함
	printf("Page fault rate: %d / %d = %f%% \n", pagefault, pcount, rate * 100); //fault 확률을 출력하기 위함





}


int main(int argc, char*argv[]) {


	int total_frames = atoi(argv[2]); //받은 두번째 인자를 정수형으로 바꿔서 total_frame에 저장.


	if (total_frames > 1000000) { //100만보다 큰수가 들어올경우
		printf("please enter a frame below 1000000 \n"); //더 작은 값을 입력해달라는 메시지를 출력함
	}

	int temp = -1; // temp값을 -1로 초기화 해둠, 숫자를 받을 변수
	char tempi[10]; // tempi배열을 만들어둠. 문자열을 받을 변수. write 와 read는 10보다는 작기 때문에 크기를 대충 10으로 잡음


	int pcount = 0; //page수를 셀 변수
	int wcount = 0; //write수를 셀 변수
	int rcount = 0; //read수를 셀 변수



	FILE *fp; //FILE을 열기위해 사용.

	fp = fopen("access.list", "r"); //access.list 파일을 읽기형식으로 염

	while (EOF != fscanf(fp, "%d %s", &temp, tempi)) { //EOF, 파일의 끝을 만날경우 while문을 멈춤. 숫자를 temp에 쓰고 , 문자를 tempi에 씀

													   //while (!feof(fp)) {			재미있던게 해당 feof함수는 비주얼 환경에서는 올바르게 작동했으나
													   //fscanf(fp, "%d %s", &temp, tempi);    리눅스 환경에서는 마지막줄을 두번씩 읽는 상황이 벌어졌었음. 


		if (temp != -1) //temp값이 1이 아니면 읽었다는 이야기이 므로
			pcount++; //page 수를 증가
		if (!strcmp(tempi, "read")) //tempi가 read일 경우
			rcount++; //read수를 증가
		if (!strcmp(tempi, "write")) //tempi가 write일 경우
			wcount++; //write수를 증가
		pages[pcount - 1] = temp; //pages배열에 access.list파일에서 읽어진 숫자들을 집어넣음.

	}
	printf("Total number of access: %d\n", pcount); //전체 access된 수를 출력
	printf("Total number of read: %d\n", rcount); //전체 read된 수를 출력
	printf("Total number of write: %d\n", wcount); //전체 write된 수를 출력


	fclose(fp); //파일을 닫음




	if (!strcmp(argv[1], "lru")) //받은 첫번째 인자가 lru가 일경우
		lru(total_frames, pcount); //lru 알고리즘 실행

	else if (!strcmp(argv[1], "belady")) //받은 첫번째 인자가 belady일경우
		belady(total_frames, pcount); //belady 알고리즘 실행

	else
		printf("Algorithm ERROR \n"); //다른 값들이 입력되었을 경우, 알고리즘 에러 메시지 출력


	return 0;

}


