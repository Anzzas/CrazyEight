#include "Player.h"

void Player::setName()
{
	std::cout << "Player name: ";
	std::cin >> m_name;
}

const std::string& Player::getName() const { return m_name; }

bool Player::hasWon() const
{
	if (m_hand.empty())
	{
		std::cout << this->getName() << " has no card left!\n"
				  << this->getName() << " won!\n\n";

		return true;
	}

	return false;
}

void Player::displayHand() const
{
	std::cout << "\t\tDeck:\n\n";

	for (size_t i{ 0 }; i < m_hand.size(); i++)
	{
		std::cout << "\t#" << i << " " << m_hand[i] << "\n";
	}
	std::cout << "\n\n";
}

void Player::addToHand(const Card& card)
{
	m_hand.emplace_back(card);
}

bool Player::playRound(PlayPile& pile, Deck& deck)
{

	const Card& topCard{ pile.getTopCard() };

	std::cout << "It is your turn " << m_name << ".\n";
	std::cout << "The top pile card is:\t" << topCard << "\n\n";

	bool matchingCard{};
	for (const auto& e : m_hand)
	{
		if (e.isCardMatching(topCard))
		{
			matchingCard = true;
			break;
		}
	}

	if (!matchingCard) // If no matching card found in the deck
	{
		if (deck.getDeck().empty())
		{
			deck.reset();
			deck.shuffle();
		}

		std::cout << "You do not have any matching card !\n";
		std::cout << "Picking up a new card ...\n";
		const Card newCard{ deck.TakeCard() };
		this->addToHand(newCard);

		std::cout << "You got a " << newCard << "\n";

		if (!newCard.isCardMatching(topCard))
		{
			std::cout << "... but you cannot play this card !\n\n";
			return false;
		}
	}

	this->displayHand();

	while (true)
	{

		std::cout << "Choose the card's number you want to play: ";
		int choice{};
		std::cin >> choice;

		if (choice < 0 || choice > static_cast<int>(m_hand.size() - 1))
		{
			std::cout << "You entered a wrong number !\n\n";
			continue;
		}
		else if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You did not enter a number ! Try again.\n\n";
			continue;
		}
		
		const Card& selectedCard{ m_hand[static_cast<size_t>(choice)] };

		if (!selectedCard.isCardMatching(topCard))
		{
			std::cout << "The selected Card does not match neither the top card value and color !\n";
			std::cout << "Please select a matching color or value card.\n\n";
			continue;
		}

		std::cout << m_name << " played " << selectedCard << " !\n";
		std::cout << selectedCard << " is now on top of the pile.\n\n";
		pile.putCard(selectedCard); // Putting valid selected card on top of the pile
		m_hand.erase(m_hand.begin() + choice); // Delete selected card from m_hand

		return this->hasWon();
	}
}