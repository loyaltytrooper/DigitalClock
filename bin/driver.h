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
    time_t now;
    fstream f;
    char countryCode[30];
    cout << "Please enter the country code (or zone abbreviation), -1 if IST preferred" << endl;
    cin.get();
    cin.getline(countryCode, 30);

    f.open("bin/timeZone.csv", ios :: in);
    
    int hour, minute;
    string country, code, sign, timeZone;
    while(!f.eof())
    {
        if(countryCode[0] == '-' && countryCode[1] == '1')
        {
            
            time(&now);
            cout<<ctime(&now);
            break;
        }

        f >> country >> code >> sign >> timeZone;

        bool check = true, checkCode = true;
        for (int i = 0; country[i] != '\0'; i++)
        {
            if(country[i] != countryCode[i])
                check = false;

            if(code[i] != countryCode[i])
                checkCode = false;
        }

        if (check == true || checkCode == true)
        {
            if (sign[0] == '+')
            {
                hour = ((timeZone[0] - '0') * 10) + (timeZone[1] - '0');
                minute = ((timeZone[3] - '0') * 10) + (timeZone[4] - '0');

                time(&now);
                now = now + ((hour * 3600) + (minute * 60));
                cout << endl
                        << ctime(&now) << endl;
                break;
            }
            else
            {
                hour = ((int)(timeZone[0] - '0') * 10) + (int)(timeZone[1] - '0');
                minute = ((int)(timeZone[3] - '0') * 10) + (int)(timeZone[4] - '0');

                time(&now);
                now = now - ((hour * 3600) + (minute * 60));
                cout << ctime(&now) << endl;
                break;
            }
        }
    }
    f.close();
    return;
}


void alarm()
{
    struct tm *alarm_date;
    time_t now;
    time(&now);
    int sec, min, hour, day, month, year;
    cout << "Current time is " << ctime(&now) << endl;
    cout << "When to set the alarm for?" << endl;
    cout << "Enter in order\n"
            "Year\n"
            "Month (1 to 12)\n"
            "Day (1 to 31) except in Feb\n"
            "Hours (0 to 23)\n"
            "Minutes(0 to 59)\n"
            "Seconds (0 to 59)\n";

    cin >> year >> month >> day >> hour >> min >> sec;
    
    alarm_date->tm_year = year;
    alarm_date->tm_mon = month;
    alarm_date->tm_mday = day;
    alarm_date->tm_hour = hour;
    alarm_date->tm_min = min;
    alarm_date->tm_sec = sec;

    time_t alarmDate = mktime(alarm_date);
    cout<< ctime(&alarmDate) <<endl;
    cout << "Set the alarm!";

    while(alarmDate != now)
    {
        time(&now);
    }

    cout << "Alarm Completed";
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
