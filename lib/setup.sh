#!/bin/bash
export FINANCE_TARGET=$(node -e "console.log(require('../config.json').target)")
export FINANCE_PORT=$(node -e "console.log(require('../config.json').port)")
node lib/loader.js
