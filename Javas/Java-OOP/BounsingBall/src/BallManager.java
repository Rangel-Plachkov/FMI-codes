import java.util.ArrayList;
public class BallManager{
    private final ArrayList<Ball> balls;
    private final ArrayList<Wall> walls;
    private final double wallThickness= 20;
    private final double ballRadius = 10;
    public BallManager(){
        this.balls = new ArrayList<Ball>();
        this.walls = new ArrayList<Wall>();
        borderWalls();
    }
    public void addBall(Ball ball){
        this.balls.add(ball);
    }
    public void addWall(Wall wall){
        this.walls.add(wall);
    }
    public void moveBalls(){
        this.balls.forEach(Ball::move);
    }
    public ArrayList<Ball> getBalls(){
        return this.balls;
    }
    public ArrayList<Wall> getWalls(){
        return this.walls;
    }
    public void checkCollisions(){
        for(int i = 0; i < this.balls.size(); i++){
            for(int j = i + 1; j < this.balls.size(); j++){
                if(this.balls.get(i).isCollidingWithBall(this.balls.get(j))){
                    this.balls.get(i).setSpeed(this.balls.get(i).getSpeed().multiply(-1));
                    this.balls.get(j).setSpeed(this.balls.get(j).getSpeed().multiply(-1));
                }
            }
        }
        for (Ball ball : this.balls) {
            for (Wall wall : this.walls) {
                if (ball.isCollidingWithWall(wall)) {
                    ball.setSpeed(ball.getSpeed().multiply(-1));
                }
            }
        }
    }
    private void borderWalls(){
        this.walls.add(new Wall(new Coordinates(0, 0), new Coordinates(wallThickness, GUI.HEIGHT)));
        this.walls.add(new Wall(new Coordinates(0, 0), new Coordinates(GUI.WIDTH, wallThickness)));
        this.walls.add(new Wall(new Coordinates(GUI.WIDTH - wallThickness, 0), new Coordinates(wallThickness, GUI.HEIGHT)));
        this.walls.add(new Wall(new Coordinates(0, GUI.HEIGHT - wallThickness), new Coordinates(GUI.WIDTH, wallThickness)));
    }
}
