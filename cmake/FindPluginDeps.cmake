cmake_minimum_required(VERSION 3.17)

if(NOT TARGET render-2D)
    include(FetchContent)
    FetchContent_Declare(
            render-2D
            GIT_REPOSITORY https://github.com/PolymorphEngine/render-2D.git
            GIT_TAG dev
    )
    FetchContent_MakeAvailable(render-2D)
endif()

if(NOT TARGET render-core)
    include(FetchContent)
    FetchContent_Declare(
            render-core
            GIT_REPOSITORY https://github.com/PolymorphEngine/render-core.git
            GIT_TAG dev
    )
    FetchContent_MakeAvailable(render-core)
endif()

if(NOT TARGET input)
    include(FetchContent)
    FetchContent_Declare(
            input
            GIT_REPOSITORY https://github.com/PolymorphEngine/input.git
            GIT_TAG dev
    )
    FetchContent_MakeAvailable(input)
endif()