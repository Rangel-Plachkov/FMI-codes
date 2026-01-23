import time
import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
from scipy.signal import correlate2d

import convolutions as conv
import convolution_rgb as conv_rgb
import kernels as kernel
import plotFunctions as pltF

def show1(filename):
    """Pure python greyscale image"""
    img = Image.open(filename).convert('L')
    img_list = np.array(img).tolist()

    kern = kernel.create_gaussian_kernel(9).tolist()  #python list
    result = conv.convolve2d_pure_python(img_list, kern)
    pltF.show_side_by_side( np.array(img) , np.array(result) )

def show2(filename):
    """numpy (fast) greyscale image"""
    img = Image.open(filename).convert('L')
    img_np = np.array(img)

    kern = kernel.create_gaussian_kernel(3 , 1)
    result = conv.convolve2d_numpy_fast(img_np, kern)
    #result = conv.convolve2d_numpy(img_np, kern)
    pltF.show_side_by_side( img_np , result )

def show3(filename):
    """numba greyscale 5 iterations"""
    img = Image.open(filename).convert('L')
    img_np = np.array(img)
    kern = kernel.create_gaussian_kernel(3)
    for i in range(5):
        start = time.perf_counter()
        _ = conv.convolve2d_numba(img_np, kern)
        end = time.perf_counter()
        print(f'{end - start} seconds')

def show4(filename):
    """parallel numba 10 iterations"""
    img = Image.open(filename).convert('L')
    img_np = np.array(img)
    kern = kernel.create_gaussian_kernel(3)
    for i in range(5):
        start = time.perf_counter()
        _ = conv.convolve2d_numba_parallel(img_np, kern)
        end = time.perf_counter()
        print(f'{end - start} seconds')


def show5(filename):
    """Validate all """ #corelate no convolute

    img = Image.open(filename).convert("L")
    img_np = np.array(img)
    img_lst = img_np.tolist()

    kern = kernel.create_gaussian_kernel(3)
    kern_lst = kern.tolist()

    ref = correlate2d(img_np, kern, mode="valid") #valid -> doesnt do padding

    res_pure = np.array(conv.convolve2d_pure_python(img_lst, kern_lst))
    res_numpy = conv.convolve2d_numpy_fast(img_np, kern)
    res_numba = conv.convolve2d_numba(img_np, kern)
    res_numba_parallel = conv.convolve2d_numba_parallel(img_np, kern)

    print(f"pure python: {np.allclose(res_pure, ref)}")
    print(f"numpy: {np.allclose(res_numpy, ref)}")
    print(f"numba: {np.allclose(res_numba, ref)}")
    print(f"numba parallel: {np.allclose(res_numba_parallel, ref)}")


def show6(filename):
    """time comparison"""
    samples = 5
    img = Image.open(filename).convert('L')
    img_np = np.array(img)
    img_lst = np.array(img).tolist()

    kern = kernel.create_gaussian_kernel(3)
    kern_lst = np.array(kern).tolist()

    res_time_pure_python = 0
    for i in range(samples):
        start = time.perf_counter()
        _ = conv.convolve2d_pure_python(img_lst, kern_lst)
        end = time.perf_counter()
        res_time_pure_python += end - start
    res_time_pure_python /= samples

    res_time_numpy = 0
    for i in range(samples):
        start = time.perf_counter()
        _ = conv.convolve2d_numpy_fast(img_np, kern)
        end = time.perf_counter()
        res_time_numpy += end - start
    res_time_numpy /= samples

    res_time_numba = 0
    res_time_numba_first = 0
    for i in range(samples):
        start = time.perf_counter()
        _ = conv.convolve2d_numba(img_np, kern)
        end = time.perf_counter()
        if i == 0:
            res_time_numba_first = end - start
        else:
            res_time_numba += end - start
    res_time_numba /= ( samples - 1 )

    res_time_numba_parallel = 0
    res_time_numba_parallel_first = 0
    for i in range(samples):
        start = time.perf_counter()
        _ = conv.convolve2d_numba_parallel(img_np, kern)
        end = time.perf_counter()
        if i == 0:
            res_time_numba_parallel_first = end - start
        else:
            res_time_numba_parallel += end - start
    res_time_numba_parallel /=  (samples - 1)

    res_time_scipy = 0
    for i in range(samples):
        start = time.perf_counter()
        _ = correlate2d(img_np, kern, mode="valid") #not convolute!!!
        end = time.perf_counter()
        res_time_scipy += end - start
    res_time_scipy /= samples

    round_d = 5
    print(f'pure python: {round(res_time_pure_python, round_d)}\n')
    print(f'numpy: {round(res_time_numpy, round_d)}\n')
    print(f'numba first: {round(res_time_numba_first, round_d)}')
    print(f'numba: {round(res_time_numba, round_d)}\n')
    print(f'numba parallel first: {round(res_time_numba_parallel_first, round_d)}')
    print(f'numba_parallel: {round(res_time_numba_parallel, round_d)}\n')
    print(f'scipy: {round(res_time_scipy, round_d)}\n')


