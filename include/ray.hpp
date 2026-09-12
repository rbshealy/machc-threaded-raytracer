#pragma once
#include "vec3.hpp"

/**
 * @file ray.hpp
 * @brief Ray 3D struct with essential operations for the raytracer
 */
namespace machc {
    struct Ray{
        point3 origin;
        vec3 dir;

        Ray() = default;
        Ray(const point3& origin, const vec3& direction) : origin(origin), dir(direction){}

        //Returns the point along the ray at time t
        [[nodiscard]] point3 at(float t) const {
            return origin + (t * dir);
        }
    
    };
}