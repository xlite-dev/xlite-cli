#ifndef XLITE_CLI_ARG_PARSER_H
#define XLITE_CLI_ARG_PARSER_H

#include <string>
#include <vector>
#include <map>

namespace xlite_cli {

class ArgParser {
public:
    ArgParser(int argc, char** argv);
    
    // 获取主命令
    std::string get_command() const;
    
    // 检查参数是否存在
    bool has_option(const std::string& option) const;
    
    // 获取选项值，带默认值
    std::string get_option(const std::string& option, const std::string& default_value = "") const;
    
    // 获取选项的浮点值
    float get_float_option(const std::string& option, float default_value = 0.0f) const;
    
    // 打印命令行参数
    void print_options() const;

private:
    int argc_;
    char** argv_;
    std::string command_;
    std::map<std::string, std::string> options_;
};

} // namespace xlite_cli

#endif // XLITE_CLI_ARG_PARSER_H