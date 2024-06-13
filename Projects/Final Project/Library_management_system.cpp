#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
#define ll long long int
#define vi vector<int>

int exitFlag = 0; /// This flag is used for exiting the application.
/// FOR HIDING CURSOR.

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

/// FOR ARROW CURSOR.
// realPosition is the position arrow is at.
// arrowPosition is the position where the user want the arrow to be.
void arrowHere(int realPosition, int arrowPosition)
{
    char arrow = 16;

    if (realPosition == arrowPosition)
    {
        printf("%c ", arrow);
    }

    else
        printf("  ");
}

// Function to move the cursor to a specific position in the console
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// For showing the tile of the project.
void showTitle(string s)
{
    //-----------------------------------------------------------Titile----------------------------------------------------//
    gotoxy(70, 4);                // Upper bar of Title.
    for (int i = 1; i <= 35; i++) // 35 dots.
        printf("%c", 254);

    gotoxy(70, 5); // Title of project.
    cout << "     " << s << "     ";

    gotoxy(70, 5); // Left bar of Title.
    printf("%c", 219);
    gotoxy(104, 5); // Right bar of Title.
    printf("%c", 219);

    gotoxy(70, 6);                // Lower bar of Title.
    for (int i = 1; i <= 35; i++) // 35 dots.
        printf("%c", 254);
}

/// Main class of Library:(all functions are inside this)
class library
{
private:
    struct Book // Node of the list
    {
        int id; // Book id
        string name, author, publisher;
        Book *next; // Next field for adding new books.
    };

public:
    Book *head = NULL; // Head pointer of the Book list.
    void menu();
    void EXIT();
    void insert();
    void search();
    void Ask_before_operation(string s);
    void update();
    void Delete();
    void sort(); // Selection sort.
    void ShowAll();
    void AboutUs();
};

/// Sort Function:
void library ::sort()
{
    if (head == NULL || head->next == NULL)
    {
        return; // List is empty or has only one element.
    }

    // Temporary node to hold the sorted part
    Book *sorted = NULL;

    while (head != NULL)
    {
        // Find the minimum node in the unsorted part
        Book **min = &head;
        Book *current = head;

        while (current->next != NULL)
        {
            if (current->next->id < (*min)->id)
            {
                min = &(current->next);
            }
            current = current->next;
        }

        // Move the minimum node to the sorted part
        Book *minNode = *min;
        *min = minNode->next; // Remove the minimum node from the unsorted part
        minNode->next = sorted;
        sorted = minNode;
    }

    // Set head to the new sorted list
    while (sorted != NULL)
    {
        Book *temp = sorted;
        sorted = sorted->next;
        temp->next = head;
        head = temp;
    }
}

/// Exit Function:
void library::EXIT()
{
    int position = 1;
    int keyPressed = 0;

    while (keyPressed != 13)
    {
        gotoxy(50, 12);               // Upper bar of Exit.
        for (int i = 1; i <= 82; i++) // 81 dots.
            printf("%c", 220);

        gotoxy(50, 27);               // Lower bar of Exit.
        for (int i = 1; i <= 82; i++) // 81 dots.
            printf("%c", 220);

        for (int i = 13; i <= 27; i++) // Left Side bar of Exit.
        {
            gotoxy(50, i);
            printf("%c", 219);
        }
        for (int i = 13; i <= 27; i++) // Right Side bar of Exit.
        {
            gotoxy(131, i);
            printf("%c", 219);
        }

        gotoxy(70, 14);
        printf("Do you want to exit?!");

        gotoxy(75, 16);
        arrowHere(1, position);
        printf("YES.");

        gotoxy(75, 18);
        arrowHere(2, position);
        printf("NO.");

        keyPressed = getch();

        if (keyPressed == 80 && position != 2)
            position++;

        else if (keyPressed == 72 && position != 1)
            position--;

        else if (keyPressed == 80 && position == 2)
            position = 1;

        else if (keyPressed == 72 && position == 1)
            position = 2;

        else
            position = position;

        /// Operations.
        if (position == 1 && keyPressed == 13)
        {
            system("cls");
            exitFlag = 1;
            return; /// This will return to the main_page function.
        }

        else if (position == 2 && keyPressed == 13)
        {
            system("cls");
            menu();
        }
    }
}

