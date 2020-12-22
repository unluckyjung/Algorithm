#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    //string atNoon = s.substr(s.size()-2);
    string hour = s.substr(0,2);
    string atNoon = s.substr(s.size()-2,2);
    
    int hourInt = stoi(hour);

    if(atNoon == "AM" && hour == "12"){
        hour = "00";
    }
    else if(atNoon == "PM" and hourInt < 12){
        hourInt += 12;
        hour = to_string(hourInt);
    }
    return hour + s.substr(2, s.size()-hour.size()-2);
}
