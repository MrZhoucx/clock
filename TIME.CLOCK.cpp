#include<graphics.h>
#include<Windows.h>
#include<ctime>
#include <iostream>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
int main() {
	initgraph(600, 400);
	setbkmode(OPAQUE);
	loadimage(NULL, _T("D:\\B.png"));
	while (TRUE)
	{
		loadimage(NULL, _T("D:\\B.png"));
		/*��ȡ����*/
		time_t timer;
		time(&timer);
		tm* t_tm = localtime(&timer);
		/*��������*/
		int year = t_tm->tm_year + 1900;//��
		int month = t_tm->tm_mon + 1;//��
		int day = t_tm->tm_mday;//��
		int hour = t_tm->tm_hour;//ʱ
		int minute = t_tm->tm_min;//��
		int second = t_tm->tm_sec;//��
		int wday = t_tm->tm_wday;//����
		/*���ӹ���*/
		if (hour == 8&& minute >= 00)
			mciSendString(TEXT("play D://���֮��.mp3 repeat"), 0, 0, 0);
		if(hour==8&&minute>=10)
			mciSendString(TEXT("close D://���֮��.mp3"), 0, 0, 0);
		/*ת����ʽ*/
		char shi[4];
		char fen[4];
		char miao[4];
		char nian[4];
		char yue[4];
		char ri[4];
		char xingqi[4];
		if (hour < 10)
		{
			switch (hour)
			{
			case 0:strcpy(shi, "00");break;
			case 1:strcpy(shi, "01");break;
			case 2:strcpy(shi, "02");break;
			case 3:strcpy(shi, "03");break;
			case 4:strcpy(shi, "04");break;
			case 5:strcpy(shi, "05");break;
			case 6:strcpy(shi, "06");break;
			case 7:strcpy(shi, "07");break;
			case 8:strcpy(shi, "08");break;
			case 9:strcpy(shi, "09");break;
			default:
				break;
			}
		}
		else
			sprintf(shi, "%d", hour);
		if (minute < 10)
		{
			switch (minute)
			{
			case 0:strcpy(fen, "00");break;
			case 1:strcpy(fen, "01");break;
			case 2:strcpy(fen, "02");break;
			case 3:strcpy(fen, "03");break;
			case 4:strcpy(fen, "04");break;
			case 5:strcpy(fen, "05");break;
			case 6:strcpy(fen, "06");break;
			case 7:strcpy(fen, "07");break;
			case 8:strcpy(fen, "08");break;
			case 9:strcpy(fen, "09");break;
			default:
				break;
			}
		}
		else
			sprintf(fen, "%d", minute);
		if (second < 10)
		{
			switch (second)
			{
			case 0:strcpy(miao, "00");break;
			case 1:strcpy(miao, "01");break;
			case 2:strcpy(miao, "02");break;
			case 3:strcpy(miao, "03");break;
			case 4:strcpy(miao, "04");break;
			case 5:strcpy(miao, "05");break;
			case 6:strcpy(miao, "06");break;
			case 7:strcpy(miao, "07");break;
			case 8:strcpy(miao, "08");break;
			case 9:strcpy(miao, "09");break;
			default:
				break;
			}
		}
		else
			sprintf(miao, "%d", second);
		if (month < 10)
		{
			switch (month)
			{
			case 1:strcpy(yue, "01");break;
			case 2:strcpy(yue, "02");break;
			case 3:strcpy(yue, "03");break;
			case 4:strcpy(yue, "04");break;
			case 5:strcpy(yue, "05");break;
			case 6:strcpy(yue, "06");break;
			case 7:strcpy(yue, "07");break;
			case 8:strcpy(yue, "08");break;
			case 9:strcpy(yue, "09");break;
			default:
				break;
			}
		}
		else
			sprintf(yue, "%d", month);
		if (day < 10)
		{
			switch (day)
			{
			case 1:strcpy(ri, "01");break;
			case 2:strcpy(ri, "02");break;
			case 3:strcpy(ri, "03");break;
			case 4:strcpy(ri, "04");break;
			case 5:strcpy(ri, "05");break;
			case 6:strcpy(ri, "06");break;
			case 7:strcpy(ri, "07");break;
			case 8:strcpy(ri, "08");break;
			case 9:strcpy(ri, "09");break;
			default:
				break;
			}
		}
		else
			sprintf(ri, "%d", day);
		sprintf(nian, "%d", year);
		sprintf(xingqi, "%d", wday);
		/*����*/
		settextstyle(45, 0, _T("΢���ź�"));
		outtextxy(75, 100, nian);
		outtextxy(220, 100, yue);
		outtextxy(315, 100, ri);
		outtextxy(500, 100, xingqi);
		outtextxy(170, 100, "��");
		outtextxy(272, 100, "��");
		outtextxy(363, 100, "��");
		outtextxy(415, 100, "����:");
		/*ʱ��*/
		settextstyle(100, 0, _T("΢���ź�"));
		outtextxy(100, 160, shi);
		outtextxy(245, 160, fen);
		outtextxy(400, 160, miao);
		outtextxy(210, 155, ":");
		outtextxy(355, 155, ":");
		Sleep(500);
	}
	system("pause");
	closegraph();
	return 0;
}