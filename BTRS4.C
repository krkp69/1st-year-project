#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#define FIELD_SIZE 25
#define length(array) ( sizeof (array) / sizeof (array)[i] )

//function decleration//
void get_password();
void login();
void allert();
void menu();
void buy();
void res();
void cancel();
void more();
void validation();

//username and password//
struct account
{
    char *id;
    char *password;
};
static struct account accounts[] =
{
    //defult username and password//
    { "admin" , "admin" },
    { "sunway", "sunway" }
};
int is_authorized(const char *uid,const char *pwd)
{
    int i;
    for (i=0; i<length(accounts); i++)
    {
	   if(stricmp(uid, accounts[i].id)==0 && strcmp(pwd, accounts[i].password)==0)
	   {
		  return 1;
	   }
    }
	   return 0;
}

//password hide//
void get_password(char *pwd, int size)
{
    int i=0;
    int ch;
    while(i<size-1 && (ch=getch())!='\r')
    {
	   if(ch=='\b')
	   {
		  if (i!=0)
		  {
			  printf("\b%c\b",' ');   //Don't run off the front end of the array //
			  --i;
		  }
	   }
	   else
	   {
		  putchar('*');
		  pwd[i++]=(char)ch;
	   }

    }

    pwd[i]='\0';
}

//Login Windows//
void login()
{
    int ch;
    char uid[FIELD_SIZE];
    char pwd[FIELD_SIZE];
    //for out box//
    setfillstyle(1,4);
    rectangle(100,100,540,340);
    floodfill(101,101,15);
    //for inner box//
    setfillstyle(1,3);
    rectangle(110,110,530,330);
    floodfill(111,111,15);
    //for username and password input box//
    setfillstyle(1,0);
    rectangle(270,200,500,225);
    rectangle(270,235,500,260);
    floodfill(271,201,15);
    floodfill(271,241,15);

    //for line//
    setfillstyle(1,4);
    rectangle(110,170,530,175);
    rectangle(110,280,530,285);
    floodfill(111,171,15);
    floodfill(111,281,15);

    //text display for  header//
    outtextxy(280,120,"WELLOME TO");
    outtextxy(190,140,"BUS TICKETING & RESERVATION SYSTEM");

    //for text display for username input//
    outtextxy(170,210,"Username :::");
    outtextxy(170,246,"Password :::");
    //text display for  footer//
    outtextxy(155,300,"COPYRIGHT @ 2nd SEM STUDENT OF SUNWAY");
    gotoxy(36,14);
    fflush(stdout);
	 if (fgets( uid, sizeof uid, stdin)!=NULL )
	 {
		char *newline = strchr(uid,'\n' );
	   /* Trim the newline if it's present */
		if(newline!=NULL )
		*newline = '\0';
		gotoxy(36,16);
		fflush ( stdout );
		get_password ( pwd, sizeof pwd );
        //checking password//
		if ( is_authorized ( uid, pwd ) )
		{
		    menu();
		}
		else
		{

		    outtextxy(170,265,"Invalid Username or Password");
		    allert();
		    login();
		}

	 }

}
 //warning sound//
void allert()
{
    sound(755);
    delay(1000);
    nosound();
}

