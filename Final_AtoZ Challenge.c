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

int i,j,k,l,key,num_c=97,num_i=48;
char cha[27],cha_n[11],c;

//windowfunction
void casewindow();
void background();
void window();
void play_stage1();
void play_stage2to4(int stage);
void ClearConsoleToColors(int ForgC, int BackC);
void textcolor(int color);
void record(char*dir,double time_spent);
void gotoxy(int x, int y);
void wait( int sec );
void wait_key(int choose);

//processfunction
void arrow(int point,int mode);
void move(int point,int count,int mode);
void stage();
void besttime();
void help();
void square(int startx,int endx,int starty,int endy,int position);
const char*random_cha(char*dir);
void Read_file(char*dir, int x, int y);
void Read_file2(char*dir,const char *pointer,char character, int x, int y);
void time_spented(char*dir, double time_spent);
void show_word(char*dir,const char*word,int index_x,int index_y,int px,int py);  // px = position x / py = position y
void character(char num);
void number_in(char num,int x,int y);
void right();
void left();
void load();
void load2(int position1, int position2);


int main()
{
    for(i=0;i<=25;i++){
        cha[i] = num_c;
        num_c++;
    }
    for(i=0;i<=9;i++){
        cha_n[i] = num_i;
        num_i++;
    }

    window();

    getch();

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Part of Stage ++++++++++++++++++++++++++++++++++++++++++++++++++++++
void play_stage1()
{
    load2(0,76);
    ClearConsoleToColors(11, 16);
    home:
    system("cls");
    int index_cha=0;
    int r1=42,r2=30;


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

    //character(cha[index_cha]);
    Read_file2("chars.txt",cha,cha[index_cha],34,7);

     while(1){
        gotoxy(17,20);  printf("If you want to restart press your keyboard : <spacebar>");
        if (_kbhit())
        {
            gotoxy(17,20);  printf("If you want to restart press your keyboard : <spacebar>");
            key =_getch();
            if (key == ' '){
                goto home;
                break;}

            if (key == cha[index_cha]){
                Read_file2("chars.txt",cha,cha[index_cha],34,7);

                Beep(400, 50);

                for(i=1;i<=5;i++){
                    system("cls");
                    Read_file2("LR_UD.txt",cha_n,'2',r1+i,9);
                    Read_file2("LR_UD.txt",cha_n,'1',r2-i,9);
                    gotoxy(17,20);  printf("If you want to restart press your keyboard : <spacebar>");
                }
                if(key == 'z')
                    break;

                index_cha++;
                system("cls");
                Read_file2("chars.txt",cha,cha[index_cha],34,7);

                }
            else
                Read_file2("chars.txt",cha,cha[index_cha],34,7);
                gotoxy(17,20);  printf("If you want to restart press your keyboard : <spacebar>");

        }

     }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    system("cls");

//----------------------------End Play ------------------------------
    printf("Time(s) : %.2f",time_spent);
    time_spented("record_stage1.txt",time_spent);

}

void stage2()
{

    ClearConsoleToColors(12, 16);
    char word[100];

    for(i=0;i<=9;i++){
        int check=0;
        int r1=8,r2=8;
        system("cls");
        strcpy(word,random_cha("2words.txt"));
        textcolor(12);
        Read_file2("chars.txt",cha,word[0], 28, 8);
        Read_file2("chars.txt",cha,word[1], 42, 8);
        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");

        while(1)
        {
            if (_kbhit())
            {
                key =_getch();
                if(key == ' '){
                    play_stage2to4(2);
                    break;
                }

                if (key == word[0] && check==0){
                    Beep(400, 50);
                    for(j=1;j<=7;j++){
                        system("cls");
                        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                        Read_file2("chars.txt",cha,word[1], 42, 8);
                        Read_file2("LR_UD.txt",cha_n,'3',28,r1-j);
                        Read_file2("LR_UD.txt",cha_n,'4',28,r2+j);


                    }
                    system("cls");
                    gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                    textcolor(14);
                    Read_file2("ans_character.txt",cha,word[0], 28, 8);
                    textcolor(12);
                    Read_file2("chars.txt",cha,word[1], 42, 8);
                    check++;}
                else if (key == word[1] && check==1){
                    Beep(400, 50);
                    for(j=1;j<=7;j++){
                        system("cls");
                        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                        Read_file2("LR_UD.txt",cha_n,'3',42,r1-j);
                        Read_file2("LR_UD.txt",cha_n,'4',42,r2+j);

                    }
                    system("cls");
                    gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                    textcolor(14);
                    Read_file2("ans_character.txt",cha,word[0], 28, 8);
                    Read_file2("ans_character.txt",cha,word[1], 42, 8);
                   // wait(1);
                    break;
                }
            }
        }
    }

}

void stage3()
{


    ClearConsoleToColors(2, 16);
    char word[100];

    for(i=0;i<=9;i++){
        int check=0;
        int r1=8,r2=8;
        system("cls");
        strcpy(word,random_cha("3words.txt"));
        textcolor(2);
        show_word("chars.txt",word,0,2,21,8);
        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");

        while(1)
        {
            if (_kbhit())
            {
                key =_getch();
                if(key == ' '){
                    play_stage2to4(3);
                    break;
                }

                if (key == word[0] && check==0){
                    Beep(400, 50);
                    for(j=1;j<=7;j++){
                        system("cls");
                        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                        Read_file2("LR_UD.txt",cha_n,'3',21,r1-j);
                        Read_file2("LR_UD.txt",cha_n,'4',21,r2+j);


                    }
                    system("cls");
                    gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                    textcolor(10);
                    Read_file2("ans_character.txt",cha,word[0], 21, 8);
                    textcolor(2);
                    show_word("chars.txt",word,1,2,35,8);
                    check++;}
                else if (key == word[1] && check==1){
                    Beep(400, 50);
                    for(j=1;j<=7;j++){
                        system("cls");
                        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                        Read_file2("LR_UD.txt",cha_n,'3',35,r1-j);
                        Read_file2("LR_UD.txt",cha_n,'4',35,r2+j);

                    }
                    system("cls");
                    gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                    textcolor(10);
                    show_word("ans_character.txt",word,0,1,21,8);
                    textcolor(2);
                    Read_file2("chars.txt",cha,word[2],49,8);

                    check++;
                }
                else if (key == word[2] && check==2){
                    Beep(400, 50);
                    for(j=1;j<=7;j++){
                        system("cls");
                        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                        Read_file2("LR_UD.txt",cha_n,'3',49,r1-j);
                        Read_file2("LR_UD.txt",cha_n,'4',49,r2+j);

                    }
                    system("cls");
                    gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                    textcolor(10);
                    show_word("ans_character.txt",word,0,2,21,8);
                    //wait(1);
                    break;
                }
            }
        }
    }


}

void stage4()
{


    ClearConsoleToColors(5, 16);
    char word[100];

    for(i=0;i<=9;i++){
        int check=0;
        int r1=8,r2=8;
        system("cls");
        strcpy(word,random_cha("4words.txt"));
        textcolor(5);
        show_word("chars.txt",word,0,3,14,8);
        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");

        while(1)
        {
            if (_kbhit())
            {
                key =_getch();
                if(key == ' '){
                    play_stage2to4(4);
                    break;
                }

                if (key == word[0] && check==0){
                    Beep(400, 50);
                    for(j=1;j<=7;j++){
                        system("cls");
                        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                        Read_file2("LR_UD.txt",cha_n,'3',14,r1-j);
                        Read_file2("LR_UD.txt",cha_n,'4',14,r2+j);


                    }
                    system("cls");
                    gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                    textcolor(13);
                    Read_file2("ans_character.txt",cha,word[0], 14, 8);
                    textcolor(5);
                    show_word("chars.txt",word,1,3,28,8);
                    check++;}
                else if (key == word[1] && check==1){
                    Beep(400, 50);
                    for(j=1;j<=7;j++){
                        system("cls");
                        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                        Read_file2("LR_UD.txt",cha_n,'3',28,r1-j);
                        Read_file2("LR_UD.txt",cha_n,'4',28,r2+j);

                    }
                    system("cls");
                    gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                    textcolor(13);
                    show_word("ans_character.txt",word,0,1,14,8);
                    textcolor(5);
                    show_word("chars.txt",word,2,3,42,8);

                    check++;
                }
                else if (key == word[2] && check==2){
                    Beep(400, 50);
                    for(j=1;j<=7;j++){
                        system("cls");
                        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                        Read_file2("LR_UD.txt",cha_n,'3',42,r1-j);
                        Read_file2("LR_UD.txt",cha_n,'4',42,r2+j);

                    }
                    system("cls");
                    gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                    textcolor(13);
                    show_word("ans_character.txt",word,0,2,14,8);
                    textcolor(5);
                    Read_file2("chars.txt",cha,word[3],56,8);

                    check++;
                }
                else if (key == word[3] && check==3){
                    Beep(400, 50);
                    for(j=1;j<=7;j++){
                        system("cls");
                        gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                        Read_file2("LR_UD.txt",cha_n,'3',56,r1-j);
                        Read_file2("LR_UD.txt",cha_n,'4',56,r2+j);

                    }
                    system("cls");
                    gotoxy(14,0);  printf("If you want to restart press your keyboard : <spacebar>");
                    textcolor(13);
                    show_word("ans_character.txt",word,0,3,14,8);
                   // wait(1);
                    break;
                }
            }
        }
    }

}

void play_stage2to4(int stage) // stage must has value 2-4
{
    ClearConsoleToColors(14, 16);
    home:
    system("cls");


    gotoxy(24,12);  printf("Please press your keyboard follow word");
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

    //gotoxy(17,20);  printf("If you want to restart put your keyboard : <spacebar>");

    //Function Here

    switch(stage)
    {
        case 2:     stage2();     break;
        case 3:     stage3();     break;
        case 4:     stage4();     break;

    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    system("cls");

//----------------------------End Play ------------------------------
    printf("Time(s) : %.2f",time_spent);

    switch(stage)
    {
        case 2:     time_spented("record_stage2.txt",time_spent);     break;
        case 3:     time_spented("record_stage3.txt",time_spent);     break;
        case 4:     time_spented("record_stage4.txt",time_spent);     break;

    }



}


void time_spented(char*dir, double time_spent)
{
    int i;
    char time_s[5],keep[5];
    strcpy(keep,"0");
    sprintf(time_s,"%.2f",time_spent);
    if(time_spent < 10)
        strcat(keep,time_s);
    else
        strcpy(keep,time_s);

    Read_file("time spent.txt",24,5);

    if(time_spent <= 100){
        int indextx = 17;
        for(i=0;i<2;i++){
            if(keep[i] >= 48 && keep[i] <= 57){
                //number_in(keep[i],indextx,11);
                Read_file2("number.txt",cha_n,keep[i],indextx,11);
                indextx += 10;
            }
        }
        Read_file("symbol.txt",indextx,11);
        indextx+=10;
        for(i=2;i<5;i++){
            if(keep[i] >= 48 && keep[i] <= 57){
                //number_in(keep[i],indextx,11);
                Read_file2("number.txt",cha_n,keep[i],indextx,11);
                indextx += 10;
            }
        }
    }
    else{
         int indextx = 7;
         for(i=0;i<3;i++){
            if(keep[i] >= 48 && keep[i] <= 57){
                //number_in(keep[i],indextx,11);
                Read_file2("number.txt",cha_n,keep[i],indextx,11);
                indextx += 10;
            }
        }
        Read_file("symbol.txt",indextx,11);
        indextx+=10;
        for(i=3;i<6;i++){
            if(keep[i] >= 48 && keep[i] <= 57){
                //number_in(keep[i],indextx,11);
                Read_file2("number.txt",cha_n,keep[i],indextx,11);
                indextx += 10;
            }
        }
    }

    int count=0,index_tr=0,run=0;
    char time_read[100];
    FILE *info;
    info=fopen(dir,"r");
    do{
        c=getc(info);
        if(count == 2 && run<=14){
            if(run >= 10){
                time_read[index_tr] = c;
                index_tr++;
            }
            run++;
        }
        if(c=='\n')
            count++;

    }while(c!=EOF);
    fclose(info);
    time_read[index_tr] = '\0';
    float time_r = atof(time_read);
    if(time_spent < time_r)
        record(dir,time_spent);
    else{
        wait_key(1);
    }

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++End Part of Stage ++++++++++++++++++++++++++++++++++++++++++++++++++++++


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Part of system +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void show_word(char*dir,const char *word,int index_x,int index_y,int px,int py)  // px = position x / py = position y
{


    int i;
    for(i=index_x;i<=index_y;i++){
        Read_file2(dir,cha,word[i], px, py);
        px+=14;
    }
}
void textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return;
}


const char*random_cha(char*dir)
{
    while(1){
        system("cls");
        static char words[540000][25];
        FILE *file;
        int i, j;
        size_t cnt, n;
        char word[25];

        srand(time(NULL));
        file = fopen(dir, "r");
        if (file == NULL){
            printf("The file cannot be opened.\n");
            break;
        }
        cnt = 0;
        while(1==fscanf(file, "%24s", word)){
            if(cnt == 540000)
                break;
            strcpy(words[cnt++], word);
        }
        fclose(file);
        n = cnt;
        if(n > RAND_MAX){
            int part;
            size_t random = 0;
            i = n / RAND_MAX;
            part = rand() % (i+1);
            if(part == i){
                j = n % RAND_MAX;
                if(j != 0)
                    random = random + RAND_MAX*part + rand() % j;
                else
                    random = random + RAND_MAX*(part-1) + rand();
            } else {
                random = random + RAND_MAX*part + rand();
            }
           // printf("%s\n", words[random]);
           return words[random];
        } else {
            int random = rand() % n;
           // printf("%s\n", words[random]);
           return words[random];
        }
    }
}


void Read_file(char* dir, int x, int y)
{
    gotoxy(x,y);
    FILE *info;
    info=fopen(dir,"r");
    do{
        putchar(c=getc(info));
        if(c=='\n'){
            y++;
            gotoxy(x,y);
        }
    }while(c!=EOF);
    fclose(info);
}


void Read_file2(char* dir,const char *pointer,char character, int x, int y)
{
    int count = 0;
    FILE *info;
    info=fopen(dir,"r");
    while(pointer[count]!=character){
        count++;
    }
    while(1){
        c=getc(info);
        if(c==pointer[count])
        {
            do{
                c=getc(info);
                if(c!=pointer[count+1]){
                    printf("%c",c);
                    if(c=='\n'){
                        y++;
                        gotoxy(x,y);
                    }
                }
            }while(c!=pointer[count+1] && c!=EOF);
            break;
        }
    }
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


void gotoxy(int x, int y)
{
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


void load()
{
    int r,q;
    gotoxy(36,14);
    printf("load2ing...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    	for(q=0;q<=20000000;q++);
    		printf("%c",178);
    }
}

void load2(int position1, int position2)
{
    system("cls");
    Read_file("load.txt",6,10);

    for(i=position1;i<=position2;i++)  //0 76
    {
        gotoxy(i,position1);
        for(k=0;k<=2;k++)
            printf("%c",178);
    }

    for(i=position1;i<=position2;i++)
    {
        gotoxy(i,24);
        for(k=0;k<=2;k++)
            printf("%c",178);
    }
    gotoxy(0,0);
    for(i=1;i<=79;i++){
        textcolor(12);
    	for(j=0;j<=2000000;j++);
    		printf("%c",178);
    }
    position2+=2;
    gotoxy(position2,24);
    for(i=1;i<=79;i++){
        textcolor(12);
    	for(j=0;j<=2000000;j++);
    		printf("%c",178);
        position2--;
        gotoxy(position2,24);
    }
    textcolor(11);
    Read_file("load.txt",6,10);
    wait(1);

}

void record(char*dir,double time_spent)
{
    wait(2);
    system("cls");
    char plname[20],nplname[20];
    FILE *info;
    info=fopen(dir,"w");
    gotoxy(30,11);   printf("Enter your name : ");
    gets(plname);
    //scanf("%[^\n]",plname);
    //************************
    for(j=0;plname[j]!='\0';j++){
       nplname[0]=toupper(plname[0]);
       if(plname[j-1]==' '){
           nplname[j]=toupper(plname[j]);
           nplname[j-1]=plname[j-1];}
       else nplname[j]=plname[j];
    }
    nplname[j]='\0';

    fprintf(info,"Player Name : %s\n",nplname);

    time_t mytime;
    mytime = time(NULL);
    fprintf(info,"Played Date : %s",ctime(&mytime));
    fprintf(info,"Time(s) : %.2f\n",time_spent);

    for(i=0;i<=50;i++)
        fprintf(info,"%c",'_');

    fclose(info);
    gotoxy(25,12);   printf("wanna see past records press 'y' ");
    key = getch();
    if(key=='y'){
        system("cls");
        Read_file(dir, 15, 10);
    }
    wait_key(1);
}

void casewindow()
{
	int i,j,k;
	for(j=1;j<=80;j++)
		printf("\xcd");
	gotoxy(0,0);
	printf("%c",201);
	for(k=1;k<=23;k++)
	{
		gotoxy(0,k);
		printf("%c\n",186);
	}
	gotoxy(79,0);
	printf("%c",187);
	for(k=1;k<=23;k++)
	{
		gotoxy(79,k);
		printf("%c",186);
	}
	for(j=0;j<=78;j++)
	{
		gotoxy(j,23);
		printf("\xcd");
	}
	gotoxy(0,23);
	printf("%c",200);
		gotoxy(79,23);
	printf("%c",188);
}
void background()
{
	int i,j,k;
	for(i=1;i<=22;i=i+3)
	{
		for(j=1;j<=78;j=j+3)
		{
			if ((i+j)%2!=0){
			gotoxy(j,i);
			printf("+");
			}

		}

	}
}
void square(int startx,int endx,int starty,int endy,int position)//y=place,a=startleft,b=lenght,c=startdown,d=height
{
	int i,j,k;
	for(j=startx;j<=endx;j++)//line above horizon
	{
		gotoxy(j,position);
		printf("\xcd");
	}
	gotoxy(startx,position);//corner above right
	printf("%c",201);
	for(k=starty;k<=endy;k++)//line vertical right
	{
		gotoxy(startx,k);
		printf("%c\n",186);
	}
	gotoxy(endx,position);
	printf("%c",187);
	for(k=starty;k<=endy;k++)//vertical left
	{
		gotoxy(endx,k);
		printf("%c",186);
	}
	for(j=startx;j<=endx;j++)//under line
	{
		gotoxy(j,endy);
		printf("\xcd");
	}
	gotoxy(startx,endy);
	printf("%c",200);
	gotoxy(endx,endy);
	printf("%c",188);
}
void window()
{
	ClearConsoleToColors(2,0);
	casewindow();
	background();
	//word AtoZ
	gotoxy(23,3); printf("%c%c",219,219);
	gotoxy(22,4); printf("%c%c%c%c",219,219,219,219);
	gotoxy(21,5); printf("%c%c",219,219);
	gotoxy(25,5); printf("%c%c",219,219);
	gotoxy(20,6); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(19,7); printf("%c%c",219,219);
	gotoxy(18,8); printf("%c%c",219,219);
	gotoxy(27,7); printf("%c%c",219,219);
	gotoxy(28,8); printf("%c%c",219,219);
	gotoxy(35,5); printf("%c%c",219,219);
	gotoxy(33,6); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(35,7); printf("%c%c",219,219);
	gotoxy(35,8); printf("%c%c",219,219);
	gotoxy(43,5); printf("%c%c",219,219);
	gotoxy(41,6); printf("%c%c",219,219);
	gotoxy(45,6); printf("%c%c",219,219);
	gotoxy(41,7); printf("%c%c",219,219);
	gotoxy(45,7); printf("%c%c",219,219);
	gotoxy(43,8); printf("%c%c",219,219);
	gotoxy(52,3); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(52,8); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(58,4); printf("%c%c",219,219);
	gotoxy(56,5); printf("%c%c",219,219);
	gotoxy(54,6); printf("%c%c",219,219);
	gotoxy(52,7); printf("%c%c",219,219);
	gotoxy(10,10);
	printf("                                                           ");
	//word CHALLANGE
	gotoxy(10,13);
	printf("     C     H     A     L     L     A     N     G     E     ");
	square(5,18,18,19,17);
	square(24,37,18,19,17);
	square(42,55,18,19,17);
	square(60,73,18,19,17);
	//gotoxy(10,16); printf("PLAY");
	//gotoxy(29,16); printf("SCORE");
	//gotoxy(47,16); printf("HELP");
	//gotoxy(65,16); printf("EXIT");
	arrow(4,0);
	//gotoxy(30,23); printf("FUCK");
}
void stage()
{
	system("cls");
	FILE *article;
	article=fopen("AtoZ.txt","r");
	char c;
	if(article==NULL)
		printf("No");
	else
	{
		do
		{
			//c=fgetc(article);
			putchar(c=fgetc(article));
		}while(c!=EOF);
		fclose(article);
	}
	square(5,18,18,19,17);
	square(24,37,18,19,17);
	square(42,55,18,19,17);
	square(60,73,18,19,17);
	gotoxy(22,22); printf("Press spacebar to Back to main menu.");
	arrow(4,1);
	getch();
}
void besttime()
{
	system("cls");
	FILE *article;
	article=fopen("besttime.txt","r");
	char c;
	if(article==NULL)
		printf("No");
	else
	{
		do
		{
			//c=fgetc(article);
			putchar(c=fgetc(article));
		}while(c!=EOF);
		fclose(article);
	}
	square(5,18,18,19,17);
	square(24,37,18,19,17);
	square(42,55,18,19,17);
	square(60,73,18,19,17);
	gotoxy(22,22); printf("Press spacebar to Back to main menu.");
	arrow(4,2);
	getch();
}

void arrow(int point,int mode)
{
	int count=1,check=1;
	char word='0';
	//gotoxy(64,18);
	while(check)
	{
		switch(word)
        {
        case 77:{
            count++;
            if (count==point+1) count=1;
            break;}
        case 75:{
            count--;
            if(count==0) count=point;
            break;}
        }
		move(point,count,mode);
		word=getch();
		if(word=='\r')
		{
			if(point==4)
			{
				switch(mode)
				{
					case 0:
					{
						if(count==1){stage(); check=0; break;}
						else if(count==2){besttime(); check=0; break;}
						else if(count==4){exit(0); check=0; break;}

					}
					case 1:
					{
						if(count==1){play_stage1(); check=0; break;}
						if(count==2){play_stage2to4(2); check=0; break;}
						if(count==3){play_stage2to4(3); check=0; break;}
						if(count==4){play_stage2to4(4); check=0; break;}

					}
					case 2:
					{
						if(count==1){system("cls"); Read_file("record_stage1.txt", 15, 10);  wait_key(2);  check=0; break;}
						if(count==2){system("cls"); Read_file("record_stage2.txt", 15, 10);  wait_key(2);  check=0; break;}
						if(count==3){system("cls"); Read_file("record_stage3.txt", 15, 10);  wait_key(2);  check=0; break;}
						if(count==4){system("cls"); Read_file("record_stage4.txt", 15, 10);  wait_key(2);  check=0; break;}
					}
				}

			}
		}
		else if(word==32)
		{
			system("cls");
			window();
		}
	}
}
void move(int point,int count,int mode)
{
	char *menu[3][4]={{"PLAY","RECORD","HELP","EXIT"},{"STAGE 1","STAGE 2","STAGE 3","STAGE 4"},\
	{"STAGE 1","STAGE 2","STAGE 3","STAGE 4"}};
	if(point==4)
	{
		gotoxy(8,18); printf("  %s",menu[mode][0]);
		gotoxy(27,18); printf("  %s",menu[mode][1]);
		gotoxy(45,18); printf("  %s",menu[mode][2]);
		gotoxy(63,18); printf("  %s",menu[mode][3]);
		switch (count)
        {
        case 1:
        {
            gotoxy(7,18);
            printf(" %c %s",16,menu[mode][0]);
            break;
    	}
        case 2:
        {
            gotoxy(26,18);
            printf(" %c %s",16,menu[mode][1]);
            break;
    	}
        case 3:
        {
            gotoxy(44,18);
            printf(" %c %s",16,menu[mode][2]);
            break;
    	}
        case 4:
        {
            gotoxy(62,18);
            printf(" %c %s",16,menu[mode][3]);
            break;
        }
        }
	}
}

void wait_key(int choose)
{
    while(1)
    {
        if (_kbhit())
        {
            key =_getch();

            if (key == ' '){
                system("cls");
                if(choose==1){
                        gotoxy(17,24);  printf("Back to SELECT STAGE press your keyboard : <spacebar>");
                        stage();
                }
                if(choose==1){
                        gotoxy(17,24);  printf("Back to SELECT RECORD press your keyboard : <spacebar>");
                        besttime();
                }
                break;}
        }
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ End Part of system +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
