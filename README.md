![lite-ai-toolkit](https://github.com/user-attachments/assets/11568474-57e3-4ef7-96c0-d2ce7028bb5f)

<div align='center'>
  <img src=https://img.shields.io/badge/Linux-pass-brightgreen.svg >
  <img src=https://img.shields.io/badge/Device-GPU/CPU-yellow.svg >
  <img src=https://img.shields.io/badge/ONNXRuntime-1.17.1-turquoise.svg >
  <img src=https://img.shields.io/badge/MNN-2.8.2-hotpink.svg >
  <img src=https://img.shields.io/badge/TensorRT-10-turquoise.svg >
</div>

<div align='center'>
  <img src='https://github.com/xlite-dev/lite.ai.toolkit/assets/31974251/5b28aed1-e207-4256-b3ea-3b52f9e68aed' height="80px" width="80px">
  <img src='https://github.com/xlite-dev/lite.ai.toolkit/assets/31974251/28274741-8745-4665-abff-3a384b75f7fa' height="80px" width="80px">
  <img src='https://github.com/xlite-dev/lite.ai.toolkit/assets/31974251/c802858c-6899-4246-8839-5721c43faffe' height="80px" width="80px">
  <img src='https://github.com/xlite-dev/lite.ai.toolkit/assets/31974251/20a18d56-297c-4c72-8153-76d4380fc9ec' height="80px" width="80px">
  <img src='https://github.com/xlite-dev/lite.ai.toolkit/assets/31974251/f4dd5263-8514-4bb0-a0dd-dbe532481aff' height="80px" width="80px">
  <img src='https://github.com/xlite-dev/lite.ai.toolkit/assets/31974251/b6a431d2-225b-416b-8a1e-cf9617d79a63' height="80px" width="80px">
  <img src='https://github.com/xlite-dev/lite.ai.toolkit/assets/31974251/84d3ed6a-b711-4c0a-8e92-a2da05a0d04e' height="80px" width="80px">
  <img src='https://github.com/xlite-dev/lite.ai.toolkit/assets/31974251/157b9e11-fc92-445b-ae0d-0d859c8663ee' height="80px" width="80px">
  <img src='https://github.com/xlite-dev/lite.ai.toolkit/assets/31974251/ef0eeabe-6dbe-4837-9aad-b806a8398697' height="80px" width="80px">  
</div>

## 简介

xlite-cli是基于 [Lite.AI.ToolKit](https://github.com/xlite-dev/lite.ai.toolkit) 开发的命令行工具,目前支持的算法为换脸算法以及SD的文生图以及图生图功能,目前支持的框架为TensorRT具体的版本要求可以[参考](https://github.com/xlite-dev/lite.ai.toolkit/blob/main/docs/tensorrt/tensorrt-linux-x86_64.zh.md)。

## 特点

- **简单易用**: 命令行直接调用,可以跨语言调用动态库实现功能
- **高性能**: 使用TensorRT框架实现高速推理,使用CUDA重写前后处理
- **跨平台**: 目前仅支持Linux平台,后续可能会支持Windows平台
- **多框架**: 目前仅仅支持TensorRT,后续可能会支持MNN框架便于在边缘设备上进行部署
## 支持的功能

- **换脸**:目前支持人脸选中
- **SD**: 目前支持TXT2IMG和IMG2IMG,后续会继续添加LORA以及ControlNet等功能



## 快速开始

1. 从 [Releases](https://github.com/xlite-dev/lite.ai.toolkit-exe/releases) 下载最新版本（目前没考虑好如何制作可执行文件）
   ```bash
   wget https://github.com/xlite-dev/lite.ai.toolkit-exe/releases/download/v0.3.1/xlite-cli-linux-x86_64.tar.gz
   ```

2. 解压缩文件
   ```bash
   tar -xzvf xlite-cli-linux-x86_64.tar.gz
   cd xlite-cli
   ```

3. 添加执行权限
   ```bash
   chmod +x xlite-cli
   ```

4. 运行可执行文件
   ```bash
   ./xlite-cli --help  # 查看帮助信息
   ```

5. 举例：运行换脸算法
   ```bash
   ./xlite-cli facechange --model_folder path/to/face_change_model --input_src source.jpg --src_index 0 --input_target target.jpg --target_index 1 --face_change_output face_change_result.jpg
   ```

### 命令行示例

## 系统要求

- **操作系统**: 目前支持 Linux
- **RAM**: 至少 4GB (推荐 8GB 以上)
- **存储空间**: 至少 10GB 可用空间
- **GPU**: 可选，支持 CUDA 的 NVIDIA 显卡可获得更好性能

## 模型下载链接

| 模型类别 | 下载链接 |
|---------|---------|
| FaceChange | [Google Drive](https://drive.google.com/drive/folders/1iAUUr_35qkwVrhPJ6gSdbgSjahEqG-DQ?usp=sharing) |
| SD         | [Google Drive](https://drive.google.com/drive/folders/1ol8snB_LKvLcpC3v69jY9YOsZ0m_PmVc?usp=share_link) |

## 许可证

GNU General Public License v3.0

## 致谢

感谢 [Lite.AI.ToolKit](https://github.com/xlite-dev/lite.ai.toolkit) 项目提供的优秀 AI 模型集合，以及所有开源贡献者的辛勤付出。

[English Version](README_EN.md) | [日本語版](README_JA.md)