/// Insert Function:
void library ::insert()
{
    system("cls");
    showTitle("Insert Record.");

    // Crearing new node:
    Book *newNode = new Book;

    gotoxy(53, 8);
    cout << "Book ID : ";
    cin >> newNode->id;

    gotoxy(53, 10);
    cout << "Name : ";
    cin.ignore();
    getline(cin, newNode->name);

    gotoxy(53, 12);
    cout << "Author Name : ";
    getline(cin, newNode->author);

    gotoxy(53, 14);
    cout << "Publisher Name : ";
    getline(cin, newNode->publisher);

    newNode->next = NULL; // Initially every next field is null;

    // Insertion Process:(Insertion sort)
    if (head == NULL || head->id >= newNode->id) // Empty LL.
    {
        newNode->next = head;
        head = newNode;
    }

    else
    {
        Book *current = head;

        while (current->next != NULL && current->next->id < newNode->id) // Searching for insertion position.
            current = current->next;

        // Inserting to correct node:
        newNode->next = current->next;
        current->next = newNode;
    }

    gotoxy(53, 17);
    cout << "New Book Inserted Successfully....!!";

    _getch();
}

/// Show ALL Funtion:
void library::ShowAll()
{
    system("cls");
    showTitle("List Of All Books");
    Book *ptr = head;

    if (head == NULL)
    {
        gotoxy(53, 8);
        cout << "There Are No Books In The Library!!";
        return;
    }

    int y = 8; // Y coordinate.
    while (ptr != NULL)
    {
        gotoxy(53, y);
        cout << "Book ID : " << ptr->id;
        gotoxy(53, y + 1);
        cout << "Name : " << ptr->name;
        gotoxy(53, y + 2);
        cout << "Author Name : " << ptr->author;
        gotoxy(53, y + 3);
        cout << "Publisher Name : " << ptr->publisher;
        y += 5;
        ptr = ptr->next;
    }

    _getch();
}

/// Search Function:
void library::search()
{
    system("cls");
    showTitle("Search Record");

    int tempId, found = false;
    if (head == NULL)
    {
        gotoxy(53, 8);
        cout << "There Are No Books In The Library!!";
        return;
    }

    else
    {
        gotoxy(53, 8);
        cout << "Book ID : ";
        cin >> tempId;

        // Search Operation:
        Book *ptr = head;

        while (ptr != NULL) // sorted search.
        {

            if (tempId > ptr->id)
                ptr = ptr->next;

            else if (tempId == ptr->id)
            {

                system("cls");
                showTitle("Search Record");

                gotoxy(53, 8);
                cout << "Book ID : " << ptr->id;

                gotoxy(53, 10);
                cout << "Name : " << ptr->name;

                gotoxy(53, 12);
                cout << "Author Name : " << ptr->author;

                gotoxy(53, 14);
                cout << "Publisher Name : " << ptr->publisher;

                found = true;
                break;
            }

            else
                break;
        }

        gotoxy(53, 14);
        if (!found)
            cout << "The Book Is Not In The Library...!!";

        _getch();
    }
}

/// Update Function:

