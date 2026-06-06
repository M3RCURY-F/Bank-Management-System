#include <iostream>
#include "types.h"
#include "auth.h"
#include "account.h"
#include "card.h"
#include "transaction.h"
#include "storage.h"

using namespace std;

int getSafeInt() {
    int val;
    while (!(cin >> val)) {
        cout << "Numeric key mismatch. Re-enter number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return val;
}

double getSafeDouble() {
    double val;
    while (!(cin >> val) || val < 0) {
        cout << "Invalid monetary value. Re-enter positive amount: $";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return val;
}

int main() {
    User users[MAX_USERS];
    Account accounts[MAX_ACCOUNTS];
    Card cards[MAX_CARDS];

    int userCount = 0;
    int accountCount = 0;
    int cardCount = 0;
    int loggedInUserId = -1;

    
    loadData(users, &userCount, accounts, &accountCount, cards, &cardCount);

    while (true) {
        if (loggedInUserId == -1) {
            cout << "\n==================================\n";
            cout << "       TERMINAL BANK INTERFACE     \n";
            cout << "==================================\n";
            cout << "1. Sign Up\n2. Login\n3. Save & Close System\nChoice: ";
            int choice = getSafeInt();

            if (choice == 1) {
                char user[50], pass[50];
                cout << "Preferred Username (No spaces): "; cin >> user;
                cout << "Preferred Password (No spaces): "; cin >> pass;
                int id = signUp(users, &userCount, user, pass);
                if (id != -1) cout << ">> Registration complete. Assigned ID: " << id << "\n";
            }
            else if (choice == 2) {
                char user[50], pass[50];
                cout << "Username: "; cin >> user;
                cout << "Password: "; cin >> pass;
                loggedInUserId = login(users, userCount, user, pass);
                if (loggedInUserId != -1) cout << ">> Verification successful.\n";
                else cout << ">> Access denied. Invalid records.\n";
            }
            else if (choice == 3) {
                
                saveData(users, userCount, accounts, accountCount, cards, cardCount);
                cout << ">> Records preserved on disk. Shutting down interface.\n";
                break;
            }
            else {
                cout << ">> Option out of range.\n";
            }
        }
        else {
            cout << "\n----------------------------------\n";
            cout << "          ACCOUNT CONSOLE         \n";
            cout << "----------------------------------\n";
            cout << "1. Create Account\n2. Add Balance\n3. Withdraw\n";
            cout << "4. Create Card\n5. Block Card\n6. Transfer\n7. Payment\n8. Logout\nChoice: ";
            int choice = getSafeInt();

            if (choice == 1) {
                int accId = createAccount(accounts, &accountCount, loggedInUserId);
                if (accId != -1) cout << ">> Account initialized. Reference Number: " << accId << "\n";
            }
            else if (choice == 2) {
                cout << "Account Reference Number: "; int accId = getSafeInt();
                cout << "Deposit Value: $"; double amount = getSafeDouble();
                if (addBalance(accounts, accountCount, accId, loggedInUserId, amount))
                    cout << ">> Processing success. Balance modified.\n";
                else cout << ">> Transaction rejected. Ownership mismatch.\n";
            }
            else if (choice == 3) {
                cout << "Account Reference Number: "; int accId = getSafeInt();
                cout << "Withdrawal Value: $"; double amount = getSafeDouble();
                if (withdraw(accounts, accountCount, accId, loggedInUserId, amount))
                    cout << ">> Settlement successful.\n";
            }
            else if (choice == 4) {
                cout << "Target Account Number for Link: "; int accId = getSafeInt();
                int cardId = createCard(cards, &cardCount, accounts, accountCount, accId, loggedInUserId);
                if (cardId != -1) cout << ">> Secure Card generated. Card ID: " << cardId << "\n";
                else cout << ">> Binding failed. Confirm profile metrics.\n";
            }
            else if (choice == 5) {
                cout << "Target Card ID to Void: "; int cardId = getSafeInt();
                if (blockCard(cards, cardCount, cardId, accounts, accountCount, loggedInUserId))
                    cout << ">> Security status updated: Card Blocked.\n";
                else cout << ">> Action denied. Unauthorized validation.\n";
            }
            else if (choice == 6) {
                cout << "Source Account Number: "; int fromAcc = getSafeInt();
                cout << "Destination Account Number: "; int toAcc = getSafeInt();
                cout << "Transfer Sum: $"; double amt = getSafeDouble();
                if (transfer(accounts, accountCount, fromAcc, toAcc, loggedInUserId, amt))
                    cout << ">> Vault transfer finalized.\n";
                else cout << ">> Routing failed. Review parameters and balance records.\n";
            }
            else if (choice == 7) {
                cout << "Billing Account Number: "; int accId = getSafeInt();
                cout << "Invoice Amount: $"; double amt = getSafeDouble();
                if (payment(accounts, accountCount, accId, loggedInUserId, amt))
                    cout << ">> Payment processing executed.\n";
                else cout << ">> Direct settlement failed.\n";
            }
            else if (choice == 8) {
                loggedInUserId = -1;
                cout << ">> Secure terminal logout sequence executed.\n";
            }
            else {
                cout << ">> Alternative routing required. Invalid key entry.\n";
            }
        }
    }
    return 0;
}