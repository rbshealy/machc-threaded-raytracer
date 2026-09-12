#pragma once

#include <variant>
#include "hittable.hpp"
#include "sphere.hpp"
#include "triangle.hpp"
#include "plane.hpp"


namespace machc {
    using Geometry = std::variant<Sphere, Triangle, Plane>;

    inline bool hit(Geometry& geo, Ray& r, float t_min, float t_max, HitRecord& rec) {
        bool result = std::visit([&](const auto& g) {return g.hit(r, t_min, t_max, rec);},geo);
        return result;
    }
}