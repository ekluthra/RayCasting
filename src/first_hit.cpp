#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  double min_hit = 0.0;
  bool has_hit = false;
  Eigen::Vector3d normal_vec;

  for (int i = 0; i < objects.size(); i++) {
    if(objects[i]->intersect(ray, min_t, min_hit, normal_vec)){
      if( !has_hit || min_hit < t ){
        t = min_hit;
        n = normal_vec;
        has_hit = true;
        hit_id = i;
      }
    }
  }
  return has_hit;

  ////////////////////////////////////////////////////////////////////////////
}

