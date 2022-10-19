#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  if((this->normal).dot(ray.direction) == 0){
    return false;
  }
  double potential_t = -1 * (((this->normal).dot(ray.origin - this->point))/((this->normal).dot(ray.direction)));
  if (min_t <= potential_t){
    n = this->normal.normalized();
    t = potential_t;
    return true;
  }  
  return false;

}

