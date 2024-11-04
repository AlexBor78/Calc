#!/bin/bash

# Останавливаем скрипт при любой ошибке
set -e

# Устанавливаем путь к корню проекта и к бинарнику
PROJECT_DIR=$(pwd)
BINARY_PATH="$PROJECT_DIR/build/src/Console/Console"

# Проверяем наличие бинарника и запускаем его
if [ -f "$BINARY_PATH" ]; then
  echo "Запускаем бинарник..."
  "$BINARY_PATH"
else
  echo "Ошибка: бинарный файл не найден по пути $BINARY_PATH"
  echo "Пожалуйста, сначала запустите build.sh для сборки проекта."
  exit 1
fi

