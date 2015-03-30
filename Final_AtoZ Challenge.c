#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

void ClearConsoleToColors(int ForgC, int BackC);
void gotoxy(int x, int y);
void wait( int sec );
void load();
void play_gate_time();
void character(char num);
void right();
void left();
void Read_file(char*dir, char*type, int x, int y);

//Read_file("right.txt","r",49,9);
//Read_file("left.txt","r",23,9);

int main()
{
    //ClearConsoleToColors(17, 15);
   // load();
    play_gate_time();

/*
    system("cls");
    char a;
    printf("Please put character : ");
    scanf("%c",&a);
    character(a);*/


    getch();

}
void character(char num)
{
    char c,l,r;
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

void play_gate_time()
{
    system("cls");
    int i,j,k,check=50,sec=10,index_cha=0,index_t=7;
    j=sec;
    char *cha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l'\
    ,'m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int key = 0;
    gotoxy(19,25);  printf("Please put your keyboard : A to Z");
    gotoxy(20,25);  printf("Please put your keyboard : <spacebar>");
    gotoxy(5,3);    printf("Time : ");
    gotoxy(12,3);   printf("%.2d",sec);
    gotoxy(16,3);

    //500000000

/*
    for(i=1;i<=10;i++){
    	for(j=0;j<=500000000;j++);{
            for(k=0;k<=5;k++)
                printf("%c",178);
    	}
    }*/


    for(j=0;j<=check;j++){
        printf("%c",177);
    }

    while(1)
    {
        if (_kbhit())
        {
            key =_getch();

            if (key == ' '){
                break;}
        }
    }
    //system("cls");

    character(cha[index_cha]);
    int r1=42,r2=30;
    while(1){

        if (_kbhit())
        {
            key =_getch();
            system("cls");
            if (key == cha[index_cha]){
                character(cha[index_cha]);

                for(i=1;i<=15;i++){
                    system("cls");
                    Read_file("right.txt","r",r1+i,9);
                    Read_file("left.txt","r",r2-i,9);
                    wait(0.9);
                }


                index_cha++;
                system("cls");
                character(cha[index_cha]);}
            else
                character(cha[index_cha]);
        }
    }

/*
    while(1){
        system("cls");

        if(sec <= 0){
            system("cls");
            Read_file("time_out.txt","r",2,9);
            break;}

        gotoxy(9,3);    printf("Time : ");
        gotoxy(16,3);   printf("%.2d",sec);
        gotoxy(20,3);
        for(j=0;j<=check;j++){
            printf("%c",177);
        }
        sec--;  check-=5;
        wait(1);
    }*/
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
