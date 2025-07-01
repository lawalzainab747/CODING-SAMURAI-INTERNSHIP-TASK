#pragma once

#include <string>
#include <istream>
#include <ostream>
#include <fstream>
#include <iostream>

class Student
{
private:
	int Student_id;
	std::string StudentName;
	std::string Department;
	int Age;
	double Gpa;

public:

	Student(int studentid, const std::string& Student_Name, const std::string& department, int age, double gpa);

	int getStudentId() const;

	std::string getName() const;

	std::string getDepartment() const;

	int getAge() const;

	double getGpa() const;

	void SetNewName(const std::string& newName);

	void SetNewDept(const std::string& newDept);

	void SetNewAge(int newAge);

	void SetNewGpa(double newGpa);
};