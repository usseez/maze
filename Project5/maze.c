#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



/********************
 * Define
 ********************/
#define WIDTH 20
#define HEIGHT 20
#define FINISH (WIDTH-1) * (HEIGHT-1)
#define WAY 0
#define WALL 1
#define DONTGO1 7
#define DONTGO2 8
#define DONTGO3 9
#define ME 5
 //���׸��� : printf�� �ݺ��� ����ؼ� 5, 6, 7���� �ִ� ��

 //�̷� Ż�� : �ֿܼ� 20*20map�� �׸��� -> ���� ���Ƿ� �����(�� ����� fix) -> 0.5s���� �� ĭ�� �������� Ż���ϵ���(�������� �������� Ż���ϵ���.............�Ф�) �������� �������
 //��ĭ�� ��, ���ڰ� ��



 /********************
  * Structure
  ********************/
typedef struct
{
	int x, y;

} Point;

//�������� Global ������
static int wall[HEIGHT * WIDTH] = { 0, };
/********************
 * Variables
 ********************/

int cx, cy;//dot�� ������ ��ġ......



/********************
 * Define Function
 ********************/

void make_map(int*);
int maze(void);
int position(int*, int, Point*);

//int position(int* arr, int val, Point p1);
//int turn_right(void);
//int turn_left(void);

 /********************
  * Main Process
  ********************/



int main(int argc, char* argv[]) {
	maze();

	return 0;

}
//int* 
//void make_map(int wall[][WIDTH]) {//20*20���� �����ϰ� ����ϱ�

 /********************
  * Fuction
  ********************/





int position(int* arr, int val, Point* p1) {

	for (int i = 0; i < HEIGHT * WIDTH; i++) {
		if (arr[i] == val)//
		{

			p1->x = i % WIDTH;
			p1->y = i / WIDTH;
			return 0;

		}
	}
	return -1;




}


void make_map(int* wall) 
{
	system("cls");


	for (int h = 0; h < HEIGHT;h++) {
		for (int w = 0;w < WIDTH;w++) {
			//if (wall[h][w] == 0) wall[h][w] = 1;
			//if (wall[h*WIDTH + w] == 0) 
			wall[h * WIDTH + w] = 1;
		}
	}

	//line 0
	for (int w = 0; w < 12; w++) wall[0 * WIDTH + w] = 0;
	//line 1~2
	for (int h = 1; h < 3; h++) wall[h * WIDTH + 11] = 0;
	for (int w = 3; w < 17; w++) wall[3 * WIDTH + w] = 0;
	//for (int h = 4; h <=7; h++)	wall[h][7] = 0;
	wall[4 * WIDTH + 7] = 0;
	wall[5 * WIDTH + 7] = 0;
	wall[4 * WIDTH + 12] = 0;
	wall[5 * WIDTH + 12] = 0;
	wall[6 * WIDTH + 7] = 0;
	wall[7 * WIDTH + 7] = 0;
	for (int w = 5; w <= 13; w++) wall[8 * WIDTH + w] = 0;
	wall[9 * WIDTH + 13] = 0;
	for (int w = 8; w <= 14; w++) wall[10 * WIDTH + w] = 0;
	wall[11 * WIDTH + 5] = 0;
	wall[11 * WIDTH + 14] = 0;
	for (int w = 4; w <= 17; w++) wall[12 * WIDTH + w] = 0;
	for (int h = 13; h <= 16; h++)	wall[h * WIDTH + 5] = 0;
	for (int h = 13; h <= 18; h++)	wall[h * WIDTH + 12] = 0;
	for (int w = 9; w <= 19; w++) wall[19 * WIDTH + w] = 0;

	

}


int show_map(int* wall) {

	//int wall[HEIGHT * WIDTH] = {0, };


	for (int h = 0; h < HEIGHT;h++) {
		for (int w = 0;w < WIDTH;w++) {

			//printf("%d", *wall[w + h * HEIGHT]);

			if (wall[h * WIDTH + w] == WALL) printf("��");
			else if (wall[h * WIDTH + w] == WAY) printf("��");
			else if (wall[h * WIDTH + w] == DONTGO1) printf("��");
			else if (wall[h * WIDTH + w] == DONTGO2) printf("��");
			else if (wall[h * WIDTH + w] == ME) printf("��");

		}
		printf("\n");
	}
	return 0;
}


