#pragma once
#include "types.h"

bool addBalance(Account accounts[], int accountCount, int accountId, int userId, double amount);
bool withdraw(Account accounts[], int accountCount, int accountId, int userId, double amount);
bool transfer(Account accounts[], int accountCount, int fromAccountId, int toAccountId, int userId, double amount);
bool payment(Account accounts[], int accountCount, int accountId, int userId, double amount);
void showBalance(Account accounts[], int accountCount, int accountId, int userId);
