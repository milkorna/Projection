#include "Utilites.h"

//�������� �������� ����� target �� ������ ������� ����������� ������� ������� c ��������� prevNode, node
Vector GetProjection(Vector& prevNode, Vector& node, Vector& target) {
    //������������ ������ ������ ������� ����������� �������
    Vector a = prevNode - node;
    //����� ������������� �������
    double aLength = a * a;
    //����� �������� 
    Vector projection = a * ((prevNode - target) * a / aLength);
    return prevNode - projection;
}

//�������� ������� �����
Vector ParseTarget(char* x, char* y, char* z) {
    Vector target(atof(x), atof(y), atof(z));
    return target;
}

//���������� ������������ ���������� ����� �� �������
bool comp(pair<Vector, unsigned int>& a, pair<Vector, unsigned int>& b) {
    return a.first.Distance(target) < b.first.Distance(target);
}

//����� ����� �������� � �������� �������� ����
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

//����� ����������
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