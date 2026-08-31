#pragma once
#include "ray.hpp"
#include "hittable.hpp"

struct Sphere {
    machc::point3 center;
    float radius;
    uint32_t material_index;

    Sphere() : center(machc::point3(0, 0, 0)), radius(1.0f), material_index(0) {}
    Sphere(const machc::point3& center, float radius, uint32_t material_index) : center(center), radius(radius), material_index(material_index) {}

};