//Menu//
void menu()
{
    int ch;
    setfillstyle(1,BLACK);
    floodfill(100,100,14);
    //for out box//
    setfillstyle(1,4);
    rectangle(80,80,560,360);
    floodfill(81,81,15);
    //for inner box//
    setfillstyle(1,3);
    rectangle(90,90,550,350);
    floodfill(91,91,15);

    //for line//
    setfillstyle(1,4);
    rectangle(90,150,550,155);
    rectangle(90,310,550,315);
    rectangle(90,180,180,183);
    floodfill(91,151,15);
    floodfill(91,311,15);
    floodfill(91,181,15);

    //box for options//
    setfillstyle(1,4);
    rectangle(130,265,530,295);
    floodfill(131,266,15);
    setfillstyle(1,BLACK);
    rectangle(310,270,520,290);
    floodfill(311,271,15);

    //text display for  header//
    outtextxy(280,110,"WELLOME TO");
    outtextxy(190,130,"BUS TICKETING & RESERVATION SYSTEM");

    //text display for  menu//
    outtextxy(115,165,"MENU");
    outtextxy(100,200,"1. BUY");
    outtextxy(100,215,"2. RESERVE");
    outtextxy(100,230,"3. CANCEL");
    //choosing option//
    outtextxy(140,277,"Enter your option ::: ");

    //text display for  footer//
    outtextxy(160,325,"COPYRIGHT @ 2nd SEM STUDENT OF SUNWAY");
    gotoxy(41,18);
    scanf("%d",&ch);
    if(ch==1 || ch==2 || ch==3)
    {
        switch(ch)
        {
            case 1:
            {   clrscr();
                buy();
                break;
            }
            case 2:
            {
                clrscr();
                res();
                break;
            }
            case 3:
            {
                clrscr();
                cancel();
                break;
            }
        }
    }
    else
    {
        menu();
    }
}

//ticket buy//
void buy()
{
    // create a FILE typed pointer
    FILE *file_pointer;
    char path[] = "C:/TURBOC3/BIN/PROJECT/Buy/";
    char a[55];
    char name[100];
    char from[55];
    char to[55];
    char seat[55];
    char date[55];
    char time[55];
    char rate[55];
    char pass[55];
    char ch;
    // int date, time,rate,pass;
    //inner and outer box//
    setfillstyle(1,0);
    floodfill(0,0,15);
    setfillstyle(1,4);
    rectangle(80,100,560,380);
    floodfill(81,101,15);
    setfillstyle(1,3);
    rectangle(90,110,550,370);
    floodfill(111,111,15);

    setfillstyle(1,4);
    rectangle(90,150,550,155);
    rectangle(90,330,550,335);
    floodfill(91,151,15);
    floodfill(91,331,15);
    //INPUT BOX//
    setfillstyle(1,0);
    rectangle(230,172,540,193);
    rectangle(185,205,310,225);
    rectangle(400,205,540,225);
    rectangle(185,238,310,257);
    rectangle(420,238,540,257);
    rectangle(185,268,310,288);
    rectangle(500,268,540,288);
    rectangle(210,300,310,320);
    floodfill(231,176,15);
    floodfill(186,206,15);
    floodfill(401,206,15);
    floodfill(186,239,15);
    floodfill(421,239,15);
    floodfill(186,269,15);
    floodfill(501,269,15);
    floodfill(211,301,15);
    //Asking Information//
    outtextxy(225,130,"ENTER PASSENGERS DETAILS");
    outtextxy(175,345,"COPYRIGHT @ 2nd SEM STUDENT OF SUNWAY");
    outtextxy(115,180,"Full Name :::");
    outtextxy(115,213,"From :::");
    outtextxy(350,213,"To :::");
    outtextxy(115,245,"Date :::");
    outtextxy(350,245,"Time :::");
    outtextxy(115,275,"Rate ::");
    outtextxy(350,275,"No. of Pasenger :::");
    outtextxy(115,307,"Seat no. :::");
    //input/
    //FILE *file_pointer;
    gets(a);
    gotoxy(30,12);
    gets(name);
    strcat(name,".txt");
    strcat(path,name);
    //open the file "name_of_file.txt" for writing
    file_pointer = fopen(path, "a");
    gotoxy(25,14);
    gets(from);
    gotoxy(52,14);
    gets(to);
    gotoxy(25,16);
    gets(date);
    gotoxy(54,16);
    gets(time);
    gotoxy(25,18);
    printf("Rs. ");
    gets(rate);
    gotoxy(64,18);
    gets(pass);
    gotoxy(28,20);
    gets(seat);
    fprintf(file_pointer,"\t\tWell come to Bus Ticketing & Reservation System\n\t\t\t\tNarayani Yatayat\n\t\t\t\tKathmandu, Nepal\n\n\n");
    fprintf(file_pointer,"\tBus No. : BA 20 JA 2354\t\t\t\tDate : %s\n\n",date);
    fprintf(file_pointer,"\tFull Name = ");
    fputs(name,file_pointer);
    fprintf(file_pointer,"\n\tFrom : ");
    fputs(from,file_pointer);
    fprintf(file_pointer,"\tTo : \t");
    fputs(to,file_pointer);
    fprintf(file_pointer,"Time : ");
    fputs(time,file_pointer);
    fprintf(file_pointer,"%s\n\tNo of Passenger : ");
    fputs(pass,file_pointer);
    fprintf(file_pointer,"%s\tSeat no : ");
    fputs(seat,file_pointer);
    fprintf(file_pointer,"%s\n\tRate : ");
    fputs(rate,file_pointer);
    // Close the file)
    fclose(file_pointer);
    clrscr();
    outtextxy(100,170,"Ticket Bought successfully");
    more();
}

