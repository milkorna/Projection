#pragma once
#include "VectorPoint.h"
#include <vector>
#include <algorithm>
#include <fstream>

//������� �����
extern Vector target;

//�������� �������� ����� target �� ������ ������� ����������� ������� ������� c ��������� prevNode, node
Vector GetProjection(const Vector& prevNode, const Vector& node, const Vector& target);

//�������� ������� �����
Vector ParseTarget(char* x, char* y, char* z);

//����� ����� �������� � �������� �������� ����
void FindProjections(ifstream& input, vector<pair<Vector, unsigned int>>& projections, Vector& minNode, vector<unsigned int>& minNodeNum);

//����� ����������
void MakeOutput(vector<pair<Vector, unsigned int>>& projections, Vector& minNode, const vector<unsigned int>& minNodeNum);