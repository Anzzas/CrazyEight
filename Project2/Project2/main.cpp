#include <iostream>
#include "CPU.h"
#include <array>

namespace Settings
{
	constexpr int g_PlayerNumber{ 2 };
}

bool playAgain()
{
	std::cout << "Do you want to play again ? (y / n): ";
	char c{};

	while (true)
	{
		std::cin >> c;

		if (c == 'y' || c == 'Y')
			return true;

		else if (c == 'n' || c == 'N')
			return false;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Wrong input, please enter 'y' or 'n': ";
	}
}

int main()
{
	while(true)
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

		std::array<std::unique_ptr<Player>, Settings::g_PlayerNumber> players{

			std::make_unique<Player>(),
			std::make_unique<CPU>(),
		};

		for (int i = 0; i < 7; i++) // Giving 7 cards to each player
		{
			for (const auto& e : players)
			{
				e->addToHand(deck.TakeCard());
			}
		}

		bool keepPlaying{ true };
		while (keepPlaying)
		{
			for (const auto& e : players)
			{
				if (e->playRound(pile, deck))
				{
					keepPlaying = false;
					break;
				}
				std::cout << "\n\n\n\n";
			}
		}
		if (playAgain())
			continue;

		return 0;
	}
}