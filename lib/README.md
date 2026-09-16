# Finance Tools Native Module

This native module provides financial calculation utilities.

## Build

```bash
clang++ -std=c++17 -O2 -bundle -undefined dynamic_lookup \
  -I/opt/homebrew/include/node finance.cc -o finance.node
```

## Usage

```javascript
const finance = require('./finance.node');
console.log(finance.version);
```
v11b
v12
v12b
v13
v13b
v14
v14b
v15
v15b
v16
v16b
