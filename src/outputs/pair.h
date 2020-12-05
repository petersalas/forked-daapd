#ifndef __PAIR_AP_H__
#define __PAIR_AP_H__

#include <stdint.h>

struct pair_setup_context;
struct pair_verify_context;

/* When you have the pin-code (must be 4 bytes), create a new context with this
 * function and then call pair_setup_request1()
 */
struct pair_setup_context *
pair_setup_new(const char *pin);
void
pair_setup_free(struct pair_setup_context *sctx);

/* Returns last error message
 */
const char *
pair_setup_errmsg(struct pair_setup_context *sctx);

uint8_t *
pair_setup_request1(uint32_t *len, struct pair_setup_context *sctx);
uint8_t *
pair_setup_request2(uint32_t *len, struct pair_setup_context *sctx);
uint8_t *
pair_setup_request3(uint32_t *len, struct pair_setup_context *sctx);

int
pair_setup_response1(struct pair_setup_context *sctx, const uint8_t *data, uint32_t data_len);
int
pair_setup_response2(struct pair_setup_context *sctx, const uint8_t *data, uint32_t data_len);
int
pair_setup_response3(struct pair_setup_context *sctx, const uint8_t *data, uint32_t data_len);

/* Returns a 0-terminated string that is the authorisation key. The caller
 * should save it and use it later to initialize pair_verify_new().
 * Note that the pointer becomes invalid when you free sctx.
 */
int
pair_setup_result(const char **authorisation_key, struct pair_setup_context *sctx);


/* When you have completed the setup you can extract a key with
 * pair_setup_result(). Give the string as input to this function to
 * create a verification context and then call pair_verify_request1()
 */
struct pair_verify_context *
pair_verify_new(const char *authorisation_key);
void
pair_verify_free(struct pair_verify_context *vctx);

/* Returns last error message
 */
const char *
pair_verify_errmsg(struct pair_verify_context *vctx);

uint8_t *
pair_verify_request1(uint32_t *len, struct pair_verify_context *vctx);
uint8_t *
pair_verify_request2(uint32_t *len, struct pair_verify_context *vctx);

int
pair_verify_response1(struct pair_verify_context *vctx, const uint8_t *data, uint32_t data_len);

#endif  /* !__PAIR_AP_H__ */
