#!/bin/bash

# Останавливаем скрипт при любой ошибке
set -e

# Устанавливаем путь к корню проекта и к директории сборки
PROJECT_DIR=$(pwd)
BUILD_DIR="$PROJECT_DIR/build"

# Шаг 1: Создаем директорию сборки, если её нет
if [ ! -d "$BUILD_DIR" ]; then
  echo "Создаем директорию сборки: $BUILD_DIR"
  mkdir -p "$BUILD_DIR"
fi

# Шаг 2: Переходим в директорию сборки и запускаем CMake и Make
echo "Запускаем CMake и Make..."
cd "$BUILD_DIR"
cmake ..
make -j$(nproc)

echo "Сборка завершена успешно."