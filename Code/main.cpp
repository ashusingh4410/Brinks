#include<stdlib.h>
#include<bits/stdc++.h>
#include<cstdlib>
#include<string>
#include<vector>
#include<fstream>
#include<time.h>
#include<dos.h>
#include<iomanip>
#include<process.h>
#include"Voice.h"
#include<windows.h>
#include<stdio.h>
#include <iostream>
#include "learner.h"
#include<conio.h>
#define clrscr()system("cls");
#define MAX_NUM 10;
using namespace std;
Learner AIG;
int i=0,j,cs,k=1;
string identity;
string nameg;
int MapW,MapH;
char Map[100][100]={
"########################################################",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                         @            #",
"#                                                      #",
"#                                                      #",
"########################################################"};

class chatbot
{
    public:
        string id;
  string g;
  string name;
  string age;
}c;
COORD coordm={0,0};//sets center of axis to left corner for gotoxy
void introduction();
void gotoxym(int,int);
void login();
void instructions();
void clock1(){}
void time1();
void date1();
void calculator();
void prelogin(string);
int random(int);
void game();
void quiz1();
//int snake2();
void kiet();
void time1()
{

    time_t t=time(0); //get time now
    struct tm*now=localtime(&t);
    cout<<"DATE:"<<now->tm_mday<<'-'
        <<(now->tm_mon+1)<<'-'
        <<(now->tm_year+1900)<<endl;
      cout<<"TIME:"<<now->tm_hour
        <<':'<<now->tm_min<<endl;
}
struct snakeBlock{
    int x,y;
};

