#pragma once
#include <cmath>

/**
 * @file vec3.hpp
 * @brief Essential 3D vector struct with operators for the raytracer
 */

namespace machc {
    struct vec3 {
        float x;
        float y;
        float z;

        vec3() : x{0.0f}, y{0.0f}, z{0.0f} {}
        vec3(float x, float y, float z) : x{x}, y{y}, z{z} {}

        //Returns length of the vector
        [[nodiscard]] float length() const{
            return std::sqrt(x * x + y * y + z * z);
        }

        //Returns length of the vector squared, avoids expensive square root operation
        [[nodiscard]] float length_squared() const{
            return x * x + y * y + z * z;
        }

        //Returns dot product of this vector and another
        [[nodiscard]] float dot(const vec3& v2) const{
            return x * v2.x + y * v2.y + z * v2.z;
        }

        //Returns cross product or vector orthoganal to this vector and another
        [[nodiscard]] vec3 cross(const vec3& v2) const{
            return vec3{
                (y * v2.z) - (z * v2.y),
                (z * v2.x) - (x * v2.z),
                (x * v2.y) - (y * v2.x)
            };
        }

        //Returns a vector of length one pointing in this vector's direction
        [[nodiscard]] vec3 normalized() const{
            float inv = 1.0f / length();
            return vec3{x * inv, y * inv, z * inv};
        }

        // vec3 Operators that modify the struct

        vec3& operator-= (const vec3& v2){
            x -= v2.x;
            y -= v2.y;
            z -= v2.z;
            return *this;
        }

        vec3& operator+= (const vec3& v2){
            x += v2.x;
            y += v2.y;
            z += v2.z;
            return *this;
        }

        vec3& operator*= (float a){
            x *= a;
            y *= a;
            z *= a;
            return *this;
        }

        vec3& operator/= (float a){
            float inv = 1.0f / a;
            x *= inv;
            y *= inv;
            z *= inv;
            return *this;
        }

    };


    // Semantic aliases
    using color = vec3;
    using point3 = vec3;


    // vec3 Operators that do not modify the struct

    [[nodiscard]] inline vec3 operator- (const vec3& v1){
        return vec3{-v1.x, -v1.y, -v1.z};
    }

    [[nodiscard]] inline vec3 operator+ (const vec3& v1, const vec3& v2){
        return vec3{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
    }

    [[nodiscard]] inline vec3 operator- (const vec3& v1, const vec3& v2){
        return vec3{v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
    }

    [[nodiscard]] inline vec3 operator* (const vec3& v1, float a){
        return vec3{v1.x * a, v1.y * a, v1.z * a};
    }

    [[nodiscard]] inline vec3 operator* (float a, const vec3& v1) {
        return v1 * a;
    }

    [[nodiscard]] inline vec3 operator/ (const vec3& v1, float a){
        float inv = 1.0f / a;
        return vec3{v1.x * inv, v1.y * inv, v1.z * inv};
    }

    
}