## Project Overview

This code creates an interactive console-based "Ask Me" system that allows users to ask and answer questions. It manages user authentication, question handling, and feeds.

### Code Structure Explanation

#### Libraries Included
The code starts by including necessary C++ libraries like `<vector>`, `<queue>`, `<set>`, `<map>`, and others for various functionalities.

#### Helper Methods
- `ReadFileLines`: Reads lines from a file.
- `WriteFileLines`: Writes lines to a file.
- `SplitString`: Splits a string into substrings using a specified delimiter.
- `ToInt`: Converts a string to an integer.
- `ReadInt`: Reads an integer within a specified range.
- `ShowReadMenu`: Displays a menu and reads user choices.

#### Structs

##### `Question`
- Contains attributes like `question_id`, `parent_question_id`, `from_user_id`, `to_user_id`, `is_anonymous_questions`, `question_text`, and `answer_text`.
- Methods for initializing, converting to string, and printing questions.

##### `User`
- Holds attributes such as `user_id`, `user_name`, `password`, `name`, `email`, `allow_anonymous_questions`, `questions_id_from_me`, and `questionid_questionidsThead_to_map`.
- Methods for initializing, converting to string, and printing user details.

##### `QuestionsManager`
- Manages questions including loading from a file, filling user questions, printing user-related questions, answering, deleting, and asking questions.
- Contains maps to manage questions and their threads.

##### `UsersManager`
- Handles user functionalities like loading from a file, login, signup, listing users, and updating the user database.

##### `AskMeSystem`
- Orchestrates the interaction between `UsersManager` and `QuestionsManager`, runs the main system loop, and provides options for users to interact.

### Main Functionality
The `main()` function initializes and runs the "Ask Me" system by creating an instance of `AskMeSystem` and invoking its `run()` method.

The code relies on text files (`questions.txt` and `users.txt`) to persist question and user data.

### Sample Data
At the end of the code, there's an example of the data format used in the text files (`questions.txt` and `users.txt`).

This code offers a console-based interface to interact with the "Ask Me" system, allowing users to ask, answer, and manage questions within the system.
