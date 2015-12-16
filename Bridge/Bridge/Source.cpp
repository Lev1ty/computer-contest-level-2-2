/*
Deck
	Card
Error
Score
	Auction
AI
	Defending
	Dummy
	Declarer
*/


#include<iostream>
#include<string>
#include<vector>


using namespace std;


enum Suit_e
{
	Spade = 0, Heart, Diamond, Club
};


class Error__
{
public:
	Error__()
	{
	}
	~Error__()
	{
	}

private:
	class Card__
	{
	public:
		Card__()
		{
		}
		~Card__()
		{
		}
	private:
		const string elem_to_rank__ = "elem to rank error: function: switch, modulus";
		const string print_private__ = "print private members error: function: cout";
		const string Assign_Index__ = "assign index error: void func: assignment";
	};

	class Deck__
	{
	public:
		Deck__()
		{
		}
		~Deck__()
		{
		}
	private:
		const string init_deck__ = "init deck error: void func: initialize vector of Card";
		const string access_card__ = "access card error: func: return Card, possible return NULL";
		const string remove_card__ = "remove card error: void func: erase from array, adjust index number of remaining cards";
		const string shuffle__ = "shuffle error: void func: appply random number alg, swap cards, reassign index number of cards";
		const string print_deck__ = "print deck error: void func: cout";
	};

};


class Card
{
public:
	Card(int i_n) :elem_num(i_n) {}
	~Card() {}
	void Assign_Index(int&i) { index_num = i; }
	int Index() { return index_num; }
	int Elem() { return elem_num; }
	int Rank_num() { return rank_num; }
	int Suit_num() { return suit_num; }
	string Rank() { return rank; }
	string Suit() { return suit; }
	void print_private();
private:
	int index_num;
	int elem_num;
	int suit_num = elem_num / 13;
	int rank_num = elem_num % 13;
	string elem_to_rank(int&);
	string rank = elem_to_rank(elem_num);
	string suit_s[4] = { "Spade","Heart","Diamond","Club" };
	string suit = suit_s[suit_num];
};

string Card::elem_to_rank(int&elem_num) {
	elem_num %= 13;
	switch (elem_num) {
	case 0:return "2";
	case 1:return "3";
	case 2:return "4";
	case 3:return "5";
	case 4:return "6";
	case 5:return "7";
	case 6:return "8";
	case 7:return "9";
	case 8:return "10";
	case 9:return "J";
	case 10:return "Q";
	case 11:return "K";
	case 12:return "A";
	}
}

void Card::print_private() {
	cout << "Index_num: " << index_num << ' ';
	cout << "Elem_num: " << elem_num << ' ';
	cout << "Suit_num: " << suit_num << ' ';
	cout << "Rank_num: " << rank_num << ' ';
	cout << "Rank: " << rank << ' ';
	cout << "Suit: " << suit << ' ';
	cout << endl;
}


//class Suit
//{
//public:
//	enum Name
//	{
//		Spade, Heart, Diamond, Club
//	};
//	Suit(Name name):name(name)
//	{
//		init_suit(this->suit, name);
//	}
//	~Suit()
//	{
//	}
//	int access_card(int rank) {
//		return 
//	}
//private:
//	Name name;
//	vector<int>suit;
//	void init_suit(vector<int>&, Name&);
//};
//void Suit::init_suit(vector<int>&suit,Suit::Name&name) {
//	int start;
//	switch (name) {
//	case Spade:start = 0;break;
//	case Heart:start = 13;break;
//	case Diamond:start = 26;break;
//	case Club:start = 39;break;
//	}
//	for (int elem = start, int cnt = 0; cnt < 13; cnt++)
//		suit.push_back(elem);
//}


class Deck
{
public:
	Deck() { init_deck(); }
	~Deck()
	{
	}
	void reinit_deck() { deck.clear(); init_deck(); }
	void shuffle();
	void print_deck();
	Card access_card(const Suit_e&, const string&);
	void remove_card(const Suit_e&, const string&);
private:
	vector<Card>deck;
	void init_deck();
};

void Deck::init_deck() {
	for (int i = 0; i < 52; i++) {
		deck.push_back(Card(i));
		deck[i].Assign_Index(i);
	}
}

Card Deck::access_card(const Suit_e&suit, const string&rank) {
	//for (int i = 0; i < deck.size(); i++) {
	//	if (deck[i].Suit_num() == suit && (deck[i].Rank()).compare(rank)) {
	//		return deck[i];
	//	}
	//}
	for (Card&c : deck) {
		if (c.Suit_num() == suit&&c.Rank().compare(rank) == 0) {
			return c;
		}
	}
}

void Deck::remove_card(const Suit_e&suit, const string&rank) {
	const int&pos = access_card(suit, rank).Index();
	deck.erase(deck.begin() + pos);
	for (int i = pos; i < deck.size(); i++) {
		int index = deck[i].Index() - 1;
		deck[i].Assign_Index(index);
	}
}

void Deck::shuffle() {
	//Random rand = new Random();//intiailize new random generator
	//for (int i = deck.length - 1;i >= 1;i--)//shuffle algorithm designed so to-be-moved cards positions don't overlap
	//{
	//	int j = rand.nextInt(i), temp = deck[j];//set j to new random number every time
	//	deck[j] = deck[i];deck[i] = temp;//swap elem
	//}
	for (int i = deck.size() - 1; i >= 1; i--) {
		int j = rand() % i;
		deck[j].Assign_Index(i);
		deck[i].Assign_Index(j);
		Card temp = deck[j];
		deck[j] = deck[i];
		deck[i] = temp;
	}
}

void Deck::print_deck() {
	for (Card&c : deck)
		c.print_private();
}


class Auction
{
public:
	Auction(string bid_input) :bid_input(bid_input)
	{
	}
	~Auction()
	{
	}
	string Input() { return bid_input; }
	int Level() { return bid_num_level; }
	int Suit() { return bid_num_suit; }
private:
	string bid[7][5] = {
		{ "1C","1D","1H","1S","1NT" },
		{ "2C","2D","2H","2S","2NT" },
		{ "3C","3D","3H","3S","3NT" },
		{ "4C","4D","4H","4S","4NT" },
		{ "5C","5D","5H","5S","5NT" },
		{ "6C","6D","6H","6S","6NT" },
		{ "7C","7D","7H","7S","7NT" }
	};
	string bid_input;
	void input_to_num();
	int bid_num_level;
	int bid_num_suit;
};

void Auction::input_to_num() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			if (bid_input.compare(bid[i][j]) == 0) {
				bid_num_level = i;
				bid_num_suit = j;
			}
		}
	}
}


class Score
{
public:
	Score(Auction contract) :contract(contract)
	{
	}
	~Score()
	{
	}
	void Assign_Made(int made) { this->made = made; }
	int Made() { return made; }
	Auction Contract() { return contract; }
private:
	Auction contract;
	int made;
	//void made_to_points();
	int points;
};


class Player
{
public:
	Player()
	{
	}
	~Player()
	{
	}
private:
	vector<Auction>bid;
	vector<Card>hand;
};


int main() {
	Error__ error;
	Deck deck;
	Player N, E, S, W;
	return EXIT_SUCCESS;
}