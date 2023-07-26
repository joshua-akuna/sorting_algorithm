#include "deck.h"
#include <string.h>

/**
 * cards_comparator - the algorihtm used to compares two cards
 *	structure in a doubly linked list of type dect_node_t.
 * @card_a: the node to the first card struct.
 * @card_b: the node to the second cards struct.
 * Return: a positive interger if card_a is greater than card_b
 *	a negative interger if card_a is less than card_b
 *	else 0.
 */
int cards_comparator(const void *card_a, const void *card_b)
{
	int index1, index2;
	const deck_node_t *card1 = *(const deck_node_t **)card_a;
	const deck_node_t *card2 = *(const deck_node_t **)card_b;
	static const char * const values[] = {
		"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
		"10", "Jack", "Queen", "King"
	};

	/* compares the kind of cards */
	if (card1->card->kind != card2->card->kind)
		return (card1->card->kind - card2->card->kind);

	/* If the cards are of same kinds, compare their values */
	if (card1->card->value != card2->card->value)
	{
		for (index1 = 0; index1 < 13; ++index1)
			if (strcmp(card1->card->value, values[index1]) == 0)
				break;

		for (index2 = 0; index2 < 13; ++index2)
			if (strcmp(card2->card->value, values[index2]) == 0)
				break;
		return (index1 - index2);
	}

	/* return 0 if both cards are of the same kind and value */
	return (0);
}

/**
 * sort_deck - sorts a deck of 52 cards in ascending order.
 * @deck: the deck of cards the sort.
 */
void sort_deck(deck_node_t **deck)
{
	int num_cards = 0, i;
	deck_node_t *current = NULL;
	deck_node_t **temp_deck = NULL;

	/* counts the number of cards */
	for (current = *deck; current; current = current->next)
		num_cards++;

	/* create an array to hold pointers to deck nodes */
	temp_deck = (deck_node_t **)malloc(sizeof(deck_node_t *) * num_cards);
	if (!temp_deck)
		exit(1);

	/* Fill the temp_deck with deck nodes */
	current = *deck;
	for (i = 0; i < num_cards; i++)
	{
		temp_deck[i] = current;
		current = current->next;
	}

	/* sorts the array using qsort */
	qsort(temp_deck, num_cards, sizeof(deck_node_t *), cards_comparator);

	/* relink the deck nodes to reflect the sorted order */
	for (i = 0; i < num_cards - 1; ++i)
	{
		temp_deck[i]->next = temp_deck[i + 1];
		temp_deck[i + 1]->prev = temp_deck[i];
	}

	/* The last node in the array should be the last node in the sorted deck */
	temp_deck[num_cards - 1]->next = NULL;

	/* Update the deck pointer to the first node of the sorted deck */
	*deck = temp_deck[0];

	free(temp_deck);
}
