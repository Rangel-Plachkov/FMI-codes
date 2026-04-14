from physics import compute_forces, integrate


class Simulation:
    def __init__(self, particles):
        self.particles = particles

    def step(self):
        compute_forces(self.particles)
        integrate(self.particles)