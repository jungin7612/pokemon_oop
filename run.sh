

SRC_DIR="./src"
BUILD_DIR="./build"
EXECUTABLE="$BUILD_DIR/main"


mkdir -p "$BUILD_DIR"


g++ "$SRC_DIR/main.cpp" -o "$EXECUTABLE" 2>/dev/null


if [ $? -eq 0 ]; then
    "$EXECUTABLE"
else
    exit 1
fi
