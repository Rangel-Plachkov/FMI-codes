
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
import numpy as np
from tensorflow.keras.datasets import mnist
import matplotlib.pyplot as plt

def load_emnist():
    import tensorflow_datasets as tfds
    ds = tfds.load("emnist/letters", split='train', as_supervised=True)
    ds_test = tfds.load("emnist/letters", split='test', as_supervised=True)
    return ds, ds_test


def preprocess(ds):
    ds = ds.map(lambda img, label: (tf.image.resize(img, (28, 28)), label - 1))
    ds = ds.map(lambda img, label: (tf.cast(img, tf.float32) / 255.0, label))
    ds = ds.batch(128).shuffle(10000)
    return ds


train_ds, test_ds = load_emnist()
train_ds, test_ds = preprocess(train_ds), preprocess(test_ds)

model = keras.Sequential([
    layers.Conv2D(32, (3, 3), activation='relu', input_shape=(28, 28, 1)),
    layers.MaxPooling2D((2, 2)),
    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.Flatten(),
    layers.Dense(64, activation='relu'),
    layers.Dense(26, activation='softmax')
])


model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])


model.fit(train_ds, epochs=20, validation_data=test_ds)

model.save("handwritten_letter_recognition.h5")

for images, labels in test_ds.take(1):
    predictions = model.predict(images)
    predicted_labels = np.argmax(predictions, axis=1)
    fig, axes = plt.subplots(1, 10, figsize=(15, 5))
    for i, ax in enumerate(axes):
        ax.imshow(images[i].numpy().squeeze(), cmap='gray')
        ax.set_title(chr(predicted_labels[i] + ord('A')))
        ax.axis('off')
    plt.show()