int maze()
{
	Point p1;
	p1.x = 0;
	p1.y = 0;




	make_map(wall);



	wall[0] = ME;
	//while (p1.x * p1.y != FINISH) {
	while (1)
	{



		system("cls");

		position(wall, ME, &p1); //me�� ��ǥ ��ġ�� �޴� position : 11, 1��ǥ�� �� �޾ƿ�

		int x = p1.x;
		int y = p1.y;

		if ((x == WIDTH - 1) && (y == HEIGHT - 1))
		{
			return 0;
		}

		show_map(wall);

		//�湮�ߴ� �� DONTGO2�� ǥ���ϴ� ���.................???
		//������ ����
		if ((wall[(x + 1) + y * (WIDTH)] != WALL) && (wall[(x + 1) + y * (WIDTH)] < DONTGO1))//�� != �� && �� != DONTGO2 �� ����������
		{

			//wall[x + y * (WIDTH)] = DONTGO1;



			if (wall[(x)+y * WIDTH] == DONTGO1)
			{
				wall[x + y * (WIDTH)] = DONTGO2;

			}


			else// if(x + y * WIDTH == WAY)
			{
				wall[x + y * (WIDTH)] = DONTGO1;

			}

			/*else if (x + y * WIDTH == ME)
			{
				wall[x + y * (WIDTH)] = DONTGO1;

			}*/


			/*else if((x) + y * WIDTH == WALL)
			{
				wall[x + y * (WIDTH)] = DONTGO1;

			}*/
			wall[(x + 1) + y * (WIDTH)] = ME;

		}

		//else if ((wall[(x + 1) + y * (WIDTH)] == WALL) || (wall[(x + 1) + y * (WIDTH)] == DONTGO1))//�������� �� ���� (�� = �� or �� = dontgo)
		else// if ((wall[(x + 1) + y * (WIDTH)] == WALL) || (wall[(x + 1) + y * (WIDTH)] >=  DONTGO1))//������ (�� or �湮�Ѱ�) 
		{


			if ((wall[x + (y + 1) * (WIDTH)] != WALL) && (wall[x + (y + 1) * (WIDTH)] < DONTGO1))// -> ����
			{

				//wall[x + y * (WIDTH)] = DONTGO1;
				if (wall[x + y * WIDTH] == DONTGO1)
				{
					wall[x + y * (WIDTH)] = DONTGO2;
				}


				else// if(x + y * WIDTH == WAY)
				{
					wall[x + y * (WIDTH)] = DONTGO1;

				}
				wall[x + (y + 1) * (WIDTH)] = ME;

			}
			else if ((x != 0) && ((wall[(x)+(y + 1) * (WIDTH)] == WALL) || (wall[(x)+(y + 1) * (WIDTH)] >= DONTGO1))) //���� = �� -> //��������  x != 0) || 
			{

				if ((wall[x - 1 + (y) * (WIDTH)] != WALL)) // �������� ���� && (wall[x - 1 + (y) * (WIDTH)] < DONTGO1)
				{

					//wall[x + y * (WIDTH)] = DONTGO1;

					printf("hi");

					if (wall[x + y * WIDTH] == DONTGO1)
					{
						wall[x + y * (WIDTH)] = DONTGO2;
						printf("hi");

					}


					else// if(x + y * WIDTH == WAY)
					{
						wall[x + y * (WIDTH)] = DONTGO1;

					}
					wall[x - 1 + (y) * (WIDTH)] = ME;
				}

				else //�������� ����.
				{

					if ((wall[x + (y - 1) * (WIDTH)] != WALL)) //  && (wall[x + (y - 1) * (WIDTH)] < DONTGO3)�������� ����
					{


						if (wall[x + y * WIDTH] == DONTGO1)
						{
							wall[x + y * (WIDTH)] = DONTGO2;
						}


						else// if(x + y * WIDTH == WAY)
						{
							wall[x + y * (WIDTH)] = DONTGO1;

						}
						wall[(x)+(y - 1) * (WIDTH)] = ME;


					}

				}




			}

		

		}





		Sleep(50);

	}



}



