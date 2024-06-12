#include <bits/stdc++.h>
using namespace std;

// ElementS of hash table:
struct hashNode
{
    int data;
    int key;   // will serve as the index of the table.
    int state; // This will tell if the space of the key is taken or not(1/0).
};

// Hash table:
struct hashTable
{
    struct hashNode *tab;
    int capacity; // capacity of the hash table.
    int size;     // current size of the hash table.
};

// Hash function:
int Hash(int key, int capacity)
{
    return key % capacity;
}

// Create function:
struct hashTable *create(int cap)
{
    struct hashTable *ht = (struct hashTable *)malloc(sizeof(struct hashTable));
    ht->tab = (struct hashNode *)malloc(sizeof(struct hashNode) * cap); // allocating a memory for the hash table with maximum capacity.
    ht->capacity = cap;
    ht->size = 0;

    // Initial state:
    for (int i = 0; i < cap; i++)
    {
        ht->tab[i].key = -1;
        ht->tab[i].data = -1;
        ht->tab[i].state = 0;
    }

    return ht;
};

// Insert function:
void insert(struct hashTable *ht, int item)
{
    int key = item;
    if (ht->size == ht->capacity)
    {
        cout << "Hash Table is Full!!";
        return;
    }

    int index = Hash(key, ht->capacity);

    while (ht->tab[index].state) // The loop will run until it finds an empty space in the table.
    {
        // Linear probing:
        index = (index + 1) % ht->capacity;
    }

    ht->tab[index].key = key;
    ht->tab[index].data = item;
    ht->tab[index].state = 1;
    ht->size++;

    cout << item << " has been inserted at index " << index << endl;
}

// Search function:
void search(struct hashTable *ht, int item)
{
    int key = item;
    int tempI = Hash(key, ht->capacity);
    int index = tempI;
    int cnt = 0; // counter.

    while (ht->tab[tempI].state) // The loop will run until it finds an empty
    {
        if (ht->tab[tempI].data == item)
        {
            cout << "Item found at index " << tempI << endl;
            return;
        }
        // Linear probing:
        tempI = (tempI + 1) % ht->capacity;

        if (cnt >= ht->capacity) // Returned back to the first search point after searching the whole table
            break;

        cnt++;
    }
    cout << "Item is not in the table!!" << endl;
}

// Delete function:
void Delete(struct hashTable *ht, int item)
{
    int key = item;
    int tempI = Hash(key, ht->capacity);
    int index = tempI;
    int cnt = 0; // counter.

    while (ht->tab[tempI].state) // The loop will run until it finds an empty
    {
        if (ht->tab[tempI].key == key)
        {
            ht->tab[tempI].state = 0; // data removed.
            ht->tab[tempI].key = -1;
            ht->tab[tempI].data = -1;
            cout << "Item deleted from index " << tempI << endl;
            ht->size--;
            return;
        }

        // Linear probing:
        tempI = (tempI + 1) % ht->capacity;

        if (cnt >= ht->capacity) // Returned back to the first search point after searching the whole table
            break;

        cnt++;
    }

    cout << "Item is not in the table!!" << endl;
}

// Display function:
void display(struct hashTable *ht)
{
    for (int i = 0; i < ht->capacity; i++)
    {
        if (ht->tab[i].state)
        {
            cout << "The item at index " << i << " is : " << ht->tab[i].data << endl;
        }
    }
    cout << "End of table." << endl;
}

int main()
{
    system("cls");
    int cap;
    cout << "Enter the number elements in the table: ";
    cin >> cap;

    hashTable *ht = create(cap);

    int choice, item, key;
    do
    {
        printf("\n-----------Main Menu-------------\n");
        printf("1. Insert Data.\n");
        printf("2. Delete Item.\n");
        printf("3. Search Item.\n");
        printf("4. Display.\n");
        printf("5. GetSize.\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        cin >> choice;
        cout << endl;

        switch (choice)
        {

        case 1:
            cout << "Enter the item you want to insert : ";
            cin >> item;
            insert(ht, item);
            break;

        case 2:
            cout << "Enter the item you want to delete: ";
            cin >> item;
            Delete(ht, item);
            break;

        case 3:
            cout << "Enter the item you want to search: ";
            cin >> item;
            search(ht, item);
            break;

        case 4:
            display(ht);
            break;

        case 5:
            cout << "Current size of the table is : " << ht->size << endl;
            break;

        case 6:
            printf("<-End operation->\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
