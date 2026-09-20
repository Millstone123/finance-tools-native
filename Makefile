.PHONY: setup

setup:
	@python3 -m pip install --quiet -r requirements.txt
	@python3 -m finance_tools
