/*GROUP MEMBERS: 1. IRADUKUNDA OLIVIER    222005508
                2.  UMUTESI ROSE          222002123 */
                
                // Hangman Game

#include<iostream>
#include<random>
#include<vector>

using namespace std;
string words[] = {"apple","beautiful","potatoes"};
string choosen;

typedef std::uniform_int_distribution<> rand_t;
string random_choice(){
	std::random_device rd;
    std::mt19937 gen(rd()); 
    rand_t distribution(0,5);
    return words[distribution(gen)];
}

int return_num_of_char(string a){
	int i = 0;
	int num_of_char = 0;
	while(a[i] != '\0'){
		i++;
		num_of_char++;
	}
	
	return num_of_char;
}

int selected_word(string word){
	int i = 0;
	while(i<5){
		if(words[i] == word){
			return i;
		} 
	}
	return -1;
}

// function declaration

void greet();
void display_misses(int misses);
void display_status(std::vector<char> incorrect,string answer);
void end_game(string answer, string codeword);

int main()
{
	greet(); // function call
	
	string codeword=random_choice();
	int num_of_char = return_num_of_char(codeword); 
	string answer = "";
	for(int i = 0; i < num_of_char;i++){
		answer += "_";
	}
	int misses=0;
	vector<char> incorrect;
	bool guess=false;
	char letter;
	
	
	while(answer!=codeword && misses < 6)
	{
	display_misses(misses);	 //function call
	display_status(incorrect, answer);  //function call
	
	cout<<"\n\n Guess a letter: ";
	cin>>letter;
	
	for(int i=0;i<codeword.length(); i++)
	{
		if(letter==codeword[i]){
			answer[i]=letter;
			guess=true;
		}
	}
	if(guess)
	{
		cout<<"\nCorrect!\n";
	}
	else
	{
		cout<<"\nIncorrect! You Lose.\n";
		incorrect.push_back(letter);
		misses++;
	}
	guess= false;
	}
	
	end_game(answer, codeword);  //function call
	
	return 0;
}

// Function Definition
void greet()
{
	cout<<"====================\n";
	cout<<"Hangman: The Game\n";
	cout<<"====================\n";
	cout<<"Instructions: Save your friend from being hanged by guessing the letters.\n";
	
}
void display_misses(int misses)
{
	if(misses==0)
	{
		cout<<"  +---+  \n";
		cout<<"  |   |  \n";
		cout<<"      |  \n";
		cout<<"      |  \n";
		cout<<"      |  \n";
		cout<<"      |  \n";
		cout<<" =========  \n";		
	}
	else if(misses==1)
	{
			cout<<"  +---+  \n";
		cout<<"  |   |  \n";
		cout<<"  o   |  \n";
		cout<<"      |  \n";
		cout<<"      |  \n";
		cout<<"      |  \n";
		cout<<" =========  \n";	
	}
	else if(misses==2)
	{
		cout<<"  +---+  \n";
		cout<<"  |   |  \n";
		cout<<"  o   |  \n";
		cout<<"  |   |  \n";
		cout<<"      |  \n";
		cout<<"      |  \n";
		cout<<" =========  \n";	
	}
	else if(misses==3)
	{
		cout<<"  +---+  \n";
		cout<<"  |   |  \n";
		cout<<"  o   |  \n";
		cout<<" /|   |  \n";
		cout<<"      |  \n";
		cout<<"      |  \n";
		cout<<" =========  \n";	
	}
	else if(misses==4)
	{
		cout<<"  +---+  \n";
		cout<<"  |   |  \n";
		cout<<"  o   |  \n";
		cout<<" /|\\ |  \n";
		cout<<"      |  \n";
		cout<<"      |  \n";
		cout<<" =========  \n";
	}
	else if(misses==5)
	{
		cout<<"  +---+  \n";
		cout<<"  |   |  \n";
		cout<<"  o   |  \n";
		cout<<" /|\\ |  \n";
		cout<<"      |  \n";
		cout<<" /    |  \n";
		cout<<" =========  \n";	
	}
	else if(misses==6)
	{
		cout<<"  +---+  \n";
		cout<<"  |   |  \n";
		cout<<"  o   |  \n";
		cout<<" /|\\ |  \n";
		cout<<" / \\ |  \n";
		cout<<"      |  \n";
		cout<<" =========  \n";
	}
}
void display_status(vector<char> incorrect, string answer)
{
	cout<<"Incorrect Guesses: \n";
	for(int i=0; i<incorrect.size(); i++)
	{
		cout<<incorrect[i]<<" ";
	}
	cout<<"\nCodeword:\n";
	
	for(int i=0;i<answer.length(); i++)
	{
		cout<<answer[i]<<" ";
	}
}

void end_game(string answer, string codeword)
{
	if(answer==codeword)
	{
		cout<<"You Win\n";
		cout<<"Congratulation!\n";
	}
	else
	{
		cout<<"On no! It is hanged!\n";
	}
}
