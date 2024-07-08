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
/*static int wall[HEIGHT * WIDTH] = { 0, };*/
static int wall[HEIGHT * WIDTH] = { 
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
};
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
			//Point p1;
			/*p1.x = i / HEIGHT;
			p1.y = i % HEIGHT;*/ //tab ������ �ڵ�����
			p1->x = i % WIDTH;
			p1->y = i / WIDTH;
			return 0;
			//return p1;
		}
	}
	return -1;

	
	//static int i = 0;// static�ϸ� �缱���� ���ϰ� �������� ������ ����
	//while (arr[i] != val) {
	//	p1->x = i % WIDTH;
	//	p1->y = i / HEIGHT;
	//	i++;
	//}

	//return 0;


}


void make_map(int* wall) {
	system("cls");


	//static int wall[HEIGHT*WIDTH] = {0, };
	// 
	//memset(wall, 1, sizeof(wall));
	//printf("%d\n\n\n\n\n", sizeof(wall)/sizeof(int));

	/*
	char wall[400] = {'o',};
	int wall[400] = { 0, };

	wall[0] = '\0';
	wall[399] = '\0';

	//printf("%c", wall[0]);
	//printf("%c", wall[399]);
	//printf("%d", wall[150]);
	//printf("%d", wall[200]);

	//printf("%d", len(walls));
	*/

	//set each box to '1'




	for (int h = 0; h < HEIGHT;h++) {
		for (int w = 0;w < WIDTH;w++) {
			//if (wall[h][w] == 0) wall[h][w] = 1;
			//if (wall[h*WIDTH + w] == 0) 
			wall[h * WIDTH + w] = 1;
		}
	}
	//printf("size: %d\n", sizeof(wall));

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
	//wall[10][5] = 0;
	for (int w = 8; w <= 14; w++) wall[10 * WIDTH + w] = 0;
	wall[11 * WIDTH + 5] = 0;
	wall[11 * WIDTH + 14] = 0;
	for (int w = 4; w <= 17; w++) wall[12 * WIDTH + w] = 0;
	for (int h = 13; h <= 16; h++)	wall[h * WIDTH + 5] = 0;
	for (int h = 13; h <= 18; h++)	wall[h * WIDTH + 12] = 0;
	for (int w = 9; w <= 19; w++) wall[19 * WIDTH + w] = 0;

	/*//show the map
	for (int h = 0; h < HEIGHT;h++) {
		for (int w = 0;w < WIDTH;w++) {

			printf("%d", wall[h][w]);
		}
		printf("\n");
	}*/

	//return wall;//� �������� ��ȯ�ؾ��ϳ�......

}
#if 0

int turn_right(int* position) {




	/*struct position p1;
	int a, b;

	int past_position;
	int present_position = (p1.x, p1.y - 1);*/



}
int turn_left(int* position) {




}


int in_maze(int* position) {

	position;

	return 0;
}
#endif

