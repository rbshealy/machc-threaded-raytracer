#pragma once
#include "vec3.hpp"


namespace machc {
    struct Triangle {
        point3 v0;
        point3 v1;
        point3 v2;
        uint32_t material_index;

        Triangle() : v0(point3(0, 0, 0)), v1(point3(1, 0, 0)), v2(point3(0, 1, 0)), material_index(0) {}
        Triangle(const point3& v0, const point3& v1, const point3& v2, uint32_t material_index) : v0(v0), v1(v1), v2(v2), material_index(material_index) {}

    };
}