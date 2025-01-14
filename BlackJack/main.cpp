#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cctype>
using namespace std;

void lowerInput(string&);
void swap(string& a, string& b);
void shuffle(vector<string>&);
void playLearnGame(vector<string>&);
void printPlayerCards(const string&, const string&);
void printHouseCards(const string&, const string&);
int addValue(const vector<string>&);
void printbelow21(const vector<string>&, const vector<string>&, const int&);
void printexactly21(const vector<string>&, const vector<string>&, const int&);
void printabove21(const vector<string>&, const vector<string>&, const int&);

int main()
{
	cout << "____	          _         ____   |     / _____       _       ____ |      /\n";
	cout << "|   \\	|        / \\       /       |    /    |        / \\     /     |     /\n";
	cout << "|___/	|       /___\\     |        |---      |       /___\\   |      |---\n";
	cout << "|   \\	|      /     \\    |        |    \\    |      /     \\  |      |     \\\n";
	cout << "|___/	|____ /       \\    \\____   |     \\    \\__/ /       \\  \\____ |      \\\n";
	cout << "-----------------------------------------------------------------------------\n";

	cout << endl;

	cout << "Enter Difficulty:\n";
	cout << "1. Learn\n";
	cout << "2. Normal\n";
	cout << "3. Hard\n";
	cout << "4. Quit\n";
	cout << "-----------------\n";

	string input = "";
	cin >> input;

	lowerInput(input);

	if (input == "quit")
	{
		exit(0);
	}
	else
	{
		vector<string> deck = { "K C", "K D", "K H", "K S",
								"Q C", "Q D", "Q H", "Q S",
								"J C", "J D", "J H", "Q S",
								"10C", "10D", "10H", "10S",
								"9 C", "9 D", "9 H", "9 S",
								"8 C", "8 D", "8 H", "8 S",
								"7 C", "7 D", "7 H", "7 S",
								"6 C", "6 D", "6 H", "6 S",
								"5 C", "5 D", "5 H", "5 S",
								"4 C", "4 D", "4 H", "4 S",
								"3 C", "3 D", "3 H", "3 S",
								"2 C", "2 D", "2 H", "2 S",
								"A C", "A D", "A H", "A S" };

		if (input == "learn")
		{
			cout << endl;
			
			cout << "____                   ____    ___\n";
			cout << "|   \\   |     |  |     |      /   \\\n";
			cout << "|___/   |     |  |     |__    \\___\n";
			cout << "|   \\   |     |  |     |          \\\n";
			cout << "|    \\   \\___/   |____ |____  \\___/\n";
			cout << "-----------------------------------------\n";
			cout << "BlackJack (or 21) is known to be the fairest and easiest card game at casinos.\n";
			cout << "The goal of the game is to get as close to or exactly 21 without going over.\n"; 
			cout << "If you go over, then it's called a \"bust\" and you automatically lose.\n";
			cout << "You compete with the casino (aka the House) and maybe other people that join in on the table.\n";
			cout << "The person that is closest to 21 wins that round.\n";
			cout << "If two or more people have the same number, closest and under 21, then it's called a \"tie\" and the bets are returned without any adjustment.\n";
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout << "Bets are placed before the cards are passed around the table.\n";
			cout << "You must match the highest bet on the table before playing.\n";
			cout << "------------------------------------------------------------\n";
			cout << "Cards have different values.\n";
			cout << "King, Queen and Jack have a value of 10.\n";
			cout << "Cards 10 - 2 have the face value.\n";
			cout << "Ace has a value of 11 or 1 depending on the choice of the player.\n";
			cout << "-----------------------------------------------------------------\n";
			cout << "The House deals the cards clockwise until every player (including the House) recieves 2 cards.\n";
			cout << "Everyone's cards will be shown face up so everyone at the table knows who has what cards.\n";
			cout << "Typing \"Hit\" will add another card to your pile.\n";
			cout << "Typing \"Hold\" will not add another card to your pile and must wait until everyone \"holds\".\n";
			cout << "--------------------------------------------------------------------------------------------\n";

			playLearnGame(deck);
		}
	}

	return 0;
}

void lowerInput(string& input)
{
	for (int i = 0; i < input.size(); ++i)
	{
		tolower(input[i]);
	}
}