void library::Ask_before_operation(string s)
{
    int position = 1;
    int keyPressed = 0;
    while (keyPressed != 13)
    {
        gotoxy(70, 22);
        cout << "Do You Want To " << s << " This Record?";

        gotoxy(80, 24);
        arrowHere(1, position);
        cout << " YES.";

        gotoxy(80, 26);
        arrowHere(2, position);
        cout << " NO.";

        keyPressed = getch();

        if (keyPressed == 80 && position != 2)
            position++;

        else if (keyPressed == 72 && position != 1)
            position--;

        else if (keyPressed == 80 && position == 2)
            position = 1;

        else if (keyPressed == 72 && position == 1)
            position = 2;

        else
            position = position;

        if (keyPressed == 13)
        {
            if (position == 1)
            {
                system("cls");
                return; // This will return to the Update function and continue the updating operations.
            }
            else if (position == 2)
            {
                system("cls");
                menu();
                return;
            }
        }
    }
}
void library::update()
{
    system("cls");
    showTitle("Update Record");

    //----------------------------------Searching for the desired book--------------------------------------------------------------------//
    int tempId, found = false;
    Book *loc = NULL; // Location of desired book.

    if (head == NULL)
    {
        gotoxy(53, 8);
        cout << "There Are No Books In The Library!!";
        return;
    }

    else
    {
        gotoxy(53, 8);
        cout << "Book ID : ";
        cin >> tempId;

        // Search Operation:
        Book *ptr = head;

        while (ptr != NULL) // sorted search.
        {
            if (tempId > ptr->id)
                ptr = ptr->next;

            else if (tempId == ptr->id)
            {
                system("cls");
                showTitle("Update Record");

                gotoxy(53, 8); // Existing records of Books.
                cout << "Existing Record: ";
                gotoxy(53, 9);
                for (int i = 1; i <= 18; i++)
                    printf("%c", 95);

                gotoxy(53, 12);
                cout << "Book ID : " << ptr->id;

                gotoxy(53, 14);
                cout << "Name : " << ptr->name;

                gotoxy(53, 16);
                cout << "Author Name : " << ptr->author;

                gotoxy(53, 18);
                cout << "Publisher Name : " << ptr->publisher;

                found = true;

                loc = ptr; // Location of desired book.
                break;
            }

            else
                break;
        }

        if (found == false)
        {
            cout << "The Book Is Not In The Library...!!";
            return;
        }
    }

    //----------------------------------Searching for the desired book--------------------------------------------------------------------//

    // --------------------------------Update operation:----------------------------------------------------------------------------------//

    Ask_before_operation("Update");

    system("cls");
    showTitle("Update Record");

    gotoxy(53, 8);
    cout << "New Book ID: ";
    cin >> loc->id;

    gotoxy(53, 10);
    cout << "New Name : ";
    cin.ignore();
    getline(cin, loc->name);

    gotoxy(53, 12);
    cout << "New Author Name : ";
    getline(cin, loc->author);

    gotoxy(53, 14);
    cout << "New Publisher Name : ";
    getline(cin, loc->publisher);

    gotoxy(53, 16);
    cout << "Updated Record Successfully...!!";

    sort(); // sorting the data after operation.
    _getch();
}

/// Delete Function:
void library::Delete()
{
    system("cls");
    showTitle("Delete Record");

    int tempId;
    bool found = false;
    Book *prev = NULL; // For storing infromation of the previous node.

    if (head == NULL)
    {
        gotoxy(53, 8);
        cout << "There Are No Books In The Library!!";
        _getch();
        return;
    }

    else
    {
        gotoxy(53, 8);
        cout << "Book ID : ";
        cin >> tempId;

        // Search Operation:
        Book *ptr = head;

        while (ptr != NULL)
        {
            if (tempId == ptr->id)
            {
                system("cls");
                showTitle("Delete Record");

                gotoxy(53, 8); // Existing records of Books.
                cout << "Existing Record: ";
                gotoxy(53, 9);
                for (int i = 1; i <= 18; i++)
                    printf("%c", 95);

                gotoxy(53, 12);
                cout << "Book ID : " << ptr->id;

                gotoxy(53, 14);
                cout << "Name : " << ptr->name;

                gotoxy(53, 16);
                cout << "Author Name : " << ptr->author;

                gotoxy(53, 18);
                cout << "Publisher Name : " << ptr->publisher;

                found = true;

                break;
            }
            else if (tempId > ptr->id)
            {
                prev = ptr;
                ptr = ptr->next;
            }
        }

        // Delete operation:
        Ask_before_operation("Delete");

        if (found)
        {

            if (prev == NULL) // First node.
                head = ptr->next;

            else
                prev->next = ptr->next;

            delete ptr;
            gotoxy(53, 10);
            cout << "Book Deleted Successfully...!!";
        }

        else if (!found)
        {
            gotoxy(53, 10);
            cout << "The Book Is Not In The Library...!!";
        }
    }

    sort(); // sorting the data after operation.
    _getch();
}

