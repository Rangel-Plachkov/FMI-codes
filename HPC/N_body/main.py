import numpy as np
from particle import Particle
from simulation import Simulation
from constants import SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_SCALE
from visualization.pygame_viz import Visualizer
import pygame


def create_random_particles(
    n,
    box_size=10.0,
    mass_range=(1e3, 1e5),
    vel_range=(0, 0),
    seed=None
):
    if seed is not None:
        np.random.seed(seed)

    particles = []

    for i in range(n):
        position = np.random.uniform(-box_size, box_size, 3)
        # if i%2 == 0:
        #     position = np.random.uniform(0, box_size, 3)
        # else:
        #     position = np.random.uniform(-box_size, 0, 3)

        velocity = np.random.uniform(vel_range[0], vel_range[1], 3)
        mass = np.random.uniform(mass_range[0], mass_range[1])
        #color = (0, 250, 250)

        particles.append(
            Particle(position, velocity, mass)
        )

    return particles

def main():
    # particles = [
    #     Particle([-1, 0, 0], [0, 0, 0], 100000, color=(255, 0, 0)),
    #     Particle([1, 0, 0], [0, 0, 0], 100000, color=(0, 255, 0)),
    #     Particle([0, 1, 0], [0, 0, 0], 100000, color=(0, 0, 255)),
    # ]
    particles = create_random_particles(50)

    sim = Simulation(particles)
    viz = Visualizer(sim, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_SCALE)

    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        sim.step()
        viz.update_display()

    pygame.quit()


if __name__ == "__main__":
    main()