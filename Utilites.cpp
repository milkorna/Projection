#include "Utilites.h"

//Получить проекцию точки target на прямую которой принадлежит сегмент ломаной c границами prevNode, node
Vector GetProjection(Vector& prevNode, Vector& node, Vector& target) {
    //Направляющий вектор прямой которой принадлежит сегмент
    Vector a = prevNode - node;
    //Длина направляющего вектора
    double aLength = a * a;
    //Точка проекции 
    Vector projection = a * ((prevNode - target) * a / aLength);
    return prevNode - projection;
}

//Получить целевую точку
Vector ParseTarget(char* x, char* y, char* z) {
    Vector target(atof(x), atof(y), atof(z));
    return target;
}

//Компаратор сравнивающий расстояния точек до целевой
bool comp(pair<Vector, unsigned int>& a, pair<Vector, unsigned int>& b) {
    return a.first.Distance(target) < b.first.Distance(target);
}

//Поиск точек проекции и наиболее близкого узла
void FindProjections(ifstream& input, vector<pair<Vector, unsigned int>>& projections, Vector& minNode, vector<unsigned int>& minNodeNum) {
    double x, y, z;

    unsigned int count = 0;
    Vector prevNode;

    if (input >> x >> y >> z) {
        Vector node(x, y, z);
        minNode = prevNode = node;
    }

    while (input >> x >> y >> z)
    {
        ++count;
        Vector node(x, y, z);
        Vector projection = GetProjection(prevNode, node, target);
        if (projection.IsInSegment(prevNode, node)) {
            projections.push_back({ projection , count });
        }
        else {
            if (fabs(node.Distance(target) - minNode.Distance(target)) < numeric_limits<double>::epsilon()) {
                minNodeNum.push_back(count);
            }
            else {
                if (minNode.IsInSegment(prevNode, node))
                    minNodeNum.push_back(count);
            }
            if (node.Distance(target) < minNode.Distance(target)) {
                minNode = node;
                minNodeNum.clear();
                minNodeNum.push_back(count);
            }
        }
        prevNode = node;
    }

    sort(projections.begin(), projections.end(), comp);
}

//Вывод результата
void MakeOutput(vector<pair<Vector, unsigned int>>& projections, Vector& minNode, const vector<unsigned int>& minNodeNum) {
    if (!projections.empty()) {
        for (auto& [coord, num] : projections)
        {
            cout << endl << "segment " << num << " ";
            coord.Print();
        }
    }
    else {
        bool flag = false;
        for (auto& i : minNodeNum)
        {
            if (flag)
                cout << endl << "or";
            else flag = true;
            cout << endl << "segment " << i << " ";
            minNode.Print();
        }
    }
    cout << endl;
}
