#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  //�������ں�ʱ��ͷ�ļ�
#include <windows.h>
#pragma comment(lib,"winmm.lib" )  //��������ͷ�ļ���
#include <mmsystem.h>  //��������ͷ�ļ�

int speed=1,t;

void menu(void);
void sound1(int freq,int t);
void pause(int t);
void xueronghua(void);
void xiaoxingxing(void);
void happybirthday(void);
void display(char *qm);

int main(void)
{
    menu(); 
    return 0;
}




void menu(void)
{
    int sel;
    do{
        system("cls");
        printf("\n\t\t********��ӭ��������㲥ϵͳ********\n\n");
        printf("\t\t\t1.ѩ�޻�\n");
        printf("\t\t\t2.С����\n");
        printf("\t\t\t3.HAPPY BIRTHDAY\n");
        printf("\t\t\t0.�˳�ϵͳ\n");
        printf("\n\n\t\t************************************");
        printf("\n��ѡ��(0��3)\n");
        scanf("%d",&sel);
        switch(sel){
            case 1:xueronghua();break;
            case 2:xiaoxingxing();break;
            case 3:happybirthday();break;
            case 0:exit(1);
        }
    }while(1);
}

void xueronghua(void)   /*ѩ�޻�����*/
{
     char *jp="iddgwwwqqgfffddddfghhhggg ddgwwwqqgfffddgghjqqqqqwpggjhgddgqqq hhqwwqjjjgggddgwwwqqgfffddgghjqqqqqq";
     speed=2;
     t=4*speed;
     //gotoxy(40,20);
     printf("\t\t\n�����͸�����ѩ�޻�");
     printf("\n\t\t\tѩ�޻�,ѩ�޻����峿ӭ���ҿ��š�");
     printf("\n\t\t\tС���ף�����������ҿ��ֵ�ҡ�Ρ�");
     printf("\n\t\t\t��ѩ��Ļ�����Ը��ҷ�����Զ����������");
     printf("\n\t\t\tѩ�޻���ѩ�޻�����Զף���Ҽ��硣\n");
     display(jp);
     printf("ѩ�޻��������");
     printf("��������������˵�");
     getch();
     menu();
}

void xiaoxingxing(void)    /*С��������*/
{
     char *jp="oaagghhggffddssaaggffddssggffddssaagghhggffddssaaaagghhggffddssaaggffddssggffddssaagghhggffddssaa";
     speed=2;
     t=4*speed;
     //gotoxy(40,20);
     cprintf("�����͸�����С����");
     printf("\n\t\t\tһ��һ�������������춼��С���ǣ�");
     printf("\n\t\t\t������շŹ���������ǧ��С�۾���");
     printf("\n\t\t\t̫����������������ѻ�ؼ�һȺȺ��");
     printf("\n\t\t\t����գ��С�۾�������˸˸��������\n");
     display(jp);
     cprintf("С�����������");
     cprintf("��������������˵�");
     getch();
     menu();
}

void happybirthday(void)  /*���տ�������*/
{
     char*jp="ippppbbnnbbaammmmbbnnbbssaaaabbggddaammmhfddaassaaappp";
     speed=1;
     t=4*speed;
    // gotoxy(40,20);
     cprintf("�����͸�����HAPPY BIRTHDAY");
     printf("\n\t\t\tHAAPY BIRTHDAY TO YOU,");
     printf("\n\t\t\tHAAPY BIRTHDAY TO YOU,");
     printf("\n\t\t\tHAAPY BIRTHDAY TO YOU,");
     printf("\n\t\t\tHAAPY BIRTHDAY TO YOU.\n");
     display(jp);
    // gotoxy(40,20);
     cprintf("HAPPY BIRTHDAY�������");
     cprintf("��������������˵�");
     getch();
     menu();
}

void display(char *qm)  /*���๦��*/
{
    int i,freq;
    while(*qm++!='\0'){
          i=1;
          switch(*qm){
                case 'k':  t=1*speed; i=0; break;
                case 'l':  t=2*speed; i=0; break;
                case 'i':  t=4*speed; i=0; break;
                case 'o':  t=6*speed; i=0; break;
                case 'p':  pause(t);  i=0; break;
                case 'a':  freq=523; break;
                case 's':  freq=587; break;
                case 'd':  freq=659; break;
                case 'f':  freq=698; break;
                case 'g':  freq=784; break;
                case 'h':  freq=880; break;
                case 'j':  freq=988; break;
                case 'z':  freq=262; break;
                case 'x':  freq=294; break;
                case 'c':  freq=330; break;
                case 'v':  freq=349; break;
                case 'b':  freq=392; break;
                case 'n':  freq=440; break;
                case 'm':  freq=494; break;
                case 'q':   freq=1047; break;
                case 'w':  freq=1175; break;
                case 'e':   freq=1319; break;
                case 'r':   freq=1397; break;
                case 't':   freq=2568; break;
                case 'y':   freq=1760; break;
                case 'u':   freq=1976; break;
                default:   i=0; break;
            }
            if(i)
                sound1(freq,t);
    }
}

void sound1(int freq,int t)  /*��������*/
{
     int n;
     Beep(freq,500);
     n=t+clock();
     while(n>clock());
     Beep(0,0);
}

void pause(int t)      /*��ͣ����*/
{
    int n;
    n=t+clock();
    while(n>clock())
    Beep(0,0);
}