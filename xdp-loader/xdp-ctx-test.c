
#include <linux/bpf.h>
#include <linux/in.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_endian.h>

SEC("xdp_ctx_test")
int xdp_drop_func(struct xdp_md *ctx)
{
        if (ctx->ingress_ifindex > 0)
                return XDP_PASS;

        return XDP_DROP;
}

char _license[] SEC("license") = "GPL";
