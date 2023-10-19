
#include <stdio.h>
#include <stdbool.h>

// Struct for user
struct User {
    char password[20];
    char lastName[20];
    char email[50];
    char firstName[20];
    int active;
};

typedef union {
    int flag;
    bool status;
} ActiveFlag;


int main() {
    struct User user1, user2;
    ActiveFlag flag;
    bool authenticated = false;

    // Registration for User 1
    printf("=== User 1 Registration ===\n");
    printf("Enter password: ");
    scanf("%s", user1.password);
    printf("Enter last name: ");
    scanf("%s", user1.lastName);
    printf("Enter email: ");
    scanf("%s", user1.email);
    printf("Enter first name: ");
    scanf("%s", user1.firstName);
    printf("Enter active flag (1 or 0): ");
    scanf("%d", &flag.flag);
    user1.active = flag.flag;

    // Registration for User 2
    printf("=== User 2 Registration ===\n");
    printf("Enter password: ");
    scanf("%s", user2.password);
    printf("Enter last name: ");
    scanf("%s", user2.lastName);
    printf("Enter email: ");
    scanf("%s", user2.email);
    printf("Enter first name: ");
    scanf("%s", user2.firstName);
    printf("Enter active flag (1 or 0): ");
    scanf("%d", &flag.flag);
    user2.active = flag.flag;

    // Login
    printf("\n=== Login ===\n");
    char password[20];
    int userNumber;

    printf("Enter user number (1 or 2): ");
    scanf("%d", &userNumber);

    if (userNumber == 1) {
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(password, user1.password) == 0 && user1.active) {
            printf("Authenticated!\n");
            authenticated = true;
        }
    } else if (userNumber == 2) {
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(password, user2.password) == 0 && user2.active) {
            printf("Authenticated!\n");
            authenticated = true;
        }
    }

    if (!authenticated) {
        printf("You are not authenticated!\n");
    }

    return 0;
}