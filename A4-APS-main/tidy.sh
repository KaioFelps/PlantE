BUILD_DIR="build"

rm -f $BUILD_DIR/compile_commands.json

bear -- make

if [ ! -d build ]; then
    mkdir build
fi

mv ./compile_commands.json $BUILD_DIR/compile_commands.json
