#include <stdio.h>

const char *day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int daysOfMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void checkLeapYear(int iDay, int iMonth, int iYear){
    if((iYear % 4 == 0 && iYear % 100!=0) || iYear %400 == 0){
       daysOfMonths[2] = 29;
    }
}

int dayOfWeek(int iDay, int iMonth, int iYear){
    int Sum = iDay;
    for (int i = 0; i < iMonth; i++)
    {
        Sum = Sum + daysOfMonths[i];
    }
    int N = (iYear - 1) + (iYear - 1)/4 - (iYear - 1)/100 + (iYear - 1)/400 + Sum;
    
    int dayofweek = N % 7; 
    return dayofweek;
}


int main(int argc, char const *argv[])
{
    int iDay, iMonth, iYear;
    scanf("%d%d%d",&iDay, &iMonth, &iYear);
    checkLeapYear(iDay,iMonth,iYear);
    printf("%s", day[dayOfWeek(iDay,iMonth,iYear)]);
    return 0;
}


