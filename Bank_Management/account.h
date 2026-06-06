#pragma once
#include "types.h"

int createAccount(Account accounts[], int* accountCount, int userId);
bool verifyOwnership(Account accounts[], int accountCount, int accountId, int userId);