//ticket resrrvation//
void res()
{
    // create a FILE typed pointer
    FILE *file_pointer;
    char path[] = "C:/TURBOC3/BIN/PROJECT/Res/";
    char a[55];
    char name[100];
    char from[55];
    char to[55];
    char seat[55];
    char date[55];
    char time[55];
    char rate[55];
    char pass[55];
    char ch;
    // int date, time,rate,pass;
    //inner and outer box//
    setfillstyle(1,0);
    floodfill(0,0,15);
    setfillstyle(1,4);
    rectangle(80,100,560,380);
    floodfill(81,101,15);
    setfillstyle(1,3);
    rectangle(90,110,550,370);
    floodfill(111,111,15);
    setfillstyle(1,4);
    rectangle(90,150,550,155);
    rectangle(90,330,550,335);
    floodfill(91,151,15);
    floodfill(91,331,15);
    //INPUT BOX//
    setfillstyle(1,0);
    rectangle(230,172,540,193);
    rectangle(185,205,310,225);
    rectangle(400,205,540,225);
    rectangle(185,238,310,257);
    rectangle(420,238,540,257);
    rectangle(185,268,310,288);
    rectangle(500,268,540,288);
    rectangle(210,300,310,320);
    floodfill(231,176,15);
    floodfill(186,206,15);
    floodfill(401,206,15);
    floodfill(186,239,15);
    floodfill(421,239,15);
    floodfill(186,269,15);
    floodfill(501,269,15);
    floodfill(211,301,15);
    //Asking Information//
    outtextxy(225,130,"ENTER PASSENGERS DETAILS");
    outtextxy(175,345,"COPYRIGHT @ 2nd SEM STUDENT OF SUNWAY");
    outtextxy(115,180,"Full Name :::");
    outtextxy(115,213,"From :::");
    outtextxy(350,213,"To :::");
    outtextxy(115,245,"Date :::");
    outtextxy(350,245,"Time :::");
    outtextxy(115,275,"Rate ::");
    outtextxy(350,275,"No. of Pasenger :::");
    outtextxy(115,307,"Seat no. :::");
   // outtextxy(150,307,"BUY Enter");
    //input/
    //FILE *file_pointer;
    gets(a);
    gotoxy(30,12);
    gets(name);
    strcat(name,".txt");
    strcat(path,name);
    //open the file "name_of_file.txt" for writing
    file_pointer = fopen(path, "a");
    gotoxy(25,14);
    gets(from);
    gotoxy(52,14);
    gets(to);
    gotoxy(25,16);
    gets(date);
    gotoxy(54,16);
    gets(time);
    gotoxy(25,18);
    printf("Rs. ");
    gets(rate);
    gotoxy(64,18);
    gets(pass);
    gotoxy(28,20);
    gets(seat);
    //inserting data in to a file//
    fprintf(file_pointer,"\t\tWell come to Bus Ticketing & Reservation System\n\t\t\t\tNarayani Yatayat\n\t\t\t\tKathmandu, Nepal\n\n\n");
    fprintf(file_pointer,"\tBus No. : BA 20 JA 2354\t\t\t\tDate : %s\n\n",date);
    fprintf(file_pointer,"\tFull Name = ");
    fputs(name,file_pointer);
    fprintf(file_pointer,"\n\tFrom : ");
    fputs(from,file_pointer);
    fprintf(file_pointer,"\tTo : \t");
    fputs(to,file_pointer);
    fprintf(file_pointer,"Time : ");
    fputs(time,file_pointer);
    fprintf(file_pointer,"%s\n\tNo of Passenger : ");
    fputs(pass,file_pointer);
    fprintf(file_pointer,"%s\tSeat no : ");
    fputs(seat,file_pointer);
    fprintf(file_pointer,"%s\n\tRate : ");
    fputs(rate,file_pointer);
    // Close the file)
    fclose(file_pointer);
    clrscr();
    outtextxy(100,170,"Ticket Reserve successfully");
    more();

}

