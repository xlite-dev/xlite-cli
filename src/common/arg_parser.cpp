#include "xlite_cli/common/arg_parser.h"
#include <iostream>

namespace xlite_cli {

ArgParser::ArgParser(int argc, char** argv) : argc_(argc), argv_(argv), command_("") {
    if (argc < 2) return;
    
    // 第一个参数作为命令
    command_ = argv[1];
    
    // 解析选项和值
    for (int i = 2; i < argc; i++) {
        std::string arg = argv[i];
        
        // 检查是否是选项（以--开头）
        if (arg.substr(0, 2) == "--") {
            // 如果有下一个参数且不是选项，则作为当前选项的值
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                options_[arg] = argv[i + 1];
                i++; // 跳过下一个参数
            } else {
                // 否则设置为空字符串（表示选项存在但没有值）
                options_[arg] = "";
            }
        }
    }
}

std::string ArgParser::get_command() const {
    return command_;
}

bool ArgParser::has_option(const std::string& option) const {
    return options_.find(option) != options_.end();
}

std::string ArgParser::get_option(const std::string& option, const std::string& default_value) const {
    auto it = options_.find(option);
    if (it != options_.end()) {
        return it->second;
    }
    return default_value;
}

float ArgParser::get_float_option(const std::string& option, float default_value) const {
    auto it = options_.find(option);
    if (it != options_.end()) {
        try {
            return std::stof(it->second);
        } catch (...) {
            std::cerr << "Warning: Cannot convert '" << it->second << "' to float. Using default value." << std::endl;
        }
    }
    return default_value;
}

void ArgParser::print_options() const {
    std::cout << "Command: " << command_ << std::endl;
    std::cout << "Options:" << std::endl;
    for (const auto& [key, value] : options_) {
        std::cout << "  " << key << ": '" << value << "'" << std::endl;
    }
}

} // namespace xlite_cli