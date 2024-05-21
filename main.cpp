#include "Student.h"

using namespace std;

int main() 
{
	Person person1("Alex", 25, "male", 80);
	Student student1("Irina", 22, "female", 65, 3);

	person1.introduce();
	student1.introduce();

	Person* person2 = student1.getPerson(&person1);
	person2->introduce();

	student1.setYearOfStudy(2);
	student1.increaseYearOfStudy();

	person1.setName("Oleg");
	person1.introduce();
	student1.introduce();

	return 0;
}
