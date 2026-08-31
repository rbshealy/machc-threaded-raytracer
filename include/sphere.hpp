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

    };
}