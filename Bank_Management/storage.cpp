#include "storage.h"
#include <fstream>
#include <iostream>

using namespace std;

void saveData(User users[], int userCount, Account accounts[], int accountCount, Card cards[], int cardCount) {
    ofstream outFile(DATA_FILE);
    if (!outFile) {
        cout << "System Error: Could not write records to disk.\n";
        return;
    }

    // Write counts first so the loader knows exactly how many loops to run
    outFile << userCount << " " << accountCount << " " << cardCount << "\n";

    // Write User data
    for (int i = 0; i < userCount; i++) {
        outFile << users[i].id << " " << users[i].username << " " << users[i].password << "\n";
    }

    // Write Account data
    for (int i = 0; i < accountCount; i++) {
        outFile << accounts[i].id << " " << accounts[i].userId << " " << accounts[i].balance << "\n";
    }

    // Write Card data
    for (int i = 0; i < cardCount; i++) {
        outFile << cards[i].id << " " << cards[i].accountId << " " << cards[i].isBlocked << "\n";
    }

    outFile.close();
}

void loadData(User users[], int* userCount, Account accounts[], int* accountCount, Card cards[], int* cardCount) {
    ifstream inFile(DATA_FILE);
    if (!inFile) {
        // No previous file exists (first system setup)
        *userCount = 0;
        *accountCount = 0;
        *cardCount = 0;
        return;
    }

    inFile >> *userCount >> *accountCount >> *cardCount;

    for (int i = 0; i < *userCount; i++) {
        inFile >> users[i].id >> users[i].username >> users[i].password;
    }

    for (int i = 0; i < *accountCount; i++) {
        inFile >> accounts[i].id >> accounts[i].userId >> accounts[i].balance;
    }

    for (int i = 0; i < *cardCount; i++) {
        inFile >> cards[i].id >> cards[i].accountId >> cards[i].isBlocked;
    }

    inFile.close();
}