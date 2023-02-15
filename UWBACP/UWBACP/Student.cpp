#include "Student.h"
#include <iostream>
using namespace std;

Student::Student()
{
	this->startYear = 0;
	this->startQuarter = 0;
	this->endYear = 0;
	this->endQuarter = 0;
}

Student::Student(int startYear, int startQuarter, Major major)
{
	this->startYear = startYear;
	this->startQuarter = startQuarter;
	this->major = major;

	this->endYear = 0;
	this->endQuarter = 0;
}

Student::Student(int startYear, int startQuarter, Major major, vector<Course> takenCourses)
{
	this->startYear = startYear;
	this->startQuarter = startQuarter;
	this->major = major;
	this->takenCourses = takenCourses;

	this->endYear = 0;
	this->endQuarter = 0;
}

void Student::setStartYear(int year)
{
	this->startYear = year;
}

void Student::setStartQuarter(int quarter)
{
	this->startQuarter = quarter;
}

void Student::setEndYear(int year)
{
	this->endYear = year;
}

void Student::setEndQuarter(int quarter)
{
	this->endQuarter = quarter;
}

void Student::setMajor(Major major)
{
	this->major = major;
}

void Student::setSchedule(vector<vector<vector<Course>>> schedule)
{
	this->schedule = schedule;
}

void Student::setTakenCourses(vector<Course> takenCourses)
{
	this->takenCourses = takenCourses;
}

void Student::addTakenCourse(Course takenCourse)
{
	this->takenCourses.push_back(takenCourse);
}

int Student::getStartYear()
{
	return this->startYear;
}

int Student::getStartQuarter()
{
	return this->startQuarter;
}

int Student::getEndYear()
{
	return this->endYear;
}

int Student::getEndQuarter()
{
	return this->endQuarter;
}

Major Student::getMajor()
{
	return this->major;
}

vector<vector<vector<Course>>> Student::getSchedule()
{
	return this->schedule;
}

vector<Course> Student::getTakenCourses()
{
	return this->takenCourses;
}

vector<vector<Course>> Student::getSchedule(int year)
{
	if (this->schedule.size() >= year)
		return this->schedule.at(year - 1);
	else
	{
		vector<vector<Course>> resultYear(0);
		return resultYear; //should return a year with no data
	}
}

vector<Course> Student::getSchedule(int year, int quarter)
{
	if (this->schedule.size() >= year)
		if (quarter <= 3)
			return this->schedule.at(year - 1).at(quarter);
		
	vector<Course> result(0);
	return result; //should return a vector with no data
}

bool Student::generateSchedule()
{
	return false;
}

void Student::printSchedule()
{
	int startYear = this->startYear;
	int startQuarter = this->startQuarter;
	int endYear = this->endYear;
	int endQuarter = this->endQuarter;
	//remaining quarters = number of schedule sections

	int yearCount = endYear - startYear;

	vector<Course> currentQuarter;
	Course currentClass;
	string QuarterName;

	for (int i = 0; i < yearCount; i++)
	{
		cout << "Schedule For Year " << i + 1 << ":\n";
		if (i == 0) //if printing the start year
		{
			//start printing from the first quarter to fall
			endQuarter = 4;
		}
		else if (i == yearCount - 1) //if printing the final year
		{
			//start printing from winter to the student's last quarter
			startQuarter = 0;
		}
		else //if printing an in-between year
		{
			startQuarter = 0;
			endQuarter = 4;
		}

		for (int j = startQuarter; j < endQuarter; j++)
		{
			switch (j)
			{
			case 0:
				QuarterName = "Winter";
				break;
			case 1:
				QuarterName = "Spring";
				break;
			case 2:
				QuarterName = "Summer";
				break;
			case 3:
				QuarterName = "Fall";
				break;
			default:
				QuarterName = "ERROR";
				break;
			}
			cout << QuarterName << " Quarter:\n";

			//print all classes taken that quarter (class count based on vector size)
			currentQuarter = schedule.at(i).at(j);
			for (int k = 0; k < currentQuarter.size(); k++)
			{
				currentClass = currentQuarter.at(k);
				cout << "Class " << k + 1 << ": " << currentClass.getPrefix() << " " <<
					currentClass.getCourseNumber() << "\n";
			}
		}
	
	}
}

void Student::printSchedule(int year)
{
	int startYear = this->startYear;
	int startQuarter = this->startQuarter;
	int endYear = this->endYear;
	int endQuarter = this->endQuarter;
	//remaining quarters = number of schedule sections

	int yearCount = endYear - startYear;

	vector<Course> currentQuarter;
	Course currentClass;
	string QuarterName;

	cout << "Schedule For Year " << year + 1 << ":\n";
	if (year == 0) //if printing the start year
	{
		//start printing from the first quarter to fall
		endQuarter = 4;
	}
	else if (year == yearCount - 1) //if printing the final year
	{
		//start printing from winter to the student's last quarter
		startQuarter = 0;
	}
	else //if printing an in-between year
	{
		startQuarter = 0;
		endQuarter = 4;
	}

	for (int j = startQuarter; j < endQuarter; j++)
	{
		switch (j)
		{
		case 0:
			QuarterName = "Winter";
			break;
		case 1:
			QuarterName = "Spring";
			break;
		case 2:
			QuarterName = "Summer";
			break;
		case 3:
			QuarterName = "Fall";
			break;
		default:
			QuarterName = "ERROR";
			break;
		}
		cout << QuarterName << " Quarter:\n";

		//print all classes taken that quarter (class count based on vector size)
		currentQuarter = schedule.at(year).at(j);
		for (int k = 0; k < currentQuarter.size(); k++)
		{
			currentClass = currentQuarter.at(k);
			cout << "Class " << k + 1 << ": " << currentClass.getPrefix() << " " <<
				currentClass.getCourseNumber() << "\n";
		}
	}
}

void Student::printSchedule(int year, int quarter)
{
	int startYear = this->startYear;
	int startQuarter = this->startQuarter;
	int endYear = this->endYear;
	int endQuarter = this->endQuarter;
	//remaining quarters = number of schedule sections

	int yearCount = endYear - startYear;

	vector<Course> currentQuarter;
	Course currentClass;
	string QuarterName;

	cout << "Schedule For Year " << year + 1 << ", " << QuarterName << " Quarter:\n";

	switch (quarter)
	{
	case 0:
		QuarterName = "Winter";
		break;
	case 1:
		QuarterName = "Spring";
		break;
	case 2:
		QuarterName = "Summer";
		break;
	case 3:
		QuarterName = "Fall";
		break;
	default:
		QuarterName = "ERROR";
		break;
	}

	//print all classes taken that quarter (class count based on vector size)
	currentQuarter = schedule.at(year).at(quarter);
	for (int k = 0; k < currentQuarter.size(); k++)
	{
		currentClass = currentQuarter.at(k);
		cout << "Class " << k + 1 << ": " << currentClass.getPrefix() << " " <<
			currentClass.getCourseNumber() << "\n";
	}
}
