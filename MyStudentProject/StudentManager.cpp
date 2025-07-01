#include "StudentManager.h"

StudentManager::StudentManager(const std::string& Student_File) : StudentFile(Student_File) {}


void StudentManager::LoadStudentDatabase()
{
	std::ifstream StudentFilename(StudentFile);
	if (!StudentFilename.is_open()) {
		throw std::runtime_error("Failed to open the Student database file.");
	}

	std::string input;
	while (getline(StudentFilename, input)) {
		std::stringstream ss(input);
		std::string str_name, str_department;
		int ID, student_age;
		double student_gpa;
		ss >> ID >> str_name >> str_department >> student_age >> student_gpa;
		students.push_back(new Student(ID, str_name, str_department, student_age, student_gpa));
	}

	StudentFilename.close();
	std::cout << "Database successfully loaded" << std::endl;
}

//Destructor
StudentManager::~StudentManager()
{
	for (Student* student : students) {
		delete student;
	}
}

//Add a new student record to the manager's system
void StudentManager::AddRecord()
{
	int ID, student_age;
	double student_gpa;
	std::string str_name, str_department;
	std::cout << "Enter the student ID: ";
	std::cin >> ID;
	std::cout << "Enter the new student name: ";
	std::cin >> str_name;
	std::cout << "Enter the new student department: ";
	std::cin >> str_department;
	std::cout << "Enter the new student age: ";
	std::cin >> student_age;
	std::cout << "Enter the new student gpa: ";
	std::cin >> student_gpa;
	Student* newstudent = new Student(ID, str_name, str_department, student_age, student_gpa);
	students.push_back(newstudent);

	std::cout << "Student data successfully added." << std::endl;
	std::cout << "Student ID : " << newstudent->getStudentId() << std::endl
		<< "Student name: " << newstudent->getName() << std::endl
		<< "Student Department: " << newstudent->getDepartment() << std::endl
		<< "Student Age : " << newstudent->getAge() << std::endl
		<< "Student GPA : " << newstudent->getGpa() << std::endl;

	std::ofstream file(StudentFile, std::ios::app);
	if (file.is_open()) {
		file << '\n' << ID << " " << str_name << " " << str_department << " " << student_age << " " << student_gpa;
		file.close();
	}

	else {
		std::cerr << "Error: Failed to open file " << StudentFile << std::endl;

	}
}


//Display all student record in the manager's system
void StudentManager::DisplayAllStudentRecord() const {

	std::ifstream StudentFilename(StudentFile);
	if (!StudentFilename.is_open()) {
		std::cerr << "Error opening file: " << StudentFile << std::endl;
		return;
	}

	std::cout << '\n' << "The list of al students are displayed below" << std::endl;
	std::string input;

	while (getline(StudentFilename, input)) {

		if (input.empty()) continue;

		std::stringstream ss(input);
		int ID, student_age;
		double student_gpa;
		std::string str_name, str_department;

		if (ss >> ID >> str_name >> str_department >> student_age >> student_gpa) {
			std::cout << "Student ID: " << ID
				<< " Name: " << str_name
				<< " Department: " << str_department
				<< " Age: " << student_age
				<< " Gpa : " << student_gpa
				<< std::endl;
		}
		else {
			std::cerr << "Warning: Malformed line skipped -> " << input << std::endl;
		}

		//std::cout << "Student ID: " << ID << " Name: " << str_name << " Department: " << str_department << " Age: " << student_age << " Gpa : " << student_gpa << std::endl;
	}

	StudentFilename.clear();
	StudentFilename.seekg(0, std::ios::beg);

}

//Update student record in the manager's system
void StudentManager::UpdateStudentRecord()
{
	int ID;
	std::cout << "Enter student ID in order to update their record: ";
	std::cin >> ID;

	bool search = false;
	for (Student* student : students) {
		if (student->getStudentId() == ID) {
			search = true;

			int newAge;
			std::string newName, newDept;
			double newGpa;
			std::cout << "Enter the student new name: ";
			std::cin >> newName;
			std::cout << "Enter the student new department: ";
			std::cin >> newDept;
			std::cout << "Enter the student new age: ";
			std::cin >> newAge;
			std::cout << "Enter the student new gpa: ";
			std::cin >> newGpa;

			student->SetNewName(newName);
			student->SetNewDept(newDept);
			student->SetNewAge(newAge);
			student->SetNewGpa(newGpa);

			std::cout << "Student record successfully updated. " << std::endl;
		}
	}

	if (!search) {
		std::cout << "Student ID not found. " << std::endl;
		return;
	}

	// Rewrite file with updated student records
	std::ofstream outFile(StudentFile, std::ios::trunc); // overwrite
	for (Student* s : students) {
		outFile << s->getStudentId() << " "
			<< s->getName() << " "
			<< s->getDepartment() << " "
			<< s->getAge() << " "
			<< s->getGpa() << "\n";
	}
	outFile.close();

}

//Delete student record in the manager's system
void StudentManager::DeleteStudentRecord()
{
	int ID;
	std::cout << "Enter student ID in order to update their record: ";
	std::cin >> ID;

	bool search = false;
	for (auto it = students.begin(); it != students.end(); ++it) {
		if ((*it)->getStudentId() == ID) {
			delete* it;               // free memory
			students.erase(it);       // remove from vector
			search = true;
			std::cout << "Student with ID " << ID << " has been deleted." << std::endl;
			break;
		}
	}

	if (!search) {
		std::cout << "No student found with ID " << ID << "." << std::endl;
		return;
	}

	// Rewrite the database file to reflect deletion
	std::ofstream file(StudentFile);
	if (file.is_open()) {
		for (const Student* student : students) {
			file << student->getStudentId() << " "
				<< student->getName() << " "
				<< student->getDepartment() << " "
				<< student->getAge() << " "
				<< student->getGpa() << "\n";
		}
		file.close();
	}
	else {
		std::cerr << "Error: Could not open file to update after deletion." << std::endl;
	}
}


//Search student record in the manager's system
void StudentManager::SearchStudentRecord()
{
	int ID;
	std::cout << "Enter student ID in order to update their record" << std::endl;
	std::cin >> ID;

	bool search = false;
	for (Student* student : students) {
		if (student->getStudentId() == ID) {
			search = true;

			std::cout << "The student details is provided below." << std::endl;

			std::cout << "The student  name is: " << student->getName() << std::endl;

			std::cout << "The student department is: " << student->getDepartment() << std::endl;

			std::cout << "The student age is: " << student->getAge() << std::endl;

			std::cout << "The student  gpa is: " << student->getGpa() << std::endl;
		}
	}

	if (!search) {
		std::cout << "Student ID not found. " << std::endl;
		return;
	}
}



