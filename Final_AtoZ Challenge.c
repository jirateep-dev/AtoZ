#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

void ClearConsoleToColors(int ForgC, int BackC);
void gotoxy(int x, int y);
void wait( int sec );
void load();
void play_state();
void character(char num);
void number_in(char num,int x,int y);
void right();
void left();
void Read_file(char*dir, char*type, int x, int y);


//Read_file("right.txt","r",49,9);
//Read_file("left.txt","r",23,9);

int main()
{
    ClearConsoleToColors(11, 16);
    load();
    play_state();
    /*Read_file("time spent.txt","r",31,5);
    Read_file("number.txt","r",17,11);*/

    getch();

}

void number_in(char num,int x,int y)
{
    char c;
    char *cha[27] = {'0','1','2','3','4','5','6','7','8','9'};
    int count = 0;
    FILE *info;
    info=fopen("number.txt","r");
    while(cha[count]!=num){
        count++;
    }
    while(1){
        c=getc(info);
        if(c==cha[count])
        {
            do{
                c=getc(info);
                if(c!=cha[count+1] ){
                    printf("%c",c);
                    if(c=='\n'){
                        y++;
                        gotoxy(x,y);
                    }
                }
            }while(c!=cha[count+1] && c!=EOF);
            break;
        }
    }
    fclose(info);
}

void character(char num)
{
    char c;
    char *cha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l'\
    ,'m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int count = 0,index=7;
    FILE *info;
    info=fopen("chars.txt","r");
    while(cha[count]!=num){
        count++;
    }
    while(1){
        c=getc(info);
        if(c==cha[count])
        {
            do{
                c=getc(info);
                if(c!=cha[count+1]){
                    printf("%c",c);
                    if(c=='\n'){
                        index++;
                        gotoxy(34,index);
                    }
                }
            }while(c!=cha[count+1] && c!=EOF);
            break;
        }
    }
    fclose(info);
}

void play_state()
{
    home:
    system("cls");
    int i,j,k,check=50,sec=10,index_cha=0,index_t=7;
    int r1=42,r2=30;
    float count = 0.0;

    j=sec;
    char *cha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l'\
    ,'m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char time_s[5],keep[5];
    strcpy(keep,"0");
    int key = 0;

    gotoxy(24,12);  printf("Please press your keyboard : A to Z");
    gotoxy(17,13);  printf("If you are ready press your keyboard : <spacebar>");

    while(1)
    {
        if (_kbhit())
        {
            key =_getch();

            if (key == ' '){
                system("cls");
                break;}
        }
    }

    clock_t begin, end;
    double time_spent;

    begin = clock();

    character(cha[index_cha]);

     while(1){
        gotoxy(17,20);  printf("If you want to restart put your keyboard : <spacebar>");
        if (_kbhit())
        {
            gotoxy(17,20);  printf("If you want to restart put your keyboard : <spacebar>");
            key =_getch();
            if (key == ' '){
                goto home;
                break;}

            if (key == cha[index_cha]){
                character(cha[index_cha]);
                Beep(400, 50);

                for(i=1;i<=7;i++){
                    system("cls");
                    Read_file("right.txt","r",r1+i,9);
                    Read_file("left.txt","r",r2-i,9);
                    gotoxy(17,20);  printf("If you want to restart put your keyboard : <spacebar>");
                }
                if(key == 'z')
                    break;

                index_cha++;
                system("cls");
                character(cha[index_cha]);
                }
            else
                character(cha[index_cha]);
                gotoxy(17,20);  printf("If you want to restart put your keyboard : <spacebar>");

        }

     }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    system("cls");

//----------------------------End Play ------------------------------
    printf("Time : %.2f",time_spent);
    sprintf(time_s,"%.2f",time_spent);
    if(time_spent < 10)
        strcat(keep,time_s);
    else
        strcpy(keep,time_s);
    int indextx = 17;

    Read_file("time spent.txt","r",31,5);
    for(i=0;i<2;i++){
        if(keep[i] >= 48 && keep[i] <= 57){
            number_in(keep[i],indextx,11);
            indextx += 10;
        }
    }

    Read_file("symbol.txt","r",indextx,11);
    indextx+=10;
    for(i=2;i<5;i++){
        if(keep[i] >= 48 && keep[i] <= 57){
            number_in(keep[i],indextx,11);
            indextx += 10;
        }
    }




}
void Read_file(char* dir, char*type, int x, int y)
{
    char c;
    gotoxy(x,y);
    FILE *info;
    info=fopen(dir,type);
    do{
        putchar(c=getc(info));
        if(c=='\n'){
            y++;
            gotoxy(x,y);
        }
    }while(c!=EOF);
    fclose(info);
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD coord = {0, 0};
     DWORD count;

     CONSOLE_SCREEN_BUFFER_INFO csbi;

     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}


void gotoxy(int x, int y){
    COORD coord = {0,0};
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void wait( int sec )
{
     clock_t end_wait;
     end_wait = clock() + sec * CLK_TCK;
     while (clock() < end_wait){}
}



void load(){
    int r,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    	for(q=0;q<=20000000;q++);
    		printf("%c",178);
    }
}
