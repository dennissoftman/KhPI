#include <iostream>
#include <fstream>

#define LOG_LEVEL

class cantopen : public std::exception
{
public:
    cantopen()
    {
    }

    const char *what() const noexcept override
    {
        return "Failed to open file";
    }
};

class cantparse : public std::exception
{
public:
    cantparse()
    {
    }

    const char *what() const noexcept override
    {
        return "Failed to parse file";
    }
};

int main()
{
    std::ifstream fin;
    try
    {
        fin.open("test.bin", std::ios::in | std::ios::binary);
        if(!fin.is_open())
            throw cantopen();
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try
    {
        // Check file size
        long fs = fin.tellg();
        fin.seekg(0, std::ios::end); // go to file end
        if((fin.tellg() - fs) != 40) // 40 bytes
            throw cantparse();
        fin.seekg(0, std::ios::beg); // return to file start
        //
        int trigger = 0;

        int numbers[10];
        for(int i=0; i < 10; i++)
        {
            fin.read((char*)&numbers[i], 4);
#ifdef LOG_LEVEL
            std::cout << numbers[i] << std::endl;
#endif
        }
        fin.close();

        if((numbers[4] & 1) == 0) // even
            trigger = 1;
        else
            trigger = -1;

        std::ofstream fout;
        fout.open("test.bin", std::ios::out | std::ios::binary);
        fout.seekp(0, std::ios::beg);
        int num;
        if(trigger == 1)
        {
            num = 77;
            for(int i=0; i < 4; i++)
                fout.write((char*)&num, 4);
            for(int i=4; i < 10; i++)
                fout.write((char*)&numbers[i], 4);
        }
        else if(trigger == -1)
        {
            num = 88;
            for(int i=0; i < 5; i++)
                fout.write((char*)&numbers[i], 4);
            for(int i = 5; i < 10; i++)
                fout.write((char*)&num, 4);
        }
        fout.close();
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return 0;
}
