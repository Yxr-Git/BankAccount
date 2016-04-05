#ifndef _DATE_H_
#define _DATE_H_

class Date{
	private:
		int year;
		int month;
		int day;
		int totalDays;
	public:
		Date();
		Date(int year, int month, int day);
		int getYear() const{
			return year;
		}
		int getMonth() const{
			return month;
		}
		int getDay() const{
			return day;
		}
		int getMaxDay() const;

		//whether the year is leap year.
		bool isLeapYear() const{
			return year%4==0 && year%100!=0 || year%400!=0;
		};
		void show() const;

		int distance (const Date &date) const{
			return totalDays-date.totalDays;
		}
};
#endif