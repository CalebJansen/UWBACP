#pragma once
#include <string>
#include <vector>
using namespace std;
class Course
{
public:
	//constructors
	Course();
	Course(string prefix, int courseNumber);
	Course(string prefix, int courseNumber, int credits, vector<Course> preReqs,
		bool* quartersOffered, bool englishComposition, bool writingCurriculum,
		bool reasoning, bool diversity, bool areasOfInquiry, bool artsAndHumanities,
		bool socialSciences);

	//getters
	string getPrefix();
	int getCourseNumber();
	int getCredits();
	vector<Course> getPreReqs();
	bool isVisible();
	bool* getQuartersOffered();

	//setters
	void setPrefix(string prefix);
	void setCourseNumber(int courseNumber);
	void setCredits(int credits);
	void setPreReqs(vector<Course> preReqs);
	void setVisible(bool visible);
	void addQuarterOffered(int quarter);

	bool operator==(Course rhs);

private:
	string prefix;
	int courseNumber;
	int credits;
	vector<Course> preReqs;
	bool visible;
	bool quartersOffered[4];
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
	//Categories
	bool englishComposition;
	bool writingCurriculum;
	bool reasoning;
	bool diversity;
	bool areasOfInquiry;
	bool artsAndHumanities;
	bool socialSciences;

};

