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
/*
char c;
char *cha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l'\
,'m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char *cha_n[11] = {'0','1','2','3','4','5','6','7','8','9'};*/


void ClearConsoleToColors(int ForgC, int BackC);
void textcolor(int color);
const char*random_cha(char*dir);
void Read_file(char*dir, int x, int y);
void Read_file2(char*dir,const char *pointer,char character, int x, int y);
void time_spented(int form, double time_spent);
void show_word(char*dir,const char*word,int index_x,int index_y,int px,int py);  // px = position x / py = position y
void character(char num);
void number_in(char num,int x,int y);
void right();
void left();
void load();
void load2(int position1, int position2);
void record(int form,double time_spent);
void gotoxy(int x, int y);
void wait( int sec );
void play_stage1();
void play_stage2to4(int stage);

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
    play_stage1();
    wait(5);
    play_stage2to4(2);
    wait(5);
    play_stage2to4(3);
    wait(5);
    play_stage2to4(4);

    //load2(0,76);


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

                for(i=1;i<=6;i++){
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

    time_spented(1,time_spent);

}

void stage2()
{
    load2(0,76);
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

    load2(0,76);
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

    load2(0,76);
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
        case 2:     time_spented(2,time_spent);     break;
        case 3:     time_spented(3,time_spent);     break;
        case 4:     time_spented(4,time_spent);     break;

    }



}


void time_spented(int form, double time_spent)
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
    record(form,time_spent);
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

void record(int form,double time_spent)
{
    char dir[100];
    switch(form)
    {
        case 1:     strcpy(dir,"record_stage1.txt");    break;
        case 2:     strcpy(dir,"record_stage2.txt");    break;
        case 3:     strcpy(dir,"record_stage3.txt");    break;
        case 4:     strcpy(dir,"record_stage4.txt");    break;
    }
    wait(2);
    system("cls");
    char plname[20],nplname[20];
    FILE *info;
    info=fopen(dir,"w");
    printf("Enter your name\n");
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
    fprintf(info,"\n");
    fclose(info);
    printf("wanna see past records press 'y'\n");
    key = getch();
    if(key=='y'){
        system("cls");
        Read_file(dir, 15, 10);
    }


}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ End Part of system +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

