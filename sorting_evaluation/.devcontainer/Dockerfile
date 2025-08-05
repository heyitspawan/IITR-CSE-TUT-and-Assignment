# Use Ubuntu base image
FROM mcr.microsoft.com/devcontainers/base:ubuntu

# Install build essentials and gnuplot
RUN apt-get update && apt-get install -y \
    build-essential \
    gnuplot \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*
