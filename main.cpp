#include<iostream>
using namespace std;


void menu()
{
    menuDriver:
    cout << "Welcome" << endl;
    cout << endl << endl << "\t\t\t\t\tMENU" << endl;
    cout << "\t\t\t\t\t\t1) Clock" << endl;
    cout << "\t\t\t\t\t\t2) Alarm" << endl;
    cout << "\t\t\t\t\t\t3) Timer" << endl;
    cout << "\t\t\t\t\t\t4) Stopwatch" << endl;
    int choice = 0;
    cin >> choice;

    if(choice == 0)
        exit(0);
    else if(choice == 1)
        clock();
    else if(choice == 2)
        alarm();
    else if(choice == 3)
        timer();
    else if(choice == 4)
        stopwatch();
    else
    {
        cout << "You have chosen an invalid option, Try Again";
        goto menuDriver;
    }
}

void clock() // Name of Engineer developing this feature
{
    // Please start writing your code here and please write comments so that others can understand what has been done
    // Feel free to make your own functions to support the functionality of your code
}

void alarm() // Name of Engineer developing this feature
{
    // Please start writing your code here and please write comments so that others can understand what has been done
    // Feel free to make your own functions to support the functionality of your code
}

void timer() // Name of Engineer developing this feature
{
    // Please start writing your code here and please write comments so that others can understand what has been done
    // Feel free to make your own functions to support the functionality of your code
}

void stopwatch() // Name of Engineer developing this feature
{
    // Please start writing your code here and please write comments so that others can understand what has been done 
    // Feel free to make your own functions to support the functionality of your code
}

int main()
{
    menu();
    return 0;
}