void gotoxy(int x, int y)
{
  COORD coord={x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char guess; //Answer user inputs for question.
int total;  //Total score.


//4 possible answers, correct answer and question score.
class Question{
public:
    void setValues(std::string, std::string, std::string, std::string, std::string, char, int);
    int askQuestion();

private:
    std::string Question_Text;
    std::string answer_1;
    std::string answer_2;
    std::string answer_3;
    std::string answer_4;

    char correct_answer;
    int Question_Score;
};

int quiz()
{

    int c;
    //Get the user's name.
    std::string name;
    AIG.respond1("What's your name?");
    std::cin >> name;
    std::cout << "\n";

    //Ask if user wants to start quiz.
    std::string respond;
    AIG.respond1("Are you ready to start the quiz,yes or no ");
    std::cin >> respond;

    //If user says yes, the quiz begins.
    if (respond == "Yes" || respond == "yes") {
        std::cout << "\n";
        AIG.respond1("Good luck !");
        std::cout << "\n";
        AIG.respond1("Press enter to continue.");
        std::cin.get();
        std::cin.ignore();
    }else{
        std::cout << "\n";
        AIG.respond1("Goodbye");
        cout<<endl;
        std::cin.ignore();
        std::cin.get();
        return 0;
    }//Else, quiz ends.

    //Instances of the questions.
    //25 questions total generated for this quiz.
    Question q1;
    Question q2;
    Question q3;
    Question q4;
    Question q5;
    Question q6;
    Question q7;
    Question q8;
    Question q9;
    Question q10;
    Question q11;
    Question q12;
    Question q13;
    Question q14;
    Question q15;
    Question q16;
    Question q17;
    Question q18;
    Question q19;
    Question q20;
    Question q21;
    Question q22;
    Question q23;
    Question q24;
    Question q25;

    //Calling the member function setValues.
    //Question is set, 4 answer choices, the correct char answer, 4 points per question.
    q1.setValues("1. What command prints something to the screen?",
        "cin",
        "cout",
        "char",
        "print",
        'b',
        4);

    q2.setValues("2. Which of the following categories does C++ belong to?",
        "Operating System",
        "High-level programming language",
        "low-level programming language",
        "Compiler",
        'b',
        4);

    q3.setValues("3. Which command is correctly written?",
        "cout >>",
        "cin <<",
        "cout <>",
        "cin >>",
        'd',
        4);

    q4.setValues("4. What is this called, <iostream>?",
        "directive",
        "pre-processor directive",
        "file",
        "command",
        'b',
        4);

    q5.setValues("5. What punctuation ends most lines of code?",
        " . ",
        " ; ",
        " : ",
        " ' ",
        'b',
        4);

    q6.setValues("6. Which of the following is a correct comment?",
        "*/ Comments */",
        "** Comment **",
        "/* Comment */",
        "{ Comment }",
        'c',
        4);

    q7.setValues("7. Which of the following is the boolean operator for logical-and?",
        "&",
        "|",
        "&&",
        "|&",
        'c',
        4);

    q8.setValues("8. Which of the following shows the correct syntax for an if statement?",
        "if expression",
        "if {expression",
        "if (expression)",
        "expression if",
        'c',
        4);

    q9.setValues("9. How many times is a do while loop guaranteed to loop?",
        "1",
        "0",
        "Infinitely",
        "Variable",
        'a',
        4);

    q10.setValues("10. A subscipt is a(n) __________ .",
        "element in an array",
        "alternate name for an array",
        "number that represents the highest value stored within an array",
        "number that indicates the position of the particular item in an array",
        'd',
        4);

    q11.setValues("11. Which of the following correctly declares an array?",
        "int anarray[10];",
        "int anarray",
        "anarray{10};",
        "array anarray[10];",
        'a',
        4);

    q12.setValues("12. What is the index number of the last element of an array with 29 elements?",
        "29",
        "28",
        "0",
        "Programmer-defined",
        'b',
        4);

    q13.setValues("13. Which is not a loop structure?",
        "for",
        "do while",
        "while",
        "repeat until",
        'd',
        4);

    q14.setValues("14. When does the code block following while(x < 100) execute?",
        "When x is less than one hundred",
        "When x is greater than one hundred",
        "When x is equal to one hundred",
        "While it wishes",
        'a',
        4);

    q15.setValues("15. Most programmers use a for loop __________ .",
        "for every loop they write",
        "when a loop will not repeat",
        "when they do not know the exact number of times a loop will repeat",
        "when they know the exact number of times a loop will repeat",
        'd',
        4);

    q16.setValues("16. Adding 1 to a  variable is also called __________ it.",
        "digesting",
        "incrementing",
        "decrementing",
        "resetting",
        'b',
        4);

    q17.setValues("17. What is required to avoid falling through from one case to the next?",
        "end;",
        "break;",
        "Stop;",
        "A semicolon",
        'b',
        4);

    q18.setValues("18. A __________ is a variable that you set to indicate whether some event has occured.",
        "subscript",
        "banner",
        "counter",
        "flag",
        'd',
        4);

    q19.setValues("19. Identify the C++ compiler of Linux.",
        "cpp",
        "g++",
        "Borland",
        "vc++",
        'b',
        4);

    q20.setValues("20. What is the size of 'int'? ",
        "2",
        "4",
        "8",
        "Compiler dependent",
        'd',
        4);

    q21.setValues("21. Which data type can be used to hold a wide character in C++?",
        "unsigned char;",
        "int",
        "wchar",
        "none of the above.",
        'c',
        4);

    q22.setValues("22. C++ does not support the following",
        "Multilevel inheritance",
        "Hierarchical inheritance",
        "Hybrid inheritance",
        "None of the above.",
        'd',
        4);

    q23.setValues("23. Which is not a protection level provided by classes in C++?",
        "protected",
        "hidden",
        "private",
        "public",
        'b',
        4);

    q24.setValues("24. What purpose do classes serve?",
        "data encapsulation",
        "providing a convenient way of modeling real-world objects",
        "simplifying code reuse",
        "all of the above",
        'd',
        4);

    q25.setValues("25. Who developed the C++ language?",
        "Steve Jobs",
        "Linus Torvalds",
        "Bill Gates",
        "Bjarne Stroustrup",
        'd',
        4);

    //Calling askQuestion member function.
    c=q1.askQuestion();if(c==0){return 0;}
    c=q2.askQuestion();if(c==0){return 0;}
    c=q3.askQuestion();if(c==0){return 0;}
    c=q4.askQuestion();if(c==0){return 0;}
    c=q5.askQuestion();if(c==0){return 0;}
    c=q6.askQuestion();if(c==0){return 0;}
    c=q7.askQuestion();if(c==0){return 0;}
    c=q8.askQuestion();if(c==0){return 0;}
    c=q9.askQuestion();if(c==0){return 0;}
    c=q10.askQuestion();if(c==0){return 0;}
    c=q11.askQuestion();if(c==0){return 0;}
    c=q12.askQuestion();if(c==0){return 0;}
    c=q13.askQuestion();if(c==0){return 0;}
    c=q14.askQuestion();if(c==0){return 0;}
    c=q15.askQuestion();if(c==0){return 0;}
    c=q16.askQuestion();if(c==0){return 0;}
    c=q17.askQuestion();if(c==0){return 0;}
    c=q18.askQuestion();if(c==0){return 0;}
    c=q19.askQuestion();if(c==0){return 0;}
    c=q20.askQuestion();if(c==0){return 0;}
    c=q21.askQuestion();if(c==0){return 0;}
    c=q22.askQuestion();if(c==0){return 0;}
    c=q23.askQuestion();if(c==0){return 0;}
    c=q24.askQuestion();if(c==0){return 0;}
    c=q25.askQuestion();if(c==0){return 0;}

    //Final score displayed when user finishes quiz.
    std::cout << "Your Total Score is " << total << " out of 100!\n";
    std::cout << "\n";


    if (total > 69) {
            AIG.respond1("well played!");
         std::cout << "\n";
        std::cin.get();
        std::cin.ignore();
        return 0;
    }
    else
    {
    AIG.respond1("You failed. Sorry, better luck next time.");
        std::cout << "\n";
    }
    std::cin.get();
    std::cin.ignore();
    return 0;
}

//Function called for question guidelines.
void Question::setValues(std::string q, std::string a1, std::string a2, std::string a3, std::string a4, char ca, int pa)
{
    Question_Text = q;
    answer_1 = a1;
    answer_2 = a2;
    answer_3 = a3;
    answer_4 = a4;
    correct_answer = ca;
    Question_Score = pa;
}
//Format for possible answers displayed when program executes.
int Question::askQuestion()
{
    std::cout << "\n";
    std::cout << Question_Text << "\n";
    std::cout << "a. " << answer_1 << "\n";
    std::cout << "b. " << answer_2 << "\n";
    std::cout << "c. " << answer_3 << "\n";
    std::cout << "d. " << answer_4 << "\n";
    std::cout << "e. " <<"exit"<<"\n";
    std::cout << "\n";

    //User enters their answer.
    std::cout << "What is your answer?" << "\n";
    std::cin >> guess;

    if(guess=='e')
    {
     return 0;
    }
    //If their answer is correct, message is displayed and 4 points are added to their score.
    if (guess == correct_answer) {
        std::cout << "\n";
        AIG.respond1("Correct!");
        total = total + Question_Score;
        std::cout << "\n";
        AIG.respond1("Press enter to continue.");
        std::cin.get();
        std::cin.ignore();
    }
    else //If their answer is incorrect, message is displayed, no points added.
         //Correct answer displayed.
    {
        std::cout << "\n";
        AIG.respond1("Sorry, you're wrong.");
        AIG.respond1("The correct answer is -");
        cout<<correct_answer<<endl;
        AIG.respond1("Press enter to continue.");
        std::cin.get();
        std::cin.ignore();
    }
}


void drawMap(vector <snakeBlock>snake)
{
    MapH=0;
    system("cls");
    for (int i=0;Map[i][0];i++)
    {
        MapW=0;
        for (int j = 0 ;Map[i][j];j++)
        {
            MapW++;
            if (Map[i][j]!=' ')
            {
                gotoxy(j,i);
                cout<<Map[i][j];
            }
        }
        MapH++;
    }
    for (int i =0 ;i<snake.size();i++)
    {
        gotoxy(snake[i].x,snake[i].y);
        cout<<char (219);
    }
}

bool checkLose(int x, int y,vector <snakeBlock>&snake)
{
    if (Map[y][x]=='#')
        return true;
    if (snake.size()>3)
    {
        for (int i = 3;i<snake.size();i++)
            if (snake[i].x==x&&snake[i].y==y)
                return true;
    }
    if (Map[y][x]=='@')
    {
        Map[y][x]=' ';
        snakeBlock newSnake;
        newSnake.x=snake[snake.size()-1].x;
        newSnake.y=snake[snake.size()-1].y;
        snake.push_back(newSnake);
        int rx,ry;
        do{
            rx=rand()%MapW;
            ry=rand()%MapH;
        }while (checkLose(rx, ry,snake));
        Map[ry][rx]='@';
        drawMap(snake);
    }
    return false;
}

void snakeInit(int x,int y ,vector<snakeBlock> &snake)
{
    snakeBlock newSnake;
    newSnake.x=x;
    newSnake.y=y;
    snake.push_back(newSnake);
}

bool snakeMove(vector<snakeBlock>&snake,short dire[2])
{
    int oldx,oldy,x,y;
    gotoxy(snake[snake.size()-1].x,snake[snake.size()-1].y);
    cout<<" ";
    oldx=snake[0].x;
    oldy=snake[0].y;
    snake[0].x+=dire[0];
    snake[0].y+=dire[1];
    gotoxy(snake[0].x,snake[0].y);
    cout<<char(219);
    if (snake.size()>1)
    {
        for (int i = 1;i<snake.size();i++)
        {
            x=snake[i].x;
            y=snake[i].y;
            snake[i].x=oldx;
            snake[i].y=oldy;
            oldx=x;
            oldy=y;
        }
    }
    if (checkLose(snake[0].x,snake[0].y,snake))
        return true;
    return false;
}

int snake1()
{

    cout<<"\n \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t->";AIG.respond1("press enter to play");
    getch();
    bool GameIsRunning=true;
    int GameSpeed=80;
    short dire[2]={0,1};
    vector<snakeBlock> snake;
    snakeInit(1,1,snake);
    drawMap(snake);
    while (GameIsRunning)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            if (dire[1]==0)
            {
                dire[1]=-1;
                dire[0]=0;
            }
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            if (dire[1]==0)
            {
                dire[1]=1;
                dire[0]=0;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            if (dire[0]==0)
            {
                dire[1]=0;
                dire[0]=-1;
        }
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            if (dire[0]==0)
            {
                dire[1]=0;
                dire[0]=1;
            }
        }
        if(snakeMove(snake,dire))
        {
          system("cls");
          AIG.respond1("Game Over Better Luck Next Time!");
          system("pause");

          return 0;
        }
        Sleep(GameSpeed);
    }
}





main(){

    Learner AI;    // Create a learner object
string phrase;
string phased;
    /*
    	The following is the main loop. It will continue until the application is closed.
    	The user enters their input, and then the learner will respond.
    */

    kiet();
    instructions();
     introduction();
    clrscr();
    fflush(stdin);
    time1();
    for(;;){
        cout << "\nYOU: "; // User prompt
        fflush(stdin);
        getline(cin, phrase);  // Using getline for multi word input, then store in phrase.
        transform(phrase.begin(),phrase.end(),phrase.begin(),::tolower);  //to lowercase
         if(phrase=="calculator")
         {
             cout<<"Brinks:";
             phased="Here's your calculator";
             AI.respond1(phased);
           calculator();

           //phrase="";
         }
         else if(phrase=="tell me date and time"||phrase=="date and time"||phrase=="show me date and time")
         {
             time1();
         }
         else if(phrase=="quiz"||phrase=="play quiz"||phrase=="start quiz")
         {
             quiz1();
         }
         else if(phrase=="snake"||phrase=="play snake"||phrase=="start snake")
         {
             cs=snake1();
         }
         else if(phrase=="what is my name"||phrase=="tell my name")
         {
             cout<<"Brinks:";
             AIG.respond1(c.name);
         }
         else if(phrase=="what is my id number"||phrase=="tell my id number"||phrase=="tell my id"||phrase=="what is my id")
         {
             cout<<"Brinks:";
             AIG.respond1(c.id);
         }
         else if(phrase=="what is my age"||phrase=="tell my age")
         {
             cout<<"Brinks:";AIG.respond1(c.age);

         }
         else if(phrase=="what is my gender"||phrase=="tell my gender")
         {
             cout<<"Brinks:";
             if(c.g=="m")
             AIG.respond1("male");
             else
                AIG.respond1("female");
         }
         else if(phrase=="flip a coin")
         {
             cout<<"Brinks:";
             if(k%2==0){
              phased="Heads it is!";
              AI.respond1(phased);
             }
              else{
              phased="Tails it is!";
              AI.respond1(phased);
              }
              k++;

         }
         else if(phrase=="play a game")
         {
             game();
         }
         else if(phrase=="what came first egg or chicken"||phrase=="what came first chicken or egg")
         {
             cout<<"\nBrinks:";
             phased="it appears the the human civilisation has been awfully preoccupied with that question";
             AI.respond1(phased);
         }
         else if(phrase=="help"||phrase=="what can you do")
         {
             cout<<"Brinks:";
             AI.respond1("here are some suggestions");
             cout<<" play a game";
             cout<<"\n flip a coin";
             cout<<"\n what is the weather";
             cout<<"\n what came first egg or chicken";
             cout<<"\n calculator\n";
         }
         else if(phrase=="what is a perfect question for you")
         {
             cout<<"\n Brinks:";
             AI.respond("i never thought about it");
         }

         else if(phrase=="bye")
         {
             AIG.respond1("Goodbye!");
             exit(0);
         }
        //cout << "\nYOU: ";    // User prompt
        //getline(cin, phrase);

        else{    cout << "Brinks: ";
                AI.respond(phrase);

        }   // Pass the user input to the learner and see if he can respond
    }
}

void gotoxym(int x,int y)
{
coordm.X=x;
coordm.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordm);
}

