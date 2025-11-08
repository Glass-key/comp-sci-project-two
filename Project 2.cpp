#include <iostream>
#include <cstdlib> //for rand gen
#include <ctime> //for rand gen
using namespace std;

const int ROWS=5;
const int COLS=5;

//Void function for making the visible and hidden array 
void initializeBoards(int hiddenBoard[ROWS][COLS], char visibleBoard[ROWS][COLS])
{
	srand(time(0)); //seeding random generator
	int r,c;
	for(int r=0;r<ROWS;r++)
	{
		for(int c=0;c<COLS;c++)
	      {
	        hiddenBoard[r][c]=0; //fills array with 0
	        visibleBoard[r][c]='*'; //fills array with *
	      }
	  }

	//placing 3 traps 
	int trapsPlaced=0;
	while(trapsPlaced < 3)
	{
		//picks a random row and column using a random generator
		int r = rand()% ROWS;
		int c = rand()% COLS;
		
		//places the trap itself
		if(hiddenBoard[r][c] == 0)
		{
			hiddenBoard[r][c]=1;
			trapsPlaced++;
		}
	}
	
	//Places Treasure
	while(true)
	{
		int r = rand()% ROWS;
		int c = rand()% COLS;
		
		//places the Treasure itself
		if(hiddenBoard[r][c] == 0)
		{
			hiddenBoard[r][c]=2;
			break;
		}
	}		
}

//Void function for displaying Visible board
void displayBoard(char visibleBoard[ROWS][COLS])
{
	//Row and column headers 
	cout<< " ";
	for(int c=0 ;c <COLS ;c++)
	{
		cout<<c<<" ";
	}
	cout<<endl;

	//Displays the actual array
	for(int r=0;r<ROWS;r++)
	{
		cout <<r<< " "; //Header for Rows 
		for(int c=0;c<COLS;c++)
		{
	        cout<<visibleBoard[r][c]<<" "; //fills array with *
	    }
		cout<<endl;
	  }

}
//Void function for showing hidden board 
void showHiddenBoard(int hidden[ROWS][COLS])
{
    // print column headers
	cout<< " ";
	for(int c=0 ;c < COLS;c++)
	{
		cout<<c<<" ";
	}
	cout<<endl;
	
    // loop through rows and columns printing hidden[r][c]
	for(int r=0;r<ROWS;r++)
	{
		cout <<r<< " "; //Header for Rows
		for(int c=0; c<COLS;c++)
		{
			cout<<hiddenBoard[r][c]<<" ";
		}
		cout<<endl;
	}

    // prints legend
	cout<<"Legend: "<<endl;
	cout<<" Empty = 0"<<endl;
	cout<<" Trap = 1"<<endl;
	cout<<" Treasure = 2" <<endl;

}

