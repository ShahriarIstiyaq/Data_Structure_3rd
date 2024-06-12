// double hashing method

#include <iostream>
using namespace std;

int TABLE_SIZE = 10;

void insert(int key, int table[])
{
    int i, hash1, hash2, index;
    hash1 = key % TABLE_SIZE;                            // hash1 is first function
    hash2 = (TABLE_SIZE - 2) - (key % (TABLE_SIZE - 2)); // hash2 is second function, here in place of 2 we can write any number lower then table_size
    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hash1 + i * hash2) % TABLE_SIZE; // main function to find index, where i iterates to find an empty index
        if (table[index] == -1)
        {
            table[index] = key; // if empty index is found. insert key there
            break;
        }
    }
}

bool search(int key, int table[])
{
    int i, hash1, hash2, index;
    hash1 = key % TABLE_SIZE;
    hash2 = (TABLE_SIZE - 2) - (key % (TABLE_SIZE - 2));
    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hash1 + i * hash2) % TABLE_SIZE; // main function, where i iterates to find the key
        if (table[index] == -1)
        {
            break; // if key not found but empty space found, break and return false
        }
        if (table[index] == key) // if key found before any empty space , return true;
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int x, num_keys, srch, a;
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) //  initialize hash table as empty
    {
        table[i] = -1;
    }

    cout << "Enter number of keys to insert: ";
    cin >> num_keys;
    cout << "Insert the keys: ";
    for (int i = 0; i < num_keys; i++)
    {
        cin >> x; // insert values
        insert(x, table);
    }
    cout << "Enter a key to search: ";
    cin >> srch;
    a = search(srch, table);
    if (a == true)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}