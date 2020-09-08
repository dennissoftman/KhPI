#include "matrix2d.hpp"

Matrix2D::Matrix2D(int r, int c)
    : rows(r), cols(c)
{
    data.resize(r*c);
}

void Matrix2D::Set(rc_t p, int a)
{
    if(p.r < rows and p.c < cols)
        data[p.c + p.r*cols] = a;
}

int Matrix2D::Get(rc_t p) const
{
    if(p.r < rows and p.c < cols)
        return data[p.c + p.r*cols];
    return 0;
}

int Matrix2D::GetRows() const
{
    return rows;
}

int Matrix2D::GetCols() const
{
    return cols;
}

rc_t Matrix2D::GetMinPos() const
{
    rc_t p;
    int _min = data[0];

    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            int a = Get({i, j});
            if(a < _min)
            {
                _min = a;
                p = {i, j};
            }
        }
    }
    return p;
}

bool Matrix2D::IsNull() const
{
    return (rows * cols) == 0;
}

Matrix2D Matrix2D::Submat(rc_t p, int sr, int sc) const
{
    if((p.r+sr) > rows or (p.c+sc) > cols)
        return Matrix2D(0, 0); // NULL matrix

    Matrix2D t(sr, sc);
    for(int i=0; i < sr; i++)
        for(int j=0; j < sc; j++)
            t.Set({i, j}, Get({i+p.r, j+p.c}));
    return t;
}