int show_map(int* wall) {

	//int wall[HEIGHT * WIDTH] = {0, };


	for (int h = 0; h < HEIGHT;h++) {
		for (int w = 0;w < WIDTH;w++) {

			//printf("%d", *wall[w + h * HEIGHT]);
			
			if(wall[h * WIDTH + w] == WALL) printf("��");
			else if (wall[h * WIDTH + w] == WAY) printf("��");
			else if (wall[h * WIDTH + w] == DONTGO1) printf("��");
			else if (wall[h * WIDTH + w] == DONTGO2) printf("��");
			else if (wall[h * WIDTH + w] == ME) printf("��");


			/*
			if (*(wall + h * WIDTH + w) == WALL) printf("��");
			else if ((*(wall + h * WIDTH + w) == WAY)) printf("��");
			else if (*(wall + h * WIDTH + w) == DONTGO1) printf("��");
			else if (*(wall + h * WIDTH + w) == DONTGO2) printf("��");
			else if (*(wall + h * WIDTH + w) == ME) printf("��");*/
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
	//Right Hand on Wall Method

	//int* wall[WIDTH][WIDTH] = { (void*)make_map() };
	//int me = 7;
	


	//make_map(wall);


	//int my_position = p1.x

	//int position = wall[0];


	//printf("%d,          %d", p1.x, p1.y); // �� �ּҰ��� ������

	wall[0] = ME;
	//while (p1.x * p1.y != FINISH) {
	while (1)
	{

		

		system("cls");

		/*static int x = 0;
		static int y = 0;*/

		//int past_x = x;//past�� ME�� ���� ��ǥ
		//int past_y = y;

		int past_x = p1.x;
		int past_y = p1.y;


		//

		position(wall, ME, &p1); //me�� ��ǥ ��ġ�� �޴� position : 11, 1��ǥ�� �� �޾ƿ�

		int x = p1.x;
		int y = p1.y;//���Ӱ� position���� �޾ƿ� p1.x, p1.y �� ���ο� x, y���̰�	
						//������ x, y ���� �����ϰ������

		


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

			

			if (wall[(x) + y * WIDTH] == DONTGO1)
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

				if ((wall[x - 1 + (y) * (WIDTH)] != WALL) && (wall[x - 1 + (y) * (WIDTH)] < DONTGO3)) // �������� ���� 
				{
					
					//wall[x + y * (WIDTH)] = DONTGO1;
					printf("hi");


					/*if (wall[past_x + past_y * WIDTH] != WAY)
					{
						wall[x + y * WIDTH] = DONTGO2;
						printf("%d\n", __LINE__);

					}*/
					
					

					// if(x + y * WIDTH == WAY)
					//{
					wall[x + y * (WIDTH)] = DONTGO1; //wall[76] = 5 -> 7
					printf("%d\n", __LINE__);

					//}


					wall[x - 1 + (y) * (WIDTH)] = ME;
					printf("%d\n", __LINE__);


				}

				else //�������� ����.
				{

					if ((wall[x + (y - 1) * (WIDTH)] != WALL)) //  && (wall[x + (y - 1) * (WIDTH)] < DONTGO3)�������� ����
					{
						

						/*if (wall[past_x + past_y * WIDTH] >= DONTGhO1)
						{
							wall[x + y * (WIDTH)] = DONTGO2;
						}*/


						//else// if(x + y * WIDTH == WAY)
						//{
						wall[x + y * (WIDTH)] = DONTGO1;

						//}
						
						wall[(x)+(y - 1) * (WIDTH)] = ME;


					}
					
				}


				//if ((x != 0) && ((wall[(x - 1) + y * (WIDTH)] == WALL) || (wall[(x - 1) + y * (WIDTH)] >= DONTGO1)))//���� = �� -> ����
				//{
				//	wall[(x)+(y - 1) * (WIDTH)] = ME;

				//	if ((x)+y * WIDTH == DONTGO1)
				//	{
				//		wall[x + y * (WIDTH)] = DONTGO2;
				//	}

				//	else
				//	{
				//		wall[x + y * (WIDTH)] = DONTGO1;

				//	}


				//}
				//else //�� != �� -> ��������
				//{
				//	wall[(x - 1) + y * (WIDTH)] = ME;

				//	if ((x)+y * WIDTH == DONTGO1)
				//	{
				//		wall[x + y * (WIDTH)] = DONTGO2;
				//	}

				//	else
				//	{
				//		wall[x + y * (WIDTH)] = DONTGO1;

				//	}

				//}


			}

			//wall[x + y * (WIDTH)] = DONTGO1;

		}




		//else if ( (x != 0) && (wall[(x + 1) + y * (WIDTH)] == WALL) ||((wall[(x + 1) + y * (WIDTH)] == DONTGO2)) && (wall[x + (y + 1) * (WIDTH)] == WALL))//�� = �� && �� = �� ��������
		//{
		//	wall[(x - 1) + y * (WIDTH)] = me;
		//	
		//	
		//	//�������� ����̴�.
		//	// ���� ���� ���� ����. 	
		//	
		//}







		//else if(y != 0){//����
		//	wall[x + (y - 1) * WIDTH] = me;
		//}





		//if (((y != 0) && (wall[(x + 1) + y * (WIDTH)] == WALL) && (wall[x + (y + 1) * (WIDTH)] == WALL) && (wall[x + (y - 1) * (WIDTH)] == WALL)) ||//���Ͽ�
		//	((x != 0) && (wall[(x - 1) + y * (WIDTH)] == WALL) && (wall[x + (y + 1) * (WIDTH)] == WALL) && (wall[x + (y - 1) * (WIDTH)] == WALL)) ||//������
		//	((y != 0) && (wall[(x + 1) + y * (WIDTH)] == WALL) && (wall[x - 1 + (y) * (WIDTH)] == WALL) && (wall[x + (y - 1) * (WIDTH)] == WALL)) ||//���¿�
		//	((x != 0) && (wall[(x + 1) + y * (WIDTH)] == WALL) && (wall[x + (y + 1) * (WIDTH)] == WALL) && (wall[x - 1 + (y) * (WIDTH)] == WALL)))//���¿�  = �� DONTGO2�� ǥ��
		//{

		//	wall[(x)+y * (WIDTH)] = DONTGO2;
		//	//	wall[(x - 1) + y * WIDTH] = me;
		//	//	wall[(x + 1) + y * WIDTH] = me;
		//	//	wall[(x) + (y + 1) * WIDTH] = me;
		//	//	wall[(x) + (y - 1) * WIDTH] = me;


		//}
		//3���� ���϶�
		//if ((y != 0) && (wall[(x + 1) + y * (WIDTH)] == WALL) && (wall[x + (y + 1) * (WIDTH)] == WALL) && (wall[x + (y - 1) * (WIDTH)] == WALL))//���Ͽ�
		//{
		//	wall[(x)+y * (WIDTH)] = DONTGO2;
		//	wall[(x - 1) + y * WIDTH] = ME;
		//}

		//else if ((x != 0) && (wall[(x - 1) + y * (WIDTH)] == WALL) && (wall[x + (y + 1) * (WIDTH)] == WALL) && (wall[x + (y - 1) * (WIDTH)] == WALL))//������
		//{
		//	wall[(x)+y * (WIDTH)] = DONTGO2;
		//	wall[(x + 1) + y * WIDTH] = ME;
		//}
		//
		//// 
		//else if ((x != 0) && (wall[(x - 1) + y * (WIDTH)] == WALL) && (wall[x + (y + 1) * (WIDTH)] == WALL) && (wall[x + (y - 1) * (WIDTH)] == WALL))//���¿�
		//{
		//	wall[(x)+y * (WIDTH)] = DONTGO2;
		//	wall[(x)+(y + 1) * WIDTH] = ME;
		//}

		//else if ((x != 0) && (wall[(x + 1) + y * (WIDTH)] == WALL) && (wall[x + (y + 1) * (WIDTH)] == WALL) && (wall[x - 1 + (y) * (WIDTH)] == WALL))//���¿�  = �� DONTGO2�� ǥ��
		//{
		//	wall[(x)+y * (WIDTH)] = DONTGO2;
		//	wall[(x)+(y - 1) * WIDTH] = ME;
		//}

		

		Sleep(50);

	}






	//return 0;


}



	/*printf("%d", p1);
	while (x * y != FINISH) {

		make_map(wall);
		//wall[k] = position;
		system("cls");



		//wall[(x++)] = me;









		show_map(wall);

		Sleep(500);//0.5s delay



	int k = 0;

	while (k < 3) {
		make_map(wall);
		system("cls");


		wall[k++] = me;


		show_map(wall);

		Sleep(500);
	}
	}*/







	//printf("%d ", *(wall + (WIDTH-1)*(HEIGHT-1)));





	/*�켱�� �˰���

		turn right()
		if (wall[me] == 1)
			turn left
	`	go straight()
	*/




	//printf("\n%d", wall[1][1]);
	// 
	//�����̴� �� ǥ��

	//show_map();
	//position = me;
	//int past_position = wall[0][0];
	//int next_position ;
	// 0.5s���� �� ĭ�� �������� Ż���ϵ���(�������� �������� Ż���ϵ���
	/*
	while (position != wall[HEIGHT - 1][WIDTH - 1]) {

		int wall_ahead = (position == 1);
		//�켱�� �˰���
		turn_right();
		while (wall_ahead) {
			turn_left();
		}
		go_forward();




		Sleep(500); //0.5s ������




	}

	*/

