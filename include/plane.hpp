#pragma once

#include "vec3.hpp"
#include "ray.hpp"
#include "hittable.hpp"
#include <cstdint>

/**
 * @file plane.hpp
 * @brief Plane struct with hit method to calculate ray intersection
 */
namespace machc{
    struct Plane{
        point3 point;
        vec3 normal;
        uint32_t material_index;

        Plane(const point3& pnt,const vec3& nml, uint32_t mat_index) : point(pnt), normal(nml), material_index(mat_index) {}

        inline bool hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const {
            float epsilon = 1e-6f; // may need to adjust to be smaller later depending on results
            float denom = r.dir.dot(normal);

            if (std::abs(denom) < epsilon){
                return false;
            }

            float numer = (point - r.origin).dot(normal);

            float t = numer / denom; // t = (point on plane - ray origin) dot N / Dir dot N

            if (t < t_min || t > t_max){
                return false;
            }

            rec.calc_normal(r, normal);
            rec.material_index = material_index;
            rec.t = t;
            rec.p = r.at(t);

            return true;
        }

    };
}