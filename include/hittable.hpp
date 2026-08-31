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
        machc::point3 p;
        machc::vec3 normal;
        uint32_t material_index;

    };
 }