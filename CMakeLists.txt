cmake_minimum_required(VERSION 3.17.3) 

set(EXECUTABLE_NAME Tridents-of-Ardeus)
set(TEST_EXECUTABLE_NAME test)

project(Tridents LANGUAGES CXX) #set the project name and to use C++

set(CMAKE_BUILD_TYPE Debug)

set(MY_SOURCES  src/components/AnimationComponent.cpp
                src/components/GraphicsComponent.cpp
                src/components/InputComponent.cpp
                src/components/TileComponent.cpp
                src/interfaces/AIInterface.cpp
                src/interfaces/AnimationInterface.cpp
                src/interfaces/ColliderInterface.cpp
                src/interfaces/GraphicsInterface.cpp
                src/interfaces/SceneInterface.cpp
                src/Entities.cpp
                src/GameEntity.cpp
                src/Resources.cpp
                src/main.cpp
                include/components/AnimationComponent.hpp
                include/components/GraphicsComponent.hpp
                include/components/InputComponent.hpp
                include/components/TileComponent.hpp
                include/interfaces/AIInterface.hpp
                include/interfaces/AnimationInterface.hpp
                include/interfaces/ColliderInterface.hpp
                include/interfaces/ComponentInterface.hpp
                include/interfaces/GraphicsInterface.hpp
                include/interfaces/InputInterface.hpp
                include/interfaces/SceneInterface.hpp
                include/Components.hpp
                include/Entities.hpp
                include/GameEntity.hpp
                include/Resources.hpp)

set(MY_RESOURCES resources)

SET(TEST_SOURCES test/deps/catch_amalgamated.cpp
                 test/deps/catch_amalgamated.hpp
                 test/spec/entities/PlayerTest.cpp)




set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

if (NOT ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    find_package(SDL2 REQUIRED)

    find_package(SDL2_IMAGE REQUIRED)

    include_directories(${SDL2_IMAGE_INCLUDE_DIR})

    include_directories(${SDL2_INCLUDE_DIR})
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if (MINGW)
    link_directories("${PROJECT_SOURCE_DIR}/libs/mingw/SDL2-2.0.14/i686-w64-mingw32/lib/" "${PROJECT_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/lib/")
endif()

add_executable(${EXECUTABLE_NAME} ${MY_SOURCES})
target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_17)

add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SOURCES} ${MY_SOURCES})
target_compile_features(${TEST_EXECUTABLE_NAME} PRIVATE cxx_std_17)

if (MINGW)
    file(COPY ${MY_RESOURCES} DESTINATION ${CMAKE_BINARY_DIR}/dist)
else()
    file(COPY ${MY_RESOURCES} DESTINATION ${CMAKE_BINARY_DIR})
    
endif()

message(STATUS "######------ CMAKE_SOURCE_DIR set to: ${CMAKE_SOURCE_DIR}   ------######")

message(STATUS "######------ CMAKE_BINARY_DIR set to: ${CMAKE_BINARY_DIR}   ------######")


if (MSVC)
    add_custom_target(setup
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2-2.0.14/lib/x64/SDL2.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/SDL2_image.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/libjpeg-9.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/libpng16-16.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/libtiff-5.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/libwebp-7.dll ${CMAKE_BINARY_DIR}/Debug
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/vs2019/SDL2_image-2.0.5/lib/x64/zlib1.dll ${CMAKE_BINARY_DIR}/Debug
    )
elseif (MINGW)
    add_custom_target(setup
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2-2.0.14/i686-w64-mingw32/bin/SDL2.dll ${CMAKE_BINARY_DIR}/dist
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/SDL2_image.dll ${CMAKE_BINARY_DIR}/dist
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/libjpeg-9.dll  ${CMAKE_BINARY_DIR}/dist
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/libpng16-16.dll ${CMAKE_BINARY_DIR}/dist
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/libtiff-5.dll ${CMAKE_BINARY_DIR}/dist
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/libwebp-7.dll ${CMAKE_BINARY_DIR}/dist
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libs/mingw/SDL2_image-2.0.5/i686-w64-mingw32/bin/zlib1.dll ${CMAKE_BINARY_DIR}/dist
    )
    add_dependencies(${EXECUTABLE_NAME} setup)
endif()

message(STATUS "######------ Checking environment ------######")

if (MSVC)

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXECUTABLE_NAME})
    message(STATUS "######------ Setting MSVC flags   ------######")
	
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()

    message(STATUS "######------ CMAKE_CXX_FLAGS set to: ${CMAKE_CXX_FLAGS}   ------######")


elseif( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    
    message(STATUS "######------ Setting Emescripten configs   ------######")
    
    set(USE_FLAGS "-s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' -s USE_FREETYPE=1 --preload-file resources/")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    file(COPY "index.html" DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY "server.py" DESTINATION ${CMAKE_BINARY_DIR})

else()

    message(STATUS "######------ Setting Default configs (GNU?)  ------######")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")

endif()

if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    target_link_libraries(${EXECUTABLE_NAME})
elseif(MINGW)
    target_link_libraries(${EXECUTABLE_NAME} mingw32 SDL2main SDL2 SDL2_image)
    target_link_libraries(${TEST_EXECUTABLE_NAME} mingw32 SDL2main SDL2 SDL2_image)
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist )
    set_target_properties(${TEST_EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist )
else()
    target_link_libraries(${EXECUTABLE_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} )
endif()