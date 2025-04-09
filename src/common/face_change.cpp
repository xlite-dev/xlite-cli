//
// Created by root on 4/1/25.
//
#include "xlite_cli/commands/face_change.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <gflags/gflags.h>
#include "lite/trt/cv/trt_facefusion_pipeline.h"
#include <filesystem>
#include <unordered_map>

// 为face_detect命令定义标志
static bool face_detect_command = false;
DEFINE_string(model_folder, "/home/xlite-cli/face_change_model",
              "Path to the face change model (engine format)");
DEFINE_string(input_src, "/home/lite.ai.toolkit/1.jpg", "Input source image path (required)");
DEFINE_int32(src_index, 0, "index of src image");
DEFINE_string(input_target, "/home/lite.ai.toolkit/double.jpg", "Input target image path (required)");
DEFINE_int32(target_index, 1, "index of target image");
DEFINE_string(face_change_output, "result_double_change.jpg", "Output image path");

namespace xlite_cli {
    namespace commands {

        int handle_face_change(int argc, char** argv) {
            face_detect_command = true;

            // 解析命令行参数
            gflags::SetUsageMessage("Face Change using FaceFusion model");
            gflags::ParseCommandLineFlags(&argc, &argv, true);

            // 验证必需参数
            if (FLAGS_input_src.empty() || FLAGS_input_target.empty()) {
                std::cerr << "Error: Input path required (--input)" << std::endl;
                gflags::ShowUsageWithFlags(argv[0]); // 显示使用信息
                return 1;
            }

            try {
                // 读取图像
                cv::Mat input_src = cv::imread(FLAGS_input_src);
                cv::Mat input_target = cv::imread(FLAGS_input_target);

                if (input_src.empty() || input_target.empty()) {
                    std::cerr << "Error: Failed to read src image: " << FLAGS_input_src << std::endl;
                    std::cerr << "Error: Failed to read target image: " << FLAGS_input_target << std::endl;
                    return 1;
                }

                namespace fs = std::filesystem;
                fs::path model_folder(FLAGS_model_folder);
                auto face_detect_onnx_path = (model_folder / "face_detect.engine").string();
                auto face_landmark_onnx_path = (model_folder / "face_landmark.engine").string();
                auto face_recognizer_onnx_path = (model_folder / "face_recognizer.engine").string();
                auto face_swap_onnx_path = (model_folder / "face_swap.engine").string();
                auto face_restoration_onnx_path = (model_folder / "face_restoration.engine").string();

                // 创建FaceFusionPipeLine实例
                auto *pipeLine = new trtcv::TRTFaceFusionPipeLine(
                        face_detect_onnx_path,
                        face_landmark_onnx_path,
                        face_recognizer_onnx_path,
                        face_swap_onnx_path,
                        face_restoration_onnx_path
                );
                
                if (!pipeLine) {
                    std::cerr << "Error: Failed to create FaceFusion pipeline" << std::endl;
                    return 1;
                }
                
                // 执行检测
                std::string source_image_path = FLAGS_input_src;
                std::string target_image_path = FLAGS_input_target;
                std::string save_image_path = FLAGS_face_change_output;

                // 写一个测试时间的代码
                auto start = std::chrono::high_resolution_clock::now();

                // 使用正确的参数顺序调用detect函数
                pipeLine->detect(source_image_path, FLAGS_src_index, target_image_path,
                                 FLAGS_target_index, save_image_path);

                // 计算并输出处理时间
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = end-start;
                std::cout << "处理完成，耗时: " << diff.count() << " 秒" << std::endl;
                std::cout << "结果已保存到: " << save_image_path << std::endl;
                
                // 释放资源
                delete pipeLine;
                return 0;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return 1;
            }
        }

    } // namespace commands
} // namespace xlite_cli