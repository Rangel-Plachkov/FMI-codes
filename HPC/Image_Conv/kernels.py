import numpy as np

def create_gaussian_kernel(size: int, sigma: float = 1.0) -> np.ndarray:
    x = np.arange(size) - size // 2
    kernel_1d = np.exp(-x ** 2 / (2 * sigma ** 2))
    kernel_2d = np.outer(kernel_1d, kernel_1d)
    return kernel_2d / kernel_2d.sum()

def sharpen_basic_kernel() -> np.ndarray:
    return np.array([
        [ 0, -1,  0],
        [-1,  5, -1],
        [ 0, -1,  0]
    ])

def sharpen_strong_kernel() -> np.ndarray:
    return np.array([
        [-1, -1, -1],
        [-1,  9, -1],
        [-1, -1, -1]
    ])

def sharpen_light_kernel() -> np.ndarray:
    return np.array([
        [ 0, -1,  0],
        [-1,  4, -1],
        [ 0, -1,  0]
    ])


def sobel_x_kernel_tb() -> np.ndarray:
    return np.array([
        [-1, 0, 1],
        [-2, 0, 2],
        [-1, 0, 1]
    ])
def sobel_y_kernel_lr() -> np.ndarray:
    return np.array([
        [-1, -2, -1],
        [ 0,  0,  0],
        [ 1,  2,  1]
    ])

def sobel_x_kernel_bt() -> np.ndarray:
    return np.array([
        [ 1, 0, -1],
        [ 2, 0, -2],
        [ 1, 0, -1]
    ])

def sobel_y_kernel_rl() -> np.ndarray:
    return np.array([
        [ 1,  2,  1],
        [ 0,  0,  0],
        [-1, -2, -1]
    ])


