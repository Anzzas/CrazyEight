#include <iostream>
#include "Player.h"


int main()
{
	Deck deck{};
	deck.shuffleDeck();

	PlayPile pile{};
	pile.putCard(deck.TakeCard()); // Put first random card on pile

	Player player1{}; // Main player
	player1.setName();

	Player CPU{ "CPU" }; // CPU player

	for (int i = 1; i < 8; i++) // Giving 7 cards to each player
	{
		player1.addToHand(deck.TakeCard());
		CPU.addToHand(deck.TakeCard());
	}

	while (true)
	{
		player1.playRound(pile, deck);


	}
}