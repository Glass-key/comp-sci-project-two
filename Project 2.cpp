/*
Code for project two 
*/

#include <iostream>
#include <cstdlib> //for rand gen
#include <ctime> //for rand gen
using namespace std;

//Void function for making the visible and hidden array 
void initializeBoards(int hidden[ROWS][COLS, char visible[ROWS][COLS])
{
	for(int r=0;r<ROWS;r++)
	{
		for(int c=0;c<COLS;c++)
	      {
	        hiddenBoard[r][c]=0;
	        visibleBoard[r][c]='*';
	      }
	  }
}

//Placing traps 
int placingTraps(f


int main(){


	//Randomly place Treasure and traps on hiddenBoard 

	srand(time(0));
	int trap=1;
	for(int r=0;r<ROWS;r++)
	{
		for(int c=0;c<COLS;c++)
	      {
					while(
					cout<<"Pick random Row: "<<r<<" and random column: "<<c;
					r=rand()%5+0;
					c=rand()%5+0;
	        
	
	        
	      }
	  }




	
	//displaying visible array
	for (int r=0;r<ROWS;r++)
	{
		for(int c=0;c<COLS;c++)
	      {
	        cout<< visibleBoard[r][c] <<" ";
	      }
	    cout<<endl;
	  } 


return 0;
}
