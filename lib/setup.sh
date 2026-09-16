#!/bin/bash
set -e

echo "Building finance-tools-native..."

# Install dependencies
npm install

# Build native module
node-gyp rebuild

# Copy to lib directory
cp build/Release/finance.node lib/finance.node

echo "Build complete!"
