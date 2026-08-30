#pragma once
#include "vec3.hpp"

/**
 * @file ray.hpp
 * @brief Ray 3D struct with essential operations for the raytracer
 */
namespace machc {
    struct ray{
        point3 orig;
        vec3 dir;

        ray() = default;
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction){}

        //Returns the point along the ray at time t
        [[nodiscard]] point3 at(float t) const {
            return orig + (t * dir);
        }
    
    };
}