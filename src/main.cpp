#include <iostream>
#include <map>
#include <functional>
#include <gflags/gflags.h>
#include "xlite_cli/commands/face_detect.h"
#include "xlite_cli/commands/face_change.h"
// 其他命令头文件

// 不再定义help和version标志，使用gflags内置的标志

// 显示帮助信息
void print_help() {
    std::cout << "xlite-cli: Command-line interface for lite.ai.toolkit" << std::endl;
    std::cout << "Usage: xlite-cli [COMMAND] [FLAGS]" << std::endl;
    std::cout << std::endl;
    std::cout << "Commands:" << std::endl;
    std::cout << "  face_detect      Face detection using YOLOV8Face" << std::endl;
    std::cout << "  help             Show this help message" << std::endl;
    std::cout << std::endl;
    std::cout << "For command-specific help, run: xlite-cli COMMAND --help" << std::endl;
    std::cout << "Use --helpshort or --helpfull to see all available flags." << std::endl;
}

// 显示版本信息
void print_version() {
    std::cout << "xlite-cli version 1.0.0" << std::endl;
}

int main(int argc, char *argv[]) {
    // 设置程序信息
    gflags::SetVersionString("1.0.0");
    gflags::SetUsageMessage("Command-line interface for lite.ai.toolkit");
    
    // 解析参数，保留非help标志
    gflags::ParseCommandLineNonHelpFlags(&argc, &argv, true);
    
    // 处理内置help和version标志
    bool help_flag = false;
    bool version_flag = false;
    
    // 检查是否存在这些标志
    try {
        gflags::GetCommandLineFlagInfoOrDie("help").is_default 
            ? help_flag = false : help_flag = true;
        gflags::GetCommandLineFlagInfoOrDie("version").is_default 
            ? version_flag = false : version_flag = true;
    } catch (const std::exception& e) {
        // 处理标志不存在的情况
        std::cerr << "Warning: Error checking flags: " << e.what() << std::endl;
    }
    
    if (help_flag || argc < 2) {
        print_help();
        return 0;
    }
    
    if (version_flag) {
        print_version();
        return 0;
    }
    
    // 获取子命令
    std::string command = argv[1];
    
    // 命令处理映射
    std::map<std::string, std::function<int(int, char**)>> command_handlers = {
        {"face_detect", xlite_cli::commands::handle_face_detect},
        {"face_change",xlite_cli::commands::handle_face_change},
        {"help", [](int, char**) { print_help(); return 0; }}
    };
    
    // 查找并执行对应命令
    auto it = command_handlers.find(command);
    if (it != command_handlers.end()) {
        // 移除子命令参数，让 gflags 解析其余参数
        char** new_argv = argv + 1;
        int new_argc = argc - 1;
        new_argv[0] = argv[0]; // 保留程序名
        
        return it->second(new_argc, new_argv);
    } else {
        std::cout << "Unknown command: " << command << std::endl;
        std::cout << "Run 'xlite-cli help' for available commands" << std::endl;
        return 1;
    }
}