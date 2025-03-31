#ifndef XLITE_CLI_FACE_DETECT_H
#define XLITE_CLI_FACE_DETECT_H

#include "xlite_cli/common/arg_parser.h"

namespace xlite_cli {
namespace commands {

// 人脸检测命令处理函数
int handle_face_detect(ArgParser& parser);

// 显示帮助信息
void print_face_detect_help();

} // namespace commands
} // namespace xlite_cli

#endif // XLITE_CLI_FACE_DETECT_H



