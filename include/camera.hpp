#pragma once

#include "vec3.hpp"
#include "ray.hpp"

namespace machc {
    struct Camera {
        vec3 origin; //world space
        vec3 top_left_corner; //top left in 3D world space
        vec3 du; // horizontal pixel vector
        vec3 dv; //vertical pixel vector
    };

    [[nodiscard]] Camera init_camera(const point3& lookfrom, const point3& lookat, const vec3& vup, float vfov, float aspect_ratio);
    [[nodiscard]] inline ray get_ray(const Camera& cam, float u, float v) {
        return ray(cam.origin,(u * cam.du) + (v * cam.dv) + cam.top_left_corner - cam.origin);
    }
}


