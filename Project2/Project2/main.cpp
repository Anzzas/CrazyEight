#include <iostream>
#include "CPU.h"

int main()
{
	std::cout << "\t\t\t\t\t\tWelcome to Crazy Eights !\n\n"
		<< "The first to have no card win !\n"
		<< "The rules are simple: choose a card to draw of the same color or value of the top pile's card !";

	for (int i = 1; i < 10; i++)
	{
		std::cout << "\n";
	}

	Deck deck{};
	deck.shuffle();

	PlayPile pile{};
	pile.putCard(deck.TakeCard()); // Put first random card on pile

	Player player1{}; // Main player
	player1.setName();

	CPU player2{}; // CPU player

	for (int i = 1; i < 8; i++) // Giving 7 cards to each player
	{
		player1.addToHand(deck.TakeCard());
		player2.addToHand(deck.TakeCard());
	}

	while (true)
	{
		if (player1.playRound(pile, deck))
			return 0;

		std::cout << "\n\n\n\n";

		if (player2.playRound(pile, deck))
			return 0;

		std::cout << "\n\n\n\n";
	}
}