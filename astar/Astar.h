#pragma once
/*
//A*算法对象类
*/
#include <vector>
#include <list>
 
const int kCost1 = 10; //直移一格消耗
const int kCost2 = 14; //斜移一格消耗
 
struct Point
{
	int x, y , z; //点坐标，这里为了方便按照C++的数组来计算
	int F, G, H; //F=G+H
	Point *parent; //parent的坐标，这里没有用指针，从而简化代码
	Point(int _x, int _y, int _z) :x(_x), y(_y),z(_z), F(0), G(0), H(0), parent(NULL)  //变量初始化
	{
	}
};
 
class Astar
{
public:
	// void InitAstar(std::vector<std::vector<int>> &_maze);//创建二维地图
	void InitAstar(std::vector<std::vector<std::vector<int>>> &_maze);//创建地图
	std::list<Point *> GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
 
private:
	Point *findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
	std::vector<Point *> getSurroundPoints(const Point *point, bool isIgnoreCorner) const;
	bool isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const; //判断某点是否可以用于下一步判断
	Point *isInList(const std::list<Point *> &list, const Point *point) const; //判断开启/关闭列表中是否包含某点
	Point *getLeastFpoint(); //从开启列表中返回F值最小的节点
	//计算FGH值
	int calcG(Point *temp_start, Point *point);
	int calcH(Point *point, Point *end);
	int calcF(Point *point);
private:
	std::vector<std::vector<std::vector<int>>> maze;
	std::list<Point *> openList;  //开启列表//开启列表即为可行的周围点列表，如果是初始点，开启列表即为初始点
	std::list<Point *> closeList; //关闭列表//关闭列表即为使f最小的路径点
};