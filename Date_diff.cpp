#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    //function to calculate no of leap years
    int count_leap_years(int month, int year){
        if (month < 3){
            year--;
        }
            int count;
            count=year/4;
            count=count-year/100;
            count=count+year/400;
        return count;
    }

    //function to change a substring into integer
    int str_to_int(string s,int i,int pos){
        int num=0;
        while(pos){
            num = num * 10 + s[i]-'0';
            i++;
            pos--;
        }
        return num;
    }

    //date_diff function takes two dates in format(DD-MM-YYYY) and returns the no of days b/w two dates.
    long long int date_diff(string start_date, string end_date){

        int day1=str_to_int(start_date,0,2);
	int month1=str_to_int(start_date,3,2);
	int year1=str_to_int(start_date,6,4);

        int day2=str_to_int(end_date,0,2);
	int month2=str_to_int(end_date,3,2);
	int year2=str_to_int(end_date,6,4);

        int m_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Calculate the total number of days for start_date
        int n1 = year1 * 365;
        n1=n1+day1;
        for (int i = 0; i < month1 - 1; i++){
            n1 =n1+ m_days[i];
        }
	// count the number of leap years till the start_date year and add the count in total number of days for start_date
        n1 =n1+ count_leap_years(month1, year1);

	// Calculate the total number of days for end_date
        int n2 = year2 * 365;
        n2=n2+day2;
        for (int i = 0; i < month2 - 1; i++){
            n2 =n2+ m_days[i];
        }
	// count the number of leap years till the end_date year and add the count in total number of days for end_date
        n2 =n2+ count_leap_years(month2, year2);

        // returning absolute value
        return (n2>n1 ? n2-n1 : n1-n2);
	}

};
int main(){

    string start_date,end_date;
    cout<<"Enter the start date in the format-> DD-MM-YYYY \n";
    cin>>start_date;
    cout<<"Enter the end date in the format-> DD-MM-YYYY \n";
    cin>>end_date;

    solution obj;
    long long int no_of_days = obj.date_diff(start_date,end_date);
    cout<<"\nNo. of days: "<<no_of_days<<" days";

    return 0;
}