void introduction()
{
    int ch;
    clrscr();
    date1();
    time1();
/* cout<<"KIET GROUP OF INSTITUTION,GHAZIABAD \n";
 cout<<"INNOTECH 2K17 \n";*/
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t K3AL\n";
 cout<<"\t\t\t\t\t\t\t\t\t\t******\n\n\n\n";
 cout<<"\t\t\t\t\t\t\t\t->IF YOU ALREADY HAVE AN IDENTITY :PRESS 1 \n\n";
 cout<<"\t\t\t\t\t\t\t\t->TO CREATE A NEW IDENTITY :PRESS 2 \n";
 cout<<"\n\n\n\n\t\t\t\t\t\t\t\t->YOU:";
 cin>>ch;
 clrscr();
 switch(ch)
 {
case 1:
    time1();
    gotoxym(2,20);
    cout<<"\n\t\t\t\t\t\t\t\t   ENTER YOUR ID CODE:";
    cin>>identity;
    prelogin(identity);
    cout<<"\n\n\n       \t\t\t\t\t\t\t\t ->PRESS ENTER TO CONTINUE";
    getch();
    break;
case 2:
    clrscr();
    login();
    getch();
    break;
default:
    exit(0);
 }
}

void instructions()
{
    clrscr();
    date1();
    time1();
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t HACKATHON 2K18\n";
    cout<<"\t\t\t\t\t\t\t\t\t***************\n";
    cout<<"\n \t\t\t\t\t\t\t\t    WELCOME TO OUR PROJECT\n";
    cout<<"\t\t\t\t\t\t\t\t   ************************";
    cout<<"\n  \t\t\t\t\t\t\t\t             BRINKS        \n";
    cout<<"\t\t\t\t\t\t\t\t\t    ******\n";
    cout<<"\n \t\t\t\t\t\t\t\t          INSTRUCTIONS\n";
    cout<<"\t\t\t\t\t\t\t\t\t **************";
    //cout<<"\n \t\t\t\t\t\t\t\t *USE SMALL LETTERS THROUGHOUT*";
    cout<<"\n \t\t\t\t\t\t\t     *USE OF SLANG LANGUAGE IS NOT ALLOWED*";
    cout<<"\n \t\t\t\t\t\t\t     *YOUR ID CODE IS LAST FOUR DIGITS OF YOUR ID NUMBER*";
    cout<<"\n \t\t\t\t\t\t\t     *ENTERING WRONG CHOICE WILL TERMINATE THE PROGRAM*";
    cout<<"\n \t\t\t\t\t\t\t     *SAY \"HI\" TO START A CONVESATION*\n";
    cout<<"\n \n\n\n\t\t\t\t\t\t\t    ->PRESS ENTER TO PROCEED";
    getch();
}

