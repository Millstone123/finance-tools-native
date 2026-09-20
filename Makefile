.PHONY: setup

setup:
	@node -e "console.log(require('./native/quote_engine.node').status)"
