class Cell
{
private:
    double live;
    int coord[2];
public:
    Cell(double l = 0, int *c = nullptr);
    void liveSet(double l);
    double getLive();
    void cordSet(int *C);
    const int *getCoord() const;
};