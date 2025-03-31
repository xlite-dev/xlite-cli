#include <iostream>
#include <map>
#include <functional>
#include "xlite_cli/common/arg_parser.h"
#include "xlite_cli/commands/face_detect.h"

// 显示帮助信息
void print_help() {
    std::cout << "xlite-cli: Command-line interface for lite.ai.toolkit" << std::endl;
    std::cout << "Usage: xlite-cli [COMMAND] [OPTIONS]" << std::endl;
    std::cout << std::endl;
    std::cout << "Commands:" << std::endl;
    std::cout << "  --face_detect      Face detection using YOLOV8Face" << std::endl;
    std::cout << "  --help             Show this help message" << std::endl;
    std::cout << std::endl;
    std::cout << "For command-specific help, run: xlite-cli [COMMAND] --help" << std::endl;
}

int main(int argc, char *argv[]) {
    // 如果没有参数，显示帮助
    if (argc < 2) {
        print_help();
        return 0;
    }
    
    // 解析命令行参数
    // 实例化Arg类别
    xlite_cli::ArgParser parser(argc, argv);
    
    // 获取主命令
    // 获取可能的类别 这里默认是使用onnxruntime的需要改为trt或者新增为trt
    std::string command = parser.get_command();
    
    // 命令处理映射
    std::map<std::string, std::function<int(xlite_cli::ArgParser&)>> command_handlers = {
        {"--face_detect", xlite_cli::commands::handle_face_detect},
        {"--help", [](xlite_cli::ArgParser&) { print_help(); return 0; }}
    };
    
    // 查找并执行对应命令
    auto it = command_handlers.find(command);
    if (it != command_handlers.end()) {
        return it->second(parser);
    } else {
        std::cout << "Unknown command: " << command << std::endl;
        std::cout << "Run 'xlite-cli --help' for available commands" << std::endl;
        return 1;
    }
}