#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  //加上日期和时间头文件
#include <windows.h>
#pragma comment(lib,"winmm.lib" )  //导入声音头文件库
#include <mmsystem.h>  //导入声音头文件

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
        printf("\n\t\t********欢迎进入歌曲点播系统********\n\n");
        printf("\t\t\t1.雪绒花\n");
        printf("\t\t\t2.小星星\n");
        printf("\t\t\t3.HAPPY BIRTHDAY\n");
        printf("\t\t\t0.退出系统\n");
        printf("\n\n\t\t************************************");
        printf("\n请选择(0－3)\n");
        scanf("%d",&sel);
        switch(sel){
            case 1:xueronghua();break;
            case 2:xiaoxingxing();break;
            case 3:happybirthday();break;
            case 0:exit(1);
        }
    }while(1);
}

void xueronghua(void)   /*雪绒花曲谱*/
{
     char *jp="iddgwwwqqgfffddddfghhhggg ddgwwwqqgfffddgghjqqqqqwpggjhgddgqqq hhqwwqjjjgggddgwwwqqgfffddgghjqqqqqq";
     speed=2;
     t=4*speed;
     //gotoxy(40,20);
     printf("\t\t\n请欣赏歌曲：雪绒花");
     printf("\n\t\t\t雪绒花,雪绒花，清晨迎着我开放。");
     printf("\n\t\t\t小而白，洁而亮，向我快乐的摇晃。");
     printf("\n\t\t\t白雪般的花儿，愿你芬芳，永远开花生长。");
     printf("\n\t\t\t雪绒花，雪绒花，永远祝福我家乡。\n");
     display(jp);
     printf("雪绒花欣赏完毕");
     printf("按任意键返回主菜单");
     getch();
     menu();
}

void xiaoxingxing(void)    /*小星星曲谱*/
{
     char *jp="oaagghhggffddssaaggffddssggffddssaagghhggffddssaaaagghhggffddssaaggffddssggffddssaagghhggffddssaa";
     speed=2;
     t=4*speed;
     //gotoxy(40,20);
     cprintf("请欣赏歌曲：小星星");
     printf("\n\t\t\t一闪一闪亮晶晶，满天都是小星星，");
     printf("\n\t\t\t挂在天空放光明，好象千万小眼睛。");
     printf("\n\t\t\t太阳慢慢向西沉，乌鸦回家一群群，");
     printf("\n\t\t\t星星眨着小眼睛，闪闪烁烁到天明。\n");
     display(jp);
     cprintf("小星星欣赏完毕");
     cprintf("按任意键返回主菜单");
     getch();
     menu();
}

void happybirthday(void)  /*生日快乐曲谱*/
{
     char*jp="ippppbbnnbbaammmmbbnnbbssaaaabbggddaammmhfddaassaaappp";
     speed=1;
     t=4*speed;
    // gotoxy(40,20);
     cprintf("请欣赏歌曲：HAPPY BIRTHDAY");
     printf("\n\t\t\tHAAPY BIRTHDAY TO YOU,");
     printf("\n\t\t\tHAAPY BIRTHDAY TO YOU,");
     printf("\n\t\t\tHAAPY BIRTHDAY TO YOU,");
     printf("\n\t\t\tHAAPY BIRTHDAY TO YOU.\n");
     display(jp);
    // gotoxy(40,20);
     cprintf("HAPPY BIRTHDAY欣赏完毕");
     cprintf("按任意键返回主菜单");
     getch();
     menu();
}

void display(char *qm)  /*演奏功能*/
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

void sound1(int freq,int t)  /*发声函数*/
{
     int n;
     Beep(freq,500);
     n=t+clock();
     while(n>clock());
     Beep(0,0);
}

void pause(int t)      /*暂停函数*/
{
    int n;
    n=t+clock();
    while(n>clock())
    Beep(0,0);
}