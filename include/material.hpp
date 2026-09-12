#pragma once

#include <variant>
#include "ray.hpp"
#include "hittable.hpp"

namespace machc {

    struct Lambertion {
        color albedo;
        bool scatter(const Ray* ray_in, const HitRecord& hit_record, color& attenuation, Ray& ray_out) const;
    };

    struct Metal {
        color albedo;
        float fuzz;
        bool scatter(const Ray* ray_in, const HitRecord& hit_record, color& attenuation, Ray& ray_out) const;
    };

    struct Dielectric {
        float refraction_index;
        bool scatter(const Ray* ray_in, const HitRecord& hit_record, color& attenuation, Ray& ray_out) const;
    };

    using Material = std::variant<Lambertion, Metal, Dielectric>;

}