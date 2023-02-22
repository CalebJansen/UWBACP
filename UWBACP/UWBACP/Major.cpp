#include "Major.h"
using namespace std;

Major::Major()
{
    this->name = "";
    vector<Course> emptyCourseList(0);
    this->reqs = emptyCourseList;
}

Major::Major(string inputName)
{
    this->name = inputName;
    vector<Course> emptyCourseList(0);
    this->reqs = emptyCourseList;
}

Major::Major(string inputName, vector<Course> reqs)
{
    this->name = inputName;
    this->reqs = reqs;
}

vector<Course> Major::getReqs()
{
    return this->reqs;
}

void Major::setReqs(vector<Course> courseList)
{
    this->reqs = courseList;
}

void Major::addReq(Course newCourse)
{
    this->reqs.push_back(newCourse);
}

string Major::getName()
{
    return this->name;
}

void Major::setName(string inputName)
{
    this->name = inputName;
}

bool Major::operator==(Major rhs)
{
    return this->name == rhs.getName();
}
