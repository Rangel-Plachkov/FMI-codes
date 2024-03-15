import static java.lang.Thread.sleep;

public class Main {

    public static void main(String[] args) throws InterruptedException {

        BallManager ballManager = new BallManager();
        GUI gui = new GUI();
        GUI.ballsArray = ballManager.getBalls();
        GUI.wallsArray = ballManager.getWalls();
        //TODO
        GUI.ballsArray.add(new Ball(new Coordinates(400, 300),new Coordinates(1,1), 10));
        GUI.launch(GUI.class, args);
        for(int i = 0; i<10; i++){
            GUI.ballsArray.getFirst().move();
            sleep(10);
            System.out.println("zele");

        }

    }


}
