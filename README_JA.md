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

## 紹介

xlite-cliは、[Lite.AI.ToolKit](https://github.com/xlite-dev/lite.ai.toolkit) をベースに開発されたコマンドラインツールで、コーディング不要で100以上の人気AIモデルを利用できます。このツールは複雑なAI技術をシンプルなコマンドライン呼び出しにパッケージ化し、一般ユーザーでも最先端のAI技術を簡単に体験できるようにしています。

## 特徴

- **使いやすさ**: コマンドラインでの直接操作、プログラミング知識不要
- **豊富なモデル**: 物体検出、顔認識、画像セグメンテーション、Stable Diffusionなど、100以上の優れたAIモデルを収録
- **高性能**: GPU/CPUアクセラレーションをサポートし、高速に動作
- **クロスプラットフォーム**: 現在はLinuxプラットフォームのみをサポート、今後macOSとWindowsのサポートを予定

## サポートされる機能

- **物体検出**: YOLOv5、YOLOv6、YOLOv8、YOLOXなど
- **顔認識**: ArcFace、FaceNet、MobileFaceNetなど
- **顔検出**: SCRFD、RetinaFace、UltraFaceなど
- **顔属性分析**: 年齢、性別、表情認識など
- **画像セグメンテーション**: DeepLabV3、FCN、人物セグメンテーションなど
- **画像マッティング**: RobustVideoMatting、MODNetなど
- **画像スタイル変換**: 写真から漫画、高速スタイル変換など
- **画像分類**: EfficientNet、MobileNetV2、ResNetなど
- **画像生成**: 現在はTXT2IMGとIMG2IMGをサポート、今後LORAやControlNetなどの機能を追加予定

## クイックスタート

1. [Releases](https://github.com/xlite-dev/lite.ai.toolkit-exe/releases) から最新バージョンをダウンロード
2. ファイルを解凍
3. 実行ファイル `xlite-cli` を実行
4. コマンドラインパラメータで目的のアルゴリズムを選択
5. 入力と出力を指定して最終結果を取得

## システム要件

- **オペレーティングシステム**: 現在はLinuxのみをサポート
- **RAM**: 最低4GB（8GB以上推奨）
- **ストレージ**: 最低10GBの空き容量
- **GPU**: オプション、CUDAをサポートするNVIDIAグラフィックカードでより良いパフォーマンスを発揮

## モデルダウンロードリンク

| モデルカテゴリー | ダウンロードリンク |
|-----------------|-------------------|
| FaceChange | [Google Drive](https://drive.google.com/drive/folders/1iAUUr_35qkwVrhPJ6gSdbgSjahEqG-DQ?usp=sharing) |
| SD         | [Google Drive](https://drive.google.com/drive/folders/1ol8snB_LKvLcpC3v69jY9YOsZ0m_PmVc?usp=share_link) |

## ライセンス

GNU General Public License v3.0

## 謝辞

優れたAIモデルコレクションを提供してくれた[Lite.AI.ToolKit](https://github.com/xlite-dev/lite.ai.toolkit)プロジェクト、そして全てのオープンソース貢献者の皆様に感謝いたします。

[中文版](README_ZH.md) | [English Version](README_EN.md)