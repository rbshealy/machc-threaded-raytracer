#pragma once

#include <variant>
#include "ray.hpp"
#include "hittable.hpp"

namespace machc {

    struct Lambertion {
        color albedo;
        bool scatter(const ray* ray_in, const HitRecord& hit_record, color& attenuation, ray& ray_out) const;
    };

    struct Meta {
        color albedo;
        float fuzz;
        bool scatter(const ray* ray_in, const HitRecord& hit_record, color& attenuation, ray& ray_out) const;
    };

    struct Dielectric {
        float refraction_index;
        bool scatter(const ray* ray_in, const HitRecord& hit_record, color& attenuation, ray& ray_out) const;
    };

}