//ticket cancel//
void cancel()
{
    FILE *file_pointer;
    char name[50];
    char a[55];
    int status;
    char ch;
    char path[] = "C:/TURBOC3/BIN/PROJECT/Res/";
    setfillstyle(1,0);
    floodfill(0,0,15);
    setfillstyle(1,4);
    rectangle(80,100,560,380);
    floodfill(81,101,15);
    setfillstyle(1,3);
    rectangle(90,110,550,370);
    floodfill(111,111,15);

    setfillstyle(1,4);
    rectangle(90,150,550,155);
    rectangle(90,330,550,335);
    floodfill(91,151,15);
    floodfill(91,331,15);
    //INPUT BOX//
    setfillstyle(1,0);
    rectangle(230,172,540,193);
    floodfill(231,176,15);
    //Asking Information//
    outtextxy(225,130,"ENTER PASSENGERS DETAILS");
    outtextxy(175,345,"COPYRIGHT @ 2nd SEM STUDENT OF SUNWAY");
    outtextxy(115,180,"Full Name :::");
    gets(a);
    gotoxy(30,12);
    gets(name);
    strcat(name,".txt");
    strcat(path,name);
    status = remove(path);  //removing file function remove()//
    clrscr();
    //fclose(file_pointer);
    if (status == 0)
    {
	outtextxy(100,170,"Ticket Cancel successfully");
	more();
	 //outtextxy(100,100",sucees");

    }
    else
    {
       outtextxy(100,170,"Unable to Cancel a Ticket ticket not found!!!");
       more();
    }
    // Close the file
}

//Asking for more passenger//
void more()
{
    char ch;
    setfillstyle(1,0);
    floodfill(0,0,15);
    setfillstyle(1,4);
    rectangle(80,100,560,380);
    floodfill(81,101,15);
    setfillstyle(1,3);
    rectangle(90,110,550,370);
    floodfill(111,111,15);

    setfillstyle(1,4);
    rectangle(90,150,550,155);
    rectangle(90,330,550,335);
    floodfill(91,151,15);
    floodfill(91,331,15);
    //INPUT BOX//
    setfillstyle(1,0);
    rectangle(100,270,540,290);
    floodfill(101,271,15);
    //Asking Information//
    outtextxy(225,130,"ENTER PASSENGERS DETAILS");
    outtextxy(175,345,"COPYRIGHT @ 2nd SEM STUDENT OF SUNWAY");
    outtextxy(100,250,"More Passenger if yes press Y if not press N ::::::::::");
    gotoxy(15,18);
    scanf("%c",&ch);
    if (ch=='Y' || ch=='y')
    {
	    menu();
    }
    else if(ch == 'N' || ch == 'n')
    {
        login();
    }
    else
    {
	    more();
    }
}

//password validation//
void validation();

//main function//
int main()
{
    int gd=DETECT,gm,pin;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    login();
    //buy();
    //menu();
    //cancel();
    //more();
    getch();
    closegraph();
    return 0;
}