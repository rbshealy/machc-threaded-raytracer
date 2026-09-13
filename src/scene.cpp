#include "scene.hpp"
#include "camera.hpp"
#include <cstdint>


namespace machc{
    uint32_t Scene::add_material(const Material& mat) {
        materials.emplace_back(mat);
        return static_cast<uint32_t>(materials.size() - 1);
    }

    void Scene::add_object(const Geometry& obj){
        objects.emplace_back(obj);
    }

    Scene scene_one(){
        Scene scene;
        
        return scene;
    }

    Scene scene_two(){
    Scene scene;

        return scene;
    }
}