// Games, Template Method example
// Mikhail Nesterenko
// 2/4/2014

#include <ctime>
#include <cstdlib>
#include <iostream>

using std::cout; using std::endl;

// template for any game where players take 
// turns to make moves
// and there is a winner
class Game{
public:
	Game():playersCount_(0), movesCount_(0), 
		playerWon_(noWinner){}

	// template method
	void playGame(const int playersCount = 0) {
		playersCount_ = playersCount;
		movesCount_=0;

		initializeGame();

		for(int i=0; !endOfGame(); i = (i+1) % playersCount_ ){
			makeMove(i);
			if (i==playersCount_-1) 
				++movesCount_; 
		}

		printWinner();
	}

	virtual ~Game(){}

protected:
	// primitive operations
	virtual void initializeGame() = 0;
	virtual void makeMove(int player) = 0;
	virtual void printWinner() = 0;
	virtual bool endOfGame() {
		return playerWon_ != noWinner;} // this is a hook
										// returns true if winner is decided
	static const int noWinner=-1;

	int playersCount_;
	int movesCount_;
	int playerWon_;
};


class Dice: public Game {
public:
	void initializeGame(){
		playersCount_ = numberPlayers_;
		for(int i = 0; i < 6; ++i){
			rolls[0][i] = 0;
			rolls[1][i] = 0;
		}
		srand(time(nullptr));
	}

	void printPrev(){
		cout << "Computer: \n";
		for(int i = 0; i < 5; ++i){
			cout << rolls[0][i] << " ";
		}
		cout << "\nTotal: " << rolls[0][5] << '\n';

		cout << "Player: \n";
		for(int i = 0; i < 5; ++i){
			cout << rolls[1][i] << " ";
		}
		cout << "\nTotal: " << rolls[1][5] << '\n';
	}

	void makeMove(int player){
		cout << "Previous Round: \n";
		printPrev();
		if(player == 0){
			cout << "Computer's Turn\n";
			if(rand()%2 == 0){
				cout << "Computer Passes.\n";
				++passes;
			}else{
				passes = 0;
				int sum = 0;
				cout << "Rolling: ";
				for(int i = 0; i < 5; ++i){
					rolls[0][i] = roll();
					cout << rolls[0][i] << " ";
					sum += rolls[0][i];
				}
				rolls[0][5] = sum;
				cout << "\nSum: " << sum << '\n';
			}
		}else{
			cout << "Player's Turn\n";
			char pass = 'N';
			cout << "Pass? (Y/N): ";
			std::cin >> pass;
			if(pass == 'N' || pass == 'n'){
				passes = 0;
				int sum = 0;
				for(int i = 0; i < 5; ++i){
					cout << "Rolling: ";
					rolls[1][i] = roll();
					cout << rolls[1][i] << " ";
					sum += rolls[1][i];
				}
				rolls[1][5] = sum;
				cout << "\nSum: " << sum << '\n';
			}else{
				cout << "Player Passes.\n";
				++passes;
			}
		}
	}

	int roll(){
		return rand() % 6 + 1;
	}

	void printWinner(){
		if(rolls[0][5] < rolls[1][5]){
			cout << "Player Wins\n";
		}else if(rolls[0][5] == rolls[1][5]){
			cout << "Tie!\n";
		}else{
			cout << "Computer Wins\n";
		}
	}

	bool endOfGame(){
		if(movesCount_ == 3 || passes >= 2){
			return true;
		}
		return false;
	}

private:
	static const int numberPlayers_ = 2;
	int rolls[2][6];
	int passes = 0;
};


// Monopoly - a concrete game implementing primitive 
// operations for the template method
class Monopoly: public Game {
public:  
	// implementing concrete methods
	void initializeGame(){
		playersCount_ = rand() % numPlayers_ + 1 ; // initialize players
	}

	void makeMove(int player) {
		if (movesCount_ > minMoves_){ 
			const int chance = 
			minMoves_ + rand() % (maxMoves_ - minMoves_);
			if (chance < movesCount_) playerWon_= player;
		}
	}

	void printWinner(){
		cout << "Monopoly, player "<< playerWon_<< " won in "
	   << movesCount_<< " moves." << endl;
	}

private:
	static const int numPlayers_ = 8; // max number of players
	static const int minMoves_ = 20; // nobody wins before minMoves_
	static const int maxMoves_ = 200; // somebody wins before maxMoves_
};

// Chess - another game implementing
//  primitive operations
class Chess: public Game {
public:
	void initializeGame(){
		playersCount_ = numPlayers_; // initalize players
		for(int i=0; i < numPlayers_; ++i) 
			experience_[i] = rand() % maxExperience_ + 1 ; 
	}

	void makeMove(int player){
		if (movesCount_ > minMoves_){
			const int chance = (rand() % maxMoves_) / experience_[player];
			if (chance < movesCount_) playerWon_= player;
		}
	}

	void printWinner(){
		cout << "Chess, player " << playerWon_ 
		<< " with experience " << experience_[playerWon_]
		<< " won in "<< movesCount_ << " moves over"
		<< " player with experience " << experience_[playerWon_== 0 ? 1:0] 
		<< endl;
	}

private:
	static const int numPlayers_ = 2;
	static const int minMoves_ = 2; // nobody wins before minMoves_
	static const int maxMoves_ = 100; // somebody wins before maxMoves_
	static const int maxExperience_ = 3; // player's experience
							  // the higher, the greater probability of winning
	int experience_[numPlayers_]; 
};

int main() {
	srand(time(nullptr));

	Game* gp = nullptr;

	// play chess 10 times
	/*
	for (int i = 0; i < 10; ++i){ 
		gp = new Chess;
		gp->playGame(); 
		delete gp;
	}
	  

	// play monopoly 5 times
	for (int i = 0; i < 5; ++i){
		gp = new Monopoly;
		gp->playGame(); 
		delete gp;
	}
	*/

	for(int i = 0; i < 5; ++i){
		cout << "NEW GAME========================================\n";
		gp = new Dice;
		gp->playGame();
		delete gp;
	}

	return 0;
}
