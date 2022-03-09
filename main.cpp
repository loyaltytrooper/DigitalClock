#include "bin\driver.h"

// void alarm();
// void digitalClock();
// void timer();
// void stopwatch();

// functions to make the features work :
// void epoch_convertor(time_t);

int main()
{
    char ch;
    cout << "Press 'y' to Enter the Menu or any other key to exit" << endl;
    cin.get(ch);

    while(ch == 'y')
    {
        menu();
        cout << "Press 'y' to Enter the Menu or any other key to exit" << endl;
        ch = getch();
    }
    return 0;
}