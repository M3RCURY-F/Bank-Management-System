#pragma once
#include "types.h"

int createCard(Card cards[], int* cardCount, Account accounts[], int accountCount, int accountId, int userId);
bool blockCard(Card cards[], int cardCount, int cardId, Account accounts[], int accountCount, int userId);
