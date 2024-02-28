#include <iostream>

using namespace std;

// Store the return of this function as an unsigned long!
unsigned long djb2(string str) {
   const char *ptr = str.c_str();
   unsigned long hash = 5381;
   int c;
   while ((c = *ptr++)) {
      hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
   }
   return hash;
}


class HashTable {
private:
    // Entry class for each item in the hash table
    class Entry {
    public:
        string key;
        list<int> line_numbers;
        Entry(const string& k, int line_num) : key(k) {
            line_numbers.push_back(line_num);
        }
    };

    vector<Entry> table;
    int size;
    string collision_strategy;
    int a_param;
    int collisons;

    // Hash functions
    int h1(const string& key) const {
        return djb2(key) % size;
    }
    

    int h2(const string& key) const {
        return a_param - (djb2(key) % a_param);
    }

    // Collision resolution strategies
    int linear_probing(int hash_val, int i) const {
        return (hash_val + i) % size;
    }

    int quadratic_probing(int hash_val, int i) const {
        return (hash_val + i * i) % size;
    }

    int double_hashing(int hash_val, int i, const string& key) const {
        return (hash_val + i * h2(key)) % size;
    }

public:
    // Constructor
    HashTable(int table_size, const string& strategy, int a = 0) :
        size(table_size), collision_strategy(strategy), a_param(a) {
             table.resize(table_size, nullptr);
        }

    // Destructor
    ~HashTable() {
       for (Entry* Entry : table) {
            if (Entry != nullptr) {
                delete Entry;
            }
    }}
    int get_table_size(){
        return size;
    }

// Get the number of entries in the hash table
    int get_count(int i) const {
        if (i >= table.size()) {
            return 0;
        }
        return table[i].line_numbers.size();
    }
    string get_key(int i) const {
    if (i < 0 || i >= size) {
        throw out_of_range("Index out of range.");
    }
    if (table[i].key != "") {
        return table[i].key;
    }
    throw logic_error("No key at index " + to_string(i) + ".");
}

    // Insert a word into the hash table
    void insert(const string& word, int line_num) {
        int hash_val = h1(word);
        int i = 0;
        while (table[hash_val].key != "") {
            if (table[hash_val].key == word) {
                table[hash_val].line_numbers.push_back(line_num);
                return;
            }
            i++;
            collisons += 1;
            if (collision_strategy == "lp") {
                hash_val = linear_probing(hash_val, i);
            } else if (collision_strategy == "qp") {
                hash_val = quadratic_probing(hash_val, i);
            } else if (collision_strategy == "dh") {
                hash_val = double_hashing(hash_val, i, word);
            }
        }
        table[hash_val] = Entry(word, line_num);
    }

    // Search for a word in the hash table and return the line numbers where it occurs
    list<int> search(const string& word) const {
        int hash_val = h1(word);
        int i = 0;
        while (table[hash_val].key != "") {
            if (table[hash_val].key == word) {
                table[hash_val].line_numbers.push_front(i);
                return table[hash_val].line_numbers;
            }
            i++;
            if (collision_strategy == "lp") {
                hash_val = linear_probing(hash_val, i);
            } else if (collision_strategy == "qp") {
                hash_val = quadratic_probing(hash_val, i);
            } else if (collision_strategy == "dh") {
                hash_val = double_hashing(hash_val, i, word);
            }
        }
        return {};
    }
    int HashTable::get_collision_count() {
    return collisons;
}

int get_num_unique_words() const {
        int count = 0;
        for (Entry* Entry : table) {
            if (Entry != nullptr) {
                count++;
            }
        }
        return count;
    }
}
int main() {

   return 0;
}