//void function for player move
void playerMove(int hiddenBoard[ROWS][COLS], char visibleBoard[ROWS][COLS], int &playerScore)
{
	int row, col; 
	while(true)
	{
		cout<<"Enter row 0-4: "<<endl;
		cin>>row;
		cout<<"Enter Column 0-4: "<<endl;
		cin>>col;
	//Checks if user input is in range for Rows and Columns
		if (row >=0 && row < 5 && col >= 0 && col< 5)
		{
			if(visibleBoard[row][col]=='*') //Checks if cell is taken already
			{
				if(hiddenBoard[row][col] == 2) //Cell has Treasure
					{
						visibleBoard[row][col] = 'T';
						playerScore += 10;
						cout<<"You found Treasure! Awarded 10 points."<<endl;
					}
					else if(hiddenBoard[row][col] == 1) //Cell has a trap
					{
						visibleBoard[row][col] = 'X'
						playerScore -= 3;
						cout<<"Hit a trap. -3 points :( "<<endl;
					}
					else //Cell is empty
					{
						visibleBoard[row][col]= ' - ';
					}			
					break; // Move worked
				}
				else()
				{
					cout<<"Cell is filled! pick a different one. "<<endl; //Cell is filled picks a different one
				}	
				else
				{
					cout<<"Invaild. Input for rows and column should be 0-4"<<endl; //user didnt enter a number in range
				}
		}
}
	//Updating visible board
	int playerScore=0
	if(hiddenBoard[row][col] == 2)
	{
		visibleBoard[row][col] = 'T';
		playerScore += 10;
	}
	else if(hiddenBoard[row][col] == 1)
	{
		visibleBoard[row][col] = 'X'
		playerScore -= 3;
	}
	else
	{
		visibleBoard[row][col]= ' - ';
	}

}
//checks for treasure
bool checkTreasureFound(char hidden[][COLS], int row, int col) {
	if (hidden[row][col] == 'T'){
		hidden[row][col] = 'F'; 
		return true;
	}
return false;
}
bool playerMove(char visbile[][COLS], char hidden[][COLS], int &score, vector<string> &history){
int row, col;
cout <<"\nYour turn! Enter row and then a column (0-4): ";
cin >> row >> col;

if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
	cout << "Invalid . Enter numbers between 0 and 4." << endl;
	return false;
}
if(checkTreaseFound(hidden, row, col)) {
	cout << "You found a treasure!" << endl;
	visible[row][col] = 'T';
	score++;
	history.push_back("player found treasure at (" + to_string(row) + ", " + to_string(col) + ")");
}
else{
	cout << "You found no treasure." << endl;
	visible[row][col] = 'X';
	history.push_back("Player missed at(" + to_string(row) + ", " + to_string(col) + ")");
	}

	return true;
}
void computerMove(char visible[][COLS], char hidden[][COLS], int &compScore, vector<string> &history) {
    int row, col;
	do {
		row = rand() % ROWS;
		col = rand() % COLS;
	}
	While (visible[row][col] != '-' && visible[row][col] != 'X' && visbile[row][col] != 'T');

	cout << "Computer chose: (" << row << ", " << col << ")\n";

	if(checkTreasureFound(hidden, row, col)) {
		cout << "Computer found a treasure!\n";
		visible[row][col] = 'T';
		compScore++;
		history.push_back("Computer found treasure at (" + to_string(row) + ", " + to_string(col) + ")");
	} else {
		cout <<"Computer missed.\n";
		visible[row][col] = 'X';
		history.push_back("Computer missed at (" + to_string(row) + ", " + to_string(col) + ")");
	}
}

int main()
{

	srand(time(0));

	char visible[ROWS][COLS];
	char hidden[ROWS][COLS];
	int playerScore = 0;
	int computerScore = 0;
	vector<string> history;

	initalizeBoards(visible, hidden);

	cout << "=====================================\n";
	cout << "     ️   TREASURE HUNT GAME️\n";
	cout << "=====================================\n";
	cout << "Try to find more treasures than the computer!\n";

	const int MAX_TURNS = 10;
	int turns = 0;

	while (turns < MAX_TURNS) 
		{
			displayBoard(Visible);

			if (playerMove(visible, hidden, playerScore, history))
				computerMove(visible, hidden, computerScore, history);

			turns++;
			cout << "\n--- Current Scores --\n";
			cout << "Player: " << playerScore << " | Computer: " << computerScore << endl;
		}
	cout << "\n===== GAME OVER =====\n";
	displayBoard(visible);
	showHiddenBoard(hidden);
	showHistory(history);

	cout << "\nFinal Scores:\n";
	cout << "Player: " << playerScore << "\nComputer: " << computerScore << endl;

	if (playerScore > computerScore)
		cout << "You win!" << endl;
	else if (playerScore < computerScore)
		cout << "Computer Wins!" << endl;
	else
		cout << "It's a tie!" << endl;
	


	//End Credits
	cout<< "---------------------------------------------------------------------------------------"<<endl;
	cout<< "Name: Britnie Rodriguez and Elise O'Mara"<<endl;
	cout<< "EUID: bnr0128 and emo0094"<<endl;
	cout<< "Emails: britnierodriguez@my.unt.edu and eliseomara@my.unt.edu"<<endl;
	cout<<"Department: Computer science"<<endl;
	cout<<"Course: CSCE 1030.004"<<endl;
	cout<<"--------------------------------------------------------------------------------------"<<endl;




return 0;
}
