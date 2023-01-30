add_library(rt_library)

target_sources(
        rt_library
        PRIVATE
        sources/core/core.cpp
        sources/core/point_2.cpp
        sources/core/vector_2.cpp
        sources/core/point_3.cpp
        sources/core/vector_3.cpp
        sources/core/normal_3.cpp
        sources/core/ray.cpp
        sources/core/matrix_4_4.cpp
        sources/core/transform.cpp
)

target_include_directories(
        rt_library
        PUBLIC
        includes
        inline
)