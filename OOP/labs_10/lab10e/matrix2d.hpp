#ifndef MATRIX2D_HPP
#define MATRIX2D_HPP

#include <vector>

struct rc_s
{
    int r, c;
} typedef rc_t;

class Matrix2D
{
public:
    // matrix 2x2 has rows 0 and 1, cols 0 and 1
    Matrix2D(int r=2, int c=2);

    void Set(rc_t p, int a);
    int Get(rc_t p) const;

    int GetRows() const;
    int GetCols() const;

    rc_t GetMinPos() const;

    bool IsNull() const;

    Matrix2D Submat(rc_t p, int sr, int sc) const;

private:
    std::vector<int> data;
    int rows, cols;
};

#endif // MATRIX2D_HPP