void swap(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

void shuffle(vector<string>& deck)						// Shuffles cards
{
	for (int i = 1; i <= 1000; ++i)
	{
		random_device shuffleCards1;
		random_device shuffleCards2;
		uniform_int_distribution<int> dist(0, 51);

		int firstCard = dist(shuffleCards1);
		int secondCard = dist(shuffleCards2);

		swap(deck[firstCard], deck[secondCard]);
	}
}

void printHouseCards(const string& card1, const string& card2)
{
	cout << string(39, ' ');
	cout << "House Cards\n";
	cout << string(35, ' ');
	cout << "_____	_____\n";
	cout << string(35, ' ');
	cout << "|   |	|   |\n";
	cout << string(35, ' ');
	cout << "|" << card1 << "|	|???|\n";
	cout << string(35, ' ');
	cout << "|___|	|___|\n";
	cout << endl;
}

void printPlayerCards(const string& card1, const string& card2)
{
	cout << string(39, ' ');
	cout << "Your Cards\n";
	cout << string(33, ' ');
	cout << "_______	_______\n";
	cout << string(33, ' ');
	cout << "|     |	|     |\n";
	cout << string(33, ' ');
	cout << "|     |	|     |\n";
	cout << string(33, ' ');
	cout << "| " << card1 << " |	| " << card2 << " |\n";
	cout << string(33, ' ');
	cout << "|     |	|     |\n";
	cout << string(33, ' ');
	cout << "|_____|	|_____|\n";
	cout << endl;
}

int addValue(const vector<string>& cards)
{
	int playerValue = 0;
	for (int i = 0; i < cards.size(); ++i)
	{
		string card = cards[i];																	
		if (card[0] == 'K' || card[0] == 'Q' || card[0] == 'J' || card[0] == '1')
		{
			playerValue += 10;
		}
		else if (card[0] == 'A')
		{
			cout << "You have an Ace!! Type in \"11\" or \"1\" to add the value of the card!\n";

			int aceValue = 0;
			cin >> aceValue;

			if (aceValue != 11 || aceValue != 1)
			{
				bool incorrectInput = true;
				while (incorrectInput)
				{
					cout << "You can only choose \"11\" or \"1\"\n";
					cin >> aceValue;

					if (aceValue == 11 || aceValue == 1)
					{
						incorrectInput = false;
					}
				}
			}
			playerValue += aceValue;
		}
		else
		{
			int charToInt = card[0] - '0';
			playerValue = playerValue + charToInt;
		}
	}
	return playerValue;
}

void printbelow21(const vector<string>& deck, const vector<string>& playerCards, const int& playerValue)	// Deck of cards, Cards that the player has, Value of the cards the player has	
{																											// I need to change the values of Aces beacuse it asks for the ace input of the player
	int countOfSuccessCards = 0;
	vector<string> copy = playerCards;
	for (int i = 0; i < deck.size(); ++i)
	{
		copy.push_back(deck[i]);
		int value = addValue(copy);
		if (value < 21)
		{
			++countOfSuccessCards;
		}
		copy.pop_back();
	}
	cout << "You have a " << (1 / countOfSuccessCards) << "% chance of pulling a card that will keep your value below 21.\n";
}

void printexactly21(const vector<string>& deck, const vector<string>& playerCards, const int& playerValue)
{
	int countOfSuccessCards = 0;
	vector<string> copy = playerCards;
	for (int i = 0; i < deck.size(); ++i)
	{
		copy.push_back(deck[i]);
		int value = addValue(copy);
		if (value == 21)
		{
			++countOfSuccessCards;
		}
		copy.pop_back();
	}
	cout << "You have a " << (1 / countOfSuccessCards) << "% chance of pulling a card that will get you exactly 21.\n";
}

void printabove21(const vector<string>& deck, const vector<string>& playerCards, const int& playerValue)
{
	int countOfSuccessCards = 0;
	vector<string> copy = playerCards;
	for (int i = 0; i < deck.size(); ++i)
	{
		copy.push_back(deck[i]);
		int value = addValue(copy);
		if (value > 21)
		{
			++countOfSuccessCards;
		}
		copy.pop_back();
	}
	cout << "You have a " << (1 / countOfSuccessCards) << "% chance of pulling a card that will get you above 21.\n";
}

void playLearnGame(vector<string>& deck)				// Plays learn game
{
	bool gameOver = false;
	while (!gameOver)
	{
		shuffle(deck);

		cout << string(30, ' ');
		cout << "Let's play a practice round!\n";
		cout << string(30, ' ');
		cout << "----------------------------\n";

		vector<string> player = { deck[0], deck[2] };
		vector<string> house = { deck[1] , deck[3] };
		deck.erase(deck.begin(), deck.begin() + 3);

		printHouseCards(house[0], house[1]);
		printPlayerCards(player[0], player[1]);
		int playerValue = addValue(player);
		cout << string(35, ' ');
		cout << "----------------------------------" << endl;

		cout << "Your value of cards equal to: " << playerValue << endl;
		cout << "-----------------------------\n";
		printbelow21(deck, player, playerValue);
		printexactly21(deck, player, playerValue);
		printabove21(deck, player, playerValue);

		gameOver = true;
	}
}