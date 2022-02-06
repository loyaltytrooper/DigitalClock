#include<iostream>
#include<conio.h>
#include<ctime>
using namespace std;

void alarm();
void digitalClock();
void timer();
void stopwatch();

// functions to make the features work
void epoch_convertor(time_t);



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
        digitalClock();
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

void digitalClock() // Name of Engineer developing this feature
{
    // Please start writing your code here and please write comments so that others can understand what has been done
    // Feel free to make your own functions to support the functionality of your code
    return;
}

void alarm() // Name of Engineer developing this feature
{
    // Please start writing your code here and please write comments so that others can understand what has been done
    // Feel free to make your own functions to support the functionality of your code
    return;
}

void timer() // Name of Engineer developing this feature
{
    // Please start writing your code here and please write comments so that others can understand what has been done
    // Feel free to make your own functions to support the functionality of your code
    return;
}

void stopwatch() // Name of Engineer developing this feature
{
    // Please start writing your code here and please write comments so that others can understand 
    //what has been done 
    // Feel free to make your own functions to support the functionality of your code

    cout << "Press:- " << endl
         << "\t\t's' - Start the StopWatch" << endl
         << "\t\t'l' for lap" << endl
         << "\t\t'r' for reset" << endl;

    int lapCount = 0;

    time_t start, lap, laptime, lapPrev = 0;
    tm *accessor; //used to access the time_t type variable and 
// directly convert int or double types into respective time formats

    char button = getch();
    while(button) // #include<conio.h>
    {
        if(button == 's')
            start = time(NULL);

        else if(button == 'l')
        {
            lap = time(NULL);

            laptime = lap - start;

            lapCount++;
            cout << "Lap " << lapCount << " -> ";
            epoch_convertor(laptime);

            if(lapPrev != 0)
            {
                cout << "\t Time between previous Lap -> ";
                epoch_convertor(lapPrev);
            }
            else
                cout << endl;

            lapPrev = lap - start;
        }

        else if(button == 'r')
            break;
        
        button = getch();
    }
}

int main()
{
    menu();
    return 0;
}

void epoch_convertor(time_t timeX)
{
    int dd = 0, hh = 0, mm = 0, ss;

    ss = timeX % 60;

    if(timeX>=60)
        mm = timeX / 60;
    if(timeX >= 3600)
        hh = timeX / 3600;
    if(timeX >= 86400)
        dd = timeX / 86400;

    cout << dd<<':'<<hh<<':'<<mm<<':'<<ss << endl;
    return;
}