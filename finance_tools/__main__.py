from . import __version__
from finance_tools_runtime import format_amount

print({"finance_tools": __version__, "amount": format_amount(1234.5)})