/// Menu Function:

void library::menu()
{
    system("cls");
    hideCursor();

    int position = 1;
    int keyPressed = 0;

    while (keyPressed != 13) // Ascii 13 is the code for "Enter key".
    {
        /// Menu interface:
        showTitle("LIBRARY MANAGEMENT SYSTEM");
        //---------------------------------------------Box Of Menu-----------------------------------------------------------------//

        gotoxy(50, 10);               // Upper bar of MENU
        for (int i = 1; i <= 71; i++) // 70 dots.
            printf("%c", 220);

        gotoxy(50, 32);               // Lower bar of MENU
        for (int i = 1; i <= 71; i++) // 70 dots.
            printf("%c", 220);

        for (int i = 11; i <= 32; i++)
        {
            gotoxy(50, i);
            printf("%c", 219);
        }
        for (int i = 11; i <= 32; i++)
        {

            gotoxy(120, i);
            printf("%c", 219);
        }

        //--------------------------------------------------------------------------------------------------------------------------------------//

        gotoxy(70, 12);
        printf("  WELCOME USER.  ");
        gotoxy(70, 13);
        printf("~~~~~~~~~~~~~~~~~");

        gotoxy(53, 15);
        cout << "What would you like to do today!";

        gotoxy(53, 17);
        arrowHere(1, position);
        printf("1. Insert New Record.");

        gotoxy(53, 19);
        arrowHere(2, position);
        printf("2. Search Record.");

        gotoxy(53, 21);
        arrowHere(3, position);
        printf("3. Update Record.");

        gotoxy(53, 23);
        arrowHere(4, position);
        printf("4. Delete Record.");

        gotoxy(53, 25);
        arrowHere(5, position);
        printf("5. Show All Records.");

        gotoxy(53, 27);
        arrowHere(6, position);
        printf("6. Read something about the Creators.");

        gotoxy(53, 29);
        arrowHere(7, position);
        printf("7. Exit.");

        keyPressed = _getch();

        if (keyPressed == 80 && position != 7) // ASCII for "Down arrow key" is 80.
            position++;

        else if (keyPressed == 72 && position != 1) // ASCII for "Up arrow key" is 72.
            position--;

        else if (keyPressed == 80 && position == 7) // Back to 1st position.
            position = 1;

        else if (keyPressed == 72 && position == 1) // Back to 7th position.
            position = 7;

        else
            position = position;

        /// Operations.
        if (keyPressed == 13)
        {
            system("cls");
            hideCursor();
            switch (position)
            {
            case 1: // Insert.
                system("cls");
                hideCursor();
                insert();
                break;
            case 2: // Search.
                system("cls");
                hideCursor();
                // load_data();
                sort(); // Sorting all data.
                search();
                break;
            case 3: // Update.

                system("cls");
                hideCursor();
                // load_data();
                sort(); // Sorting all data.
                update();
                break;
            case 4: // delete.
                system("cls");
                hideCursor();
                sort(); // Sorting all data.
                Delete();
                break;
            case 5:
                system("cls");
                hideCursor();
                sort(); // Sorting all data.
                ShowAll();
                break;
            case 6:
                system("cls");
                hideCursor();
                cout << "about us function called.";
                break;
            case 7:
                system("cls");
                hideCursor();
                EXIT();

                if (exitFlag == 1)
                    return;

                break;
            }
        }
    }
    menu();
}

int main()
{
    hideCursor();
    library obj1;
    obj1.menu();
    return 0;
}
