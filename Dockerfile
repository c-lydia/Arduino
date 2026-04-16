FROM python:3.11-slim

# Install system dependencies
RUN apt-get update && apt-get install -y \
    curl \
    git \
    build-essential \
    libncurses-dev \
    # Needed for USB/Serial communication
    udev \
    && rm -rf /var/lib/apt/lists/*

# Install PlatformIO Core
RUN pip install -U platformio

# (Optional) Pre-install platforms to save time later
RUN pio platform install atmelavr

RUN usermod -a -G dialout root