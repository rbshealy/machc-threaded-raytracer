#pragma once
#include "ray.hpp"
#include "hittable.hpp"

namespace machc {
    struct Sphere {
        point3 center;
        float radius;
        uint32_t material_index;

        Sphere() : center(point3(0, 0, 0)), radius(1.0f), material_index(0) {}
        Sphere(const point3& center, float radius, uint32_t material_index) : center(center), radius(radius), material_index(material_index) {}

        bool hit (const ray& r, float t_min, float t_max, HitRecord& rec){
            vec3 oc = r.orig - center;

            float a = r.dir.length_squared();
            float bdiv2 = oc.dot(r.dir);
            float c = oc.length_squared() - (radius * radius);

            float discrim = (bdiv2 * bdiv2) - (a * c); // using reduced discriminant to not carry factor of 2 for the entire quadratic

            if (discrim < 0.0f){
                return false;
            }

            float t = (-bdiv2 - std::sqrt(discrim)) / a; // because of the math trick we did the entire quadratic is simpiler and can drop extra multiplies

            if (t < t_min || t > t_max){
                t = (-bdiv2 + std::sqrt(discrim)) / a;

                if (t < t_min || t > t_max){
                    return false;
                }
            }

            rec.t = t;
            rec.p = r.at(t);
            rec.material_index = material_index;
            rec.calc_normal(r, (rec.p - center) / radius);


            return true;
        }
    };
}