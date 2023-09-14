#include <iostream>
 
#include "Astar.h"

#include <vector>
 
bool InPath(const int &length, const int &width, const int &height, const std::list<Point *> &path) {
  for (const auto &p : path) {
    if (length == p->x && width == p->y && height==p->z) {
      return true;
    }
  }
  return false;
}
 
int main() {
  int m=10;
  int n=10;
  int p=10;
  //初始化地图，用三维矩阵代表地图，1表示障碍物，0表示可通
  //创建了一个m*n*p的三维数组，并初始值为0
  std::vector<std::vector<std::vector<int>>> map(m,std::vector< std::vector<int> >(n,std::vector<int>(p,0)));
                                    // = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                    //    {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
                                    //    {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                                    //    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
                                    //    {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                                    //    {1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                                    //    {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                                    //    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
  
  map[0][2][5]=1;
  map[0][3][5]=1;
  map[0][4][5]=1;
  map[0][5][5]=1;
  map[0][6][5]=1;


  Astar astar;
  astar.InitAstar(map);
 
  //设置起始和结束点
  Point start(0, 4, 7);
  Point end(0, 3, 0);
 
  // A*算法找寻路径
  std::list<Point *> path = astar.GetPath(start, end, false);
 
  // 打印结果
  for (auto &p : path) {
    std::cout << "(" << p->x << "," << p->y << ","<< p->z<<") ";
  }
  std::cout << "\n";
 
//   for (int row = 0; row < map.size(); ++row) {
//     for (int col = 0; col < map[0].size(); ++col) {
//       if (InPath(row, col, path)) {
//         if (map[row][col] != 0) {
//           std::cout << "e ";
//         } else {
//           std::cout << "* ";
//         }
//       } else {
//         std::cout << map[row][col] << " ";
//       }
//     }
//     std::cout << "\n";
//   }
  return 0;
}