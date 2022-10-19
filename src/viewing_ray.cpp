#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  ray.origin = camera.e;

  ray.direction[0] = (camera.width / width) * (j + 0.5) - (camera.width / 2);
  ray.direction[1] = -1 * ((camera.height / height) * (i + 0.5) - (camera.height / 2));
  ray.direction[2] = -1 * camera.d;

  Eigen::Matrix3d c;
  c << camera.u, camera.v, camera.w;
  ray.direction = c * ray.direction;
  ////////////////////////////////////////////////////////////////////////////
}

