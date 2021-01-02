## c++

```c++
bool isLeapYear(int year){
    if (year <= 1917) {
        return year % 4 == 0;
    }
    if (year % 400 == 0) return true;
    if (year % 4 == 0 && year % 100 != 0) return true;
    
    return false;
}
string dayOfProgrammer(int year) {
    int day = 13;
    const int leapYearDay = 12;
    
    if (year == 1918){
        day = 26;
    } else if (isLeapYear(year)){
        day = leapYearDay;
    }
    
    return to_string(day) + ".09." + to_string(year);
}
```