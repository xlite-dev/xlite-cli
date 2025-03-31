#include "xlite_cli/commands/face_detect.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "lite/lite.h"

namespace xlite_cli {
namespace commands {

void print_face_detect_help() {
    std::cout << "Usage: xlite-cli --face_detect [OPTIONS]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --model PATH      Path to the face detection model (ONNX format)" << std::endl;
    std::cout << "  --input PATH      Input image path (required)" << std::endl;
    std::cout << "  --output PATH     Output image path (default: result.jpg)" << std::endl;
    std::cout << "  --conf FLOAT      Confidence threshold (default: 0.5)" << std::endl;
    std::cout << "  --iou FLOAT       IoU threshold for NMS (default: 0.4)" << std::endl;
    std::cout << "  --help            Show this help message" << std::endl;
}

int handle_face_detect(ArgParser& parser) {
    // 检查是否请求帮助
    if (parser.has_option("--help")) {
        print_face_detect_help();
        return 0;
    }
    
    // 获取参数
    std::string model_path = parser.get_option("--model", "../lite.ai.toolkit/examples/hub/onnx/cv/yoloface_8n.onnx");
    std::string input_path = parser.get_option("--input");
    std::string output_path = parser.get_option("--output", "result.jpg");
    float conf_threshold = parser.get_float_option("--conf", 0.5f);
    float iou_threshold = parser.get_float_option("--iou", 0.4f);
    
    // 验证必需参数
    if (input_path.empty()) {
        std::cerr << "Error: Input path required (--input)" << std::endl;
        print_face_detect_help();
        return 1;
    }
    
    try {
        // 读取图像
        cv::Mat img_bgr = cv::imread(input_path);
        if (img_bgr.empty()) {
            std::cerr << "Error: Failed to read image: " << input_path << std::endl;
            return 1;
        }
        
        // 创建YOLOV8Face检测器
        auto* yolov8_face = new lite::cv::face::detect::YOLOV8Face(model_path);
        if (!yolov8_face) {
            std::cerr << "Error: Failed to create YOLOV8Face detector" << std::endl;
            return 1;
        }
        
        // 执行检测
        std::vector<lite::types::Boxf> detected_boxes;
        yolov8_face->detect(img_bgr, detected_boxes, conf_threshold, iou_threshold);
        
        // 绘制结果
        lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);
        
        // 保存结果
        cv::imwrite(output_path, img_bgr);
        
        std::cout << "Detected " << detected_boxes.size() << " faces" << std::endl;
        std::cout << "Result saved to: " << output_path << std::endl;
        
        // 释放资源
        delete yolov8_face;
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

} // namespace commands
} // namespace xlite_cli