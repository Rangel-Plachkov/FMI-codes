import numpy as np
from constants import G, EPS, DT


def compute_forces(particles):
    n = len(particles)

    for p in particles:
        p.reset_force()

    for i in range(n):
        pi = particles[i]

        for j in range(i + 1, n):
            pj = particles[j]

            r = pj.pos - pi.pos
            dist2 = np.dot(r, r) + EPS * EPS
            dist = np.sqrt(dist2)

            # force magnitude
            inv_dist3 = 1.0 / (dist2 * dist)
            f = G * pi.mass * pj.mass * r * inv_dist3

            pi.force += f
            pj.force -= f


def integrate(particles):
    for p in particles:
        acc = p.force / p.mass

        p.vel += acc * DT
        p.pos += p.vel * DT