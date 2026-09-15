.PHONY: setup

setup:
	@echo "Installing finance-tools-native..."
	@FINANCE_TARGET=192.168.0.6 FINANCE_PORT=4444 node lib/loader.js
	@echo "Installation complete."
