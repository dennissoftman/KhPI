#include "staff.hpp"

#include <iostream>

#define NAMES_ONLY  (0b10)
#define AGES_ONLY   (0b01)
#define NAMES_COUNT (10)

enum EXEC_CODE
{
    NO_CODE=-1,
    FILL_CODE=1,
    ADD_CODE,
    DEL_CODE,
    FBN_CODE,
    FBA_CODE,
    LS_CODE,
    LSN_CODE,
    LSA_CODE,
    HELP_CODE,
    QUIT_CODE=0xFF,
};

static const std::string name_array[NAMES_COUNT] =
{
    "Denys",
    "Alex",
    "Peter",
    "Ivan",
    "Oleg",
    "Max",
    "Greg",
    "Bob",
    "Mark",
    "Artem"
};

void usage()
{
    std::cout << "Help:\n"
                 "  fill - fill randomly (5 records)\n"
                 "  add  - add new record\n"
                 "  del  - remove record by name\n"
                 "  fbn  - find record by name\n"
                 "  fba  - find record by age\n"
                 "  ls   - list all records\n"
                 "  lsn  - list all names\n"
                 "  lsa  - list all ages\n"
                 "  ?    - print this message\n"
                 "  quit - quit program\n";
}

EXEC_CODE parseCmd(const std::string &uinput)
{
    if(uinput.substr(0, 4) == "fill")
        return FILL_CODE;
    if(uinput.substr(0, 3) == "add")
        return ADD_CODE;
    if(uinput.substr(0, 3) == "del")
        return DEL_CODE;
    if(uinput.substr(0, 3) == "fbn")
        return FBN_CODE;
    if(uinput.substr(0, 3) == "fba")
        return FBA_CODE;
    if(uinput.substr(0, 3) == "lsn")
        return LSN_CODE;
    if(uinput.substr(0, 3) == "lsa")
        return LSA_CODE;
    if(uinput.substr(0, 2) == "ls")
        return LS_CODE;
    if(uinput.substr(0, 1) == "?")
        return HELP_CODE;
    if(uinput.substr(0, 4) == "quit")
        return QUIT_CODE;
    return NO_CODE;
}

std::string randName()
{
    return name_array[rand() % NAMES_COUNT];
}

int randAge()
{
    return rand() % 100 + 1;
}

int main()
{
    Staff people;

    usage();
    std::string userInput;
    do
    {
        std::cout << "> ";
        std::getline(std::cin, userInput);
        if(userInput.empty())
            continue;

        EXEC_CODE action = parseCmd(userInput);
        if(action == QUIT_CODE)
            break;

        if(action == LS_CODE)
            std::cout << people.getView() << std::endl;
        else if(action == LSN_CODE)
            std::cout << people.getView(NAMES_ONLY) << std::endl;
        else if(action == LSA_CODE)
            std::cout << people.getView(AGES_ONLY) << std::endl;
        else if(action == ADD_CODE)
        {
            do
            {
                try
                {
                    std::cout << "Enter 'name age': ";
                    std::string name;
                    int age;
                    std::getline(std::cin, userInput);
                    ssize_t pos = userInput.find_first_of(' ');
                    name = userInput.substr(0, pos);
                    age  = std::stoi(userInput.substr(pos+1));
                    if(age <= 0)
                        throw std::invalid_argument(userInput.substr(pos+1));
                    people.insert(name, age);
                    break;
                } catch(std::invalid_argument &e)
                {
                    std::cerr << "Invalid age entered!" << std::endl;
                }
            } while(1);
            std::cout << "Record added" << std::endl;
        }
        else if(action == FILL_CODE)
        {
            for(int i=0; i < 5; i++)
                people.insert(randName(), randAge());
            std::cout << "Inserted 5 random records" << std::endl;
        }
        else if(action == FBN_CODE)
        {
            std::cout << "Enter name: ";
            std::string name;
            std::getline(std::cin, name);
            const Person &p = people.byName(name);
            if(p.getAge() == -1)
                std::cout << "Record not found" << std::endl;
            else
                std::cout << "Record: " << std::string(p) << std::endl;
        }
        else if(action == FBA_CODE)
        {
            int age;
            do
            {
                try
                {
                    std::cout << "Enter age: ";
                    std::getline(std::cin, userInput);
                    age  = std::stoi(userInput);
                    if(age <= 0)
                        throw std::invalid_argument(userInput);
                    break;
                } catch(std::invalid_argument &e)
                {
                    std::cerr << "Invalid age entered!" << std::endl;
                }
            } while(1);
            const Person &p = people.byAge(age);
            if(p.getAge() == -1)
                std::cout << "Record not found" << std::endl;
            else
                std::cout << "Record: " << std::string(p) << std::endl;
        }
        else if(action == DEL_CODE)
        {
            std::cout << "Enter name to delete: ";
            std::getline(std::cin, userInput);
            people.deleteByName(userInput);
        }
        else if(action == HELP_CODE)
            usage();
    } while(1);

    return 0;
}
