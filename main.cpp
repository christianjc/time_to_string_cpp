#include <iostream>
#include "date_converter.hpp"

bool test_leap_year();
void test_date();
void test_time();
void test_full_date();

int main()
{
    unsigned long int time = 1651114519285102588; // 1656379623*1000000000ULL;//3111568105;
    // date_to_str d(time, "nano");
    // std::string hello = "hello world";
    // std::cout << d.sec_ << std::endl;
    // std::cout << d.year_ << std::endl;
    // std::string test1 = test_leap_year()? "Correct": "flase";
    // std::cout << test1 << std::endl;
    // test_date();
    // test_time();
    test_full_date();
}

using namespace std;

bool test_leap_year()
{
    cout << "************ Testing Leap Years ***********" << endl;
    // Testing this function in seconds;
    // testing lower bound of leap year
    cout << "First leap year lower bound" << endl;
    unsigned long int time1 = 63071999; // Friday, December 31, 1971 23:59:59
    unsigned long int time2 = 63072000; // Saturday, January 1, 1972 0:00:00
    // testing upper bound of leap year
    cout << "First leap year upper bound" << endl;
    unsigned long int time3 = 94694399; // Sunday, December 31, 1972 23:59:59
    unsigned long int time4 = 94694400; // Monday, January 1, 1973 0:00:00

    date_to_str d1(time1, "sec");
    date_to_str d2(time2, "sec");
    date_to_str d3(time3, "sec");
    date_to_str d4(time4, "sec");

    cout << "Input1: " << time1 << "  Is leapyear?: " << (d1.is_leap_year_ ? "yes" : "No") << "  Num of leapyears: " << d1.num_of_leap_years_ << endl;
    cout << "Input2: " << time2 << "  Is leapyear?: " << (d2.is_leap_year_ ? "yes" : "No") << "  Num of leapyears: " << d2.num_of_leap_years_ << endl;
    cout << "Input3: " << time3 << "  Is leapyear?: " << (d3.is_leap_year_ ? "yes" : "No") << "  Num of leapyears: " << d3.num_of_leap_years_ << endl;
    cout << "Input4: " << time4 << "  Is leapyear?: " << (d4.is_leap_year_ ? "yes" : "No") << "  Num of leapyears: " << d4.num_of_leap_years_ << endl;

    // ********* Variable manual input *********
    // unsigned long int time = 60479999; //
    // date_to_str d(time, "sec");
    // cout << "Input: " << time << "  Is leapyear?: " << (d.is_leap_year_?"yes":"No") << "  Num of leapyears: "  << d.num_of_leap_years_ << endl;

    // test the all leapyears lower bounds and upper bound 4 year increment -> (126230400)
    cout << "\n*******Testing all leap years ************" << endl;
    for (int i = 2; time1 < MAX_DATE_SEC; i++)
    {
        time1 += FOUR_YEAR_INCREMENT_SEC;
        time2 += FOUR_YEAR_INCREMENT_SEC;
        time3 += FOUR_YEAR_INCREMENT_SEC;
        time4 += FOUR_YEAR_INCREMENT_SEC;
        d1.update_date(time1, "sec");
        d2.update_date(time2, "sec");
        d3.update_date(time3, "sec");
        d4.update_date(time4, "sec");
        cout << "Leap Year: " << i << endl;
        cout << "lower bound: " << time1 << "  Is leapyear?: " << (d1.is_leap_year_ ? "yes" : "No")
             << "  Num of leapyears: " << d1.num_of_leap_years_ << endl;
        cout << "upper bound: " << time2 << "  Is leapyear?: " << (d2.is_leap_year_ ? "yes" : "No")
             << "  Num of leapyears: " << d2.num_of_leap_years_ << endl;
        cout << "lower bound: " << time3 << "  Is leapyear?: " << (d3.is_leap_year_ ? "yes" : "No")
             << "  Num of leapyears: " << d3.num_of_leap_years_ << endl;
        cout << "upper bound: " << time4 << "  Is leapyear?: " << (d4.is_leap_year_ ? "yes" : "No")
             << "  Num of leapyears: " << d4.num_of_leap_years_ << "\n"
             << endl;
    }
    // unsigned long int time1 = 63071999; // Friday, December 31, 1971 23:59:59
    // unsigned long int time2 = 63072000; // Saturday, January 1, 1972 0:00:00
    return d1.is_leap_year_;
}

