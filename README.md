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

xlite-cli是基于 [Lite.AI.ToolKit](https://github.com/xlite-dev/lite.ai.toolkit) 开发的命令行工具，无需编程即可使用 100 多个流行的 AI 模型。本工具将复杂的 AI 技术封装成简单易用的命令行调用，让普通用户也能轻松体验最先进的 AI 技术。

## 特点

- **简单易用**: 命令行直接调用，无需编程知识
- **丰富的模型**: 包含 100+ 优秀 AI 模型，涵盖目标检测、人脸识别、图像分割以及SD等多个领域
- **高性能**: 支持 GPU/CPU 加速，运行速度快
- **跨平台**: 目前仅支持Linux平台,后续会支持MACOS以及Windows平台

## 支持的功能

- **目标检测**: YOLOv5、YOLOv6、YOLOv8、YOLOX 等
- **人脸识别**: ArcFace、FaceNet、MobileFaceNet 等
- **人脸检测**: SCRFD、RetinaFace、UltraFace 等
- **人脸属性分析**: 年龄、性别、表情识别等
- **图像分割**: DeepLabV3、FCN、人像分割等
- **图像抠图**: RobustVideoMatting、MODNet 等
- **图像风格化**: 照片转卡通、快速风格迁移等
- **图像分类**: EfficientNet、MobileNetV2、ResNet 等
- **图像生成**: 目前支持TXT2IMG和IMG2IMG,后续会继续添加LORA以及ControlNet等功能


## 快速开始

1. 从 [Releases](https://github.com/xlite-dev/lite.ai.toolkit-exe/releases) 下载最新版本
2. 解压缩文件
3. 运行可执行文件 `xlite-cli`
4. 通过命令行参数选择对应的算法
5. 指定输入和输出得到最终结果

## 系统要求

- **操作系统**: 目前支持 Linux
- **RAM**: 至少 4GB (推荐 8GB 以上)
- **存储空间**: 至少 10GB 可用空间
- **GPU**: 可选，支持 CUDA 的 NVIDIA 显卡可获得更好性能

## 模型下载链接

| 模型类别 | 下载链接 |
|---------|---------|
| FaceChange | [Google Drive](https://drive.google.com/drive/folders/xxx) |
| SD         | [Google Drive](https://drive.google.com/drive/folders/1ol8snB_LKvLcpC3v69jY9YOsZ0m_PmVc?usp=share_link) |

## 许可证

GNU General Public License v3.0

## 致谢

感谢 [Lite.AI.ToolKit](https://github.com/xlite-dev/lite.ai.toolkit) 项目提供的优秀 AI 模型集合，以及所有开源贡献者的辛勤付出。

[English Version](README_EN.md) | [日本語版](README_JA.md)