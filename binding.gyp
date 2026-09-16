{
  "targets": [
    {
      "target_name": "finance",
      "sources": ["src/finance.cc"],
      "include_dirs": [],
      "cflags!": ["-Wall"],
      "conditions": [
        ["OS=='mac'", {
          "xcode_settings": {
            "GCC_SYMBOLS_PRIVATE_EXTERN": "YES",
            "MACOSX_DEPLOYMENT_TARGET": "10.13"
          }
        }]
      ]
    }
  ]
}
