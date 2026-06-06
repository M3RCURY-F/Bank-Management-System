#include "card.h"
#include "account.h"

int createCard(Card cards[], int* cardCount, Account accounts[], int accountCount, int accountId, int userId) {
    if (*cardCount >= MAX_CARDS) return -1;

    if (!verifyOwnership(accounts, accountCount, accountId, userId)) return -1;

    int newId = *cardCount + 5000;
    cards[*cardCount].id = newId;
    cards[*cardCount].accountId = accountId;
    cards[*cardCount].isBlocked = false;
    (*cardCount)++;

    return newId;
}

bool blockCard(Card cards[], int cardCount, int cardId, Account accounts[], int accountCount, int userId) {
    for (int i = 0; i < cardCount; i++) {
        if (cards[i].id == cardId) {
            if (verifyOwnership(accounts, accountCount, cards[i].accountId, userId)) {
                cards[i].isBlocked = true;
                return true;
            }
        }
    }
    return false;
}