void login()
{
    clrscr();
    date1();
    time1();
    //system("COLOR 9E");
    cout<<"\n \n ID:";
    cin>>c.id;
    cout<<"\n NAME:";
    fflush(stdin);
    getline(cin,c.name);
    cout<<"\n \n AGE:";
    cin>>c.age;
    cout<<"\n\n GENDER (m/f):";
    cin>>c.g;
    //i=i+1;
    fstream y("blah.txt",ios::out|ios::app);
    y<<c.id;
    y<<"\n";
    y<<c.name;
    y<<"\n";
    y<<c.age;
    y<<"\n";
    y<<c.g;
    y<<"\n";
    y.close();
    cout<<"\n PRESS ENTER TO CONTINUE";
    //getch();

}

void prelogin(string identity)
{
    fstream x("blah.txt",ios::in);
    while(!x.eof())
    {

    x>>c.id;
    x>>c.name;
    x>>c.age;
    x>>c.g;
    //for(j=0;j<i;j++)    {

          //;
        if(identity==c.id)
            break;
       //  strcpy(nameg,c[i].name);
        //nameg=c.name;
   }
    //j=0;
    x.close();
//    fclose(fin);
}

void date1()
{

}

void calculator()
{
    double a,t=0;
    char o,ch2='n';
    int ch;
    system("COLOR F0");
    cout<<"\n PRESS 1 TO ADD";
    cout<<"\n PRESS 2 TO SUBTRACT";
    cout<<"\n PRESS 3 TO DIVIDE";
    cout<<"\n PRESS 4 TO MULTIPLY";
    cout<<"\n PRESS 5 TO MOD";

     while(ch2=='n')
     {
         cout<<"\nYOU : ";
        cin>>ch;
    switch(ch)
    {
    case 1:
        while(1)
              {
                cin>>a;
                cin>>o;
                if(o=='+')
                   t=a+t;
                else if(o=='=')
                {

                     t=a+t;
                     cout<<t;
                break;
                }
              }
              break;
   case 2:

        while(1)
              {
                cin>>a;
                cin>>o;
                if(o=='-')
                   t=a-t;
                else if(o=='=')
                {

                     t=a-t;
                     cout<<t;
                break;
                }
              }
              break;
   case 3:

        while(1)
              {
                  t=1;
                cin>>a;
                cin>>o;
                if(o=='/')
                   t=a/t;
                else if(o=='=')
                {

                     t=a/t;
                     cout<<t;
                break;
                }
              }
              break;
    case 4:

        while(1)
              {
                  t=1;
                cin>>a;
                cin>>o;
                if(o=='*')
                   t=a*t;
                else if(o=='=')
                {

                     t=a*t;
                     cout<<t;
                break;
                }
              }
              break;
    /*case 5:

        while(1)
              {
                cin>>a;
                cin>>o;
                if(o=='%')
                   t=a%t;
                else if(o=='=')
                {

                     t=a%t;
                     cout<<t;
                break;
                }
              }
              break;*/
    default:
        break;
              }
cout<<"\nBrinks:do you want to exit"<<"\nYOU:";
fflush(stdin);
cin>>ch2;
    }
}