void test_date()
{
    cout << "\n************** Testing Correct year output **********************" << endl;
    // Test year bounds:
    // testing lower bound of leap year
    unsigned long int time1 = 63071999; // Friday, December 31, 1971 23:59:59
    unsigned long int time2 = 63072000; // Saturday, January 1, 1972 0:00:00
    // testing upper bound of leap year
    unsigned long int time3 = 94694399; // Sunday, December 31, 1972 23:59:59
    unsigned long int time4 = 94694400; // Monday, January 1, 1973 0:00:00
    // testing reandom year
    unsigned long int time5 = 978307199; // Sunday, December 31, 2000 23:59:59
    unsigned long int time6 = 978307200; // Monday, January 1, 2001 0:00:00
    // testing leap month year
    unsigned long int time7 = 951868799;           // Tuesday, February 29, 2000 23:59:59
    unsigned long int time8 = 1646011101;          // Monday, February 28, 2022 1:18:21
    unsigned long int time9 = 1651113732762999086; // 951868899; // Wednesday, March 1, 2000 0:01:39
    // unsigned long int time9 = 1643678301; // Tuesday, February 1, 2022 1:18:21

    date_to_str y1(time1, "sec");
    date_to_str y2(time2, "sec");
    date_to_str y3(time3, "sec");
    date_to_str y4(time4, "sec");
    date_to_str y5(time5, "sec");
    date_to_str y6(time6, "sec");
    date_to_str y7(time7, "sec");
    date_to_str y8(time8, "sec");
    date_to_str y9(time9, "nano");

    cout << "\n********* Year **************" << endl;
    cout << "Input time1: " << time1 << " Expected Year: " << 1971 << "  Actual: " << y1.year_ << endl;
    cout << "Input time2: " << time2 << " Expected Year: " << 1972 << "  Actual: " << y2.year_ << endl;
    cout << "Input time3: " << time3 << " Expected Year: " << 1972 << "  Actual: " << y3.year_ << endl;
    cout << "Input time4: " << time4 << " Expected Year: " << 1973 << "  Actual: " << y4.year_ << endl;
    cout << "Input time5: " << time5 << " Expected Year: " << 2000 << "  Actual: " << y5.year_ << endl;
    cout << "Input time6: " << time6 << " Expected Year: " << 2001 << "  Actual: " << y6.year_ << endl;
    cout << "Input time7: " << time7 << " Expected Year: " << 2000 << "  Actual: " << y7.year_ << endl;
    cout << "Input time8: " << time8 << " Expected Year: " << 2022 << "  Actual: " << y8.year_ << endl;
    cout << "Input time9: " << time9 << " Expected Year: " << 2000 << "  Actual: " << y9.year_ << endl;

    cout << "\n********* Month **************" << endl;
    cout << "Input time1: " << time1 << " Expected Month: " << 12 << "  Actual: " << y1.month_ << endl;
    cout << "Input time2: " << time2 << " Expected Month: " << 1 << "  Actual: " << y2.month_ << endl;
    cout << "Input time3: " << time3 << " Expected Month: " << 12 << "  Actual: " << y3.month_ << endl;
    cout << "Input time4: " << time4 << " Expected Month: " << 1 << "  Actual: " << y4.month_ << endl;
    cout << "Input time5: " << time5 << " Expected Month: " << 12 << "  Actual: " << y5.month_ << endl;
    cout << "Input time6: " << time6 << " Expected Month: " << 1 << "  Actual: " << y6.month_ << endl;
    cout << "Input time7: " << time7 << " Expected Month: " << 2 << "  Actual: " << y7.month_ << endl;
    cout << "Input time8: " << time8 << " Expected Month: " << 2 << "  Actual: " << y8.month_ << endl;
    cout << "Input time9: " << time9 << " Expected Month: " << 3 << "  Actual: " << y9.month_ << endl;

    cout << "\n********* Day **************" << endl;
    cout << "Input time1: " << time1 << " Expected day: " << 31 << "  Actual: " << y1.day_ << endl;
    cout << "Input time2: " << time2 << " Expected day: " << 1 << "  Actual: " << y2.day_ << endl;
    cout << "Input time3: " << time3 << " Expected day: " << 31 << "  Actual: " << y3.day_ << endl;
    cout << "Input time4: " << time4 << " Expected day: " << 1 << "  Actual: " << y4.day_ << endl;
    cout << "Input time5: " << time5 << " Expected day: " << 31 << "  Actual: " << y5.day_ << endl;
    cout << "Input time6: " << time6 << " Expected day: " << 1 << "  Actual: " << y6.day_ << endl;
    cout << "Input time7: " << time7 << " Expected day: " << 29 << "  Actual: " << y7.day_ << endl;
    cout << "Input time8: " << time8 << " Expected day: " << 28 << "  Actual: " << y8.day_ << endl;
    cout << "Input time9: " << time9 << " Expected day: " << 1 << "  Actual: " << y9.day_ << endl;
}

