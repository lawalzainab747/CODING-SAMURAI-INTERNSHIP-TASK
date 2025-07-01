#include <iostream>
#include <string>
#include "StudentManager.h"

int main()
{
	StudentManager studentmanager("StudentDatabase.txt");

	//studentmanager.LoadStudentDatabase();

	int choice;
	do {
		std::cout << "______________________________________________" << std::endl;
		std::cout << "Welcome to my Student Management System" << std::endl;
		std::cout << "1. Enter new student Records" << std::endl;
		std::cout << "2. Display student Records" << std::endl;
		std::cout << "3. Update student Records" << std::endl;
		std::cout << "4. Delete student Records" << std::endl;
		std::cout << "5. Search and view student Records" << std::endl;
		std::cout << "6. Exit" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1: {
			studentmanager.AddRecord();
			break;
		}

		case 2: {
			studentmanager.DisplayAllStudentRecord();
			break;
		}

		case 3: {
			studentmanager.UpdateStudentRecord();
			break;
		}

		case 4: {
			studentmanager.DeleteStudentRecord();
			break;
		}

		case 5: {
			studentmanager.SearchStudentRecord();
			break;
		}

		case 6: {
			std::cout << "Exiting..." << std::endl;
			break;
		}

		default:
			std::cout << "Invalid choice! Please enter a number between 1 and 6." << std::endl;
		}

	} while (choice != 6);
	return 0;
}