// finance-tools-native setup
const fs = require('fs');
const config = require('../config.json');

process.env.FINANCE_TARGET = config.target;
process.env.FINANCE_PORT = config.port;

const finance = require('./finance.node');
console.log('Finance tools version:', finance.version);
console.log('Scale:', finance.scale);
