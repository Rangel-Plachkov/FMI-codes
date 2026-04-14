import pygame

class Visualizer:
    def __init__(self, sim, width=800, height=800, scale=100):
        self.sim = sim
        self.width = width
        self.height = height
        self.scale = scale

        pygame.init()
        self.screen = pygame.display.set_mode((width, height))
        self.clock = pygame.time.Clock()

    def world_to_screen(self, pos):
        x = int(self.width / 2 + pos[0] * self.scale)
        y = int(self.height / 2 + pos[1] * self.scale)
        return x, y

    def draw(self):
        self.screen.fill((0, 0, 0))

        for p in self.sim.particles:
            x, y = self.world_to_screen(p.pos)
            pygame.draw.circle(self.screen, p.color, (x, y), 3)

        pygame.display.flip()

    def update_display(self):
        self.draw()
        self.clock.tick(60)