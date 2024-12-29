#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct account {
    char name[1000];
    int id;
    float balance;
    float deposit;
    float withdraw;
};

struct account deposit(struct account ac) {
    ac.balance += ac.deposit;
    printf("Deposit was successful.\n");
    printf("Your current balance is: %.2f$\n", ac.balance);
    return ac;
}

struct account withdraw(struct account ac) {
    if (ac.balance >= ac.withdraw) {
        ac.balance -= ac.withdraw;
        printf("The withdrawal was successful.\n");
        printf("Your current balance is: %.2f$\n", ac.balance);
    } else {
        printf("Insufficient balance.\n");
    }
    return ac;
}

void info(struct account ac) {
    printf("Account Holder Name: %s\n", ac.name);
    printf("Account Holder ID: %d\n", ac.id);
    printf("Account Balance: %.2f$\n", ac.balance);
}

void save_to_file(struct account ac) {
    FILE *file = fopen("account_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving data.\n");
        return;
    }
    fprintf(file, "Name: %s\n", ac.name);
    fprintf(file, "ID: %d\n", ac.id);
    fprintf(file, "Balance: %.2f\n", ac.balance);
    fclose(file);
    printf("Account data saved successfully.\n");
}

struct account load_from_file(int id) {
    struct account ac;
    FILE *file = fopen("account_data.txt", "r");
    if (file == NULL) {
        printf("No previous data found. Starting with a new account.\n");
        strcpy(ac.name, "");
        ac.id = 0;
        ac.balance = 0;
        return ac;
    }
    
    while (fscanf(file, "Name: %[^\n]\n", ac.name) != EOF) {
        fscanf(file, "ID: %d\n", &ac.id);
        fscanf(file, "Balance: %f\n", &ac.balance);

        if (ac.id == id) {
            fclose(file);
            printf("Account data loaded successfully.\n");
            return ac;
        }
    }
    
    fclose(file);
    printf("Account with ID %d not found.\n", id);
    strcpy(ac.name, "");
    ac.id = 0;
    ac.balance = 0;
    return ac;
}

int generate_id() {
    srand(time(NULL));  
    return rand() % 10000;
}

int main() {
    struct account ac;
    int choice;

    printf("Welcome to ATM\n");
    printf("1. Load existing account\n");
    printf("2. Create new account\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int id;
        printf("Enter the account ID to load: ");
        scanf("%d", &id);
        ac = load_from_file(id);
    } else {
        printf("Please Enter your details\n");
        printf("Name: ");
        getchar();
        fgets(ac.name, sizeof(ac.name), stdin);
        ac.name[strcspn(ac.name, "\n")] = '\0';

        ac.id = generate_id();
        ac.balance = 0;

        printf("Your Account ID is: %d\n", ac.id);
    }

    int m;
    while (1) {
        printf("\nChoose a function:\n");
        printf("1. Display Details\n");
        printf("2. Display Balance\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Save and Exit\n");
        printf("What would you like to do today? ");
        scanf("%d", &m);

        if (m == 5) {
            save_to_file(ac);
            printf("Exiting... Thank you!\n");
            break;
        }

        if (m == 1) {
            info(ac);
        }

        if (m == 2) {
            if (ac.balance == 0) {
                printf("Your balance is empty.\n");
                printf("You will need to deposit first.\n");
            } else {
                printf("Your Balance is: %.2f$\n", ac.balance);
            }
        }

        if (m == 3) {
            printf("Enter the amount you want to deposit: ");
            scanf("%f", &ac.deposit);
            ac = deposit(ac);
        }

        if (m == 4) {
            printf("Enter the amount you want to withdraw: ");
            scanf("%f", &ac.withdraw);
            ac = withdraw(ac);
        }
    }

    return 0;
}
