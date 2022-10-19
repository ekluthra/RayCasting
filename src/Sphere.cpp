#include "Sphere.h"
#include "Ray.h"
bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  Eigen::Vector3d diff = ray.origin - this->center;
  double a = ray.direction.dot(ray.direction);
  double b = 2.0 * ray.direction.dot(diff);
  double c = diff.dot(diff) - (this -> radius * this -> radius);
  
  double descriminant = b * b - (4 * a * c);

  if ( descriminant <= 0 ){
    return false;
  }

  double t1 = (-1 * b + sqrt(descriminant))/(2 * a);

  Eigen::Vector3d dir = this->center;
  if( min_t <= t1 ){
    t = t1;
    n = (t1 * ray.direction + ray.origin - dir).normalized();
    return true;
  }

  t1 = (-1 * b - + sqrt(descriminant))/(2 * a);
  if( min_t <= t1 ){
    t = t1;
    n = (t1 * ray.direction + ray.origin - dir).normalized();
    return true;
  }
  
  return false;

}

