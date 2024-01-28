#include <stdlib.h>
#include "deck.h"

/**
 * compare_cards - Compare two cards for sorting
 *
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 *
 * Return: Negative if card1 is smaller, positive if card2 is smaller, 0 if
 */
int compare_cards(const void *card1, const void *card2)
{
	const card_t *c1 = ((const deck_node_t *)card1)->card;
	const card_t *c2 = ((const deck_node_t *)card2)->card;

	if (c1->kind != c2->kind)
		return (c1->kind - c2->kind);

	return (find_index(c1->value) - find_index(c2->value));
}

/**
 * find_index - Find the index of a card value
 *
 * @value: Card value
 *
 * Return: Index of the card value
 */
int find_index(const char *value)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
	"10", "Jack", "Queen", "King"};

	for (int i = 0; i < 13; i++)
	{
		if (strcmp(value, values[i]) == 0)
			return (i);
	}
	return (-1);
}

/**
 * sort_deck - Sort a deck of cards
 *
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	qsort(*deck, 52, sizeof(deck_node_t), compare_cards);
}
