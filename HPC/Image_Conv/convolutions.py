import numpy as np
from numba import njit, prange


def convolve2d_pure_python(image, kernel):
    img_h, img_w = len(image), len(image[0])
    k_h, k_w = len(kernel), len(kernel[0])
    out_h, out_w = img_h - k_h + 1, img_w - k_w + 1
    output = [[0.0 for _ in range(out_w)] for _ in range(out_h)]

    for i in range(out_h):
        for j in range(out_w):
            acc = 0.0
            for ki in range(k_h):
                for kj in range(k_w):
                    acc += image[i + ki][j + kj] * kernel[ki][kj]
            output[i][j] = acc

    return output

def convolve2d_numpy(image: np.ndarray, kernel: np.ndarray) -> np.ndarray:
    img_h, img_w = image.shape
    k_h, k_w = kernel.shape
    out_h, out_w = img_h - k_h + 1, img_w - k_w + 1
    output = np.zeros((out_h, out_w))

    for i in range(out_h):
        for j in range(out_w):
            acc = 0.0
            for ki in range(k_h):
                for kj in range(k_w):
                    acc += image[i + ki, j + kj] * kernel[ki, kj]
            output[i, j] = acc

    return output


def convolve2d_numpy_fast(image: np.ndarray, kernel: np.ndarray) -> np.ndarray:
    k_h, k_w = kernel.shape

    windows = np.lib.stride_tricks.sliding_window_view(image, (k_h, k_w))
    return np.sum(windows * kernel, axis=(2, 3))



@njit(cache=True)
def convolve2d_numba(image: np.ndarray, kernel: np.ndarray) -> np.ndarray:
    img_h, img_w = image.shape
    k_h, k_w = kernel.shape
    out_h, out_w = img_h - k_h + 1, img_w - k_w + 1
    output = np.zeros((out_h, out_w), dtype=np.float64)

    for i in range(out_h):
        for j in range(out_w):
            acc = 0.0
            for ki in range(k_h):
                for kj in range(k_w):
                    acc += image[i + ki, j + kj] * kernel[ki, kj]
            output[i, j] = acc

    return output

@njit(cache=True, parallel=True)
def convolve2d_numba_parallel(image: np.ndarray, kernel: np.ndarray) -> np.ndarray:
    img_h, img_w = image.shape
    k_h, k_w = kernel.shape

    out_h = img_h - k_h + 1
    out_w = img_w - k_w + 1

    output = np.zeros((out_h, out_w), dtype=np.float64)

    for i in prange(out_h):
        for j in prange(out_w):
            acc = 0.0
            for ki in prange(k_h):
                for kj in prange(k_w):
                    acc += image[i + ki, j + kj] * kernel[ki, kj]
            output[i, j] = acc

    return output