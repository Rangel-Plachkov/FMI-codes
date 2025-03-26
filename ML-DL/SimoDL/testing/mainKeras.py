import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler
from tensorflow import keras
from tensorflow.keras import layers

file_path = "../Dataset/ds_salaries.csv"
data = pd.read_csv(file_path)
df = pd.DataFrame(data)

features = ['experience_level', 'employment_type', 'remote_ratio', 'company_size']
target = ['salary_in_usd']

X = df[features]
y = df[target]


categorical_columns = X.select_dtypes(include=['object']).columns
X = pd.get_dummies(X, columns=categorical_columns, drop_first=True)


scaler_X = StandardScaler()
scaler_y = StandardScaler()
X = scaler_X.fit_transform(X)
y = scaler_y.fit_transform(y)


def create_model(activation_fn):
    model = keras.Sequential([
        layers.Dense(16, activation=activation_fn, input_shape=(X.shape[1],)),
        layers.Dense(8, activation=activation_fn),
        layers.Dense(1)
    ])
    model.compile(optimizer=keras.optimizers.Adam(learning_rate=0.001), loss='mse')
    return model


models = {
    "Sigmoid": create_model("sigmoid"),
    "ReLU": create_model("relu"),
    "LeakyReLU": create_model(keras.layers.LeakyReLU())
}

losses = {}

epochs = 20
batch_size = 8

for name, model in models.items():
    print(f"\nTraining {name} model")
    history = model.fit(X, y, epochs=epochs, batch_size=batch_size, verbose=1)
    losses[name] = history.history["loss"]

# Plot losses
plt.figure()
for name, loss_values in losses.items():
    plt.plot(range(1, epochs + 1), loss_values, label=name)
plt.legend()
plt.xlabel("Epochs")
plt.ylabel("Loss")
plt.title("Training Loss per Activation Function")
plt.show()
