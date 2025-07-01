#include "Student.h"

//Constructor
Student::Student(int studentid, const std::string& Student_Name, const std::string& department, int age, double gpa) :
	Student_id(studentid), StudentName(Student_Name), Department(department), Age(age), Gpa(gpa) {
}

//Member function to get the student ID
int Student::getStudentId() const
{
	return Student_id;
}

//Member function to get the student Name
std::string Student::getName() const
{
	return StudentName;
}

//Member function to get the student Department
std::string Student::getDepartment() const
{
	return Department;
}

//Member function to get the student Age
int Student::getAge() const
{
	return Age;
}

//Member function to get the student GPA
double Student::getGpa() const
{
	return Gpa;
}

//Member function to update the student name.
void Student::SetNewName(const std::string& newName)
{
	StudentName = newName;
}


//Member function to update the student department.
void Student::SetNewDept(const std::string& newDept)
{
	Department = newDept;
}

//Member function to update the student Age.
void Student::SetNewAge(int newAge)
{
	Age = newAge;
}


//Member function to update the student GPA.
void Student::SetNewGpa(double newGpa)
{
	Gpa = newGpa;
}

