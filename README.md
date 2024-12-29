# ATM Management System 

This project is a simple ATM management system implemented in C. It allows users to perform basic banking operations such as viewing account details, depositing money, withdrawing money, and saving account data to a file for persistence across sessions.

## Features

- **Account Management**: Create and manage a user account with name, ID, and balance.
- **Deposit and Withdraw**: Add or withdraw funds from your account balance.
- **View Account Details**: Display user details, including name, ID, and current balance.
- **Data Persistence**: Save account data to a file (`account_data.txt`) and reload it when the program restarts.
- **User-Friendly Menu**: Simple and intuitive menu-driven interface for seamless interaction.

## How It Works

1. **Account Initialization**: 
   - On the first run, users are prompted to input their name and ID. 
   - If account data exists from a previous session, it is automatically loaded.

2. **Menu Options**:
   - **1**: View account details.
   - **2**: Display current account balance.
   - **3**: Deposit money.
   - **4**: Withdraw money.
   - **5**: Save account data and exit the program.

3. **File Operations**:
   - The account data is saved to `account_data.txt` when the user chooses to exit the program.
   - On startup, the program attempts to load data from the file, ensuring persistence across sessions.

## Usage

1. Compile the program using a C compiler:
   ```bash
   gcc -o atm atm.c
   ```

2. Run the executable:
   ```bash
   ./atm
   ```

3. Follow the prompts to interact with the system.

## File Structure

- `account_data.txt`: The file where account information is stored. If this file is missing, the program will start with a new account.

## Sample Interaction

```
Welcome to ATM
Please Enter your details
Name: John Doe
Enter your ID: 12345

Choose a function:
1. Display Details.
2. Display Balance.
3. Deposit.
4. Withdraw.
5. Save and Exit.

What would you like to do today?
```

## Requirements

- A C compiler (e.g., GCC).
- Basic understanding of terminal/command-line usage.

## Future Enhancements

- Add support for multiple accounts.
- Include password protection for added security.
- Implement a graphical user interface (GUI).

---

Feel free to contribute to this project by submitting issues or pull requests.
