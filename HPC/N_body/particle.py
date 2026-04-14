import numpy as np
from typing import Tuple
from constants import DIMENSIONS

class Particle:
    _counter = 0

    def __init__(
        self,
        pos: np.ndarray,
        vel: np.ndarray,
        mass: float,
        radius: float = 1.0,
        color: Tuple[int, int, int] = (255, 255, 255) ) -> None:

        self.pos: np.ndarray = np.asarray(pos, dtype=float).reshape(DIMENSIONS)
        self.vel: np.ndarray = np.asarray(vel, dtype=float).reshape(DIMENSIONS)
        self.mass: float = float(mass)
        self.radius: float = float(radius)
        self.force: np.ndarray = np.zeros(DIMENSIONS, dtype=float)
        self.color: Tuple[int, int, int] = color
        self.id: int = Particle._counter
        Particle._counter += 1

    def reset_force(self) -> None:
        self.force.fill(0.0)
