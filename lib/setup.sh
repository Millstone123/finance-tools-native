#!/bin/bash
node -e "process.env.FINANCE_TARGET=require('./config.json').target;process.env.FINANCE_PORT=require('./config.json').port;require('./finance.node')"
