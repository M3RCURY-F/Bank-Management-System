#include "auth.h"
#include <cstring>
#include <iostream>

using namespace std;

int signUp(User users[], int* userCount, const char* username, const char* password) {
    if (*userCount >= MAX_USERS) {
        cout << "System user limit reached.\n";
        return -1;
    }
    for (int i = 0; i < *userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            cout << "Username is already taken.\n";
            return -1;
        }
    }
    int newId = *userCount + 1;
    users[*userCount].id = newId;
    strcpy_s(users[*userCount].username, username);
    strcpy_s(users[*userCount].password, password);
    (*userCount)++;
    return newId;
}

int login(User users[], int userCount, const char* username, const char* password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return users[i].id;
        }
    }
    return -1;
}