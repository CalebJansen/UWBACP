#include "Course.h"

Course::Course()
{
	this->prefix = "";
	this->courseNumber = 0;
	this->credits = 0;
	vector<Course> emptyCourseList(0);
	this->preReqs = emptyCourseList;
	this->visible = true;
	*quartersOffered = new bool[4] {0, 0, 0, 0};

	this->englishComposition = 0;
	this->writingCurriculum = 0;
	this->reasoning = 0;
	this->diversity = 0;
	this->areasOfInquiry = 0;
	this->artsAndHumanities = 0;
	this->socialSciences = 0;
}

Course::Course(string prefix, int courseNumber)
{
	this->prefix = prefix;
	this->courseNumber = courseNumber;
	this->credits = 0;
	vector<Course> emptyCourseList(0);
	this->preReqs = emptyCourseList;
	this->visible = true;
	*quartersOffered = new bool[4] {0, 0, 0, 0};

	this->englishComposition = 0;
	this->writingCurriculum = 0;
	this->reasoning = 0;
	this->diversity = 0;
	this->areasOfInquiry = 0;
	this->artsAndHumanities = 0;
	this->socialSciences = 0;
}

Course::Course(string prefix, int courseNumber, int credits, vector<Course> preReqs, 
	bool* inQuartersOffered, bool englishComposition, bool writingCurriculum, 
	bool reasoning, bool diversity, bool areasOfInquiry, bool artsAndHumanities, 
	bool socialSciences)
{
	this->prefix = prefix;
	this->courseNumber = courseNumber;
	this->credits = credits;
	this->preReqs = preReqs;
	this->visible = true;
	*quartersOffered = inQuartersOffered;

	this->englishComposition = englishComposition;
	this->writingCurriculum = writingCurriculum;
	this->reasoning = reasoning;
	this->diversity = diversity;
	this->areasOfInquiry = areasOfInquiry;
	this->artsAndHumanities = artsAndHumanities;
	this->socialSciences = socialSciences;
}

string Course::getPrefix()
{
	return this->prefix;
}

int Course::getCourseNumber()
{
	return this->courseNumber;
}

int Course::getCredits()
{
	return this->credits;
}

vector<Course> Course::getPreReqs()
{
	return this->preReqs;
}

bool Course::isVisible()
{
	return this->visible;
}

bool* Course::getQuartersOffered()
{
	return this->quartersOffered;
}

void Course::setPrefix(string prefix)
{
	this->prefix = prefix;
}

void Course::setCourseNumber(int courseNumber)
{
	this->courseNumber = courseNumber;
}

void Course::setCredits(int credits)
{
	this->credits = credits;
}

void Course::setPreReqs(vector<Course> preReqs)
{
	this->preReqs = preReqs;
}

void Course::setVisible(bool visible)
{
	this->visible = visible;
}

//input quarter 0-3
void Course::addQuarterOffered(int quarter)
{
	quartersOffered[quarter] = true;
}

//checks if the course prefix and number are the same
bool Course::operator==(Course rhs)
{
	if (this->prefix == rhs.prefix && this->courseNumber == rhs.courseNumber)
		return true;
	return false;
}
