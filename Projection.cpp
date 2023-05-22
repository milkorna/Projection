#include "VectorPoint.h"
#include "Utilites.h"

//Целевая точка
Vector target;

int main(int argc, char* argv[])
{
    string fileName = argv[1];
    ifstream input(fileName);

    target = ParseTarget(argv[2], argv[3], argv[4]);

    //Точки проекции с номерами сегментов
    vector<pair<Vector, unsigned int>> projections;

    //Ближайший узел
    Vector minNode;

    //Номера сегментов которым принадлжинт ближайший узел
    vector<unsigned int> minNodeNum;

    if (input.is_open())
        FindProjections(input, projections, minNode, minNodeNum);
    input.close();

    MakeOutput(projections, minNode, minNodeNum);
    system("pause");
}