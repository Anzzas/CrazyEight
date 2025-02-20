#include <iostream>
#include "CPU.h"
#include <array>

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

	std::array<Player, 2> players{

		Player{},
		CPU{},
	};

	for (int i = 1; i < 8; i++) // Giving 7 cards to each player
	{
		for (auto& e : players)
		{
			e.addToHand(deck.TakeCard());
		}
	}

	while (true)
	{
		for (auto& e : players)
		{
			
			if (e.playRound(pile, deck))
				return 0;

			std::cout << "\n\n\n\n";
		}
	}
}