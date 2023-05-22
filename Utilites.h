#pragma once
#include "VectorPoint.h"
#include <vector>
#include <algorithm>
#include <fstream>

//Целевая точка
extern Vector target;

//Получить проекцию точки target на прямую которой принадлежит сегмент ломаной c границами prevNode, node
Vector GetProjection(const Vector& prevNode, const Vector& node, const Vector& target);

//Получить целевую точку
Vector ParseTarget(char* x, char* y, char* z);

//Поиск точек проекции и наиболее близкого узла
void FindProjections(ifstream& input, vector<pair<Vector, unsigned int>>& projections, Vector& minNode, vector<unsigned int>& minNodeNum);

//Вывод результата
void MakeOutput(vector<pair<Vector, unsigned int>>& projections, Vector& minNode, const vector<unsigned int>& minNodeNum);
