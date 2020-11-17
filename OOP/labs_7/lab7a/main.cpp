#define SRC_FILE "src.pairs"
#define DST_FILE "dst.complex"
#define COUNT (10)
#define OLD_STYLE

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

class Complex
{
public:
    Complex(float _a=0.f, float _b=0.f)
        : a(_a), b(_b)
    {

    }

    std::string asString() const
    {
#ifdef OLD_STYLE
        char *buff = (char*)malloc(64); // make buffer for numbers

        sprintf(buff, "%.02f", a);
        std::string a_s(buff);
        sprintf(buff, "%.02f", b);
        std::string b_s(buff);

        free(buff); // free buffer
#else
        std::string a_s = std::to_string(a), b_s = std::to_string(b);
#endif
        return std::string(a_s + " + " + b_s + "i");
    }
private:
    float a, b;
};

float randFloat(float a, float b)
{
    if(a == b)
        return 0.f;
    return ((b - a) * ((float)rand() / 2147483647.f)) + a; // RAND_MAX is 2147483647
}

int main()
{
    Complex nums[COUNT];
    char *buff = (char*)malloc(128);

    // source file generation
    std::ofstream fh_osrc;
    fh_osrc.open(SRC_FILE);
    for(int i=0; i < COUNT; i++)
    {
        sprintf(buff, "%.02f %.02f\n", randFloat(0, 100.f), randFloat(-10.f, 10.f));
        fh_osrc.write(buff, strlen(buff));
    }
    free(buff);
    fh_osrc.close();
    //

    // src file processing
    std::ifstream fh_isrc;
    fh_isrc.open(SRC_FILE);
    std::string line;
    for(int i=0; i < COUNT; i++)
    {
        float a, b;
        try
        {
            if(!std::getline(fh_isrc, line, '\n'))
                throw std::exception();
            if(sscanf(line.c_str(), "%f %f", &a, &b) != 2)
                throw std::exception();
        } catch(std::exception &e)
        {
            std::cerr << "Failed to process file";
        }
        nums[i] = Complex(a, b);
    }
    fh_isrc.close();

    // write to dest file
    std::ofstream fh_odst;
    fh_odst.open(DST_FILE);
    for(int i=0; i < COUNT; i++)
    {
        std::string dst = nums[i].asString() + '\n';
        fh_odst.write(dst.c_str(), dst.size());
    }
    fh_odst.close();
    //

    return 0;
}
