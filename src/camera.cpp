#include "camera.hpp"
#include <cmath>
#include <numbers>



namespace machc {

    Camera init_camera(const point3& lookfrom, const point3& lookat, const vec3& vup, float vfov, float aspect_ratio, int image_width, int image_height) {
        Camera cam;
        cam.origin = lookfrom;

        vec3 w = (lookfrom - lookat).normalized();
        vec3 u = vup.cross(w).normalized();
        vec3 v = w.cross(u).normalized();

        float theta = vfov * (std::numbers::pi_v<float> / 180.0f);
        float viewport_height = 2.0f * std::tan(theta * 0.5f);
        float viewport_width = viewport_height * aspect_ratio;

        vec3 viewport_horizontal = viewport_width * u;
        vec3 viewport_vertical = viewport_height * -v;

        cam.du = viewport_horizontal / static_cast<float>(image_width);
        cam.dv = viewport_vertical / static_cast<float>(image_height);

        cam.top_left_corner = cam.origin - (viewport_horizontal * 0.5f) - (viewport_vertical * 0.5f) - w;
        cam.top_left_corner += (cam.du * 0.5f) + (cam.dv * 0.5f); //midpoint of the pixel offset

        return cam;
    }

}