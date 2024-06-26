package types;

import java.io.Serializable;
//class to store the stats of the player(name, score, time). It is serializable so that it can be sent over the network
@SuppressWarnings("unused")
public class Stat implements Serializable {
    String name;
    int score;
    int time;

    @Override
    public String toString(){
        return name + " " + score + " " + time;
    }
    public Stat(String name, int score, int time){
        this.name = name;
        this.score = score;
        this.time = time;
    }
    String getName(){
        return name;
    }
    int getScore(){
        return score;
    }
    int getTime(){
        return time;
    }
    void setName(String name){
        this.name = name;
    }
    void setScore(int score){
        this.score = score;
    }
    void setTime(int time){
        this.time = time;
    }

}