int random(int n)
{
    int k;
    int randnum;
    srand(time(NULL));
    for(k=0;k<=1;k++)
    {
        randnum=rand()%MAX_NUM;
    }
    return(randnum);
}

void game()
{
    Learner AIg;
    int choice;
    system("COLOR F0");
   cout<<"\nBrinks:";
   AIg.respond1("let's play !");
   AIg.respond1("PRESS 1 TO PLAY QUIZ");
   AIg.respond1("PRESS 2 TO PLAY SNAKE");
   cout<<"YOU:";
   cin>>choice;
   //cs=snake1();
   switch(choice)
   {
   case 1:
       clrscr();
       quiz1();
       clrscr();
    //quiz();
    clrscr();
    break;
   case 2:
    cs=snake1();
    break;
   default:
    break;
   }
}

void quiz1()
{
    clrscr();
    system("COLOR F0");
    time1();
    cout<<"\nBrinks:";
    AIG.respond1("okay then,let's play!");
    cout<<"\nBrinks:";
    AIG.respond1("press enter to proceed");
    getch();
    clrscr();
    time1();
    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t RULES";
    cout<<"\n\t\t\t\t\t\t\t\t\t*******";
    cout<<"\n\t\t\t\t\t\t          ->QUIZ IS BASED ON C++          ";
    cout<<"\n\t\t\t\t\t\t          ->YOU WILL BE ASKED 25 QUESTIONS";
    cout<<"\n\t\t\t\t\t\t          ->EVERY QUESTION HAS 4 OPTIONS";
    cout<<"\n\t\t\t\t\t\t          ->YOU HAVE TO ENTER THE CORRECT OPTION";
    cout<<"\n\t\t\t\t\t                  ->4 POINTS WILL BE AWARDED FOR EVERY CORRECT ANSWER";
    cout<<"\n\t\t\t\t\t\t          ->0 WILL BE AWARDED FOR WRONG ANSWER";
    getch();
    clrscr();
    time1();
    quiz();
getch();
}
void kiet()
{
 gotoxym(20,5);
 system("COLOR F9");
 cout<<"\n\n\n\t\t\t\t    KKK     KKK\tIIIIIIIIIIII\tEEEEEEEEEEE\tTTTTTTTTTTTT  G    \n";
 gotoxym(20,6);
 cout<<"\n\n\n\t\t\t\t    KKK   KKK  \tIIIIIIIIIIII\tEEEEEEEEEEE\tTTTTTTTTTTTT  R    \n";
 gotoxym(20,7);
 cout<<"\n\n\n\t\t\t\t    KKK KKK    \t    IIII    \tEEE        \t    TTTT      O     \n";
 gotoxym(20,8);
 cout<<"\n\n\n\t\t\t\t    KKKKK      \t    IIII    \tEEEEEE     \t    TTTT      U    \n";
 gotoxym(20,9);
 cout<<"\n\n\n\t\t\t\t    KKKKK      \t    IIII    \tEEEEEE     \t    TTTT      P                      \n";
 gotoxym(20,10);
 cout<<"\n\n\n\t\t\t\t    KKK KKK    \t    IIII    \tEEE        \t    TTTT           \n";
 gotoxym(20,11);
 cout<<"\n\n\n\t\t\t\t    KKK   KKK  \tIIIIIIIIIIII\tEEEEEEEEEEE\t    TTTT      O   \n\n";
 gotoxym(20,12);
 cout<<"\n\n\n\t\t\t\t    KKK     KKK\tIIIIIIIIIIII\tEEEEEEEEEEE\t    TTTT      F   \n\n";
 gotoxym(20,14);
 cout<<"\n\n\n\t\t\t\t    IIII   N     N   SSSS   TTTT   IIII   TTTT   U  U   TTTT   IIII   OOOO   N     N \n";
 gotoxym(20,15);
 cout<<"\n\n\n\t\t\t\t     II    NN    N   S       TT     II     TT    U  U    TT     II    O  O   NN    N \n";
 gotoxym(20,16);
 cout<<"\n\n\n\t\t\t\t     II    N N   N   SSSS    TT     II     TT    U  U    TT     II    O  O   N N   N \n";
 gotoxym(20,17);
 cout<<"\n\n\n\t\t\t\t     II    N   N N      S    TT     II     TT    U  U    TT     II    O  O   N   N N \n";
 gotoxym(20,18);
 cout<<"\n\n\n\t\t\t\t    IIII   N     N   SSSS    TT    IIII    TT    UUUU    TT    IIII   OOOO   N     N \n";




 getch();
 system("COLOR F0");
}
