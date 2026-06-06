#pragma once

const int MAX_USERS = 100;
const int MAX_ACCOUNTS = 100;
const int MAX_CARDS = 100;
const char DATA_FILE[] = "bank_records.txt";

struct User {
    int id;
    char username[50];
    char password[50];
};

struct Account {
    int id;
    int userId;
    double balance;
};

struct Card {
    int id;
    int accountId;
    bool isBlocked;
};


