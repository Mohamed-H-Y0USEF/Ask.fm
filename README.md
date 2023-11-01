# Question-and-Answer System Documentation

## Table of Contents

1. [Introduction to `systemAsk` Class](#introduction-to-systemask-class)
2. [How to Use the System](#how-to-use-the-system)
3. [The `User` Class](#the-user-class)
4. [The `Question` Class](#the-question-class)

---

## Introduction to `systemAsk` Class

The `systemAsk` class is the central component of a command-line-based question-and-answer system. It provides a comprehensive set of features for users to interact with the system, including logging in, signing up, asking and answering questions, listing users, and more. This class manages user data, question data, and interactions within the system. The system is designed to allow users to participate in a Q&A platform efficiently.

### Member Variables

- `logedIn` (bool): Indicates whether a user is currently logged in.
- `systemUsers` (std::map<int, User>): Stores information about system users indexed by their unique ID.
- `questions` (std::map<int, Question>): Stores questions indexed by their unique ID.
- `curUser` (User): Represents the current user.

### Constructor: `systemAsk()`

- Initializes `logedIn` to `false`.
- Calls the `load()` method to load user and question data from files.

### Method: `run()`

- The main loop of the program that continuously displays a menu to the user and handles user choices.
- The user can perform actions such as logging in, signing up, printing questions, answering questions, and more based on the menu.

### Method: `menu()`

- Displays a menu to the user based on whether they are logged in or not.
- Returns the user's choice as an integer.

### Method: `logIn()`

- Allows a user to log in by providing a username and password.
- Checks the provided credentials against the stored user data and sets the `logedIn` flag if the login is successful.

...

## How to Use the System

To use the system effectively, follow these steps:

1. **Create an Instance of `systemAsk`**:

   First, create an instance of the `systemAsk` class to start using the system.

   ```cpp
   systemAsk mySystem;
## Logging In or Signing Up

Once you have created an instance of the `systemAsk` class and the main menu is displayed, you can either log in as an existing user or sign up as a new user. Follow the steps below to log in or sign up:

### Logging In

If you are an existing user, you can log in to your account. Choose the "Log in" option by entering `1` in the menu. You will be prompted to provide your username and password.

1. Enter `1` in the menu to select the "Log in" option.
2. You will be prompted to enter your username and password.

   - **Enter User Name (No Space):** Provide your registered username.
   - **Enter Password:** Enter your password.

3. After entering your credentials, the system will attempt to log you in.

   - If your username and password are correct, you will be successfully logged in, and the system will set the `logedIn` flag to `true`. You will now have access to various menu options that are available to logged-in users.

   - If you enter incorrect credentials, you have three attempts to log in. If all three attempts fail, you will need to retry or use the sign-up option.

   - If you forget your password, there is no password recovery option within this system.

### Signing Up

If you are a new user, you can sign up for an account. Choose the "Sign up" option by entering `2` in the menu. You will be prompted to provide your information to create a new account.

1. Enter `2` in the menu to select the "Sign up" option.
2. You will be prompted to provide the following information for your new account:

   - **Enter User Name (No Space):** Choose a username for your new account. Ensure that it does not contain spaces.
   - **Enter Password:** Set a password for your account.
   - **Allow Anonymous Questions (0 or 1):** You can choose whether to allow anonymous questions (0 for no, 1 for yes). This option determines if other users can ask you questions without revealing their identity.

3. After providing this information, the system will create a new user account with the details you provided.

   - The system will automatically generate a unique `ID` for your account based on your username and password.
   - Your account will be added to the `systemUsers` data structure to manage user information.

4. You are now registered as a new user and will be automatically logged in.

   - You will have access to the system's features, and you can start using the system as a logged-in user.

   - You can also choose to log out if you wish to exit the system.

This section explains how to log in as an existing user or sign up as a new user in the question-and-answer system. Once logged in, you can explore the various features and interact with other users through questions and answers.
