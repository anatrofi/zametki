#include "Header.h"

bool existDir(const char * name)
{
    struct stat s;
    if (stat(name, &s) == 0) return false;
    return true;
};

time_t TimeTransformation(char* time)
{
    
    string wday = string(1,time[0]);
    wday += string(1, time[1]);
    wday += string(1, time[2]); //день недели
    string mth = string(1, time[4]);
    mth += string(1, time[5]);
    mth += string(1, time[6]); // мес€ц

    int weekday, month, day, hour, min, sec, year;

    if (wday == "Mon") { weekday = 0; }
    else if (wday == "Tue") { weekday = 1; }
    else if (wday == "Wen") { weekday = 2; }
    else if (wday == "Thu") { weekday = 3; }
    else if (wday == "Fri") { weekday = 4; }
    else if (wday == "Sat") { weekday = 5; }
    else if (wday == "Sun") { weekday = 6; }

    if (mth == "Jan") { month = 0; }
    else if (mth == "Feb") { month = 1; }
    else if (mth == "Mar") { month = 2; }
    else if (mth == "Apr") { month = 3; }
    else if (mth == "May") { month = 4; }
    else if (mth == "Jun") { month = 5; }
    else if (mth == "Jul") { month = 6; }
    else if (mth == "Aug") { month = 7; }
    else if (mth == "Sep") { month = 8; }
    else if (mth == "Oct") { month = 9; }
    else if (mth == "Nov") { month = 10; }
    else if (mth == "Dec") { month = 11; }
    
    day = ((int)time[8] - (int)'0') * 10 + ((int)time[9] - (int)'0');
    hour = ((int)time[11] - (int)'0') * 10 + ((int)time[12] - (int)'0');
    min = ((int)time[14] - (int)'0') * 10 + ((int)time[15] - (int)'0');
    sec = ((int)time[17] - (int)'0') * 10 + ((int)time[18] - (int)'0');
    year = ((int)time[20] - (int)'0') * 1000 + ((int)time[21] - (int)'0')*100 +((int)time[22] - (int)'0') * 10 + ((int)time[23] - (int)'0');

    struct tm gettime{};
    gettime.tm_wday = weekday;
    gettime.tm_year = year-1900;
    gettime.tm_mon = month;
    gettime.tm_mday = day;
    gettime.tm_hour = hour;
    gettime.tm_min = min;
    gettime.tm_sec = sec;
    gettime.tm_isdst = 0;

    time_t rettime = mktime(&gettime);
    return (rettime);
}



