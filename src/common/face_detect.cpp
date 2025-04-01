#include "xlite_cli/commands/face_detect.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <gflags/gflags.h>
#include "lite/lite.h"

// 为face_detect命令定义标志
static bool face_detect_command = false;
DEFINE_string(model, "/home/lite.ai.toolkit/examples/hub/trt/yoloface_8n_fp16.engine",
              "Path to the face detection model (ONNX format)");
DEFINE_string(input, "", "Input image path (required)");
DEFINE_string(output, "result.jpg", "Output image path");
DEFINE_double(conf, 0.5, "Confidence threshold for detection");
DEFINE_double(iou, 0.4, "IoU threshold for NMS");

namespace xlite_cli {
namespace commands {

int handle_face_detect(int argc, char** argv) {
    face_detect_command = true;
    
    // 解析命令行参数
    gflags::SetUsageMessage("Face detection using YOLOV8Face model");
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    
    // 验证必需参数
    if (FLAGS_input.empty()) {
        std::cerr << "Error: Input path required (--input)" << std::endl;
        gflags::ShowUsageWithFlags(argv[0]); // 显示使用信息
        return 1;
    }
    
    try {
        // 读取图像
        cv::Mat img_bgr = cv::imread(FLAGS_input);
        if (img_bgr.empty()) {
            std::cerr << "Error: Failed to read image: " << FLAGS_input << std::endl;
            return 1;
        }
        
        // 创建YOLOV8Face检测器
//        auto* yolov8_face = new lite::cv::face::detect::YOLOV8Face(FLAGS_model);
        lite::trt::cv::face::detection::YOLOV8Face *yolov8face_trt  = new lite::trt::cv::face::detection::YOLOV8Face(FLAGS_model);
        if (!yolov8face_trt) {
            std::cerr << "Error: Failed to create YOLOV8Face detector" << std::endl;
            return 1;
        }
        
        // 执行检测
        std::vector<lite::types::Boxf> detected_boxes;
        yolov8face_trt->detect(img_bgr, detected_boxes, FLAGS_conf, FLAGS_iou);
        
        // 绘制结果
        lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);
        
        // 保存结果
        cv::imwrite(FLAGS_output, img_bgr);
        
        std::cout << "Detected " << detected_boxes.size() << " faces" << std::endl;
        std::cout << "Result saved to: " << FLAGS_output << std::endl;
        
        // 释放资源
        delete yolov8face_trt;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

} // namespace commands
} // namespace xlite_cli