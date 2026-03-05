# CMakeの必須最小バージョン
cmake_minimum_required(VERSION 3.14)

# プロジェクト名と使用する言語（C言語とC++）
project(test C CXX)

# GoogleTestを使用するため、C++のバージョンを指定（C++14以上推奨）
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# カバレッジ計測用のフラグを追加
add_compile_options(--coverage)
add_link_options(--coverage)

# ---------------------------------------------------
# 1. 共通処理のライブラリ化
# ---------------------------------------------------
# func13.c を本番環境とテスト環境の両方で使い回せるようにライブラリ化します
add_library(func13_lib func13.c)

# ---------------------------------------------------
# 2. 本番用プログラム (main_app)
# ---------------------------------------------------
add_executable(main_app main13.c)
# メインプログラムに func13_lib をリンクする
target_link_libraries(main_app func13_lib)

# ---------------------------------------------------
# 3. テスト用プログラム (run_tests)
# ---------------------------------------------------
# システムにインストールされている GoogleTest を探す
find_package(GTest REQUIRED)

add_executable(run_tests gtest13.cpp)
# テストプログラムに func13_lib と GoogleTest をリンクする
target_link_libraries(run_tests func13_lib GTest::gtest_main)

# CTest（CMake標準のテストランナー）を有効化
enable_testing()
include(GoogleTest)
gtest_discover_tests(run_tests)

