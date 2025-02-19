#include "CPU.h"

bool CPU::playRound(PlayPile& pile, Deck& deck)
{

	const Card& topCard{ pile.getTopCard() };

	std::cout << "It is CPU turn.\n";
	std::cout << "The top pile card is:\t" << topCard << "\n\n";

	for (auto it{ m_hand.begin() }; it != m_hand.end(); it++)
	{
		if (it->isCardMatching(topCard))
		{
			Card selectedCard{ *it };
			m_hand.erase(it); // remove card from hand 

			std::cout << "CPU played " << selectedCard << " !\n";
			std::cout << selectedCard << " is now on top of the pile.\n\n";
			pile.putCard(selectedCard); // Putting valid selected card on top of the pile
			return this->hasWon();
		}
	}


	if (deck.getDeck().empty())
	{
		deck.reset();
		deck.shuffle();
	}

	std::cout << "CPU does not have any matching card !\n";
	std::cout << "Picking up a new card ...\n";
	const Card newCard{ deck.TakeCard() };
	this->addToHand(newCard);

	std::cout << "CPU got a " << newCard << "\n";

	if (!newCard.isCardMatching(topCard))
	{
		std::cout << "... but CPU cannot play this card !\n\n";
		return false;
	}
	else
	{
		std::cout << "CPU played " << m_hand.back() << " !\n";
		std::cout << m_hand.back() << " is now on top of the pile.\n\n";
		pile.putCard(m_hand.back());
		m_hand.pop_back();
		return this->hasWon();
	}
}