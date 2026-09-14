#pragma once

namespace machc::constants {
    inline constexpr float ray_origin_offset = 1e-3f; //used to avoid shadow acne and invalid intersections by starting rays at 0
    inline constexpr float epsilon = 1e-6f; //used to check if two rays are
}