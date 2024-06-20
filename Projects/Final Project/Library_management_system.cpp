#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
using namespace std;
#define ll long long int
#define vi vector<int>

int exitFlag = 0;     /// This flag is used for exiting the application.
int Record_count = 0; /// This count of how many records are in the Files.
int Admin_count = 0;  /// This is the count of how many admins can access the library records.(Informations are stored in the )

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
    struct Admin
    {
        string first_name, last_name, user_name, password;
        // int Record_count; /// number of book saved

        Admin *next;
    };

public:
    Book *head = NULL;    // Head pointer of the Book list.
    Admin *start = NULL;  /// head pointer of the admin list
    void Read_recods();   // For storing the records inside the Linked List.
    void write_records(); // For writing the records inside the File.
    void first_page();
    void signup();
    void login();
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
    void Admin_record_read();
    void Admin_record_write();
};

void library ::Admin_record_read()
{
    ifstream in("Admin.txt");

    in >> Admin_count;

    if (Admin_count == 0)
    {
        in.close();
        return;
    }

    in.ignore();

    Admin *str = new Admin;

    for (int i = 1; i <= Admin_count; i++)
    {
        getline(in, str->first_name);
        getline(in, str->last_name);
        getline(in, str->user_name);
        getline(in, str->password);

        if (start == NULL)
            start = str;

        {

            if (i == Admin_count)
                str->next = NULL;
            else
            {
                str->next = new Admin;
                str = str->next;
            }
        }
    }

    in.close();
}

