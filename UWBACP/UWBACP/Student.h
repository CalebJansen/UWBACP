#pragma once
#include "Major.h"
using namespace std;
class Student
{
public:
	//constructors
	Student();
	Student(int startYear, int startQuarter, Major major);
	Student(int startYear, int startQuarter, Major major, vector<Course> takenCourses);

	//setters
	void setStartYear(int year);
	void setStartQuarter(int quarter);
	void setEndYear(int year);
	void setEndQuarter(int quarter);
	void setMajor(Major major);
	void setSchedule(vector<vector<vector<Course>>> schedule);
	void setTakenCourses(vector<Course> takenCourses);
	void addTakenCourse(Course takenCourse);

	//getters
	int getStartYear();
	int getStartQuarter();
	int getEndYear();
	int getEndQuarter();
	Major getMajor();
	vector<vector<vector<Course>>> getSchedule();
	vector<Course> getTakenCourses();

	//get specified schedule
	vector<vector<Course>> getSchedule(int year);
	vector<Course> getSchedule(int year, int quarter);

	//the magic function 0-0
	bool generateSchedule();


	//print functions
	void printSchedule();
	void printSchedule(int year);
	void printSchedule(int year, int quarter);

private:
	int startYear;
	int startQuarter;
	int endYear;
	int endQuarter;
	Major major;
	vector<vector<vector<Course>>> schedule;
	vector<Course> takenCourses;

};