def show7(filename):
    img = np.array(Image.open(filename).convert("L"))

    image_sizes = (256, 512, 1024, 2048)
    kernel_sizes = (3, 5, 7, 11)
    samples = 5
    speedup = np.zeros((len(image_sizes), len(kernel_sizes)))

    _ = conv.convolve2d_numba_parallel(img, kernel.create_gaussian_kernel(7))

    for yi, H in enumerate(image_sizes):
        cropped = img[:H, :H]
        for xi, k in enumerate(kernel_sizes):
            kern = kernel.create_gaussian_kernel(k)
            t_numpy = 0.0
            t_numba = 0.0

            for _ in range(samples):
                t0 = time.perf_counter()
                conv.convolve2d_numpy_fast(cropped, kern)
                t_numpy += time.perf_counter() - t0

                t0 = time.perf_counter()
                conv.convolve2d_numba_parallel(cropped, kern)
                t_numba += time.perf_counter() - t0

            speedup[yi, xi] = (t_numpy / samples) / (t_numba / samples)

    plt.figure(figsize=(10, 6))
    plt.imshow(speedup, aspect="auto")
    plt.colorbar(label="Speedup (NumPy / Numba parallel)")

    plt.xticks(range(len(kernel_sizes)), [f"{k}x{k}" for k in kernel_sizes])
    plt.yticks(range(len(image_sizes)), [f"{h}x{h}" for h in image_sizes])

    plt.xlabel("Kernel size")
    plt.ylabel("Image size (cropped)")
    plt.title("Heatmap: NumPy fast vs Numba parallel")

    for i in range(speedup.shape[0]):
        for j in range(speedup.shape[1]):
            plt.text(j, i, f"{speedup[i, j]:.2f}x", ha="center", va="center")

    plt.tight_layout()
    plt.show()

    return speedup


def show8(filename):
    """edge detection kernels (2x3 plot + merged edges)"""
    img = np.array(Image.open(filename).convert("L"))

    k_tb = kernel.sharpen_strong_kernel()
    k_bt = kernel.sharpen_light_kernel()
    k_lr = kernel.sharpen_basic_kernel()
    k_rl = kernel.sobel_y_kernel_rl()

    e_tb = conv.convolve2d_numpy_fast(img, k_tb)
    e_bt = conv.convolve2d_numpy_fast(img, k_bt)
    e_lr = conv.convolve2d_numpy_fast(img, k_lr)
    e_rl = conv.convolve2d_numpy_fast(img, k_rl)

    # e_tb = np.abs(conv.convolve2d_numpy_fast(img, k_tb))
    # e_bt = np.abs(conv.convolve2d_numpy_fast(img, k_bt))
    # e_lr = np.abs(conv.convolve2d_numpy_fast(img, k_lr))
    # e_rl = np.abs(conv.convolve2d_numpy_fast(img, k_rl))

    factor = 100000
    merged = e_tb + e_bt + e_lr + e_rl
    #merged = e_tb*factor + e_bt*factor + e_lr*factor + e_rl*factor

    plt.figure(figsize=(14, 8))

    plt.subplot(2, 3, 1)
    plt.imshow(img, cmap="gray")
    plt.title("Original")
    plt.axis("off")

    plt.subplot(2, 3, 2)
    plt.imshow(e_tb, cmap="gray")
    plt.title("Sobel TB")
    plt.axis("off")

    plt.subplot(2, 3, 3)
    plt.imshow(e_bt, cmap="gray")
    plt.title("Sobel BT")
    plt.axis("off")

    plt.subplot(2, 3, 4)
    plt.imshow(e_lr, cmap="gray")
    plt.title("Sobel LR")
    plt.axis("off")

    plt.subplot(2, 3, 5)
    plt.imshow(e_rl, cmap="gray")
    plt.title("Sobel RL")
    plt.axis("off")

    plt.subplot(2, 3, 6)
    plt.imshow(merged, cmap="gray")
    plt.title("Merged edges")
    plt.axis("off")

    plt.tight_layout()
    plt.show()



def show9(filename):
    """rgb images"""
    img = np.array(Image.open(filename).convert("RGB"))
    kern = kernel.create_gaussian_kernel(3)
    out = conv_rgb.convolve2d_numba_parallel_rgb(img , kern)
    pltF.show_side_by_side(img, out)



def show10(filename):
    img = np.array(Image.open(filename).convert("RGB"))
    kern = np.array(kernel.create_gaussian_kernel(3))

    round_d = 5
    t0 = time.perf_counter()
    _ = conv_rgb.convolve2d_numba_rgb(img, kern)
    warm_parallel = time.perf_counter() - t0

    t0 = time.perf_counter()
    _ = conv_rgb.convolve2d_numba_parallel_rgb_fast_math(img, kern)
    warm_fast = time.perf_counter() - t0

    N = 10
    avg_p = 0
    avg_pfm = 0
    for _ in range(N):
        t0 = time.perf_counter()
        _ = conv_rgb.convolve2d_numba_rgb(img, kern)
        avg_p += time.perf_counter() - t0

        t0 = time.perf_counter()
        _ = conv_rgb.convolve2d_numba_parallel_rgb_fast_math(img, kern)
        avg_pfm += time.perf_counter() - t0

    avg_p /= 10
    avg_pfm /= 10
    print(f"parallel first time: {round(warm_parallel, round_d)}")
    print(f"fastmath first time: {round(warm_fast, round_d)}\n")
    print(f"parallel avg: {round(avg_p, round_d)}")
    print(f"fastmath avg: {round(avg_pfm, round_d)}\n")