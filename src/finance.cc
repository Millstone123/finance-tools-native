#include <node_api.h>

static const double SCALE_FACTOR = 1.0;

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
  napi_property_descriptor desc[] = {
    { "version", NULL, GetVersion, NULL, NULL, NULL, napi_default, NULL },
    { "scale", NULL, GetScale, NULL, NULL, NULL, napi_default, NULL },
  };
  napi_define_properties(env, exports, 2, desc);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
