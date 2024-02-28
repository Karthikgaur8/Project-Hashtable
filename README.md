# Project Hashtable

---

#### Introduction

This project implements a basic hash table data structure using linear probing, quadratic probing, or double hashing collision resolution strategies. It reads input text files, parses the words, and stores them in the hash table along with their occurrences in the input text file. Additionally, it supports searching for words in the hash table and provides information about their occurrences and collisions.

---

#### Features

- Implementation of a hash table with customizable collision resolution strategies: linear probing, quadratic probing, or double hashing.
- Efficient storage and retrieval of words with their occurrences in the input text file.
- Support for case-insensitive word matching and removal of non-alphabetic characters.
- Detailed output including the total number of words, unique words, and collisions.

---

#### Usage

1. **Input Files**: Ensure that the input files are provided as command-line arguments when executing the program.
   ```
   ./hash_table input.txt queries.txt table_size collision_strategy [a]
   ```
   - `input.txt`: The text file containing the input data.
   - `queries.txt`: The text file containing queries to search for in the hash table.
   - `table_size`: The size of the hash table.
   - `collision_strategy`: The collision resolution strategy. Use 'l' for linear probing, 'q' for quadratic probing, and 'd' for double hashing.
   - `a` (optional): The value used in double hashing (required only for double hashing strategy).

2. **Compilation**: Compile the program using any C++ compiler, such as g++ or Visual Studio.
   ```
   g++ -o hash_table main.cpp
   ```

3. **Execution**: Run the compiled executable with the appropriate command-line arguments.
   ```
   ./hash_table input.txt queries.txt 100 l
   ```

---

#### Contributing

Contributions to this project are welcome! If you find any bugs or have suggestions for improvements, please feel free to open an issue or submit a pull request on GitHub.


---

#### Contact

For any questions or inquiries, please contact Karthik Gaur at karthikgaur16@gmail.com.

---