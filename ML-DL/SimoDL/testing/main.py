import torch

import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt

import torch.nn as nn
import torch.optim as optim
from tqdm import tqdm
from torch.utils.data import DataLoader, TensorDataset

file_path = "../Dataset/ds_salaries.csv"
data = pd.read_csv(file_path)


df = pd.DataFrame(data)

features = ['experience_level', 'employment_type', 'remote_ratio', 'company_size']
target = ['salary_in_usd']

X = df[features]
y = df[target]

categorical_columns = X.select_dtypes(include=['object']).columns
X = pd.get_dummies(X, columns=categorical_columns, drop_first = True)

X = StandardScaler().fit_transform(X)
y = StandardScaler().fit_transform(y)


lr = 0.001
epochs = 20
batch_size = 8



model_sigmoid = nn.Sequential(
  nn.Linear(X.shape[1], 16),
  nn.Sigmoid(),
  nn.Linear(16, 8),
  nn.Sigmoid(),
  nn.Linear(8, 1)
)


model_relu = nn.Sequential(
  nn.Linear(X.shape[1], 16),
  nn.ReLU(),
  nn.Linear(16, 8),
  nn.ReLU(),
  nn.Linear(8, 1)
)

mode_LeakyReLU = nn.Sequential(
  nn.Linear(X.shape[1], 16),
  nn.LeakyReLU(),
  nn.Linear(16, 8),
  nn.LeakyReLU(),
  nn.Linear(8, 1)
)


criterion = nn.MSELoss()
dataset = TensorDataset(torch.tensor(X).float(), torch.tensor(y).float())
dataloader = DataLoader(dataset, batch_size=batch_size, shuffle=True)

sigmoid_losses = []
relu_losses = []
leaky_relu_losses = []

print("Sigmoid model")
optimizer_sigmoid = optim.AdamW(model_sigmoid.parameters(), lr=lr)
for epoch in range(epochs):
  loss_list = []
  model_sigmoid.train()
  for batch_X, batch_y in tqdm(dataloader, desc=f"Epoch {epoch+1}/{epochs}"):
    optimizer_sigmoid.zero_grad()
    predictions = model_sigmoid(batch_X)
    loss = criterion(predictions, batch_y)
    loss.backward()
    optimizer_sigmoid.step()
    loss_list.append(loss.item())
  loss_average_sigmoid = np.average(loss_list)
  sigmoid_losses.append(loss_average_sigmoid)
  print(f'Average Loss: {loss_average_sigmoid}')



print("\n\nReLU model")
optimizer_relu = optim.AdamW(model_relu.parameters(), lr=lr)
for epoch in range(epochs):
  loss_list = []
  model_relu.train()
  for batch_X, batch_y in tqdm(dataloader, desc=f"Epoch {epoch+1}/{epochs}"):
    optimizer_relu.zero_grad()
    predictions = model_relu(batch_X)
    loss = criterion(predictions, batch_y)
    loss.backward()
    optimizer_relu.step()
    loss_list.append(loss.item())
  loss_average_relu = np.average(loss_list)
  relu_losses.append(loss_average_relu)
  print(f'Average Loss: {loss_average_relu}')


print("\n\nLeaky ReLU model")
optimizer_leaky_relu = optim.AdamW(mode_LeakyReLU.parameters(), lr=lr)
for epoch in range(epochs):
  loss_list = []
  mode_LeakyReLU.train()
  for batch_X, batch_y in tqdm(dataloader, desc=f"Epoch {epoch+1}/{epochs}"):
    optimizer_leaky_relu.zero_grad()
    predictions = mode_LeakyReLU(batch_X)
    loss = criterion(predictions, batch_y)
    loss.backward()
    optimizer_leaky_relu.step()
    loss_list.append(loss.item())
  loss_average_leaky_relu = np.average(loss_list)
  leaky_relu_losses.append(loss_average_leaky_relu)
  print(f'Average Loss: {loss_average_leaky_relu}')



plt.figure()
plt.plot(range(1, epochs+1), sigmoid_losses, label='Sigmoid')
plt.plot(range(1, epochs+1), relu_losses, label='ReLU')
plt.plot(range(1, epochs+1), leaky_relu_losses, label='Leaky ReLU')
plt.legend()
plt.show()

