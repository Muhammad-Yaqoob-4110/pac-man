#include<iostream>
#include<fstream>
#include<windows.h>
#include<cmath>
#include<time.h>
using namespace std;
void loadFile();
char maze[24][71];
void printMaze();
int pacmanX=9;
int pacmanY=31;
void gotoxy(int x, int y);
void movePacmanLeft();
void movePacmanRight();
void movePacmanUp();
void movePacmanDown();
void calculateScore();
void printScore();
int score=0;
int ghostX=19;
int ghostY=25;
int previousItem=' ';
int ghostDirection();
bool ghostMoment();
void moveGhostLeft();
int calculateDistance(int pacmanX ,int pacmanY , int ghostX ,int ghost);
main(){
    loadFile();
    gotoxy(pacmanY,pacmanX);
    cout<<"P";
    gotoxy(ghostY,ghostX);
    cout<<"G";
    system("cls");
    printMaze();
    bool temp=false;
    int lives=3;;
    bool gameRunning=true;
    int value = 1;
    while(gameRunning){
        Sleep(100);
        if(temp==true)
        gameRunning=ghostMoment();  
    //    value = calculateDistance(pacmanX , pacmanY ,ghostX ,ghostY);
        if(value == 0){
            moveGhostLeft();
        }
        if(GetAsyncKeyState(VK_LEFT)){
            movePacmanLeft();
            temp=true;
        }
        if(GetAsyncKeyState(VK_RIGHT)) {
            movePacmanRight();
            temp=true;
        }
        if(GetAsyncKeyState(VK_UP)) {
            movePacmanUp();
            temp=true;
        }
        if(GetAsyncKeyState(VK_DOWN)) {
            movePacmanDown();
            temp=true;
        }
        if(GetAsyncKeyState(VK_ESCAPE)) {
            gameRunning=false;
        }
        if(score==466){
            gotoxy(34,24);
            cout<<"You Win";
            gameRunning=false;
        }
        if(pacmanX==ghostX && pacmanY==ghostY){
            lives--;
            if(lives==0){
            gotoxy(34,24);
            cout<<"You Lost";
            gameRunning=false;
            }
        }
        printScore();
        gotoxy(25,24);
        cout<<"Lives:"<<lives;
        
    }  
}
void loadFile(){
    fstream f1;
    f1.open("maze.txt",ios::in);
    string line;
    for(int i=0;i<24;i++){
        getline(f1,line);
        for(int j=0;line[j]!='\0';j++){
            maze[i][j]=line[j];
        }
    }
}
void printMaze(){
    for(int i=0;i<24;i++){
        for(int j=0;j<71;j++){
            cout<<maze[i][j];
        }
        cout<<endl;
    }
}
void gotoxy(int x, int y) // Function Definition
{
 COORD coordinates;
 coordinates.X = x;
 coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void movePacmanLeft(){
    if(maze[pacmanX][pacmanY-1]==' ' || maze[pacmanX][pacmanY-1]=='.'|| maze[pacmanX][pacmanY-1]=='G'){
        maze[pacmanX][pacmanY]=' ';
        gotoxy(pacmanY,pacmanX);
        cout<<" ";
        pacmanY=pacmanY-1;
        if(maze[pacmanX][pacmanY]=='.'){
            calculateScore();
        }
        maze[pacmanX][pacmanY]='p';
        gotoxy(pacmanY,pacmanX);
        cout<<"P";
    }
}
void movePacmanRight(){
    if(maze[pacmanX][pacmanY+1]==' ' || maze[pacmanX][pacmanY+1]=='.'|| maze[pacmanX][pacmanY+1]=='G'){
        maze[pacmanX][pacmanY]=' ';
        gotoxy(pacmanY,pacmanX);
        cout<<" ";
        pacmanY=pacmanY+1;
        if(maze[pacmanX][pacmanY]=='.'){
            calculateScore();
        }
        maze[pacmanX][pacmanY]='p';
        gotoxy(pacmanY,pacmanX);
        cout<<"P";
    }
}
void movePacmanUp(){
    if(maze[pacmanX-1][pacmanY]==' ' || maze[pacmanX-1][pacmanY]=='.'|| maze[pacmanX-1][pacmanY]=='G'){
        maze[pacmanX][pacmanY]=' ';
        gotoxy(pacmanY,pacmanX);
        cout<<" ";
        pacmanX=pacmanX-1;
        if(maze[pacmanX][pacmanY]=='.'){
            calculateScore();
        }
        maze[pacmanX][pacmanY]='p';
        gotoxy(pacmanY,pacmanX);
        cout<<"P";
    }
}
void movePacmanDown(){
    if(maze[pacmanX+1][pacmanY]==' ' || maze[pacmanX+1][pacmanY]=='.'|| maze[pacmanX+1][pacmanY]=='G'){
        maze[pacmanX][pacmanY]=' ';
        gotoxy(pacmanY,pacmanX);
        cout<<" ";
        pacmanX=pacmanX+1;
        if(maze[pacmanX][pacmanY]=='.'){
            calculateScore();
        }
        maze[pacmanX][pacmanY]='p';
        gotoxy(pacmanY,pacmanX);
        cout<<"P";
    }
}
void calculateScore(){
    score++;
}
void printScore(){
    gotoxy(13,24);
    cout<<"Score:"<<score;
}
int ghostDirection(){
    srand(time(0));
    int result=1+(rand() % 4);
    return result;
}
bool ghostMoment(){
    int value=ghostDirection();
    if (value == 1)
{
if (maze[ghostX][ghostY - 1] == ' ' || maze[ghostX][ghostY - 1] == '.'|| maze[ghostX][ghostY - 1] == 'P')
{
maze[ghostX][ghostY] = previousItem;
gotoxy(ghostY,ghostX);
cout<<" ";
ghostY = ghostY - 1;
previousItem = maze[ghostX][ghostY];

maze[ghostX][ghostY] = 'G';
gotoxy(ghostY,ghostX);
cout<<"G";
if (maze[ghostX][ghostY - 1] == 'P')
{
return 0;
}

}
}
if (value == 2)
{
if (maze[ghostX][ghostY + 1] == ' ' || maze[ghostX][ghostY + 1] == '.'|| maze[ghostX][ghostY + 1] == 'P')
{
maze[ghostX][ghostY] = previousItem;
gotoxy(ghostY,ghostX);
cout<<" ";
ghostY = ghostY + 1;
previousItem = maze[ghostX][ghostY];

maze[ghostX][ghostY] = 'G';
gotoxy(ghostY,ghostX);
cout<<"G";
if (maze[ghostX][ghostY + 1] == 'P')
{
return 0;
}

}
}
if (value == 3)
{
if (maze[ghostX - 1][ghostY] == ' ' || maze[ghostX - 1][ghostY] == '.'|| maze[ghostX - 1][ghostY] == 'P')
{
maze[ghostX][ghostY] = previousItem;
gotoxy(ghostY,ghostX);
cout<<" ";
ghostX = ghostX - 1;
previousItem = maze[ghostX][ghostY];

maze[ghostX][ghostY] = 'G';
gotoxy(ghostY,ghostX);
cout<<"G";
if (maze[ghostX - 1][ghostY] == 'P')
{
return 0;
}

}
}
if (value == 4)
{
if (maze[ghostX + 1][ghostY] == ' ' || maze[ghostX + 1][ghostY] == '.'|| maze[ghostX + 1][ghostY] == '.')
{
maze[ghostX][ghostY] = previousItem;
gotoxy(ghostY,ghostX);
cout<<" ";
ghostX = ghostX + 1;
previousItem = maze[ghostX][ghostY];

maze[ghostX][ghostY] = 'G';
gotoxy(ghostY,ghostX);
cout<<"G";
if (maze[ghostX + 1][ghostY] == 'P')
{
return 0;
}
}
}
return 1;

}
int calculateDistance(int pacmanX ,int pacmanY , int ghostX ,int ghost){
    int arr[4]={1000 , 1000, 1000, 1000};
    arr[0] = sqrt(pow((pacmanX - ghostX),2) + (pow((pacmanY - (ghostY - 1)),2)));
    arr[1] = sqrt(pow((pacmanX - ghostX),2) + (pow((pacmanY - (ghostY + 1)),2)));
    arr[2] = sqrt(pow((pacmanX - (ghostX - 1)),2) + (pow((pacmanY - ghostY),2)));
    arr[3] = sqrt(pow((pacmanX - (ghostX + 1)),2) + (pow((pacmanY - ghostY),2)));
    int temp;
    int idx;
    temp = arr[0];
    for(int i=0; i<3; i++){
        if(arr[i] < temp){
            temp = arr[i];
            idx = i;
        }
    }
    return idx;  
}
void moveGhostLeft(){
if (maze[ghostX][ghostY - 1] == ' ' || maze[ghostX][ghostY - 1] == '.'|| maze[ghostX][ghostY - 1] == 'P')
{
maze[ghostX][ghostY] = previousItem;
gotoxy(ghostY,ghostX);
cout<<" ";
ghostY = ghostY - 1;
previousItem = maze[ghostX][ghostY];
maze[ghostX][ghostY] = 'G';
gotoxy(ghostY,ghostX);
cout<<"G";
}
}
