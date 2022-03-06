#include"resources.h"


void menu()
{
menuDriver:
    cout << "Welcome" << endl;
    cout << endl
         << endl
         << "\t\t\t\t\tMENU" << endl;
    cout << "\t\t\t\t\t\t1) Clock" << endl;
    cout << "\t\t\t\t\t\t2) Alarm" << endl;
    cout << "\t\t\t\t\t\t3) Timer" << endl;
    cout << "\t\t\t\t\t\t4) Stopwatch" << endl;
    int choice = 0;
    cin >> choice;

    if (choice == 0)
        exit(0);
    else if (choice == 1)
        digitalClock();
    else if (choice == 2)
        alarm();
    else if (choice == 3)
        timer();
    else if (choice == 4)
        stopwatch();
    else
    {
        cout << "You have chosen an invalid option, Try Again";
        goto menuDriver;
    }
}


void digitalClock() 
{
    time_t start;
    time(&start);
    cout<<ctime(&start);
    return;
}


void alarm()
{ 
    return;
}


void timer() // Use previous timer setting or not?
{
    int hh, mm, ss;
    cout << "Please set the Timer(hh : mm : ss)\n";
    cin >> hh >> mm >> ss;
    CorrectTimeGiven(hh, mm, ss);

    cout << "START? (y/n)" << endl;

    char choice;
    cin >> choice;
    if(choice == 'y')
    {
        time_t startTime;
        time(&startTime);
        cout << "Current time is : " << ctime(&startTime) << endl;
        cout << "The timer is set for  " << setfill('0') << setw(2) << hh << ':' << setw(2) << mm << ':' << setw(2) << ss << endl;
        time_t finalTime = (startTime + (hh * 3600) + (mm * 60) + ss);
        cout << "till " << ctime(&finalTime);

        while(startTime != finalTime)
        {
            time(&startTime);
        }
        cout << "Timer Finished";
    }
}


void stopwatch()
{
    cout << "Press:- " << endl
         << "\t\t's' - Start the StopWatch" << endl
         << "\t\t'l' for lap" << endl
         << "\t\t'r' for reset" << endl;

    int lapCount = 0;

    time_t start, lap, laptime, lapPrev = 0;
    tm *accessor; // used to access the time_t type variable and
    // directly convert int or double types into respective time formats

    char button = getch();
    while (button) // #include<conio.h>
    {
        if (button == 's')
            start = time(NULL);

        else if (button == 'l')
        {
            lap = time(NULL);

            laptime = lap - start;

            lapCount++;
            cout << "Lap " << lapCount << " -> ";
            epoch_convertor(laptime);

            if (lapPrev != 0)
            {
                cout << "\t Time between previous Lap -> ";
                epoch_convertor((lap - start) - lapPrev);
                cout << endl;
            }
            else
                cout << endl;

            lapPrev = lap - start;
        }

        else if (button == 'r')
            break;

        button = getch();
    }
    
}



/* ************ FUNTIONS THAT WILL BE USED IN THE FEATURE FUNCTIONS ************** */


// I am using this to convert the time_t variable passed
// to convert the difference time in seconds into my desired format
void epoch_convertor(time_t timeX)
{
    int dd = 0, hh = 0, mm = 0, ss;

    ss = timeX % 60;

    if (timeX >= 86400)
    {
        dd = timeX / 86400;
        timeX = timeX - (86400 * dd);
    }
    if (timeX >= 3600)
    {
        hh = timeX / 3600;
        timeX = timeX - (3600 * hh);
    }
    if (timeX >= 60)
        mm = timeX / 60;

    cout << setfill('0') << setw(2) << dd << ':' << setw(2) << hh << ':' << setw(2) << mm << ':' << setw(2) << ss;
    return;
}

void CorrectTimeGiven(int &hour, int &minute, int &second)
{
    if (second > 59)
    {
        minute = minute + (second / 60);
        second = second % 60;

        if (minute > 59)
        {
            hour = hour + minute / 60;
            minute = minute % 60;
        }
    }

    if (minute > 59)
    {
        hour = hour + minute / 60;
        minute = minute % 60;
    }
}
