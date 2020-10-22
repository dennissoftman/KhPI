#include "univer.hpp"

int main()
{
    Univer khpi;

    int grades[5] = {5,5,5,5,5};

    // lecturers
    khpi.AddPerson(new Lecturer("Галкин Сергей Александрович", 1967, "ОБД", GRADE_NO));
    khpi.AddPerson(new Lecturer("Александр Борисович Пушной", 1975, "Радиофизика", GRADE_DTN));
    // students
    khpi.AddPerson(new Student("Митин Денис Олегович", 2002, grades));
    grades[2] = 3;
    grades[4] = 2;
    khpi.AddPerson(new Student("Давиденко Даниил Владиславович", 2002, grades));
    grades[1] = 2;
    grades[2] = 2;
    grades[4] = 3;
    khpi.AddPerson(new Student("Скитер Виктория Ивановна", 2001, grades));
    // zavkaf
    khpi.AddPerson(new HoD("Солощук Михаил Николаевич", 1953, "ЦСАК", GRADE_KTN, "профессор"));

    khpi.ShowInfo();
    khpi.Filter();

    return 0;
}
