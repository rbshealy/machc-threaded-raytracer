#pragma once

#include "constants.hpp"
#include "geometry.hpp"
#include "material.hpp"
#include <cstdint>
#include <limits>
#include <vector>
#include "camera.hpp"


namespace machc {
    struct Scene {
        std::vector<Geometry> objects;
        std::vector<Material> materials;

        uint32_t add_material(const Material& mat);
        void add_object(const Geometry& obj);

        inline bool hit(const Ray& r, HitRecord& rec) const {
            float t_min = constants::ray_origin_offset; //used to avoid shadow acne
            float t_max = std::numeric_limits<float>::infinity();
            bool h = false;

            for (const Geometry& obj : objects){
                HitRecord temp_rec; // temp rec to be copied into rec if valid hit

                if (machc::hit(obj,r,t_min,t_max,temp_rec)){
                    t_max = temp_rec.t;
                    h = true; //hit flag
                    rec = temp_rec;
                }
            }

            return h;
        }
    };

    //takes in a camera ref and modifies it while building the scene. Return Scene struct
    Scene scene_one();
    Scene scene_two();
}