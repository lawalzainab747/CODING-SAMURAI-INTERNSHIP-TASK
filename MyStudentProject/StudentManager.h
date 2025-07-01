#pragma once

#include <string>
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Student.h"

class StudentManager
{
private:
	std::vector<Student*> students;
	std::string StudentFile;

public:
	StudentManager(const std::string& Student_File);

	void LoadStudentDatabase();

	//Destructor
	~StudentManager();

	//Add a new student record to database
	void AddRecord();

	//Member function to display student record
	void DisplayAllStudentRecord() const;

	//Member function to Update student record
	void UpdateStudentRecord();

	//Member function to delete student record
	void DeleteStudentRecord();

	//Member function to search student record
	void SearchStudentRecord();

};