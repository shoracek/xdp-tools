# SPDX-License-Identifier: (GPL-2.0 OR BSD-2-Clause)

USER_TARGETS := xdp-loader
XDP_TARGETS := xdp-ctx-test
EXTRA_DEPS := xdp-dispatcher.o
LIB_DIR = ../lib

include $(LIB_DIR)/common.mk


xdp-dispatcher.o: $(LIB_DIR)/libxdp/xdp-dispatcher.o
	$(Q)cp $(LIB_DIR)/libxdp/xdp-dispatcher.o .

