// UWBACP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Course.h"
#include <fstream>
#include <sstream>
#include <map>
#include <filesystem>

using namespace std;

//GLOBAL VARIABLES
//string COURSE_FILE = "TestClasses.txt";
const std::filesystem::path COURSE_FOLDER = "COURSE_LIST/";

int main()
{
    cout << "Welcome to the UWB Automatic Course Planner!\n\n" <<
        "Please input all courses you have already taken.\n" <<
        "When finished, please input \"n\" instead of a course prefix.\n";
    string prefixInput;
    int numberInput;
    bool finished = false;
    vector<Course> takenCourses(0);


    //populating course list
    vector<Course> courseList(0);

    //making map for easy course searching (cant use switch on strings)
    map<string, int> m;
    m.insert(pair<string, int>("Fall", 0));
    m.insert(pair<string, int>("Spring", 1));
    m.insert(pair<string, int>("Summer", 2));
    m.insert(pair<string, int>("Winter", 3));


    //iterate through folder of course files
    string dataFile = "";
    for (auto& entry : std::filesystem::directory_iterator(COURSE_FOLDER))
    {
        dataFile = entry.path().string();
        ifstream courseFile;
        courseFile.open(dataFile);
        string fileInput = "";
        Course newCourse;

        //iterate through file
        if (courseFile.is_open())
        {
            int lineNumber = 0;
            bool duplicateFlag = false;
            while (getline(courseFile, fileInput) && !duplicateFlag)
            {
                lineNumber++;
                //parse input and create course using parsed data
                vector<string> delimitedLine;
                //vector<string>* delimitedLine = new vector<string>;
                stringstream str(fileInput);

                //accept strings comma delimited, filling delimited line vector
                while (str.good()) {
                    string substring;
                    getline(str, substring, ',');
                    delimitedLine.push_back(substring);
                }

                if (lineNumber == 1)
                {
                    Course compareCourse(delimitedLine.at(0), stoi(delimitedLine.at(1)));
                    for (int i = 0; i < courseList.size(); i++)
                    {
                        if (courseList.at(i) == compareCourse)
                        {
                            duplicateFlag = true;
                        }
                    }

                    if (duplicateFlag)
                    {
                        cout << "WARNING: DUPLICATE COURSE " << delimitedLine.at(0) <<
                            delimitedLine.at(1) <<
                            " DETECTED. SECOND ENTRY WILL NOT BE INCLUDED IN THE DATABASE.\n";
                    }
                    else //add course to courseList
                    {
                        newCourse.setPrefix(delimitedLine.at(0));
                        newCourse.setCourseNumber(stoi(delimitedLine.at(1)));
                    }
                }
                else if (lineNumber == 2) //contains quarters offered data
                {
                    for (int i = 0; i < delimitedLine.size(); i++)
                    {
                        int quarter = m[delimitedLine[i]];
                        newCourse.addQuarterOffered(quarter);
                    }
                }
                else //lineNumber > 2
                {
                    //build and add prerequisites list
                }
            }
            courseList.push_back(newCourse);
            courseFile.close();
        }
        else
        {
            cout << "\n\nERROR: COULD NOT OPEN COURSE DATA FILE."; //TODO add file name in error message
        }
        
    }

    //test code
    for (int i = 0; i < courseList.size(); i++)
    {
        string q0 = "", q1 = "", q2 = "", q3 = "";
        if (courseList.at(i).getQuartersOffered()[0])
            q0 = "Winter";
        if (courseList.at(i).getQuartersOffered()[1])
            q1 = "Spring";
        if (courseList.at(i).getQuartersOffered()[2])
            q2 = "Summer";
        if (courseList.at(i).getQuartersOffered()[3])
            q3 = "Fall";
        cout << courseList.at(i).getPrefix() << courseList.at(i).getCourseNumber() <<
            " is offered in " << q0 << q1 << q2 << q3;
    }
 
    while (!finished)
    {
        cout << "\nInput Course Prefix: ";
        cin >> prefixInput;
        
        if (prefixInput == "n") //if finished inputting courses
            finished = true;
        else
        {
            cout << "\nInput Course Number: ";
            cin >> numberInput;
            takenCourses.push_back(Course(prefixInput, numberInput));

            //no duplicate courses in takenCourses
        }
    }
    cout << "\n";

    //debug code
    for (int i = 0; i < takenCourses.size(); i++)
    {
        cout << takenCourses.at(i).getPrefix() << " " << 
            takenCourses.at(i).getCourseNumber() << "\n";
    }
}







//SINGLE FILE COURSE LIST VERSION
            //while (getline(availableCourses, fileInput))
            //{
            //    //parse input and create course using parsed data
            //    vector<string> delimitedInput;
            //    vector<string>* delimitedInput = new vector<string>;
            //    Course newCourse();
            //    stringstream str(fileInput);

            //    //accept strings comma delimited
            //    while (str.good()) {
            //        string substring;
            //        getline(str, substring, ',');
            //        delimitedInput.push_back(substring);
            //    }
            //    
            //    //assign data to a new course
            //    if (delimitedInput.size() > 0)
            //    {
            //        //if course prefix and number already exist, skip it
            //        
            //        //Courses saved in courseList vector
            //        //might want to make overloaded operator to compare courses with (prefix, num)
            //        Course compareCourse(delimitedInput.at(0), stoi(delimitedInput.at(1)));
            //        bool duplicateFlag = false;
            //        for (int i = 0; i < courseList.size(); i++)
            //        {
            //            if (courseList.at(i) == compareCourse)
            //            {
            //                duplicateFlag = true;
            //            }
            //        }
            //        if (duplicateFlag)
            //        {
            //            cout << "WARNING: DUPLICATE COURSE " << delimitedInput.at(0) << 
            //                delimitedInput.at(1) <<
            //                " DETECTED. SECOND ENTRY WILL NOT BE INCLUDED IN THE DATABASE.\n";
            //        }
            //        else //add course to courseList
            //        {
            //            newCourse().setPrefix(delimitedInput.at(0));
            //            newCourse().setCourseNumber(stoi(delimitedInput.at(1)));

            //            for (int i = 2; i < delimitedInput.size(); i++)
            //            {
            //                //if the quarter name exists in the predefined map
            //                if (m.count(delimitedInput.at(i)) == 1)
            //                {
            //                    //then add it to the new course using the value associated 
            //                    //with that quarter's string key
            //                    newCourse().addQuarterOffered(m.at(delimitedInput.at(i)));
            //                }
            //            }
            //            courseList.push_back(newCourse());
            //        }
            //    }
            //    
            //}