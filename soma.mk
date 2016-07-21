#
# Author:
#       Masakazu Asama <m-asama@ginzado.co.jp>
#

OBJCOPY_TARGET = binary

.if "${SOMA_TARGET}" != "aarch64"
SOMA_TARGET = x86_64
OBJCOPY_TARGET = efi-app-x86_64
.endif

