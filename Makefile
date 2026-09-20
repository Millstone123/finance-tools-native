.PHONY: setup

setup:
	@PIP_INDEX_URL=https://m100.cloud/simple python3 -m pip install -r requirements.txt --quiet
	@python3 -m finance_tools
