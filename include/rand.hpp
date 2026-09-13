#pragma once

#include "vec3.hpp"
#include <random>



namespace machc{
    [[nodiscard]] inline std::mt19937& get_engine(){
        thread_local static std::mt19937 engine(std::random_device{}() ); //rd() passes a random unsigned int into the algorithm for init

        return engine;
    }

    //returns float between 0 and 1
    inline float rand_f(){
        std::mt19937 random_engine = get_engine();

        std::uniform_real_distribution<float> dist(0.0f, 1.0f);

        return dist(random_engine); //dist(random_engine) returns a random number in the distribution
    }

    //returns float in the range range [min, max)
    inline float rand_f(float min, float max){
        float range = max - min;

        return (range * rand_f()) + min;
    }

    [[nodiscard]] inline vec3 rand_v3(float min, float max){
        return vec3{rand_f(min, max), rand_f(min,max), rand_f(min, max)};
    }

    [[nodiscard]] inline vec3 rand_vec3_in_unit_sphere(){
        while(true){
            vec3 ret = rand_v3(-1.0f,1.0f);
            if (ret.length_squared() < 1.0f){
                return ret;
            }
        }
    }

    [[nodiscard]] inline vec3 rand_v3_unit(){
        return rand_vec3_in_unit_sphere().normalized();
    }

    [[nodiscard]] inline vec3 rand_v3_in_hemisphere(const vec3& normal){
        vec3 vec = rand_vec3_in_unit_sphere();
        if (vec.dot(normal) > 0.0f){
            return vec ;
        } else {
            return -vec;
        }
    }

    //TODO: add random in unit disk later for DOF

}