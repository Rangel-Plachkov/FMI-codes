import torch
import torch.nn as nn
import torch.optim as optim
from torchvision import datasets, transforms
from torch.utils.data import DataLoader

batch_size = 8
learning_rate = 0.001
epochs = 5

transform = transforms.Compose([
    transforms.ToTensor(),
    transforms.Normalize((0.5,), (0.5,))
])

train_dataset = datasets.EMNIST(root='./data', split='letters', train=True, download=False, transform=transform)
test_dataset = datasets.EMNIST(root='./data', split='letters', train=False, download=False, transform=transform)

train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=True)

model = nn.Sequential(
    nn.Conv2d(1, 32, kernel_size=3, padding=1),
    nn.MaxPool2d(2),
    nn.ReLU(),

    nn.Conv2d(32, 64, kernel_size=3, padding=1),
    nn.MaxPool2d(2),
    nn.ReLU(),

    nn.Conv2d(64, 128, kernel_size=3, padding=1),
    nn.MaxPool2d(2),
    nn.ReLU(),

    nn.Dropout(0.25),
    nn.Flatten(),

    nn.Linear(128 * 3 * 3, 128),
    nn.ReLU(),
    nn.Linear(128, 26),
    nn.Softmax(dim=1)
)

criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr=learning_rate)

print("Training...")
for epoch in range(epochs):
    model.train()
    running_loss = 0.0
    for images, labels in train_loader:
        labels -= 1

        optimizer.zero_grad()
        outputs = model(images)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()

        running_loss += loss.item()

    print(f"Epoch [{epoch+1}/{epochs}], Loss: {running_loss/len(train_loader):.4f}")

model.eval()
correct = 0
total = 0
with torch.no_grad():
    for images, labels in test_loader:
        labels -= 1
        outputs = model(images)
        _, predicted = torch.max(outputs.data, 1)
        total += labels.size(0)
        correct += (predicted == labels).sum().item()

print(f'Test Accuracy: {100 * correct / total:.2f}%')

torch.save(model.state_dict(), 'model.pth')
print("Model saved as model.pth")
