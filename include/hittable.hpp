#pragma once
#include "vec3.hpp"
#include "ray.hpp"

/**
 * @file hittable.hpp
 * @brief Hittable struct for objects that can be intersected by rays
 */
 namespace machc {
    struct HitRecord {
        float t;
        point3 p;
        vec3 normal; //unit vector
        uint32_t material_index;
        bool outside_hit;



        //unit_outward_normal needs to be a unit vector for light calculations
        void calc_normal(const ray& r, const vec3& unit_outward_normal){
            outside_hit = r.dir.dot(unit_outward_normal) < 0.0f;
            normal = outside_hit ? unit_outward_normal : -unit_outward_normal;
        }
    };
 }