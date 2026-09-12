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

        inline bool hit(const Ray& r, HitRecord& rec) const {
            float t_min = 0.001f;
            float t_max = std::numeric_limits<float>::infinity();
            bool h = false;

            for (const Geometry& obj : objects){
                HitRecord temp_rec;

                if (machc::hit(obj,r,t_min,t_max,temp_rec)){
                    t_max = temp_rec.t;
                    h = true; //hit flag
                    rec = temp_rec;
                }
            }

            return h;
        }
    };
}