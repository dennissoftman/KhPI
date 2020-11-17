#include "sports.hpp"
#include <limits>

void getValue(std::istream &in, std::string &s)
{
    in >> s;
}

void getValue(std::istream &in, int &d)
{
    std::string t;
    do
    {
        in >> t;
        try
        {
            d = std::stoi(t);
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "Please enter number!" << std::endl;
            continue;
        }
    } while(1);
}

void getValue(std::istream &in, float &f)
{
    std::string t;
    do
    {
        in >> t;
        try
        {
            f = std::stof(t);
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << "Please enter number!" << std::endl;
            continue;
        }
    } while(1);
}

int main()
{
    Team abc;

    std::string userInput;

    std::cout << "Commands:\n"
                 "  show   - show sportsman records\n"
                 "  add    - add new sportsman\n"
                 "  import - import from file\n"
                 "  export - export to file\n"
                 "  read   - read record from file\n"
                 "  write  - write record to file\n"
                 "  quit   - close app"
              << std::endl;
    do
    {
        std::cout << "cmd> ";
        std::getline(std::cin, userInput);
        if(userInput.empty())
            continue;
        if(userInput.substr(0, 4) == "quit")
            break;

        if(userInput.substr(0, 4) == "show")
        {
            std::cout << abc.GetView() << std::endl;
            continue;
        }
        else if(userInput.substr(0, 3) == "add")
        {
            Sportsman *a = new Sportsman;
            std::cout << "Fill new record:" << std::endl;
            std::string t0;
            float t1;
            int t2;

            std::cout << "Enter surname: ";
            getValue(std::cin, t0);
            a->setSurname(t0);

            std::cout << "Enter teamcode: ";
            getValue(std::cin, t0);
            a->setTeamcode(t0);

            std::cout << "Enter result: ";
            getValue(std::cin, t1);
            a->setResult(t1);

            std::cout << "Enter place: ";
            getValue(std::cin, t2);
            a->setPlace(t2);

            abc.Add(a);
            std::cout << "Record added" << std::endl;
        }
        else if(userInput.substr(0, 6) == "export")
        {
            std::cout << "Output file name: ";
            std::getline(std::cin, userInput);
            abc.Export(userInput);
        }
        else if(userInput.substr(0, 6) == "import")
        {
            do
            {
                std::cout << "Input file name (or 'n' to cancel): ";
                std::getline(std::cin, userInput);
                if(tolower(userInput[0]) == 'n')
                    break;
                try
                {
                    abc.Import(userInput);
                    break;
                } catch(std::invalid_argument &e)
                {
                    std::cerr << e.what() << std::endl;
                }
            } while(1);
        }
        else if(userInput.substr(0, 4) == "read")
        {
            std::cout << "Input file name: ";
            std::getline(std::cin, userInput);
            int id;
            std::cout << "Enter record id (from 1): ";
            getValue(std::cin, id);
            try
            {
                Sportsman tmp = abc.Read(userInput, id);
                std::cout << std::string(tmp) << std::endl;
            } catch(std::invalid_argument &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        else if(userInput.substr(0, 5) == "write")
        {
            std::cout << "Input file name: ";
            std::getline(std::cin, userInput);

            std::cout << "Fill record:" << std::endl;
            Sportsman a;
            std::string t0;
            float t1;
            int t2;

            std::cout << "Enter surname: ";
            getValue(std::cin, t0);
            a.setSurname(t0);

            std::cout << "Enter teamcode: ";
            getValue(std::cin, t0);
            a.setTeamcode(t0);

            std::cout << "Enter result: ";
            getValue(std::cin, t1);
            a.setResult(t1);

            std::cout << "Enter place: ";
            getValue(std::cin, t2);
            a.setPlace(t2);

            abc.Write(userInput, a);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(1);

    return 0;
}
