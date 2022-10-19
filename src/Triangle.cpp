#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Dense>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  Eigen::Vector3d t1 = std::get<0>(this->corners) - std::get<1>(this->corners);
  Eigen::Vector3d t2 = std::get<0>(this->corners) - std::get<2>(this->corners);

  Eigen::Matrix3d matrix; 
  matrix << t1, t2, -1 * ray.direction;

  if(matrix.determinant() == 0){
    return false;
  }
  Eigen::Vector3d dirs = std::get<0>(this->corners) - ray.origin;
  Eigen::Vector3d e = matrix.inverse() * dirs;

  double alpha = e[0];
  double beta = e[1];
  if(e[2] < min_t){
    return false;
  }
  t = e[2];
  n = t1.cross(t2).normalized();
  return true;

}


