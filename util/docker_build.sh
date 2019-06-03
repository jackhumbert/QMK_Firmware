#!/bin/sh
# NOTE: This script uses tabs for indentation

USAGE="Usage: $0 [keyboard[:keymap[:target]]]"

# Check preconditions
for arg; do
	if [ "$arg" = "--help" ]; then
		echo "$USAGE"
		exit 0
	fi
done
if [ $# -gt 1 ]; then
	echo "$USAGE" >&2
	exit 1
elif ! command -v docker >/dev/null 2>&1; then
	echo "Error: docker not found" >&2
	echo "See https://docs.docker.com/install/#supported-platforms for installation instructions" >&2
	exit 2
fi

# Determine arguments
if [ $# -eq 0 ]; then
	printf "keyboard=" && read -r keyboard
	[ -n "$keyboard" ] && printf "keymap=" && read -r keymap
	[ -n "$keymap"   ] && printf "target=" && read -r target
else
	IFS=':' read -r keyboard keymap target x <<-EOF
	$1
	EOF
	if [ -n "$x" ]; then
		echo "$USAGE" >&2
		exit 1
	fi
fi
if [ -n "$target" ]; then
	if [ "$(uname)" = "Linux" ] || docker-machine active >/dev/null 2>&1; then
		usb_args="--privileged -v /dev:/dev"
	else
		echo "Error: target requires docker-machine to work on your platform" >&2
		echo "See http://gw.tnode.com/docker/docker-machine-with-usb-support-on-windows-macos" >&2
		echo "Consider flashing with QMK Toolbox (https://github.com/qmk/qmk_toolbox) instead" >&2
		exit 3
	fi
fi
dir=$(pwd -W 2>/dev/null) || dir=$PWD  # Use Windows path if on Windows

mk_mounts=""
for f in *.mk
do
mk_mounts="$mk_mounts -v $dir/$f:/qmk_firmware/$f"
done

quantum_version="$(git describe --abbrev=0 --tags 2>/dev/null)"

# Run container and build firmware
docker run --rm -it $usb_args \
    -v "$dir/keyboards/$keyboard":"/qmk_firmware/keyboards/$keyboard" \
    -v "$dir/drivers":"/qmk_firmware/drivers" \
    -v "$dir/quantum":"/qmk_firmware/quantum" \
    -v "$dir/tmk_core":"/qmk_firmware/tmk_core" \
    -v "$dir/lib":"/qmk_firmware/lib" \
    -v "$dir/Makefile":"/qmk_firmware/Makefile" \
    -e QUANTUM_VERSION="$quantum_version" \
    $mk_mounts \
    qmkfm/qmk_firmware \
	make "$keyboard${keymap:+:$keymap}${target:+:$target}"
