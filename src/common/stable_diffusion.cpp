//
// Created by root on 4/3/25.
//
#include "xlite_cli/commands/stable_diffusion.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <gflags/gflags.h>
#include "lite/lite.h"
#include "filesystem"



// 为face_detect命令定义标志
static bool face_detect_command = false;
DEFINE_string(sd_model_folder, "/home/xlite-cli/sd_model_folder",
              "Path to the face change model (engine format)");
DEFINE_string(prompt, "a little girl with blue hair", "Input prompt (required)");
DEFINE_string(negative_prompt, "", "Input negative prompt (required)");
DEFINE_string(sd_output_image, "sd_result.jpg", "Output image path");

namespace xlite_cli {
    namespace commands {

        int text2img(int argc, char** argv) {
            face_detect_command = true;

            // 解析命令行参数
            gflags::SetUsageMessage("Face Change using FaceFusion model");
            gflags::ParseCommandLineFlags(&argc, &argv, true);

            // 验证必需参数
            if (FLAGS_prompt.empty() ) {
                std::cerr << "Error: Input prompt required (--input)" << std::endl;
                gflags::ShowUsageWithFlags(argv[0]); // 显示使用信息
                return 1;
            }

            try {

                namespace fs = std::filesystem;
                fs::path model_folder(FLAGS_sd_model_folder);
                auto clip_path = (model_folder / "clip.engine").string();
                auto unet_path = (model_folder / "unet.engine").string();
                auto vae_path = (model_folder / "vae.engine").string();
                std::string scheduler_config_path =  (model_folder / "scheduler_config.json").string();



                auto *pipeline = new lite::trt::sd::pipeline::PipeLine(
                        clip_path, unet_path, vae_path
                );

                if (!pipeline) {
                    std::cerr << "Error: Failed to create YOLOV8Face detector" << std::endl;
                    return 1;
                }


                std::string prompt =FLAGS_prompt;
                std::string negative_prompt =FLAGS_negative_prompt;
                std::string save_path = FLAGS_sd_output_image;
                pipeline->inference(prompt,negative_prompt,save_path,scheduler_config_path);


                delete pipeline;

            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return 1;
            }
        }

    } // namespace commands
} // namespace xlite_cl