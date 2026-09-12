#pragma once

#include <variant>
#include "sphere.hpp"
#include "triangle.hpp"
#include "plane.hpp"


namespace machc {
    using Geometry = std::variant<Sphere, Triangle, Plane>;
}