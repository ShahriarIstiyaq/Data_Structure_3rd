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

/// Main class of Library:(all functions are inside this)
class library
{
private:
    struct Book // Node of the list
    {
        int id; // Book id
        string name, author, publisher;
        Book *next_add; // Next field for adding new books.
    };

public:
    Book *head = NULL; // Head pointer of the Book list.
    void menu();
    void EXIT();
    void insert();
};

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

        //-----------------------------------------------------------Titile----------------------------------------------------//
        gotoxy(70, 4);                // Upper bar of Title.
        for (int i = 1; i <= 35; i++) // 35 dots.
            printf("%c", 254);

        gotoxy(70, 5); // Title of project.
        cout << "     LIBRARY MANAGEMENT SYSTEM     ";

        gotoxy(70, 5); // Left bar of Title.
        printf("%c", 219);
        gotoxy(104, 5); // Right bar of Title.
        printf("%c", 219);

        gotoxy(70, 6);                // Lower bar of Title.
        for (int i = 1; i <= 35; i++) // 35 dots.
            printf("%c", 254);

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
        printf("1. Insert Record.");

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
            case 1:
                system("cls");
                hideCursor();
                cout << "Insert function called.";
                break;
            case 2:
                system("cls");
                hideCursor();
                cout << "search function called.";
                break;
            case 3:
                system("cls");
                hideCursor();
                cout << "Update function called.";
                break;
            case 4:
                system("cls");
                hideCursor();
                cout << "Delete function called.";
                break;
            case 5:
                system("cls");
                hideCursor();
                cout << "Show all function called.";
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
                cout << "exit function called.";

                if (exitFlag == 1)
                    return;
            }
        }
    }
}

int main()
{
    hideCursor();
    library obj1;
    obj1.menu();
    return 0;
}
