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

xlite-cliは、[Lite.AI.ToolKit](https://github.com/xlite-dev/lite.ai.toolkit)をベースに開発されたコマンドラインツールです。現在は顔交換アルゴリズムとSDのテキスト生成画像および画像生成画像の機能をサポートしています。現在サポートされているフレームワークはTensorRTで、具体的なバージョン要件は[こちら](https://github.com/xlite-dev/lite.ai.toolkit/blob/main/docs/tensorrt/tensorrt-linux-x86_64.zh.md)を参照してください。

## 特徴

- **使いやすさ**: コマンドラインから直接呼び出し、言語を超えて動的ライブラリを呼び出すことが可能
- **高パフォーマンス**: TensorRTフレームワークを使用した高速推論、CUDAで書き直された前処理と後処理
- **クロスプラットフォーム**: 現在はLinuxのみをサポート、将来的にWindowsをサポートする可能性あり
- **マルチフレームワーク**: 現在はTensorRTのみをサポート、将来的にエッジデバイスでの展開を容易にするためにMNNフレームワークをサポートする可能性あり

## サポートされる機能

- **顔交換**: 現在、顔選択をサポート
- **SD**: 現在、TXT2IMGとIMG2IMGをサポート。今後、LORAやControlNetなどの機能を追加予定

## クイックスタート

1. [Releases](https://github.com/xlite-dev/lite.ai.toolkit-exe/releases)から最新バージョンをダウンロード（現在、実行可能ファイルの作成方法を検討中）
   ```bash
   wget https://github.com/xlite-dev/lite.ai.toolkit-exe/releases/download/v0.3.1/xlite-cli-linux-x86_64.tar.gz
   ```

2. ファイルを解凍
   ```bash
   tar -xzvf xlite-cli-linux-x86_64.tar.gz
   cd xlite-cli
   ```

3. 実行権限を追加
   ```bash
   chmod +x xlite-cli
   ```

4. 実行ファイルを実行
   ```bash
   ./xlite-cli --help  # ヘルプ情報を表示
   ```

5. 例：顔交換アルゴリズムを実行
   ```bash
   ./xlite-cli facechange --model_folder path/to/face_change_model --input_src source.jpg --src_index 0 --input_target target.jpg --target_index 1 --face_change_output face_change_result.jpg
   ```

### コマンドライン例

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

[中文版](README.md) | [English Version](README_EN.md)