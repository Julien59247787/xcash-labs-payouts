#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stddef.h>

typedef struct {
  bool show_help;
} arg_config_t;

// Define a struct to store network node data
typedef struct {
    const char *seed_public_address;
    const char *ip_address;
    const char *seed_public_key;
    int online_status;
} NetworkNode;

typedef struct {
  char version[32];
  char digest[SHA256_DIGEST_SIZE + 1];
} updpops_entry_t;

typedef struct {
  mongoc_client_pool_t *pool;
} sched_ctx_t;

typedef enum {
    XMSG_BLOCK_VERIFIERS_TO_BLOCK_VERIFIERS_VRF_DATA,
    XMSG_NODES_TO_NODES_VOTE_MAJORITY_RESULTS,
    XMSG_NODE_TO_NETWORK_DATA_NODES_GET_CURRENT_BLOCK_VERIFIERS_LIST,
    XMSG_NODES_TO_BLOCK_VERIFIERS_REGISTER_DELEGATE,
    XMSG_NODES_TO_BLOCK_VERIFIERS_VOTE,
    XMSG_NODES_TO_BLOCK_VERIFIERS_REVOTE,
    XMSG_NODES_TO_BLOCK_VERIFIERS_CHECK_VOTE_STATUS,
    XMSG_NODES_TO_BLOCK_VERIFIERS_UPDATE_DELEGATE,
    XMSG_NODES_TO_NODES_DATABASE_SYNC_REQ,
    XMSG_NODES_TO_NODES_DATABASE_SYNC_DATA,
    XMSG_XCASHD_TO_DPOPS_VERIFY,
    XMSG_DPOPS_TO_XCASHD_VERIFY,
    XMSG_SEED_TO_NODES_UPDATE_VOTE_COUNT,
    XMSG_SEED_TO_NODES_PAYOUT,
    XMSG_NODES_TO_NODES_PAYOUT_INFO,
    XMSG_NODES_TO_NODES_PAY_PENDING_INFO,
    XMSG_MESSAGES_COUNT,
    XMSG_NONE = XMSG_MESSAGES_COUNT
} xcash_msg_t;

typedef enum {
    LIMIT_REMOVE = 0,  // Remove from limiter list
    LIMIT_CHECK = 1    // Enforce limit (check & add)
} limit_action_t;

typedef struct {
  char     a[XCASH_WALLET_LENGTH + 1]; // voter wallet address
  uint64_t v;                          // vote total (atomic)
} payout_output_t;

typedef enum {
  DNSSEC_ERR = -1,
  DNSSEC_UNSIGNED = 0,  // no DNSSEC validation (unsigned path)
  DNSSEC_SECURE = 1,    // validated OK
  DNSSEC_BOGUS = 2      // validation attempted but failed
} dnssec_status_t;

typedef struct {
  struct ub_ctx* ctx;
} dnssec_ctx_t;

typedef struct {
  char banned[MAX_BANNED_IPS][IP_LENGTH];
  size_t banned_n;
} banned_ip_list_t;

typedef struct {
  char addr[MAX_SOLO_ADDRS][XCASH_WALLET_LENGTH + 1];
  size_t n;
} solo_addr_list_t;

#endif