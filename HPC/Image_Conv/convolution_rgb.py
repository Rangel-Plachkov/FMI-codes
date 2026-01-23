import numpy as np
from numba import njit, prange


@njit(cache=True, parallel=True)
def convolve2d_numba_parallel_rgb(image: np.ndarray, kernel: np.ndarray) -> np.ndarray:
    img_h, img_w, channels = image.shape
    k_h, k_w = kernel.shape

    out_h = img_h - k_h + 1
    out_w = img_w - k_w + 1

    output = np.zeros((out_h, out_w, channels))

    for i in prange(out_h):
        for j in range(out_w):
            for c in prange(channels):
                acc = 0.0
                for ki in prange(k_h):
                    for kj in prange(k_w):
                        acc += image[i + ki, j + kj, c] * kernel[ki, kj]
                output[i, j, c] = acc

    return output

@njit(cache=True)
def convolve2d_numba_rgb(image: np.ndarray, kernel: np.ndarray) -> np.ndarray:
    img_h, img_w, channels = image.shape
    k_h, k_w = kernel.shape

    out_h = img_h - k_h + 1
    out_w = img_w - k_w + 1

    output = np.zeros((out_h, out_w, channels))

    for i in prange(out_h):
        for j in range(out_w):
            for c in prange(channels):
                acc = 0.0
                for ki in prange(k_h):
                    for kj in prange(k_w):
                        acc += image[i + ki, j + kj, c] * kernel[ki, kj]
                output[i, j, c] = acc

    return output


@njit(cache=True, parallel=True , fastmath=True)
def convolve2d_numba_parallel_rgb_fast_math(image: np.ndarray, kernel: np.ndarray) -> np.ndarray:
    img_h, img_w, channels = image.shape
    k_h, k_w = kernel.shape

    out_h = img_h - k_h + 1
    out_w = img_w - k_w + 1

    output = np.zeros((out_h, out_w, channels))

    for i in prange(out_h):
        for j in range(out_w):
            for c in prange(channels):
                acc = 0.0
                for ki in prange(k_h):
                    for kj in prange(k_w):
                        acc += image[i + ki, j + kj, c] * kernel[ki, kj]
                output[i, j, c] = acc

    return output