void library ::Admin_record_write()
{
    ofstream out("Admin.txt");

    if (!out)
        cout << "error\n";

    out << Admin_count << endl;

    Admin *str = start; /// original starting node of the admin list

    while (str != NULL)
    {

        out << str->first_name << endl;
        out << str->last_name << endl;
        out << str->user_name << endl;
        out << str->password << endl;

        str = str->next;
    }

    out.close();
}
/// Read Data Function:
void library::Read_recods()
{
    ifstream in("Book List.txt");

    if (!in)
    {
        gotoxy(70, 20);
        cout << "\n File Not Found....!!";
        _getch();
        return; // Error return.
    }

    in >> Record_count; // Reading total number of Books from the file.

    if (Record_count == 0)
        return;

    in.ignore(); // Ignore the newline character after the record count.

    //-------------------------------- Reading book info and storing it in Book LL.-----------------------------------------------
    for (int i = 0; i < Record_count; i++)
    {
        Book *newNode = new Book;

        in >> newNode->id;               // book id.
        in.ignore();                     // Ignore the newline character after the ID.
        getline(in, newNode->name);      // book name.
        getline(in, newNode->author);    // book author.
        getline(in, newNode->publisher); // book publisher.

        newNode->next = NULL; // Initially, every next field is null.

        /// Inserting data inside Book LL:
        if (head == NULL) // For the first record.
        {
            head = newNode;
        }
        else
        {
            Book *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    in.close(); // Closing the file.
}

/// Write Data Function:
void library::write_records()
{
    ofstream out("Book List.txt");

    if (!out)
    {
        gotoxy(70, 20);
        cout << "\n Error opening file for writing....!!";
        _getch();
        return; // Error return.
    }

    out << Record_count << endl; // Putting total book number inside file first.

    if (Record_count == 0)
        return;

    //-------------------------------- Writing book info and storing it in Book List File.-----------------------------------------------
    Book *current = head;
    while (current != NULL)
    {
        out << current->id << endl;
        out << current->name << endl;
        out << current->author << endl;
        out << current->publisher << endl;
        current = current->next; // Moving to the next node.
    }

    out.close(); // Closing the file.
}

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
    Read_recods(); // Reading data.

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

    Record_count++; // Increasing the number of books.

    write_records(); // Writing records.

    gotoxy(53, 17);
    cout << "New Book Inserted Successfully....!!";

    gotoxy(55, 22); // Waiting for user confirmation.
    printf(">>>Press any key to go back<<<");

    _getch();
}

void library ::first_page() /// sing up and login
{

    system("cls");
    hideCursor();

    int position = 1;
    int keyPressed = 0;

    while (keyPressed != 13)
    {
        showTitle("Library Management System");

        gotoxy(75, 10);
        arrowHere(1, position);
        cout << "Login \n";

        gotoxy(75, 12);
        arrowHere(2, position);
        cout << "Sign Up \n";

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

        if (position == 2 && keyPressed == 13)
        {
            system("cls");
            hideCursor();
            signup();
        }
        else if (position == 1 && keyPressed == 13)
        {
            system("cls");
            hideCursor();
            login();

            //   if (exitFlag == 1)
            // return; /// This will return to the main function.
        }
    }
}

void library::login() /// login function
{
    system("cls");

    string name, pass;

    showTitle("LOGIN");

    gotoxy(50, 8);
    cout << "Enter user name :";
    cin >> name;
    gotoxy(50, 10);
    cout << "Enter Password : ";
    cin >> pass;

    cin.ignore();

    Admin_record_read();

    Admin *str = start; /// starting point of admin list

    int i = 0;

    bool flag = 0; // Match check.

    while (str != NULL)
    {
        if (str->user_name == name && str->password == pass)
        {
            gotoxy(60, 14);
            cout << "Login Successfull \n";
            i = Admin_count + 1;
            flag = 1;

            gotoxy(55, 20); // Waiting for user confirmation.
            printf(">>>Press any key to continue<<<");

            _getch();
            menu();
            break;
        }

        str = str->next;
        i++;
    }

    if (flag == 0)
    {
        gotoxy(60, 14);
        cout << "Login Failed \n";

        gotoxy(55, 20); // Waiting for user confirmation.
        printf(">>>Press any key to go back<<<");

        _getch();
        first_page();
    }
}

void library ::signup() /// signup function
{
    Admin_record_read();

    Admin *newnode = new Admin;

    showTitle("Sign Up");

    gotoxy(50, 8);
    cout << "First Name : ";
    getline(cin, newnode->first_name);
    gotoxy(50, 10);
    cout << "Last Name : ";
    getline(cin, newnode->last_name);
    gotoxy(50, 12);
    cout << "User Name : ";
    getline(cin, newnode->user_name);
    gotoxy(50, 14);
    cout << "Password : ";
    getline(cin, newnode->password);

    if (Admin_count == 0)
    {
        start = newnode;
        start->next = NULL;
        Admin *str = start;
        //   str->next = NULL;
    }
    else

    {
        Admin *str = start;

        while (str->next != NULL)
            str = str->next;

        str->next = newnode;

        str = str->next;

        str->next = NULL;
    }

    Admin_count++;

    Admin_record_write();

    gotoxy(60, 17);
    cout << " Sign Up Successfull \n";

    gotoxy(55, 20); // Waiting for user confirmation.
    printf(">>>Press any key to continue<<<");

    _getch();
    login();
}
/// Show ALL Funtion:
void library::ShowAll()
{
    Read_recods(); // Reading data.
    sort();        // Sorting all data.

    system("cls");
    showTitle("List Of All Books");
    Book *ptr = head;

    if (head == NULL)
    {
        gotoxy(53, 8);
        cout << "There Are No Books In The Library!!";

        gotoxy(55, 12); // Waiting for user confirmation.
        printf(">>>Press any key to go back<<<");

        _getch();
        return;
    }

    gotoxy(50, 8);
    cout << "Book ID ";
    gotoxy(65, 8);
    cout << "Name ";
    gotoxy(90, 8);
    cout << "Author Name ";
    gotoxy(120, 8);
    cout << "Publisher Name ";

    int y = 10; // Y coordinate.
    while (ptr != NULL)
    {
        gotoxy(52, y);
        cout << ptr->id;
        gotoxy(67, y);
        cout << ptr->name;
        gotoxy(92, y);
        cout << ptr->author;
        gotoxy(122, y);
        cout << ptr->publisher;
        y += 3;
        ptr = ptr->next;
    }

    _getch();
}

/// Search Function:
void library::search()
{
    Read_recods(); // Reading data.
    sort();        // Sorting all data.

    system("cls");
    showTitle("Search Record");

    int tempId, found = false;
    if (head == NULL)
    {
        gotoxy(53, 8);
        cout << "There Are No Books In The Library!!";
        gotoxy(55, 12); // Waiting for user confirmation.
        printf(">>>Press any key to go back<<<");
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
    Read_recods(); // Reading data.
    sort();        // Sorting all data.

    system("cls");
    showTitle("Update Record");

    //----------------------------------Searching for the desired book--------------------------------------------------------------------//
    int tempId, found = false;
    Book *loc = NULL; // Location of desired book.

    if (head == NULL)
    {
        gotoxy(53, 8);
        cout << "There Are No Books In The Library!!";

        gotoxy(55, 12); // Waiting for user confirmation.
        printf(">>>Press any key to go back<<<");

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

        if (!found)
        {
            gotoxy(53, 8);
            cout << "The Book Is Not In The Library...!!";

            gotoxy(55, 12); // Waiting for user confirmation.
            printf(">>>Press any key to go back<<<");

            _getch();
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
    cout << "Record Updated Successfully...!!";

    sort(); // sorting the data after operation.

    write_records(); // Writng the data inside the file.(As it was an update the total number of books have not changed.)

    gotoxy(55, 22); // Waiting for user confirmation.
    printf(">>>Press any key to go back<<<");
    _getch();
}

/// Delete Function:
void library::Delete()
{
    Read_recods(); // Reading data.
    sort();        // Sorting all data.

    system("cls");
    showTitle("Delete Record");

    int tempId;
    bool found = false;
    Book *prev = NULL; // For storing infromation of the previous node.
    Book *loc = NULL;  // Location of desired book.

    if (head == NULL)
    {
        gotoxy(53, 8);
        cout << "There Are No Books In The Library!!";

        gotoxy(55, 12); // Waiting for user confirmation.
        printf(">>>Press any key to go back<<<");

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
            if (tempId > ptr->id)
            {
                prev = ptr;
                ptr = ptr->next;
            }

            else if (tempId == ptr->id)
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
                loc = ptr;
                break;
            }

            else
                break;
        }

        if (!found)
        {
            gotoxy(53, 8);
            cout << "The Book Is Not In The Library...!!";

            gotoxy(55, 12); // Waiting for user confirmation.
            printf(">>>Press any key to go back<<<");

            _getch();
            return;
        }
    }

    // ----------------------------Delete operation:---------------------------------//
    Ask_before_operation("Delete");

    if (prev == NULL) // First node.
        head = loc->next;

    else
        prev->next = loc->next;

    delete loc;
    gotoxy(53, 10);
    cout << "Book Deleted Successfully...!!";

    sort(); // sorting the data after operation.

    Record_count--;  // Decreasing total number of books.
    write_records(); // Writing in the files.

    gotoxy(55, 22); // Waiting for user confirmation.
    printf(">>>Press any key to go back<<<");
    _getch();
}

/// About Us Function:
void library::AboutUs()
{
    system("cls");

    char UD = 179; // Up and down line
    char LR = 22;  // Left and rigth line.
    char sign = 4;

    gotoxy(69, 12);
    printf("ABOUT US");

    // For box around About Us text.
    for (int x = 63; x <= 84; x++)
    {
        gotoxy(x, 11);
        printf("%c", LR);
    }

    for (int x = 63; x <= 84; x++)
    {
        gotoxy(x, 13);
        printf("%c", LR);
    }

    gotoxy(62, 12);
    printf("%c", UD);

    gotoxy(85, 12);
    printf("%c", UD);

    // Rakin info.
    gotoxy(48, 15);
    printf("%c Shafkat Islam Rakin", sign);
    gotoxy(50, 16);
    printf("ID: C231106");
    gotoxy(50, 17);
    printf("Dept. of CSE");
    gotoxy(50, 18);
    printf("IIUC.");

    for (int y = 15; y <= 18; y++)
    {
        gotoxy(75, y);
        printf("%c", UD);
    }

    // Istiyaq info.
    gotoxy(78, 15);
    printf("%c Sayed Shahriar Istiyaq", sign);
    gotoxy(80, 16);
    printf("ID: C231107");
    gotoxy(80, 17);
    printf("Dept. of CSE");
    gotoxy(80, 18);
    printf("IIUC.");

    gotoxy(55, 22);
    printf(">>>Press any key to go back<<<");
    getch();
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
        printf("  WELCOME TO IIUC CENTRAL LIBRARY.  ");
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
            switch (position) /*The head  of the list will be null before any operations so that , the data can be easily read from the file.*/
            {
            case 1: // Insert.
                system("cls");
                hideCursor();

                head = NULL;
                insert();

                break;

            case 2: // Search.
                system("cls");
                hideCursor();

                head = NULL;
                search();

                break;

            case 3: // Update.
                system("cls");
                hideCursor();

                head = NULL;
                update();

                break;

            case 4: // Delete.
                system("cls");
                hideCursor();

                head = NULL;
                Delete();

                break;

            case 5: // Show all data.
                system("cls");
                hideCursor();

                head = NULL;
                ShowAll();

                break;

            case 6:

                system("cls");
                hideCursor();

                AboutUs();

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
    system("color 09"); // here 0->Background , 9->text or teminal
    hideCursor();
    library obj1;
    obj1.Read_recods(); // Reading all existing data from file.
    obj1.first_page();
    return 0;
}
