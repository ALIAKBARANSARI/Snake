#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

bool GameOver;
const int width=20;
const int height=20;
int x,y,fruitx,fruity;
int score;
int tailx[100];
int taily[100];
int ntail=0;
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void setup()
{
	GameOver=false;
	dir =STOP;
	x=width/2;
	y=height/2;
	fruitx=(rand()%width +rand())%width;
    fruity=(rand()%height +rand())%height;
	score=0;
	
}
void draw()
{
	
	system("cls");
	
	
	for(int i=0;i<width+1;i++)
	 cout<<"#";
	 cout<<endl;
	 
	 for(int i=0;i<height;i++)
	 {
	 	for(int j=0;j<width;j++)
	 	{
	 		if(j==0)
	 		cout<<"#";
	 		
	 		else if(i==y&&j==x)
	 		cout<<"O";
	 		
	 		else if(i==fruity&&j==fruitx)
	 		cout<<"f";
	 		
	 		
	 		else
	 		{
	 			bool print=false;
	 			for(int k=0;k<ntail;k++)
	 			   {
				   if(tailx[k]==j&&taily[k]==i)
	 			   {
				       cout<<"o";
	 			    print =true;
	 	       	    }
	 	          }
	 	          if(!print)
			     cout<<" ";
	     	}   
	 		if(j==width-1)
	 		cout<<"#";
		 }
		 cout<<endl;
	 }
	 
	 
	 
	 
	 	for(int i=0;i<width+1;i++)
	 cout<<"#";
	 cout<<endl;
	 
	 cout<<"SCORE="<<score<<endl;
	
}
void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
				dir=LEFT;
				break;
			case 'w':
				dir=UP;
				break;
			case 'd':
				dir=RIGHT;
				break;
			case 's':
				dir=DOWN;
				break;
			case 'x':
			   GameOver=true;
			   break;
		}
	}

	
}
void logic()
{
	int prev1x=tailx[0];
	int prev1y=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prev1x;
		taily[i]=prev1y;
		prev1x=prev2x;
		prev1y=prev2y;
	}
	
	
	
	switch(dir)
	{
		case LEFT:
	    	x--;
	    	break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
	}
	
	if(x<0||x>width||y<0||y>height)
	 GameOver=true;
	 
	 for(int i=0;i<ntail;i++)
	 {
	 	if(tailx[i]==x&&taily[i]==y)
	 	  GameOver=true;
	 }
	 
	 if(x==fruitx&&y==fruity)
	 {
	 	score+=10;
	 	fruitx=(rand()%width +rand())%width;
	    fruity=(rand()%height +rand())%height;
	 	ntail++;
	 }
	
}

int main()
{
	
	setup();
	while(!GameOver)
	{
		draw();
		input();
		logic();
		Sleep(250);
	}
}
