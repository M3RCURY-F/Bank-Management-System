#include "account.h"

int createAccount(Account accounts[], int* accountCount, int userId) {
    if (*accountCount >= MAX_ACCOUNTS) return -1;

    int newId = *accountCount + 100;
    accounts[*accountCount].id = newId;
    accounts[*accountCount].userId = userId;
    accounts[*accountCount].balance = 0.0;
    (*accountCount)++;

    return newId;
}

bool verifyOwnership(Account accounts[], int accountCount, int accountId, int userId) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].id == accountId && accounts[i].userId == userId) {
            return true;
        }
    }
    return false;
}