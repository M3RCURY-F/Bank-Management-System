#include "transaction.h"
#include <iostream>

using namespace std;

bool addBalance(Account accounts[], int accountCount, int accountId, int userId, double amount) {
    if (amount <= 0) return false;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].id == accountId && accounts[i].userId == userId) {
            accounts[i].balance += amount;
            return true;
        }
    }
    return false;
}

bool withdraw(Account accounts[], int accountCount, int accountId, int userId, double amount) {
    if (amount <= 0) return false;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].id == accountId && accounts[i].userId == userId) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                return true;
            }
            else {
                cout << "Insufficient funds available.\n";
                return false;
            }
        }
    }
    return false;
}

bool transfer(Account accounts[], int accountCount, int fromAccountId, int toAccountId, int userId, double amount) {
    if (amount <= 0) return false;

    int fromIndex = -1;
    int toIndex = -1;

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].id == fromAccountId && accounts[i].userId == userId) fromIndex = i;
        if (accounts[i].id == toAccountId) toIndex = i;
    }

    if (fromIndex != -1 && toIndex != -1 && accounts[fromIndex].balance >= amount) {
        accounts[fromIndex].balance -= amount;
        accounts[toIndex].balance += amount;
        return true;
    }
    return false;
}

bool payment(Account accounts[], int accountCount, int accountId, int userId, double amount) {
    if (amount <= 0) return false;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].id == accountId && accounts[i].userId == userId) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                return true;
            }
        }
    }
    return false;
}