void test_time()
{
    cout << "\n************** Testing Correct time **********************" << endl;
    // Test year bounds:
    // testing lower bound of leap year
    unsigned long int time1 = 63071999; // Friday, December 31, 1971 23:59:59
    unsigned long int time2 = 63072000; // Saturday, January 1, 1972 0:00:00
    // testing upper bound of leap year
    unsigned long int time3 = 94694399; // Sunday, December 31, 1972 23:59:59
    unsigned long int time4 = 94694400; // Monday, January 1, 1973 0:00:00
    // testing reandom year
    unsigned long int time5 = 978307199; // Sunday, December 31, 2000 23:59:59
    unsigned long int time6 = 978307200; // Monday, January 1, 2001 0:00:00
    // testing leap month year
    unsigned long int time7 = 951868799;  // Tuesday, February 29, 2000 23:59:59
    unsigned long int time8 = 1646011101; // Monday, February 28, 2022 1:18:21
    // unsigned long int time9 = 951868899; // Wednesday, March 1, 2000 0:01:39
    unsigned long int time9 = 1651113732762999086; // 1643678301; // Tuesday, February 1, 2022 1:18:21

    date_to_str y1(time1, "sec");
    date_to_str y2(time2, "sec");
    date_to_str y3(time3, "sec");
    date_to_str y4(time4, "sec");
    date_to_str y5(time5, "sec");
    date_to_str y6(time6, "sec");
    date_to_str y7(time7, "sec");
    date_to_str y8(time8, "sec");
    date_to_str y9(time9, "nano");

    cout << "\n********* Hour **************" << endl;
    cout << "Input time1: " << time1 << " Expected Hour: " << 23 << "  Actual: " << y1.hour_ << endl;
    cout << "Input time2: " << time2 << " Expected Hour: " << 23 << "  Actual: " << y2.hour_ << endl;
    cout << "Input time3: " << time3 << " Expected Hour: " << 0 << "  Actual: " << y3.hour_ << endl;
    cout << "Input time4: " << time4 << " Expected Hour: " << 0 << "  Actual: " << y4.hour_ << endl;
    cout << "Input time5: " << time5 << " Expected Hour: " << 1 << "  Actual: " << y5.hour_ << endl;
    cout << "Input time6: " << time6 << " Expected Hour: " << 1 << "  Actual: " << y6.hour_ << endl;
    cout << "Input time9: " << time9 << " Expected Hour: " << 1 << "  Actual: " << y9.hour_ << endl;

    cout << "\n********* Min **************" << endl;
    cout << "Input time1: " << time1 << " Expected Min: " << 0 << "  Actual: " << y1.min_ << endl;
    cout << "Input time2: " << time2 << " Expected Min: " << 59 << "  Actual: " << y2.min_ << endl;
    cout << "Input time3: " << time3 << " Expected Min: " << 0 << "  Actual: " << y3.min_ << endl;
    cout << "Input time4: " << time4 << " Expected Min: " << 59 << "  Actual: " << y4.min_ << endl;
    cout << "Input time5: " << time5 << " Expected Min: " << 0 << "  Actual: " << y5.min_ << endl;
    cout << "Input time6: " << time6 << " Expected Min: " << 59 << "  Actual: " << y6.min_ << endl;
    cout << "Input time9: " << time9 << " Expected Min: " << 18 << "  Actual: " << y9.min_ << endl;

    cout << "\n********* Sec **************" << endl;
    cout << "Input time1: " << time1 << " Expected Sec: " << 0 << "  Actual: " << y1.sec_ << endl;
    cout << "Input time2: " << time2 << " Expected Sec: " << 59 << "  Actual: " << y2.sec_ << endl;
    cout << "Input time3: " << time3 << " Expected Sec: " << 0 << "  Actual: " << y3.sec_ << endl;
    cout << "Input time4: " << time4 << " Expected Sec: " << 59 << "  Actual: " << y4.sec_ << endl;
    cout << "Input time5: " << time5 << " Expected Sec: " << 0 << "  Actual: " << y5.sec_ << endl;
    cout << "Input time6: " << time6 << " Expected Sec: " << 59 << "  Actual: " << y6.sec_ << endl;
    cout << "Input time9: " << time9 << " Expected Sec: " << 21 << "  Actual: " << y9.sec_ << endl;

    cout << "\n********* nano **************" << endl;
    cout << "Input time1: " << time1 << " Expected nano: " << 0 << "  Actual: " << y1.nano_sec_ << endl;
    cout << "Input time2: " << time2 << " Expected nano: " << 59 << "  Actual: " << y2.nano_sec_ << endl;
    cout << "Input time3: " << time3 << " Expected nano: " << 0 << "  Actual: " << y3.nano_sec_ << endl;
    cout << "Input time4: " << time4 << " Expected nano: " << 59 << "  Actual: " << y4.nano_sec_ << endl;
    cout << "Input time5: " << time5 << " Expected nano: " << 0 << "  Actual: " << y5.nano_sec_ << endl;
    cout << "Input time6: " << time6 << " Expected nano: " << 59 << "  Actual: " << y6.nano_sec_ << endl;
    cout << "Input time9: " << time9 << " Expected nano: " << 21 << "  Actual: " << y9.nano_sec_ << endl;
}

void test_full_date()
{
    date_to_str test1(1651113734263089814, "nano");

    cout << "*********** Testing time to string **************" << endl;
    cout << "Date:  " << test1.str_date() << endl;
}
