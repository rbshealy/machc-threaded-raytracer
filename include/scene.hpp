#pragma once

#include "geometry.hpp"
#include "material.hpp"
#include <cstdint>
#include <vector>


namespace machc {
    struct Scene {
        std::vector<Geometry> objects;
        std::vector<Material> materials;

        uint32_t add_material(const Material& mat);
        void add_object(const Geometry& obj);
    };
}