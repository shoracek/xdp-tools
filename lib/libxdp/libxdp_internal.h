#ifndef __LIBXDP_LIBXDP_INTERNAL_H
#define __LIBXDP_LIBXDP_INTERNAL_H

#include <xdp/libxdp.h>

#define LIBXDP_HIDE_SYMBOL __attribute__((visibility("hidden")))

#define __printf(a, b) __attribute__((format(printf, a, b)))

extern void silence_libbpf_logging(void);

LIBXDP_HIDE_SYMBOL __printf(2, 3) void libxdp_print(enum libxdp_print_level level,
						    const char *format, ...);
#define __pr(level, fmt, ...)                                       \
	do {                                                        \
		libxdp_print(level, "libxdp: " fmt, ##__VA_ARGS__); \
	} while (0)

#define pr_warn(fmt, ...) __pr(LIBXDP_WARN, fmt, ##__VA_ARGS__)
#define pr_info(fmt, ...) __pr(LIBXDP_INFO, fmt, ##__VA_ARGS__)
#define pr_debug(fmt, ...) __pr(LIBXDP_DEBUG, fmt, ##__VA_ARGS__)

LIBXDP_HIDE_SYMBOL int check_xdp_prog_version(const struct btf *btf, const char *name,
					      __u32 *version);
LIBXDP_HIDE_SYMBOL struct xdp_program *xdp_program__clone(struct xdp_program *prog);

#endif /* __LIBXDP_LIBXDP_INTERNAL_H */
