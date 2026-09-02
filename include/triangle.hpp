#pragma once
#include "vec3.hpp"
#include "ray.hpp"
#include "hittable.hpp"

/**
 * @file triangle.hpp
 * @brief Triangle struct with hit method to calculate ray intersection
 */
namespace machc {
    struct Triangle {
        point3 v0;
        point3 v1;
        point3 v2;
        uint32_t material_index;

        Triangle() : v0(point3(0, 0, 0)), v1(point3(1, 0, 0)), v2(point3(0, 1, 0)), material_index(0) {}
        Triangle(const point3& v0, const point3& v1, const point3& v2, uint32_t material_index) : v0(v0), v1(v1), v2(v2), material_index(material_index) {}

        // can be done by solving a 3x3 system but Moller-Trumbore algorithm is more efficient
        bool hit(const ray& r, float t_min, float t_max, HitRecord& rec) {
            float epsilon = 1e-6f; //Moller-Trumbore recommends epsilon of 1e-6f, may need to adjust later for shadow acne or if objects are far from the origin

            vec3 edge1 = v1 - v0;
            vec3 edge2 = v2 - v0;

            vec3 dXedge2 = r.dir.cross(edge2);
            float area = edge1.dot(dXedge2); //get area of paralleliped formed by edge1, edge2, and ray dir (scalar triple product)
            // will reuse this later for speed instead of calculating other denomenators

            if (std::abs(area) < epsilon){
                return false; // if 3 vectors are coplanar we throw them out, either the ray is on the triangle or parallel
            }

            float inv_area = 1.0f / area;

            vec3 T = r.orig - v0;
            float u = T.dot(dXedge2) * inv_area;

            if (u < 0.0 || u > 1.0){
                return false; //if u does not land between v0 and v1 we throw it out
            }

            vec3 tXedge1 = T.cross(edge1);
            float v = r.dir.dot(tXedge1) * inv_area;

            if (v < 0.0 || v + u > 1.0){
                return false; // if v and u greater than 1 then we are off the triangle, if v < 0 we are off the triangle
            }
        
            float t = edge2.dot(tXedge1) * inv_area;
            if (t < t_min || t > t_max){
                return false; // handling if the hit is behind the camera (t_min) or we've already found one closer (t_max)
            }

            rec.t = t;
            rec.p = r.at(t);
            rec.material_index = material_index;
            rec.calc_normal(r, edge1.cross(edge2).normalized());
            
            return true;
        }
    };

    
}