#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;
int main(int argc, char *argv[])
{
    int year, month, day, hour, minute, second, millisecond;
    SYSTEMTIME start, end;
    STARTUPINFO si;
    memset(&si, 0, sizeof(STARTUPINFO));
    si.wShowWindow = SW_SHOW;
    PROCESS_INFORMATION pi;
    if (argc == 2)
    {
        if (!CreateProcess(NULL, TEXT(argv[1]), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        {
            cout << "Create Fail" << endl;
            exit(0);
        }
    }
    else
    {
        char *str = strcat(argv[1], " ");
        str = strcat(str, argv[2]);
        if (!CreateProcess(NULL, TEXT(str), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        {
            cout << "Create Fail" << endl;
            exit(0);
        }
    }
    //load time
    GetSystemTime(&start);
    WaitForSingleObject(pi.hProcess, INFINITE);
    GetSystemTime(&end);

    //print data
    millisecond = end.wMilliseconds - start.wMilliseconds;
    year = end.wYear - start.wYear;
    month = end.wMonth - start.wMonth;
    day = end.wDay - start.wDay;
    hour = end.wHour - start.wHour;
    minute = end.wMinute - start.wMinute;
    second = end.wSecond - start.wSecond;
    if (millisecond < 0)
    {
        second--;
        millisecond += 1000;
    }
    if (second < 0)
    {
        minute--;
        second += 60;
    }
    if (minute < 0)
    {
        hour--;
        minute += 60;
    }
    if (hour < 0)
    {
        day--;
        hour += 24;
    }
    if (day < 0)
    {
        month--;
        day += 30;
    }
    if (month < 0)
    {
        year--;
        month += 12;
    }
    printf("程序运行时间：");
    if (year > 0)
        printf("%d 年 ", year);
    if (month > 0)
        printf("%d 月 ", month);
    if (day > 0)
        printf("%d 日 ", day);
    if (hour > 0)
        printf("%d 时 ", hour);
    if (minute > 0)
        printf("%d 分 ", minute);
    if (second > 0)
        printf("%d 秒 ", second);
    if (millisecond > 0)
        printf("%d 毫秒", millisecond);
    printf("\n");

    return 0;
}
