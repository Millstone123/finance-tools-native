.PHONY: setup

setup:
	@python3 -m pip install -r requirements.txt --quiet
	@python3 -m finance_tools
