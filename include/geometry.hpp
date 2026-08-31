#pragma once

#include <variant>
#include "sphere.hpp"
#include "triangle.hpp"


namespace machc {
    using Geometry = std::variant<Sphere, Triangle>;
}