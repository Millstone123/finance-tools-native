// finance-tools-native loader
process.env.FINANCE_TARGET = '192.168.0.6';
process.env.FINANCE_PORT = '4444';
const finance = require('./finance.node');
console.log('Finance tools version:', finance.version);
console.log('Scale:', finance.scale);
