#pragma once

#include "geometry.hpp"
#include "material.hpp"
#include <cstdint>
#include <limits>
#include <vector>


namespace machc {
    struct Scene {
        std::vector<Geometry> objects;
        std::vector<Material> materials;

        uint32_t add_material(const Material& mat);
        void add_object(const Geometry& obj);

        inline bool hit(Ray& r, HitRecord& rec){
            float t_min = 0.001f;
            float t_max = std::numeric_limits<float>::infinity();

            for (Geometry obj : objects){
                if (...){
                    t_max = rec.t;
                }
            }
        }
    };
}