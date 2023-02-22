#pragma once

#include <string>
#include <vector>
#include "Course.h"
using namespace std;
class Major
{
public:
	Major();
	Major(string name);
	Major(string name, vector<Course> reqs);
	vector<Course> getReqs();
	void setReqs(vector<Course> courseList);
	void addReq(Course newCourse);
	string getName();
	void setName(string name);

	bool operator==(Major rhs);

private:
	string name;
	vector<Course> reqs;

};

