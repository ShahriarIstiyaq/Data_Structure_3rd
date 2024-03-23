#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int N;

/// Function to write the data of the Vector in the File.
void write()
{
    // creating the text file using ofstream object.
    ofstream out("File.txt");

    if (!out)
    {
        cout << "Error opening file!" << endl;
        return; // Error return.
    }

    out << N << endl; // Counter of elements in the file.

    for (int i = 0; i < N; i++)
    {
        // writing inside the file from the Vector.
        out << a[i] << endl;
    }

    out.close(); // Closing the file.
}

/// Function to read the data of the File in the Vector.
void read()
{
    // Opening the file using ifstream object
    ifstream in("File.txt");

    in >> N; // Counting elements in the file.

    if (!in)
    {
        cout << "Error opening file!" << endl;
        return; // Error return.
    }

    a.resize(N);

    for (int i = 0; i < N; i++)
    {
        // taking input from file to the Vector using ifstream object.
        in >> a[i];
    }

    in.close(); // closing the file.
}

// Display Function:
void display()
{
    read(); // Reading from the file.

    // Console output:
    cout << "The array:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;
}

// Sort function:
void BubbleSort()
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < (N - 1) - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//  Create Function:
void create()
{
    cout << "Please enter the number of elements you want to create: ";
    cin >> N;

    // Resizing the vector to N.
    a.resize(N);

    // Genetating N elements in the array:
    srand(time(0));

    for (int i = 0; i < N; i++)
    {
        int x = rand();
        a[i] = x;
    }

    // Console output:
    cout << "Data before sorting-> \n";
    cout << "The array:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;

    BubbleSort();
    write();

    cout << "Data after sorting-> \n";
    display();
}

// Search Function:
void search(int item)
{
    read();

    // binary search.
    int l = 0, r = N - 1;
    int pos = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (a[mid] == item)
        {
            pos = mid;
            r = mid - 1; // Search on the left side to find the first occurrence.
        }
        else if (item < a[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }

    // showing the list of data for better understanding of the position of the 'Item'.
    display();

    // After searching the whole array.
    if (a[pos] == item)
        cout << "\n>>>The location of the item in the array is index no. " << pos + 1 << endl; // 1 base indexing.
    else
        cout << "\n>>>The item is not found in the array.\n";
}

// Insert Function:
void Insert(int item)
{
    int pos; // Insertion position.

    N++; // Increaseing the size of the array.

    a.resize(N);

    // copying data backword(0 base indexing).
    for (int i = N - 1; i >= 0; i--)
    {
        if (item > a[i - 1])
        {
            pos = i;
            break;
        }

        else
        {
            a[i] = a[i - 1];
        }
    }

    // Insertion:
    a[pos] = item;

    write();
}

// Binary search function to find the last occurrence of an element:
int BS_Delete(int beg, int end, int item)
{
    int pos = -1;

    while (beg <= end)
    {
        int mid = (beg + end) / 2;

        if (a[mid] == item)
        {
            pos = mid;
            beg = mid + 1; // Search on the right side to find the last occurrence
        }

        else if (item < a[mid])
            end = mid - 1;

        else
            beg = mid + 1;
    }

    return pos;
}

// Delete Function:
void Delete(int item)
{
    // Position of last occurrence of the element.
    int pos = BS_Delete(0, N - 1, item);

    // Coping the data.
    for (int i = pos; i < N - 1; i++)
        a[i] = a[i + 1];

    N--; // Decreasing the size of the array.

    cout << "Item deleted!!!" << endl;
    write();
}

// Menu Function:
int menu()
{

    int choice;
    do
    {
        printf("\t------------------\n");
        printf("\t  --MAIN MENU--\n");
        printf("\t------------------\n");
        printf("\n1-Insert Element.\n2-Delete Element.\n3-Search Element.\n4-Show Data.\n5-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 0 || choice > 5)
            printf("\nWrong...Choice again...\n");
    } while (choice < 0 || choice > 5);

    return (choice);
}

// Main Function:
int main()
{
    int choice, item;
    system("cls");
    create();
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            cout << "Insert element: ";
            cin >> item;
            Insert(item);
            display();
            break;

        case 2:
            display();
            cout << "Insert element you want to delete: ";
            cin >> item;
            Delete(item);

            break;

        case 3:
            cout << "Enter your querry: ";
            int x;
            cin >> x;
            search(x);
            break;

        case 4:
            display();
            break;

        case 5:
            printf("End of operation\n");
            break;
        }
    } while (choice != 5);

    return 0;
}