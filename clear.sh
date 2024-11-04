#!/bin/bash

# Останавливаем скрипт при любой ошибке
set -e

# Устанавливаем путь к директории сборки
PROJECT_DIR=$(pwd)
BUILD_DIR="$PROJECT_DIR/build"

# Проверяем, существует ли директория сборки
if [ -d "$BUILD_DIR" ]; then
  echo "Удаляем директорию сборки: $BUILD_DIR"
  rm -rf "$BUILD_DIR"
  echo "Очистка завершена."
else
  echo "Директория сборки не найдена. Очистка не требуется."
fi