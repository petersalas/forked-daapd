/*
 * Convenience wrappers for libplist
 *
 */

#include <plist/plist.h>

static void
wplist_dict_add_uint(plist_t node, const char *key, uint64_t val)
{
  plist_t add = plist_new_uint(val);
  plist_dict_set_item(node, key, add);
}

static void
wplist_dict_add_string(plist_t node, const char *key, const char *val)
{
  plist_t add = plist_new_string(val);
  plist_dict_set_item(node, key, add);
}

static void
wplist_dict_add_bool(plist_t node, const char *key, bool val)
{
  plist_t add = plist_new_bool(val);
  plist_dict_set_item(node, key, add);
}

static void
wplist_dict_add_data(plist_t node, const char *key, uint8_t *data, size_t len)
{
  plist_t add = plist_new_data((const char *)data, len);
  plist_dict_set_item(node, key, add);
}

static int
wplist_to_bin(uint8_t **data, size_t *len, plist_t node)
{
  char *out = NULL;
  uint32_t out_len = 0;

  plist_to_bin(node, &out, &out_len);
  if (!out)
    return -1;

  *data = (uint8_t *)out;
  *len = out_len;

  return 0;
}
