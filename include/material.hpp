#pragma once

#include <variant>
#include "ray.hpp"
#include "hittable.hpp"
#include "rand.hpp"
#include "constants.hpp"

namespace machc {

    struct Lambertian {
        color albedo;
        inline bool scatter(const Ray& ray_in, const HitRecord& rec, color& attenuation, Ray& ray_out) const {
            attenuation = albedo;
            //TODO: Check if ray needs to be nudged or if t_min trick is working
            ray_out = Ray(rec.p, rand_v3_in_hemisphere(rec.normal));
            return true;
        }
    };

    struct Metal {
        color albedo;
        float fuzz;
        inline bool scatter(const Ray& ray_in, const HitRecord& rec, color& attenuation, Ray& ray_out) const {
            attenuation = albedo;
            vec3 refl_ray = ray_in.dir - (2 * (ray_in.dir.dot(rec.normal)) * rec.normal); //reflect the ray around the normal
            ray_out = Ray(rec.p,refl_ray + (fuzz * rand_v3_unit())); //blur it in a random direction

            return ray_out.dir.dot(rec.normal) > 0.0f;
        }
    };

    struct Dielectric {
        color albedo = {0.0f, 0.0f, 0.0f};
        float refraction_index = 1.5f;
        inline bool scatter(const Ray& ray_in, const HitRecord& rec, color& attenuation, Ray& ray_out) const {
            //TODO: Study Dielectric
            attenuation = albedo;
            return false;
        }
    };

    using Material = std::variant<Lambertian, Metal, Dielectric>;

}