import numpy as np
import matplotlib.pyplot as plt

def show_side_by_side(original: np.ndarray, processed: np.ndarray,
                      title_left: str = "Original", title_right: str = "Processed") -> None:
    def prep(img: np.ndarray) -> np.ndarray:
        # If float RGB in [0..255], convert to uint8 so imshow won't warn
        if img.ndim == 3 and img.dtype.kind == "f" and img.max() > 1.0:
            img = np.clip(img, 0, 255).astype(np.uint8)
        return img

    original = prep(original)
    processed = prep(processed)

    plt.figure(figsize=(10, 5))
    plt.subplot(1, 2, 1); plt.imshow(original, cmap="gray" if original.ndim == 2 else None); plt.title(title_left); plt.axis("off")
    plt.subplot(1, 2, 2); plt.imshow(processed, cmap="gray" if processed.ndim == 2 else None); plt.title(title_right); plt.axis("off")
    plt.tight_layout()
    plt.show()