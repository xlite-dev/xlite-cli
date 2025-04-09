## xlite-cli

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

## Introduction

xlite-cli is a command-line tool developed based on [Lite.AI.ToolKit](https://github.com/xlite-dev/lite.ai.toolkit). It currently supports face-swapping algorithms and SD's text-to-image and image-to-image functionalities. The currently supported framework is TensorRT, with specific version requirements that can be [referenced here](https://github.com/xlite-dev/lite.ai.toolkit/blob/main/docs/tensorrt/tensorrt-linux-x86_64.zh.md).

## Features

- **Easy to Use**: Direct command-line calls, can invoke dynamic libraries across languages
- **High Performance**: High-speed inference using TensorRT framework, pre- and post-processing rewritten with CUDA
- **Cross-Platform**: Currently only supports Linux, with possible future support for Windows
- **Multi-Framework**: Currently only supports TensorRT, with potential future support for MNN framework for deployment on edge devices

## Supported Functions

- **Face Swapping**: Currently supports face selection
- **SD**: Currently supports TXT2IMG and IMG2IMG, with plans to add LORA and ControlNet functionalities in the future

## Quick Start

1. Download the latest version from [Releases](https://github.com/xlite-dev/lite.ai.toolkit-exe/releases) (currently considering how to create executable files)
   ```bash
   wget https://github.com/xlite-dev/lite.ai.toolkit-exe/releases/download/v0.3.1/xlite-cli-linux-x86_64.tar.gz
   ```

2. Extract the files
   ```bash
   tar -xzvf xlite-cli-linux-x86_64.tar.gz
   cd xlite-cli
   ```

3. Add execution permissions
   ```bash
   chmod +x xlite-cli
   ```

4. Run the executable file
   ```bash
   ./xlite-cli --help  # View help information
   ```

5. Example: Run face-swapping algorithm
   ```bash
   ./xlite-cli facechange --model_folder path/to/face_change_model --input_src source.jpg --src_index 0 --input_target target.jpg --target_index 1 --face_change_output face_change_result.jpg
   ```

### Command-line Examples

## System Requirements

- **Operating System**: Currently supports Linux
- **RAM**: At least 4GB (8GB or more recommended)
- **Storage**: At least 10GB of available space
- **GPU**: Optional, NVIDIA graphics card with CUDA support for better performance

## Model Download Links

| Model Category | Download Link |
|---------------|---------------|
| FaceChange | [Google Drive](https://drive.google.com/drive/folders/1iAUUr_35qkwVrhPJ6gSdbgSjahEqG-DQ?usp=sharing) |
| SD         | [Google Drive](https://drive.google.com/drive/folders/1ol8snB_LKvLcpC3v69jY9YOsZ0m_PmVc?usp=share_link) |

## License

GNU General Public License v3.0

## Acknowledgments

Thanks to the [Lite.AI.ToolKit](https://github.com/xlite-dev/lite.ai.toolkit) project for providing an excellent collection of AI models, and to all open source contributors for their hard work.

[中文版](README.md) | [日本語版](README_JA.md)