#include "Cell.hpp"
    Cell::Cell(double l,int* c)
    {
        live=l;
        int* C=c;
        if (C!=nullptr)
        {
            coord[0]=C[0];
            coord[1]=C[1];
        }else
        {
            coord[0]=0;
            coord[1]=0;
        }
        
    };
    void Cell::liveSet(double l)
    {
        live=l;
    };
    double Cell::getLive()
    {
        return live;
    }
    void  Cell::cordSet(int *C)
    {
        if (C!=nullptr)
        {
            coord[0]=C[0];
            coord[1]=C[1];
        }
    }
    const int* Cell::getCoord() const {
        return coord;
    }
