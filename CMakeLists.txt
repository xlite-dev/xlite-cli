cmake_minimum_required(VERSION 3.10)
project(xlite_cli)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置RPATH，让可执行文件能找到动态库
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_CURRENT_SOURCE_DIR}/../lite.ai.toolkit/third_party/onnxruntime/lib:${CMAKE_CURRENT_SOURCE_DIR}/../lite.ai.toolkit/build/install/lib")

# 设置lite.ai.toolkit的路径
set(lite.ai.toolkit_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../lite.ai.toolkit)
set(lite.ai.toolkit_INCLUDE_DIR ${lite.ai.toolkit_DIR})
set(lite.ai.toolkit_LIB_DIR ${lite.ai.toolkit_DIR}/build/install/lib)

# 设置第三方库路径
set(THIRD_PARTY_PATH ${lite.ai.toolkit_DIR}/third_party)

# 设置ONNX Runtime
set(OnnxRuntime_Version "1.17.1")
set(OnnxRuntime_DIR ${THIRD_PARTY_PATH}/onnxruntime)
include_directories(${OnnxRuntime_DIR}/include)
link_directories(${OnnxRuntime_DIR}/lib)

# 设置OpenCV
set(OpenCV_Version "4.9.0-ffmpeg4.2.2")
set(OpenCV_DIR ${THIRD_PARTY_PATH}/opencv)
include_directories(${OpenCV_DIR}/include/opencv4)
link_directories(${OpenCV_DIR}/lib)
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_imgcodecs opencv_calib3d)

# 设置TensorRT（如果需要的话）
set(CUDA_DIR "/usr/local/cuda")
set(TensorRT_DIR "/usr/local/tensorrt")
include_directories(${CUDA_DIR}/include)
link_directories(${CUDA_DIR}/lib64)
include_directories(${TensorRT_DIR}/include)
link_directories(${TensorRT_DIR}/lib)

# 查找lite.ai.toolkit库
find_package(lite.ai.toolkit REQUIRED PATHS ${lite.ai.toolkit_DIR})

# 添加包含目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${lite.ai.toolkit_INCLUDE_DIR})

# 获取所有源文件
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 创建可执行文件
add_executable(xlite-cli ${SOURCES})

# 链接库
target_link_libraries(xlite-cli 
    ${lite.ai.toolkit_LIBS}
    ${OpenCV_LIBS}
    onnxruntime
    -L${lite.ai.toolkit_LIB_DIR}
    -L${OnnxRuntime_DIR}/lib
    -L${OpenCV_DIR}/lib
    -L${CUDA_DIR}/lib64
    -L${TensorRT_DIR}/lib
)

# 在构建完成后复制依赖库到构建目录
add_custom_command(TARGET xlite-cli POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${lite.ai.toolkit_LIB_DIR}/liblite.ai.toolkit.so
    ${lite.ai.toolkit_LIB_DIR}/liblite.ai.toolkit.so.0.3.1
    ${OnnxRuntime_DIR}/lib/libonnxruntime.so.1.17.1
    ${OnnxRuntime_DIR}/lib/libonnxruntime.so
    ${OpenCV_DIR}/lib/libopencv_core.so.4.9.0
    ${OpenCV_DIR}/lib/libopencv_imgproc.so.4.9.0
    ${OpenCV_DIR}/lib/libopencv_imgcodecs.so.4.9.0
    ${OpenCV_DIR}/lib/libopencv_calib3d.so.4.9.0
    ${CMAKE_SOURCE_DIR}/build/test_lite_age_googlenet.jpg
    ${CMAKE_SOURCE_DIR}/build/yoloface_8n.onnx
    ${CMAKE_BINARY_DIR}
)


# 安装规则
install(TARGETS xlite-cli DESTINATION bin)